#include <native_streaming_client_module/native_streaming_device_impl.h>
#include <native_streaming_client_module/native_streaming_signal_impl.h>
#include <native_streaming_client_module/native_streaming_impl.h>

#include <opendaq/device_info_factory.h>
#include <opendaq/component_deserialize_context_factory.h>
#include <opendaq/deserialize_component_ptr.h>

#include <coretypes/function_factory.h>

#include <coreobjects/property_object_protected_ptr.h>

#include <regex>

BEGIN_NAMESPACE_OPENDAQ_NATIVE_STREAMING_CLIENT_MODULE

using namespace opendaq_native_streaming_protocol;

NativeStreamingDeviceImpl::NativeStreamingDeviceImpl(const ContextPtr& ctx,
                                                     const ComponentPtr& parent,
                                                     const StringPtr& localId,
                                                     const StringPtr& connectionString,
                                                     const StringPtr& host,
                                                     const StringPtr& port,
                                                     const StringPtr& path)
    : Device(ctx, parent, localId)
    , connectionString(connectionString)
    , reconnectionStatus(ClientReconnectionStatus::Connected)
{
    if (!this->connectionString.assigned())
        throw ArgumentNullException("connectionString cannot be null");

    createNativeStreaming(host, port, path);
    activateStreaming();
}

void NativeStreamingDeviceImpl::createNativeStreaming(const StringPtr& host,
                                                      const StringPtr& port,
                                                      const StringPtr& path)
{
    ProcedurePtr onSignalAvailableCallback =
        Procedure([this](const StringPtr& signalStringId,
                         const StringPtr& serializedSignal)
                  {
                      signalAvailableHandler(signalStringId, serializedSignal);
                  });

    ProcedurePtr onSignalUnavailableCallback =
        Procedure([this](const StringPtr& signalStringId)
                  {
                      signalUnavailableHandler(signalStringId);
                  });

    opendaq_native_streaming_protocol::OnReconnectionStatusChangedCallback onReconnectionStatusChangedCallback =
        [this](opendaq_native_streaming_protocol::ClientReconnectionStatus status)
        {
            reconnectionStatusChangedHandler(status);
        };

    auto clientHandler = std::make_shared<NativeStreamingClientHandler>(context);
    std::string streamingConnectionString = std::regex_replace(connectionString.toStdString(),
                                                               std::regex(NativeStreamingDevicePrefix),
                                                               NativeStreamingPrefix);
    nativeStreaming =
        createWithImplementation<IStreaming, NativeStreamingImpl>(streamingConnectionString,
                                                                  host,
                                                                  port,
                                                                  path,
                                                                  context,
                                                                  clientHandler,
                                                                  onSignalAvailableCallback,
                                                                  onSignalUnavailableCallback,
                                                                  onReconnectionStatusChangedCallback);
}

void NativeStreamingDeviceImpl::activateStreaming()
{
    auto self = this->borrowPtr<DevicePtr>();
    const auto signals = self.getSignals(search::Any());
    nativeStreaming.addSignals(signals);
    nativeStreaming.setActive(true);

    for (const auto& signal : signals)
    {
        auto mirroredSignalConfigPtr = signal.template asPtr<IMirroredSignalConfig>();
        mirroredSignalConfigPtr.setActiveStreamingSource(nativeStreaming.getConnectionString());
    }
}

DeviceInfoPtr NativeStreamingDeviceImpl::onGetInfo()
{
    if (deviceInfo != nullptr)
        return deviceInfo;

    deviceInfo = DeviceInfo(connectionString, "NativeStreamingClientPseudoDevice");
    deviceInfo.freeze();
    return deviceInfo;
}

SignalPtr NativeStreamingDeviceImpl::createSignal(const StringPtr& signalStringId,
                                                  const StringPtr& serializedSignal)
{
    const auto deserializer = JsonDeserializer();
    const auto deserializeContext = ComponentDeserializeContext(context, nullptr, this->signals, signalStringId);

    return deserializer.deserialize(
        serializedSignal,
        deserializeContext,
        [](const StringPtr& typeId, const SerializedObjectPtr& object, const BaseObjectPtr& context, const FunctionPtr& factoryCallback) -> BaseObjectPtr
        {
            if (typeId != "Signal")
                return nullptr;
            BaseObjectPtr obj;
            checkErrorInfo(NativeStreamingSignalImpl::Deserialize(object, context, factoryCallback, &obj));
            return obj;
        });
}

void NativeStreamingDeviceImpl::addToDeviceSignals(const StringPtr& signalStringId,
                                                   const StringPtr& serializedSignal)
{
    if (auto iter = deviceSignals.find(signalStringId); iter != deviceSignals.end())
        throw AlreadyExistsException("Signal with id {} already exists in native streaming device", signalStringId);

    auto signalToAdd = createSignal(signalStringId, serializedSignal);
    StringPtr domainSignalStringId = signalToAdd.asPtr<IDeserializeComponent>(true).getDeserializedParameter("domainSignalId");

    // recreate signal -> domainSignal relations in the same way as on server
    for (const auto& item : deviceSignals)
    {
        auto addedSignalId = item.first;
        auto [addedSignal, domainSignalId] = item.second;
        if (domainSignalId == signalStringId)
        {
            addedSignal.asPtr<IMirroredSignalPrivate>()->assignDomainSignal(signalToAdd);
        }
        if (domainSignalStringId == addedSignalId)
        {
            signalToAdd.asPtr<IMirroredSignalPrivate>()->assignDomainSignal(addedSignal);
        }
    }

    this->addSignal(signalToAdd);
    deviceSignals.insert({signalStringId, {signalToAdd, domainSignalStringId}});
}

void NativeStreamingDeviceImpl::addToDeviceSignalsOnReconnection(const StringPtr& signalStringId,
                                                                 const StringPtr& serializedSignal)
{
    SignalPtr signalToAdd = createSignal(signalStringId, serializedSignal);
    StringPtr domainSignalStringId = signalToAdd.asPtr<IDeserializeComponent>(true).getDeserializedParameter("domainSignalId");

    if (auto iter1 = deviceSignals.find(signalStringId); iter1 != deviceSignals.end())
    {
        signalToAdd = iter1->second.first;
        // TODO update existing signal
    }
    else
    {
        if (auto iter2 = deviceSignalsReconnection.find(signalStringId); iter2 == deviceSignalsReconnection.end())
            signalToAdd = createSignal(signalStringId, serializedSignal);
        else
            throw AlreadyExistsException("Signal with id {} already exists in native streaming device", signalStringId);
    }

    // remove domain signal if it is no longer assigned after reconnection
    if (signalToAdd.getDomainSignal().assigned() && !domainSignalStringId.assigned())
    {
        signalToAdd.asPtr<IMirroredSignalPrivate>()->assignDomainSignal(nullptr);
    }
    // recreate signal -> domainSignal relations in the same way as on server
    for (const auto& item : deviceSignalsReconnection)
    {
        auto addedSignalId = item.first;
        auto [addedSignal, domainSignalId] = item.second;
        if (domainSignalId == signalStringId)
        {
            addedSignal.asPtr<IMirroredSignalPrivate>()->assignDomainSignal(signalToAdd);
        }
        if (domainSignalStringId == addedSignalId)
        {
            signalToAdd.asPtr<IMirroredSignalPrivate>()->assignDomainSignal(addedSignal);
        }
    }

    // add only new signals under device
    if (auto iter = deviceSignals.find(signalStringId); iter == deviceSignals.end())
        this->addSignal(signalToAdd);
    deviceSignalsReconnection.insert({signalStringId, {signalToAdd, domainSignalStringId}});
}

void NativeStreamingDeviceImpl::signalAvailableHandler(const StringPtr& signalStringId,
                                                       const StringPtr& serializedSignal)
{
    if (reconnectionStatus == ClientReconnectionStatus::Reconnecting)
    {
        addToDeviceSignalsOnReconnection(signalStringId, serializedSignal);
    }
    else
    {
        addToDeviceSignals(signalStringId, serializedSignal);
    }
}

void NativeStreamingDeviceImpl::signalUnavailableHandler(const StringPtr& signalStringId)
{
    if (auto iter = deviceSignals.find(signalStringId); iter == deviceSignals.end())
        throw NotFoundException("Signal with id {} is not found in native streaming device", signalStringId);

    auto [signalToRemove,_] = deviceSignals.at(signalStringId);

    // recreate signal -> domainSignal relations in the same way as on server
    for (const auto& item : deviceSignals)
    {
        auto addedSignalId = item.first;
        auto [addedSignal, domainSignalId] = item.second;
        if (domainSignalId == signalStringId)
        {
            addedSignal.asPtr<IMirroredSignalPrivate>()->assignDomainSignal(nullptr);
        }
    }

    this->removeSignal(signalToRemove);
    deviceSignals.erase(signalStringId);
}

void NativeStreamingDeviceImpl::reconnectionStatusChangedHandler(ClientReconnectionStatus status)
{
    if (status == ClientReconnectionStatus::Restored)
    {
        // remove signals which no longer exist after reconnection
        for (const auto& item : deviceSignals)
        {
            auto signalId = item.first;
            auto signal = item.second.first;

            if (auto iter = deviceSignalsReconnection.find(signalId); iter == deviceSignalsReconnection.end())
            {
                this->removeSignal(signal);
            }
        }

        // replace signal container with new one
        deviceSignals = deviceSignalsReconnection;
        deviceSignalsReconnection.clear();
    }
    reconnectionStatus = status;
}

END_NAMESPACE_OPENDAQ_NATIVE_STREAMING_CLIENT_MODULE
