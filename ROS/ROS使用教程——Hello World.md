# ROS使用教程——Hello World

Publisher和Subscriber是ROS系统中最基本、最常用的通信方式。
接下来以经典的“Hello, world”为例来学习如何创建Publisher和Subscriber

## 如何创建Publisher

Publisher的主要作用是针对指定话题发布特定数据类型的消息。我们尝试使用代码实现一个节点，节点中创建一个Publisher并发布字符串“Hello World”，源码learning_communication\src\talker.cpp的详细内容如下：

```cpp
#include <sstream>

// 为了避免包含大量的头文件，ros.h已经包含了大部分ROS所需的头文件
#include "ros/ros.h"
#include "std_msgs/String.h"￼￼        

int main(int argc, char **argv)￼        
{￼            
    //ROS节点初始化
    ros::init(argc, argv, "talker");￼

    // 创建节点句柄
    ros::NodeHandle n;

    //创建一个Publisher，发布名为chatter的topic，消息类型为std_msgs::String
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
    
    //设置循环的频率
    ros::Rate loop_rate(10);
    ￼￼            
    int count = 0;

    while (ros::ok())
    {
        //初始化std_msgs::String类型的消息
        std_msgs::String msg;
        std::stringstream ss;
        ss << "hello world " << count;
        msg.data = ss.str();
        
        //发布消息
        ROS_INFO("%s", msg.data.c_str());
        chatter_pub.publish(msg);
        
        //循环等待回调函数
        ros::spinOnce();

        //按照循环频率延时
        loop_rate.sleep();
        ++count;
    }
    
    return 0;
}
```

### 初始化

在调用任何ros的函数前必须要先调用`ros:init()`函数

## ros:init()

[ros:init()][init]

### **声明如下**：

```cpp
void ros::init(
    <command line or remapping arguments>, 
    std::string node_name, 
    uint32_t options
);
```

### **参数说明**：

#### argc and argv

ROS uses these to parse remapping arguments from the command line. It also modifies them so that they no longer contain any remapping arguments, so that if you call ros::init() before processing your command line you will not need to skip those arguments yourself.

#### node_name

This is the name that will be assigned to your node unless it's overridden by one of the remapping arguments. Node names must be unique across the ROS system. If a second node is started with the same name as the first, the first will be shutdown automatically. In cases where you want multiple of the same node running without worrying about naming them uniquely, you may use the init_options::AnonymousName option described below.

#### options

This is an optional argument that lets you specify certain options that change roscpp's behavior. The field is a bitfield, so multiple options can be specified. The options are described in the Initialization Options section.

[init]:http://wiki.ros.org/roscpp/Overview/Initialization%20and%20Shutdown
