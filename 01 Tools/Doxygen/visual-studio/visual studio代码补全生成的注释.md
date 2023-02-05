# visual studio代码补全生成的注释

例子：

```cpp
#pragma once
#include <robot/HYRobotPlugin.hpp>
#include <common/HYPluginFactory.hpp>
#include <io/TCPClient.h>

class BorunteRobotPlugin :public hrl::HYRobotPlugin
{
public:
	BorunteRobotPlugin();
	virtual ~BorunteRobotPlugin();

public:
	/// @brief 创建并初始化一个伯朗特机器人对象
	/// @return PLUGIN_ERROR_FAIL 初始化失败了
	///			PLUGIN_ERROR_SUCESS 初始化成功了
	virtual int initialize() override;
	
	/// @brief 释放伯朗特机器人对象
	virtual void release() override;

	/// @brief 连接机器人
	/// @return PLUGIN_ERROR_FAIL 连接失败了
	///			PLUGIN_ERROR_SUCESS 连接成功了
	virtual int connect() override;

	/// @brief 断开与机器人的连接
	virtual void disconnect() override;

	/// @brief 判断机器人是否已经连接上。
	/// @return true 已连接
	///			false 未连接
	virtual bool connected() override;

	/// @brief 准备拍照取图
	/// @return true 取图完毕
	///			false 未能取图
	virtual bool ready() override;

	/// @brief 	获取borunte机器人当前世界坐标
 	/// @details   默认是法兰盘中心坐标 borunte工具端标定在机器人控制器内
  	/// 
	/// @param loc 
	/// @param type 
	/// @return 
	virtual int pose(std::vector<double>& loc, int type = hrl::ROBOT_POSE_TCP) override;

	/// @brief     远程发送要运动的点位loc (mm) 寄存器地址800给borunte
	/// @details   以绝对坐标直线运动方式运动
 	///
	/// @param loc 
	/// @param type 
	/// @return 
	virtual int move(const std::vector<double>& loc, int type = hrl::ROBOT_POSE_TCP) override;

	/// @brief 抓取程序函数，由HyPick调用，完成后触发软件取图信号
	/// @param param 
	/// @param type 
	/// @return 
	virtual int navigation(const hrl::NavigationParam& param, int type = hrl::ROBOT_POSE_TCP) override;

	/// @brief 
	/// @return 
	virtual bool reached() override;

	/// @brief 
	virtual void stop() override;

	/// @brief 控制IO
	/// @param task 
	/// @return 
	virtual int run(const std::string& task) override;
	//int moveto(const std::vector<double>& loc, int addr, int type = hrl::ROBOT_POSE_TCP);
	
	/// @brief 给定坐标和寄存器地址发送到borunte
 	/// @details   需要事先在borunte上定义好对应寄存器地址和数据类型
	/// @param loc 
	/// @param addr 
	/// @param type 
	/// @return 
	int setPos(const std::vector<double>& loc, int addr, int type = hrl::ROBOT_POSE_TCP);

private:
	/// @brief 
	hrl::TCPClient::Ptr client_;

	/// @brief 
	const static size_t buffer_length_ = 1024;
	//char response_buff_[buffer_length_] = { 0 };

private:
	/// @brief 获取DO状态
	/// @param board_index 
	/// @param do_index 
	/// @param val 
	/// @return 
	bool getDO(const int board_index, const int do_index, int& val);

	/// @brief 设置DO状态
	/// @param board_index 
	/// @param do_index 
	/// @param state 
	/// @return 
	bool setDO(const int board_index, const int do_index, const int state);

	/// @brief 解析字符串，获得指定位IO的状态
	/// @param data 
	/// @param position 
	/// @return 
	int decodeIOState(char data[], int position); 

	/// @brief 解析字符串，获得Borunte机械臂坐标
	/// @param data 
	/// @return 
	double decodeCoordinate(char data[]); 

private:
	/// @brief Borunte中触发DO的索引，即该位DO置1时，软件应取图进行识别
	int trigger_do_index_ = 4; 

	/// @brief 数据传输完毕标志位DO的索引，点位数据传输完成后，该标志位将被置1
	int transferred_do_index_ = 5; 

	/// @brief Borunte中机器人抵达标志位DO的索引，即机器人抵达目标点后，机器人将该DO置为1
	int arrival_do_index_ = 7; 
private:
	/// @brief 目标点（抓取点）的坐标所在的基地址
	int target_addr_ = 0;		

	/// @brief 过渡点的坐标所在的基地址
	int transition_addr_ = 0;	

	/// @brief 起始点的坐标所在的基地址
	int start_pos_addr_ = 0;	

	/// @brief 放料点的坐标所在的基地址
	/// @detail 点位坐标所在的基地址的设置应根据示教器上的代码来设置
	int put_pos_addr_ = 0;		
	
};
HYPLUGIN_REGISTER("BorunteRobotPlugin", BorunteRobotPlugin);
```
