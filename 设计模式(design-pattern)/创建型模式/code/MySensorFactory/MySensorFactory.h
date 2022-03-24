#pragma once

//#ifndef  ABSTRACT_FACTORY_H_
//#define  ABSTRACT_FACTORY_H_

#include <iostream>
#include <memory>

#include "Sensor.h"

enum SensorFactoryType
{
	vaild,
	SensorFactory,
	PluginFactory
};

/// <summary>
/// 抽象3D传感器工厂类
/// </summary>
class MySensorFactory : public std::enable_shared_from_this<MySensorFactory>
{
public:
	MySensorFactory() : type_(vaild) {
		std::cout << "MySensorFactory constructor called!" << std::endl;
	};
	virtual ~MySensorFactory() {};

	/// <summary>
	/// 获取HYSensor类型，类型定义参考枚举HYSensorType
	/// </summary>
	/// <returns></returns>
	virtual SensorFactoryType type() {
		std::cout << "MySensorFactory's type called!\n";
		return type_;
	}

	/// <summary>
	/// 创建 3D传感器
	/// </summary>
	/// <returns></returns>
	virtual std::shared_ptr<Sensor> createSensor() = 0;

	/// @brief 恢复使用上一次的传感器配置参数
	//virtual void recover() {
	//	std::cout << "MySensorFactory's recover called!\n";
	//};

protected:
	SensorFactoryType type_;
};

//#endif
