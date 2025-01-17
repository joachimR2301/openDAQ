#include <opendaq/device_info_factory.h>
#include <gtest/gtest.h>
#include <coreobjects/property_object_factory.h>
#include <coreobjects/property_factory.h>
#include <opendaq/device_type_factory.h>

using DeviceInfoTest = testing::Test;

BEGIN_NAMESPACE_OPENDAQ

TEST_F(DeviceInfoTest, Factory)
{
    DeviceInfoPtr deviceInfo;
    ASSERT_NO_THROW(deviceInfo = DeviceInfo("connectionStr", "name"));
    ASSERT_EQ(deviceInfo.getConnectionString(), "connectionStr");
    ASSERT_EQ(deviceInfo.getName(), "name");
}

TEST_F(DeviceInfoTest, DefaultValues)
{
    DeviceInfoPtr deviceInfo = DeviceInfo("");

    ASSERT_EQ(deviceInfo.getName(), "");
    ASSERT_EQ(deviceInfo.getConnectionString(), "");
    ASSERT_EQ(deviceInfo.getManufacturer(), "");
    ASSERT_EQ(deviceInfo.getManufacturerUri(), "");
    ASSERT_EQ(deviceInfo.getModel(), "");
    ASSERT_EQ(deviceInfo.getProductCode(), "");
    ASSERT_EQ(deviceInfo.getHardwareRevision(), "");
    ASSERT_EQ(deviceInfo.getSoftwareRevision(), "");
    ASSERT_EQ(deviceInfo.getDeviceManual(), "");
    ASSERT_EQ(deviceInfo.getDeviceClass(), "");
    ASSERT_EQ(deviceInfo.getSerialNumber(), "");
    ASSERT_EQ(deviceInfo.getProductInstanceUri(), "");
    ASSERT_EQ(deviceInfo.getRevisionCounter(), 0);
    ASSERT_EQ(deviceInfo.getDeviceRevision(), "");
    ASSERT_EQ(deviceInfo.getAssetId(), "");
    ASSERT_EQ(deviceInfo.getMacAddress(), "");
    ASSERT_EQ(deviceInfo.getParentMacAddress(), "");
    ASSERT_EQ(deviceInfo.getPlatform(), "");
    ASSERT_EQ(deviceInfo.getPosition(), 0);
    ASSERT_EQ(deviceInfo.getSystemType(), "");
    ASSERT_EQ(deviceInfo.getSystemUuid(), "");
    ASSERT_FALSE(deviceInfo.getDeviceType().assigned());

    ASSERT_EQ(deviceInfo.getAllProperties().getCount(), 21u);
}

TEST_F(DeviceInfoTest, SetGetProperties)
{
    DeviceInfoConfigPtr deviceInfoConfig = DeviceInfo("", "");
    DeviceInfoPtr deviceInfo = deviceInfoConfig;
    
    ASSERT_NO_THROW(deviceInfoConfig.setName("name"));
    ASSERT_EQ(deviceInfo.getName(), "name");
    ASSERT_EQ(deviceInfo.getPropertyValue("name"), "name");

    ASSERT_NO_THROW(deviceInfoConfig.setConnectionString("connectionString"));
    ASSERT_EQ(deviceInfo.getConnectionString(), "connectionString");
    ASSERT_EQ(deviceInfo.getPropertyValue("connectionString"), "connectionString");

    ASSERT_NO_THROW(deviceInfoConfig.setManufacturer("manufacturer"));
    ASSERT_EQ(deviceInfo.getManufacturer(), "manufacturer");
    ASSERT_EQ(deviceInfo.getPropertyValue("manufacturer"), "manufacturer");

    ASSERT_NO_THROW(deviceInfoConfig.setManufacturerUri("manufacturerUri"));
    ASSERT_EQ(deviceInfo.getManufacturerUri(), "manufacturerUri");
    ASSERT_EQ(deviceInfo.getPropertyValue("manufacturerUri"), "manufacturerUri");

    ASSERT_NO_THROW(deviceInfoConfig.setModel("model"));
    ASSERT_EQ(deviceInfo.getModel(), "model");
    ASSERT_EQ(deviceInfo.getPropertyValue("model"), "model");

    ASSERT_NO_THROW(deviceInfoConfig.setProductCode("productCode"));
    ASSERT_EQ(deviceInfo.getProductCode(), "productCode");
    ASSERT_EQ(deviceInfo.getPropertyValue("productCode"), "productCode");

    ASSERT_NO_THROW(deviceInfoConfig.setHardwareRevision("hardwareRevision"));
    ASSERT_EQ(deviceInfo.getHardwareRevision(), "hardwareRevision");
    ASSERT_EQ(deviceInfo.getPropertyValue("hardwareRevision"), "hardwareRevision");

    ASSERT_NO_THROW(deviceInfoConfig.setSoftwareRevision("softwareRevision"));
    ASSERT_EQ(deviceInfo.getSoftwareRevision(), "softwareRevision");
    ASSERT_EQ(deviceInfo.getPropertyValue("softwareRevision"), "softwareRevision");

    ASSERT_NO_THROW(deviceInfoConfig.setDeviceManual("deviceManual"));
    ASSERT_EQ(deviceInfo.getDeviceManual(), "deviceManual");
    ASSERT_EQ(deviceInfo.getPropertyValue("deviceManual"), "deviceManual");

    ASSERT_NO_THROW(deviceInfoConfig.setDeviceClass("deviceClass"));
    ASSERT_EQ(deviceInfo.getDeviceClass(), "deviceClass");
    ASSERT_EQ(deviceInfo.getPropertyValue("deviceClass"), "deviceClass");

    ASSERT_NO_THROW(deviceInfoConfig.setSerialNumber("serialNumber"));
    ASSERT_EQ(deviceInfo.getSerialNumber(), "serialNumber");
    ASSERT_EQ(deviceInfo.getPropertyValue("serialNumber"), "serialNumber");

    ASSERT_NO_THROW(deviceInfoConfig.setProductInstanceUri("productInstanceUri"));
    ASSERT_EQ(deviceInfo.getProductInstanceUri(), "productInstanceUri");
    ASSERT_EQ(deviceInfo.getPropertyValue("productInstanceUri"), "productInstanceUri");

    ASSERT_NO_THROW(deviceInfoConfig.setRevisionCounter(1));
    ASSERT_EQ(deviceInfo.getRevisionCounter(), 1);
    ASSERT_EQ(deviceInfo.getPropertyValue("revisionCounter"), 1);

    ASSERT_NO_THROW(deviceInfoConfig.setDeviceRevision("deviceRevision"));
    ASSERT_EQ(deviceInfo.getDeviceRevision(), "deviceRevision");
    ASSERT_EQ(deviceInfo.getPropertyValue("deviceRevision"), "deviceRevision");

    ASSERT_NO_THROW(deviceInfoConfig.setAssetId("assetId"));
    ASSERT_EQ(deviceInfo.getAssetId(), "assetId");
    ASSERT_EQ(deviceInfo.getPropertyValue("assetId"), "assetId");

    ASSERT_NO_THROW(deviceInfoConfig.setMacAddress("macAddress"));
    ASSERT_EQ(deviceInfo.getMacAddress(), "macAddress");
    ASSERT_EQ(deviceInfo.getPropertyValue("macAddress"), "macAddress");

    ASSERT_NO_THROW(deviceInfoConfig.setParentMacAddress("parentMacAddress"));
    ASSERT_EQ(deviceInfo.getParentMacAddress(), "parentMacAddress");
    ASSERT_EQ(deviceInfo.getPropertyValue("parentMacAddress"), "parentMacAddress");

    ASSERT_NO_THROW(deviceInfoConfig.setPlatform("platform"));
    ASSERT_EQ(deviceInfo.getPlatform(), "platform");
    ASSERT_EQ(deviceInfo.getPropertyValue("platform"), "platform");

    ASSERT_NO_THROW(deviceInfoConfig.setPosition(1));
    ASSERT_EQ(deviceInfo.getPosition(), 1);
    ASSERT_EQ(deviceInfo.getPropertyValue("position"), 1);

    ASSERT_NO_THROW(deviceInfoConfig.setSystemType("systemType"));
    ASSERT_EQ(deviceInfo.getSystemType(), "systemType");
    ASSERT_EQ(deviceInfo.getPropertyValue("systemType"), "systemType");

    ASSERT_NO_THROW(deviceInfoConfig.setSystemUuid("systemUuid"));
    ASSERT_EQ(deviceInfo.getSystemUuid(), "systemUuid");
    ASSERT_EQ(deviceInfo.getPropertyValue("systemUuid"), "systemUuid");
}

TEST_F(DeviceInfoTest, SetGetDeviceType)
{
    DeviceInfoConfigPtr deviceInfoConfig = DeviceInfo("", "");
    DeviceInfoPtr deviceInfo = deviceInfoConfig;

    auto deviceType = DeviceType("test", "", "");
    deviceInfoConfig.setDeviceType(deviceType);
    ASSERT_EQ(deviceInfo.getDeviceType(), deviceType);
    ASSERT_EQ(deviceInfo.getDeviceType().getId(), "test");
}

TEST_F(DeviceInfoTest, Freezable)
{
    DeviceInfoConfigPtr deviceInfoConfig = DeviceInfo("", "");

    ASSERT_FALSE(deviceInfoConfig.isFrozen());
    ASSERT_NO_THROW(deviceInfoConfig.freeze());
    ASSERT_TRUE(deviceInfoConfig.isFrozen());

    ASSERT_THROW(deviceInfoConfig.setName("name"), FrozenException);
    ASSERT_THROW(deviceInfoConfig.setConnectionString("connection_string"), FrozenException);
    ASSERT_THROW(deviceInfoConfig.setManufacturer("manufacturer"), FrozenException);
    ASSERT_THROW(deviceInfoConfig.setManufacturerUri("manufacturer_uri"), FrozenException);
    ASSERT_THROW(deviceInfoConfig.setModel("model"), FrozenException);
    ASSERT_THROW(deviceInfoConfig.setProductCode("product_code"), FrozenException);
    ASSERT_THROW(deviceInfoConfig.setHardwareRevision("hardware_revision"), FrozenException);
    ASSERT_THROW(deviceInfoConfig.setSoftwareRevision("software_revision"), FrozenException);
    ASSERT_THROW(deviceInfoConfig.setDeviceManual("device_manual"), FrozenException);
    ASSERT_THROW(deviceInfoConfig.setDeviceClass("device_class"), FrozenException);
    ASSERT_THROW(deviceInfoConfig.setSerialNumber("serial_number"), FrozenException);
    ASSERT_THROW(deviceInfoConfig.setProductInstanceUri("product_instance_uri"), FrozenException);
    ASSERT_THROW(deviceInfoConfig.setRevisionCounter(1), FrozenException);

    ASSERT_THROW(deviceInfoConfig.addProperty(StringProperty("test_key", "test_value")), FrozenException);

    auto deviceType = DeviceType("test", "", "");
    ASSERT_THROW(deviceInfoConfig.setDeviceType(deviceType), FrozenException);
}

TEST_F(DeviceInfoTest, CustomProperties)
{
    DeviceInfoConfigPtr info = DeviceInfo("", "");

    info.addProperty(StringProperty("Name", "Chell"));
    ASSERT_EQ(info.getPropertyValue("Name"), "Chell");
    ASSERT_EQ(info.getPropertyValue("Name"), "Chell");

    ASSERT_NO_THROW(info.addProperty(IntProperty("Age", 999)));
    ASSERT_NO_THROW(info.addProperty(FloatProperty("Height", 172.4)));
    ASSERT_NO_THROW(info.addProperty(BoolProperty("IsAsleep", true)));

    ASSERT_EQ(info.getCustomInfoPropertyNames().getCount(), 4u);
}

END_NAMESPACE_OPENDAQ
