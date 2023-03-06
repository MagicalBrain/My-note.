# ROS2日志系统的使用

## 设置日志保存目录

读取两个环境变量来设置日志目录

* `ROS_LOG_DIR`
* `ROS_HOME`

* ROS会先检查`ROS_LOG_DIR`变量是否设置；
  * 设置了（且不为空），那么日志就会保存在这个目录下（第一优先级）
  * 如果没有`ROS_LOG_DIR`变量，那么就会去检查是否有`ROS_HOME`变量，
    * 如果有就会将日志保存到`ROS_HOME/log`目录下

```bash
export ROS_LOG_DIR=~/my_logs
ros2 run logging_demo logging_demo_main
```

关于设置Linux环境变量请参考[我的笔记](https://gitee.com/CPLASF000000/linux-notes/blob/master/Variable/Linux%E6%B7%BB%E5%8A%A0%E7%8E%AF%E5%A2%83%E5%8F%98%E9%87%8F.md)

## 设置日志等级

### 命令行设置

```bash
ros2 run logging_demo logging_demo_main --ros-args --log-level debug
```

<!-- ### 代码里设置 -->

## 设置日志输出格式

```bash
export RCUTILS_CONSOLE_OUTPUT_FORMAT="[{severity} {time}] [{name}]: {message} ({function_name}() at {file_name}:{line_number})"
```

```bash
ros2 run logging_demo logging_demo_main 
[INFO 1677916399.970067284] [logger_usage_demo]: Timer callback called (this will only log once) (on_timer() at /tmp/binarydeb/ros-eloquent-logging-demo-0.8.4/src/logger_usage_component.cpp:58)
[INFO 1677916399.970212608] [logger_usage_demo]: Publishing: 'Current count: 0' (on_timer() at /tmp/binarydeb/ros-eloquent-logging-demo-0.8.4/src/logger_usage_component.cpp:64)
[INFO 1677916400.470457962] [logger_usage_demo]: Publishing: 'Current count: 1' (on_timer() at /tmp/binarydeb/ros-eloquent-logging-demo-0.8.4/src/logger_usage_component.cpp:64)
[INFO 1677916400.970370023] [logger_usage_demo]: Publishing: 'Current count: 2' (on_timer() at /tmp/binarydeb/ros-eloquent-logging-demo-0.8.4/src/logger_usage_component.cpp:64)
[INFO 1677916401.470067709] [logger_usage_demo]: Publishing: 'Current count: 3' (on_timer() at /tmp/binarydeb/ros-eloquent-logging-demo-0.8.4/src/logger_usage_component.cpp:64)
[INFO 1677916401.970453894] [logger_usage_demo]: Publishing: 'Current count: 4' (on_timer() at /tmp/binarydeb/ros-eloquent-logging-demo-0.8.4/src/logger_usage_component.cpp:64)
[INFO 1677916402.470363149] [logger_usage_demo]: Publishing: 'Current count: 5' (on_timer() at /tmp/binarydeb/ros-eloquent-logging-demo-0.8.4/src/logger_usage_component.cpp:64)
[INFO 1677916402.970436456] [logger_usage_demo]: Publishing: 'Current count: 6' (on_timer() at /tmp/binarydeb/ros-eloquent-logging-demo-0.8.4/src/logger_usage_component.cpp:64)
[INFO 1677916403.469973874] [logger_usage_demo]: Publishing: 'Current count: 7' (on_timer() at /tmp/binarydeb/ros-eloquent-logging-demo-0.8.4/src/logger_usage_component.cpp:64)
[INFO 1677916403.970453220] [logger_usage_demo]: Publishing: 'Current count: 8' (on_timer() at /tmp/binarydeb/ros-eloquent-logging-demo-0.8.4/src/logger_usage_component.cpp:64)
[INFO 1677916404.469942961] [logger_usage_demo]: Publishing: 'Current count: 9' (on_timer() at /tmp/binarydeb/ros-eloquent-logging-demo-0.8.4/src/logger_usage_component.cpp:64)
[INFO 1677916404.969964042] [logger_usage_demo]: Publishing: 'Current count: 10' (on_timer() at /tmp/binarydeb/ros-eloquent-logging-demo-0.8.4/src/logger_usage_component.cpp:64)
[INFO 1677916404.970052344] [logger_usage_demo]: Setting severity threshold to DEBUG (operator()() at /tmp/binarydeb/ros-eloquent-logging-demo-0.8.4/src/logger_usage_component.cpp:43)
[INFO 1677916405.469993403] [logger_usage_demo]: Publishing: 'Current count: 11' (on_timer() at /tmp/binarydeb/ros-eloquent-logging-demo-0.8.4/src/logger_usage_component.cpp:64)
[INFO 1677916405.970367428] [logger_usage_demo]: Publishing: 'Current count: 12' (on_timer() at /tmp/binarydeb/ros-eloquent-logging-demo-0.8.4/src/logger_usage_component.cpp:64)
[DEBUG 1677916405.970434540] [logger_usage_demo]: Count divides into 12 (function evaluated to true) (on_timer() at /tmp/binarydeb/ros-eloquent-logging-demo-0.8.4/src/logger_usage_component.cpp:72)
[DEBUG 1677916405.970477307] [logger_usage_demo]: Count is even (expression evaluated to true) (on_timer() at /tmp/binarydeb/ros-eloquent-logging-demo-0.8.4/src/logger_usage_component.cpp:77)
^C[INFO 1677916406.086357369] [rclcpp]: signal_handler(signal_value=2) (signal_handler() at /tmp/binarydeb/ros-eloquent-rclcpp-0.8.5/src/rclcpp/signal_handler.cpp:223)
```

### 总结格式

* `{file_name}`

### 我自己喜欢的格式

```bash
export RCUTILS_CONSOLE_OUTPUT_FORMAT="[{time}][{severity}][{file_name}]: {message} ({function_name}() at :{line_number})"
```

## 参考链接

http://docs.ros.org/en/eloquent/Tutorials/Logging-and-logger-configuration.html


https://zhuanlan.zhihu.com/p/378175365
