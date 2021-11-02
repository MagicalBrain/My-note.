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
    // 在调用任何ros的函数前必须要先调用 ros:init() 函数

    // 创建节点句柄，方便对节点资源的使用和管理
    ros::NodeHandle n;

    //创建一个Publisher，发布名为chatter的topic，消息类型为std_msgs::String
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
    /*
    * 在ROS Master端注册一个Publisher。
    * 第一个参数 告诉系统Publisher节点将会发布以chatter为话题的String类型消息。
    * 第二个参数 表示消息发布队列的大小，当发布消息的实际速度较慢时，Publisher会将消息存储在一定空间的队列中；
    *   如果消息数量超过队列大小时，ROS会自动删除队列中最早入队的消息。
    */

    
    //设置循环的频率
    ros::Rate loop_rate(10);
    /*
    * 设置循环的频率，单位是Hz，
    * 这里设置的是10 Hz。
    * 当调用Rate::sleep()时，ROS节点会根据此处设置的频率休眠相应的时间，以保证循环维持一致的时间周期。
    */

        ￼￼            
    int count = 0;

    // 进入节点的主循环，节点未发生异常将一直在循环中运行
    while (ros::ok())
    /* 
    * 一旦节点发生错误， ros::ok() 就会返回false 跳出循环
    * 这里的异常情况包括：
    *   1. 收到 SIGINT信号 （Ctrl + C）
    *   2. 被另外一个相同名称的节点踢下线了
    *   3. 节点调用了关闭函数 ros::shut-down()
    *   4. 所有 ros::NodeHandles 句柄被销毁
    */
    {
        //初始化std_msgs::String类型的消息
        std_msgs::String msg;
        std::stringstream ss;
        ss << "hello world " << count;
        msg.data = ss.str();
        
        //发布消息
        //// 打印日志信息
        ROS_INFO("%s", msg.data.c_str());
        //// 发布封装完毕的消息msg
        chatter_pub.publish(msg);
        /*
        * 消息发布后，Master会查找订阅该话题的节点，并且帮助两个节点建立连接，完成消息的传输。
        */
        
        //循环等待回调函数
        ros::spinOnce();
        // ros::spinOnce用来处理节点订阅话题的所有回调函数。

        //按照循环频率延时
        loop_rate.sleep();
        /* 
        * 现在 Publisher 一个周期的工作已经完成 
        * 可以让节点休息一段时间，调用休眠函数，节点进入休眠状态。
        * 当然，节点不可能一直休眠下去，别忘了之前设置了10Hz的休眠时间，节点休眠100ms后又会开始下一个周期的循环工作。
        */

        ++count;
    }
    
    return 0;
}
```

**总结 Publisher 的实现流程**

1. 初始化ROS节点
2. 向ROS Master注册节点信息
3. 安装一定的频率发布消息

## 如何创建Subscriber

```cpp
#include "ros/ros.h"
#include "std_msgs/String.h"

// 回调函数
//接收到订阅的消息后，会进入消息回调函数
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{￼            
    //将接收到的消息打印出来
    ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
    //初始化ROS节点
    ros::init(argc, argv, "listener");

    //创建节点句柄
    ros::NodeHandle n;

    //创建一个Subscriber，订阅名为chatter的话题，注册回调函数chatterCallback
    ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
    
    //循环等待回调函数
    ros::spin();
    return 0;
}
```

**总结 Subscriber 的实现流程**
·
1. 初始化ROS节点
2. 订阅需要的话题
3. 循环等待话题消息，接收到消息后进入回调函数
4. 在回调函数完成消息处理

## 编译功能包

节点的代码已经完成了，在运行前需要将代码编译成可执行文件。

打开功能包里的`CMakeLists.txt`文件，找到以下代码修改：

```bash
include_directories(include ${catkin_INCLUDE_DIRS})

# talker
add_executable(talker src/talker.cpp)

target_link_libraries(talker ${catkin_LIBRARIES})       

add_dependencies(talker ${PROJECT_NAME}_generate_messages_cpp)

# listener
add_executable(listener src/listener.cpp)

target_link_libraries(listener ${catkin_LIBRARIES})

add_dependencies(talker ${PROJECT_NAME}_generate_messages_cpp)
```

对于这个较为简单的功能包，主要用到了以下四种配置语句：

## 运行Publisher与Subscriber




## ros::init()

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
