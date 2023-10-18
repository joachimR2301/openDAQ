#include <websocket_streaming/streaming_client.h>
#include <websocket_streaming/streaming_server.h>
#include <opendaq/context_factory.h>

#include <gtest/gtest.h>
#include <chrono>
#include "streaming_test_helpers.h"


using namespace daq;
using namespace daq::websocket_streaming;

class StreamingTest : public testing::Test
{
public:
    const uint16_t StreamingPort = daq::streaming_protocol::WEBSOCKET_LISTENING_PORT;
    SignalPtr testDoubleSignal;
    ContextPtr context;

    void SetUp() override
    {
        context = NullContext();
        testDoubleSignal = streaming_test_helpers::createTestSignal(context);
    }

    void TearDown() override
    {
    }

    PacketPtr createDataPacket(const std::vector<double> data, Int packetOffset = 0)
    {
        auto sampleCount = data.size();
        auto dataDescriptor = testDoubleSignal.getDescriptor();
        auto domainDescriptor = testDoubleSignal.getDomainSignal().getDescriptor();
        auto domainPacket = DataPacket(domainDescriptor, sampleCount, packetOffset);
        return DataPacketWithDomain(domainPacket, dataDescriptor, sampleCount);
    }
};

TEST_F(StreamingTest, Connect)
{
    auto server = std::make_shared<StreamingServer>(context);
    server->start(StreamingPort);

    auto client = StreamingClient(context, "127.0.0.1", StreamingPort);

    ASSERT_FALSE(client.isConnected());
    client.connect();

    ASSERT_TRUE(client.isConnected());

    client.disconnect();
    ASSERT_FALSE(client.isConnected());
}

TEST_F(StreamingTest, ConnectTimeout)
{
    auto server = std::make_shared<StreamingServer>(context);
    server->start(StreamingPort);

    auto client = StreamingClient(context, "127.0.0.1", 7000);

    client.connect();
    ASSERT_FALSE(client.isConnected());
}

TEST_F(StreamingTest, ConnectTwice)
{
    auto server = std::make_shared<StreamingServer>(context);
    server->start(StreamingPort);

    auto client = StreamingClient(context, "127.0.0.1", StreamingPort);

    ASSERT_TRUE(client.connect());
    client.disconnect();

    ASSERT_TRUE(client.connect());
    ASSERT_TRUE(client.isConnected());
    client.disconnect();

    ASSERT_FALSE(client.isConnected());
}

TEST_F(StreamingTest, ParseConnectString)
{
    auto client = std::make_shared<StreamingClient>(NullContext(), "daq.wss://127.0.0.1");
    ASSERT_EQ(client->getPort(), daq::streaming_protocol::WEBSOCKET_LISTENING_PORT);
    ASSERT_EQ(client->getHost(), "127.0.0.1");
    ASSERT_EQ(client->getTarget(), "/");

    client = std::make_shared<StreamingClient>(NullContext(), "daq.wss://localhost/path/other");
    ASSERT_EQ(client->getPort(), daq::streaming_protocol::WEBSOCKET_LISTENING_PORT);
    ASSERT_EQ(client->getHost(), "localhost");
    ASSERT_EQ(client->getTarget(), "/path/other");

    client = std::make_shared<StreamingClient>(NullContext(), "daq.wss://localhost:3000/path/other");
    ASSERT_EQ(client->getPort(), 3000u);
    ASSERT_EQ(client->getHost(), "localhost");
    ASSERT_EQ(client->getTarget(), "/path/other");
}

TEST_F(StreamingTest, SimpePacket)
{
    std::vector<double> data = {-1.5, -1.0, -0.5, 0, 0.5, 1.0, 1.5};
    auto packet = createDataPacket(data, 100);

    auto server = std::make_shared<StreamingServer>(context);
    server->onAccept([this](const daq::streaming_protocol::StreamWriterPtr& writer) {
        auto signals = List<ISignal>();
        signals.pushBack(testDoubleSignal);
        return signals;
    });
    server->start(StreamingPort);

    std::vector<PacketPtr> receivedPackets;
    auto client = StreamingClient(context, "127.0.0.1", StreamingPort);

    auto onPacket = [&receivedPackets](const StringPtr& signalId, const PacketPtr& packet)
    {
        receivedPackets.push_back(packet);
    };

    auto findSignal = [&](const StringPtr& signalId) { return testDoubleSignal; };

    client.onPacket(onPacket);
    client.onFindSignal(findSignal);
    client.connect();
    ASSERT_TRUE(client.isConnected());

    std::string signalId = testDoubleSignal.getGlobalId();
    server->broadcastPacket(signalId, packet);

    std::this_thread::sleep_for(std::chrono::milliseconds(250));

    ASSERT_EQ(receivedPackets.size(), 2u);
    ASSERT_EQ(receivedPackets[0].asPtr<IEventPacket>().getEventId(), event_packet_id::DATA_DESCRIPTOR_CHANGED);
    ASSERT_TRUE(BaseObjectPtr::Equals(packet, receivedPackets[1]));
}