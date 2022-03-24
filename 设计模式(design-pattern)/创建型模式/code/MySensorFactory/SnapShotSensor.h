#pragma once

//#ifndef  CONCRETE_PRODUCT_H_
//#define  CONCRETE_PRODUCT_H_

#include "Sensor.h"

class SnapShotSensor : public Sensor
{
public:
	SnapShotSensor();
	~SnapShotSensor();

	/// @brief 恢复使用上一次的传感器配置参数
	//virtual void recover() override;

	virtual void Show() override;

private:

};

//#endif
