#include "SnapShotSensor.h"

SnapShotSensor::SnapShotSensor()
{
	std::cout << "SnapShotSensor's constructor called!\n";
}

SnapShotSensor::~SnapShotSensor()
{
	std::cout << "SnapShotSensor's deconstructor called!\n";
}

void SnapShotSensor::Show()
{
	std::cout << "Show the SnapShotSensor!" << std::endl;
}

//void SnapShotSensor::recover()
//{
//	std::cout << "SnapShotSensor's recover called!\n";
//}
