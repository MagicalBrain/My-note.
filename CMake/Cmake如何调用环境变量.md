# Cmake如何调用环境变量

使用$ENV{NAME} 指令就可以调用系统的环境变量了。比如

MESSAGE(STATUS “HOME dir: $ENV{HOME}”)

设置环境变量的方式是：SET(ENV{ 变量名} 值)

## CMAKE_INCLUDE_CURRENT_DIR

自动添加CMAKE_CURRENT_BINARY_DIR 和CMAKE_CURRENT_SOURCE_DIR 到当前处理的CMakeLists.txt 。相当于在每个CMakeLists.txt 加入：

```cmake
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR}${CMAKE_CURRENT_SOURCE_DIR})
```

## CMAKE_INCLUDE_DIRECTORIES_PROJECT_BEFORE

将工程提供的头文件目录始终至于系统头文件目录的前面，当你定义的头文件确实跟系统发

生冲突时可以提供一些帮助。

## CMAKE_INCLUDE_PATH 和CMAKE_LIBRARY_PATH
