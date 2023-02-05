# ROS2创建一个Publisher（发布者）节点

## 创建一个 rclcpp::Node 的子类



## 源码

```cpp
// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
 * member function as a callback from the timer. */
/* 本例中创建一个Node的子类，
* 然后使用 std::bind() 注册了一个成员函数作为timer计时器的回调
*/
class MinimalPublisher : public rclcpp::Node
{
public:
  MinimalPublisher() :
  // 类内初始化 node 名为 minimal_publisher
  Node("minimal_publisher"), 
  // 类内初始化 计数器 count_ = 0
  count_(0)
  {
    // 初始化publisher_为一个publisher实例
    // 本publisher是用来发布 std_msgs::msg::String类型的数据的
    // 发布的topic名为“topic”，发布出来的数据队列长度为10
    publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);

    // 创建一个计时器
    // 计时周期 500ms
    // 绑定 自己定义的 计时回调函数
    timer_ = this->create_wall_timer(
      500ms, std::bind(&MinimalPublisher::timer_callback, this));
  }

private:

  // 自己定义的用来被绑定的计时回调函数
  void timer_callback()
  {
    // 初始化一个 std_msgs::msg::String 类型的对象 message
    auto message = std_msgs::msg::String();

    // 给message赋值
    message.data = "Hello, world! " + std::to_string(count_++);

    // 通过rclcpp日志打印 message
    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());

    // 将该publisher的msg发布到topic中去
    publisher_->publish(message);
  }

  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  size_t count_;
};

// 节点真正执行的地方
int main(int argc, char * argv[])
{
  // 初始化节点
  rclcpp::init(argc, argv);
  // 开始处理消息回调
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}

```

### 重要api详解

#### node::create_publisher<>()

```cpp
publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
```

* create_publisher() [1/2]

```cpp
template<typename MessageT , typename Alloc , typename PublisherT >
std::shared_ptr< PublisherT > rclcpp::Node::create_publisher	(	const std::string & 	topic_name,
size_t 	qos_history_depth,
std::shared_ptr< Alloc > 	allocator = nullptr 
)		
```

Create and return a Publisher.

Parameters
[in]	topic_name	The topic for this publisher to publish on.
[in]	qos_history_depth	The depth of the publisher message queue.
[in]	allocator	Optional custom allocator.
Returns
Shared pointer to the created publisher.

----

* create_publisher() [2/2]
```cpp
template<typename MessageT , typename Alloc , typename PublisherT >
std::shared_ptr< PublisherT > rclcpp::Node::create_publisher	(	const std::string & 	topic_name,
const rmw_qos_profile_t & 	qos_profile = rmw_qos_profile_default,
std::shared_ptr< Alloc > 	allocator = nullptr 
)		
```

Create and return a Publisher.

Parameters
[in]	topic_name	The topic for this publisher to publish on.
[in]	qos_profile	The quality of service profile to pass on to the rmw implementation.
[in]	allocator	Optional custom allocator.
Returns
Shared pointer to the created publisher.

这里我们用的是第一种

## 开始编译

### 在package.xml文件中添加依赖和描述信息

打开`package.xml` 文件：

```xml
<?xml version="1.0"?>
<?xml-model href="http://download.ros.org/schema/package_format3.xsd" schematypens="http://www.w3.org/2001/XMLSchema"?>
<package format="3">
  <name>cpp_pubsub</name>
  <version>0.0.0</version>
  <description>TODO: Package description</description>
  <maintainer email="jetson@todo.todo">jetson</maintainer>
  <license>TODO: License declaration</license>

  <buildtool_depend>ament_cmake</buildtool_depend>

  <!- 在这里添加依赖 />
  <depend>rclcpp</depend>
  <depend>std_msgs</depend>

  <test_depend>ament_lint_auto</test_depend>
  <test_depend>ament_lint_common</test_depend>

  <export>
    <build_type>ament_cmake</build_type>
  </export>
</package>

```

### 编写CMakeLists.txt

```cmake
cmake_minimum_required(VERSION 3.5)
project(cpp_pubsub)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)
# 在这里添加依赖
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# 添加可执行文件 并命名为talker
add_executable(talker src/publisher_member_function.cpp)
ament_target_dependencies(talker rclcpp std_msgs)

# 添加安装文件到ros2目录下，让ros2 run 指令能够找到并运行
install(TARGETS
  talker
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()

```

下面这个会更加简洁点：
```cmake
cmake_minimum_required(VERSION 3.5)
project(cpp_pubsub)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(talker src/publisher_member_function.cpp)
ament_target_dependencies(talker rclcpp std_msgs)

install(TARGETS
  talker
  DESTINATION lib/${PROJECT_NAME})

ament_package()
```

## 功能包源码

/d/hrl/MyNotes/ROS/ROS2/rclcpp/code/cpp_pubsub

## 参考链接

[官方文档](https://docs.ros.org/en/eloquent/Tutorials/Writing-A-Simple-Cpp-Publisher-And-Subscriber.html)
[官方api库](https://docs.ros2.org/latest/api/rclcpp/)
