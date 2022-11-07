#include "SensorPlugin.h"

SensorPlugin::SensorPlugin()
{
	std::cout << "SensorPlugin's constructor called!\n";
	//this->type_ = SensorPlugin;
}

SensorPlugin::~SensorPlugin()
{
	std::cout << "SensorPlugin's deconstructor called!\n";
}

void SensorPlugin::Show()
{
	std::cout << "Show the SensorPlugin!" << std::endl;
}

//void SensorPlugin::recover()
//{
//	std::cout << "SnapShotSensor's recover called!\n";
//}