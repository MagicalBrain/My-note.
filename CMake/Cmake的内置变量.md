# Cmake常用的内置变量

## CMAKE_BINARY_DIR / PROJECT_BINARY_DIR / _BINARY_DIR

运行cmake命令所在的目录，及编译发生的目录

## PROJECT_SOURCE_DIR

包含`PROJECT()`的最近的一个CMakeLists.txt所在的目录

## 一个用来查看的例子

文件目录：

CMakeLists.txt: 

```cmake

```

例如一般情况下cmake是这么用的：

```bash
mkdir build && cd build
cmake ..
```

那么

PROJECT_BINARY_DIR：./build
PROJECT_SOURCE_DIR: ./

## CMAKE_CURRENT_SOURCE_DIR 

指的是当前处理的CMakeLists.txt 所在的路径

## CMAKE_CURRENT_BINARY_DIR

当前正在处理的二进制目录路径

如果是in-source 编译，它跟CMAKE_CURRENT_SOURCE_DIR 一致，如果是out-of-source 编译，他指的是target 编译目录。使用我们上面提到的ADD_SUBDIRECTORY(src bin) 可以更改这个变量的值。使用SET(EXECUTABLE_OUTPUT_PATH < 新路径>)并不会对这个变量造成影响，它仅仅

修改了最终目标文件存放的路径。

## CMAKE_CURRENT_LIST_FILE 

输出调用这个变量的CMakeLists.txt 的完整路径

## CMAKE_CURRENT_LIST_LINE 输出这个变量所在的行

## CMAKE_MODULE_PATH

这个变量用来定义自己的cmake 模块所在的路径。如果你的工程比较复杂，有可能会自己编写一些cmake 模块，这些cmake 模块是随你的工程发布的，为了让cmake 在处理CMakeLists.txt 时找到这些模块，你需要通过SET指令，将自己的cmake 模块路径设置一下。

比如

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake) 这时候你就可以通过INCLUDE 指令来调用自己的模块了。

## EXECUTABLE_OUTPUT_PATH 和LIBRARY_OUTPUT_PATH 

分别用来重新定义最终结果的存放目录，前面我们已经提到了这两个变量

## PROJECT_NAME 

返回通过PROJECT 指令定义的项目名称

## 查看系统信息


## 参考链接

https://www.kancloud.cn/itfanr/cmake-practice/82989
