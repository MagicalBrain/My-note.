#pragma once

//#ifndef CONCRETE_FACTORY_H_
//#define CONCRETE_FACTORY_H_

#include "MySensorFactory.h"
#include "SensorPlugin.h"

class SensorPluginFactory : public MySensorFactory
{
public:
	SensorPluginFactory();
	~SensorPluginFactory();

	/// <summary>
	/// 获取HYSensor类型，类型定义参考枚举HYSensorType
	/// </summary>
	/// <returns></returns>
	virtual SensorFactoryType type() override;

	/// <summary>
	/// 创建 3D传感器
	/// </summary>
	/// <returns></returns>
	virtual std::shared_ptr<Sensor> createSensor() override;

private:

};

//#endif
