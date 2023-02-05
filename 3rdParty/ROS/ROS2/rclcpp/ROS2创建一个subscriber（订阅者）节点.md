# ROS2创建一个subscriber（订阅者）节点

## 源码

```cpp
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
using std::placeholders::_1;

class MinimalSubscriber : public rclcpp::Node
{
  public:
    MinimalSubscriber() : 
    // 类内初始化一个名为 minial_subscriber 的订阅者节点
    Node("minimal_subscriber")
    {
      subscription_ = this->create_subscription<std_msgs::msg::String>(
      "topic", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));
    }

  private:
    void topic_callback(const std_msgs::msg::String::SharedPtr msg) const
    {
      RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
    }
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

 // 注意main函数是和发布者节点一样的
int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  // 但是这句代码虽然一样，但是左右和发布者节点那里是不一样的
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}
```

## 功能包源码

/d/hrl/MyNotes/ROS/ROS2/rclcpp/code/cpp_pubsub

## 参考链接

https://blog.csdn.net/qq_38649880/article/details/104418424
