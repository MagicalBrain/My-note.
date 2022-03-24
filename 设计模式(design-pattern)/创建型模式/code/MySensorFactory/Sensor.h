#pragma once

//#ifndef  ABSTRACT_PRODUCT_H_
//#define  ABSTRACT_PRODUCT_H_

#include <iostream>
#include <memory>

/// <summary>
/// 抽象3D传感器类
/// </summary>
class Sensor : public std::enable_shared_from_this<Sensor>
{
public:
	Sensor() {};
	virtual ~Sensor() {};

	/// <summary>
	/// 虚函数，输出3D传感器类型
	/// </summary>
	virtual void Show() = 0;

private:

};

//Sensor::Sensor()
//{
//}

//#endif
