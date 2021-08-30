# HinYeung插件开发指南

## 对于学习插件的使用的要求

**机器人插件**：
实现控制机器人走一个路径

**算法插件**：
1. 了解PPF的原理并编码实现
2. 读入点云文件
3. 识别出结果并输出

## 如何创建插件开发工程

### 机器人插件

### 算法插件



## 如何生成可执行文件

## 如何调试

### 离线调试

通过生成的.exe可执行文件，直接在控制台里调试

### 在线调试

通过生成dll文件，复制到HYpick对应目录下，在HYpick里直接调用。

## 机器人插件

### 总体框架

以Aubo为例：

```cpp
//设置头文件只被include一次，防止被多次include
#pragma once
//include机器人插件所需的头文件
#include <common/HYPluginFactory.hpp>
#include <robot/HYRobotPlugin.hpp>
//includeAubo的开发环境
#include "rsdef.h"

class AuboRobotPlugin : public hy::HYRobotPlugin
{
public:
    struct SpeedLimit
    {
        double max_joint_vel = 0.1; 
        double max_joint_acc = 0.1; 
        double max_angle_vel = 0.1; 
        double max_angle_acc = 0.1; 
        double max_line_vel = 0.1; 
        double max_line_acc = 0.1; 
        
    };

public:
    AuboRobotPlugin();
    virtual ~AuboRobotPlugin();

public:
    virtual int initialize() override;
    virtual void release() override;
    virtual int connect() override;
    virtual void disconnect() override;
    virtual bool ready() override;
    virtual int pose(std::vector<double>& loc, int type = hy::ROBOT_POSE_TCP) override;
    virtual int move(const std::vector<double>& loc, int type = hy::ROBOT_POSE_TCP) override;
    virtual int navigation(const hy::NavigationParam& originParam, int type = hy::ROBOT_POSE_TCP) override;
    virtual bool reached() override;
    virtual void stop() override;
	virtual int run(const std::string& task) override;

private:
    int toolToFlange(Pos& pos, Ori& ori); 
    int movesTo(const std::vector<double>& target_loc, bool enable_tool = true); 
    void stopMotion(); 
    void setSpeedLimit(const SpeedLimit& limit);
    int auboPose(const std::vector<double>& loc, Pos& pos, Rpy& rpy);
    void auboPose(const Pos& pos, const Rpy& rpy, std::vector<double>& loc);
    //void configJoints(const wayPoint_S& origin_wayPoint, wayPoint_S& new_wayPoint);
    wayPoint_S start_point;
private:
    RSHD device_handle_ = -1; 
    bool is_target_reached_ = false; 


private:
    std::string data_file_ = "./data/param/aubo_data.json"; 
    std::vector<double> tool_; 
    std::vector<std::vector<double>> unload_location_; 
    SpeedLimit speed_limit_; 
    int use_movej;
};

HYPLUGIN_REGISTER("AuboRobotPlugin", AuboRobotPlugin);
```

1. 必需的头文件
2. 公有成员函数
   1. initialize()
   2. release()
   3. connect()
   4. disconnect()
   5. ready()
   6. pose()
   7. move()
   8. navigation()
   9. reached()
   10. stop()
   11. run()
3.  使用HYPLUGIN_REGISTER宏注册插件。
