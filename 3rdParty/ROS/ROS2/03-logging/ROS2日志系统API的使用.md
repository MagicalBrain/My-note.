# ROS2日志系统API的使用

这里主要介绍的是如何在代码里打印日志：

## cpp

### 设置日志等级

* `RCLCPP_INFO`

### 设置日志输出方式

以INFO等级的日志为例

* `RCLCPP_INFO()`
* `RCLCPP_INFO_FUNCTION()`
* `RCLCPP_INFO_STREAM()`
* `RCLCPP_INFO_STREAM_ONCE()`
* `RCLCPP_INFO_STREAM_SKIPFIRST()`

#### 示例代码

```cpp
auto condition_func = [&](const bool cond) -> bool {
  return cond;
};

std::function<bool()> condition_func_true = std::bind(condition_func,true);
std::function<bool()> condition_func_false = std::bind(condition_func,false);

RCLCPP_INFO(this->get_logger(), "[info] inside log [%s]", this->get_nam());

RCLCPP_INFO_STREAM(this->get_logger(), "[info-stream] inside log [" <<this->get_name() << "]");

RCLCPP_INFO_FUNCTION(
  this->get_logger(),
  &condition_func_true,
  "[info-func] func log true output");

RCLCPP_INFO_FUNCTION(
  this->get_logger(),
  &condition_func_false,
  "[info-func] func log false output");
```

## py

python比较简单，而且用的少，待补充
