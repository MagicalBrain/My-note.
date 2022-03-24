#include "SnapShotSensorFactory.h"

SnapShotSensorFactory::SnapShotSensorFactory()
{
}

SnapShotSensorFactory::~SnapShotSensorFactory()
{
}

SensorFactoryType SnapShotSensorFactory::type()
{
	std::cout << "SnapShotSensorFactory's type called!\n";
	return SensorFactoryType::SensorFactory;
}

std::shared_ptr<Sensor> SnapShotSensorFactory::createSensor()
{
	std::cout << "SnapShotSensorFactory creates a SensorPlugin!\n";
	return std::make_shared<SnapShotSensor>();
}


