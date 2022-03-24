#include "SensorPluginFactory.h"

SensorPluginFactory::SensorPluginFactory()
{
}

SensorPluginFactory::~SensorPluginFactory()
{
}

SensorFactoryType SensorPluginFactory::type()
{
	std::cout << "SensorPluginFactory's type called!\n";
	return SensorFactoryType::PluginFactory;
}

std::shared_ptr<Sensor> SensorPluginFactory::createSensor()
{
	std::cout << "SensorPluginFactory creates a SensorPlugin!\n";
	return std::make_shared<SensorPlugin>();
}
