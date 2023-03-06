# ROS2编译工具——colcon的使用

ROSwiki官网推荐了新的软件包编译工具colcon。ROS编译工具主要经历了三个阶段：

1. catkin 2. ament 3. colcon。

什么是colcon？

安装和使用，请参考：http://colcon.readthedocs.io
[我自己的使用笔记](https://gitee.com/CPLASF000000/colcon-notes/blob/master/readme.md)
## colcon安装

```bash
sudo apt install python3-colcon-ros
```

## 功能包编译

```bash
# 先cd到工作空间下的src文件夹
cd ~/ros2_ws/src
# 编译所有功能包
colcon build
```

如果需要仅仅编译其中一个包：

```bash
# 单独编译一个名为 my_package的包
colcon build --packages-select my_package
```

## CMakelists.txt的编写

使用`ros2 pkg create`命令创建一个功能包之后，默认生成的`CMakelists.txt`内容如下：

```cmake
cmake_minimum_required(VERSION 3.5)
project(realsense_D430)

# Default to C99
# 默认设置为C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
# 默认设置为C++ 14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

# 
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    # 添加 编译参数
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
# 寻找依赖
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

# 是否生成测试
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

