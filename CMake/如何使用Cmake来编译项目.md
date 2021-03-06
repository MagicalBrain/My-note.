# 如何使用Cmake来编译项目

## 以一个简单的例子引入

创建一个文件夹，新建一个```main.cpp```文件其内容如下：

```cpp
#include <iostream>
using namespace std;

int main()
{
        cout << "begin to learn how to use Cmake!" << endl;
        return 0;
}
```

接下来新建一个```CMakeLists.txt```，其内容如下：

```cmake
# 设置Cmake 的最小版本
cmake_minimum_required(VERSION 3.13)

# 设置项目名字
project(demo4Cmake)

# 添加源代码文件
aux_source_directory(./ DIR_SRC)

# 生成可执行文件
add_executable(${PROJECT_NAME} ${DIR_SRC})
```

**注意**：```#```开头的一行是注释

然后输入命令新建一个```build```文件夹：
```
mkdir build && cd build
```

在文件夹里输入命令：
```
cmake
make
```

然后你就会看到一个```demo4Cmake```文件，这就是生成的可执行文件

```
./demo4Cmake
```

即可执行这个文件，输出：

```
begin to learn how to use Cmake!
```

## 三方库

### 查找并链接三方库

使用`find_package`命令。

```
# 导入protobuf库
find_package(protobuf REQUIRED)
if (protobuf_FOUND)
    include_directories(${protobuf_INCLUDE_DIRS})
    link_directories(${protobuf_LIBRARY_DIRS})
    add_definitions(${protobuf_DEFINITIONS})
    message(STATUS "found protobuf ${protobuf_VERSION} Library ${protobuf_LIBRARIES}")
endif (protobuf_FOUND)
```

### 生成库

```
# 生成库
## 生成静态库
add_library(${PROJECT_NAME}_static STATIC src/HYGRPCClient.cpp src/HYWebSocketClient.cpp src/HYSensorClient.cpp)

## 生成动态库
add_library(${PROJECT_NAME} SHARED src/HYGRPCClient.cpp src/HYWebSocketClient.cpp src/HYSensorClient.cpp)
```

#### 同时生成静态库和动态库

```
# 生成库
## 生成静态库
add_library(${PROJECT_NAME}_static STATIC src/HYGRPCClient.cpp src/HYWebSocketClient.cpp src/HYSensorClient.cpp)

## 生成动态库
add_library(${PROJECT_NAME} SHARED src/HYGRPCClient.cpp src/HYWebSocketClient.cpp src/HYSensorClient.cpp)

# 指定静态库的输出名称
set_target_properties(${PROJECT_NAME}_static PROPERTIES OUTPUT_NAME ${PROJECT_NAME})

# 使动态库和静态库同时存在
set_target_properties(${PROJECT_NAME} PROPERTIES CLEAN_DIRECT_OUTPUT 1)
set_target_properties(${PROJECT_NAME}_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)
```

[参考链接][参考链接]

[参考链接]:https://my.oschina.net/iamhere/blog/515660

## 添加编译指令选项

### 添加C++11标准

```
add_compile_options(-std=c++11)
```

## 以下是一个项目的CMakeLists.txt

仅仅是作为参考

```
# 设置cmake版本限制，需3.8以上
cmake_minimum_required (VERSION 3.8)

# 设置项目名称
project(HYDeviceSDK LANGUAGES CXX)

# 寻找 Boost安装包依赖
find_package(Boost REQUIRED)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})
    add_definitions(${Boost_DEFINITIONS})
    message(STATUS "found Boost ${Boost_VERSION} Library ${Boost_LIBRARIES}")
endif (Boost_FOUND)

# 寻找 OpenCV安装包依赖
find_package(OpenCV REQUIRED)
if (OpenCV_FOUND)
    include_directories(${OpenCV_INCLUDE_DIRS})
    link_directories(${OpenCV_LIBRARY_DIRS})
    add_definitions(${OpenCV_DEFINITIONS})
    message(STATUS "found OpenCV ${OpenCV_VERSION} Library ${OpenCV_LIBRARIES}")
endif (OpenCV_FOUND)

# include头文件
include_directories(${PROJECT_SOURCE_DIR}/include)

# 将源代码文件添加到目录
aux_source_directory(${PROJECT_SOURCE_DIR}/src PROJECT_SRCS)

# 将源代码文件添加到生成可执行文件的目录
add_executable(${PROJECT_NAME} ${PROJECT_SRCS})

# 链接库
target_link_libraries(${PROJECT_NAME}
    ${Boost_LIBRARIES}
    ${PCL_LIBRARIES}
    ${OpenCV_LIBRARIES}
)

# 这段有什么用暂时不知道，此坑待填
if (NOT CMAKE_INSTALL_PREFIX)
    set(CMAKE_INSTALL_PREFIX /usr/local)
endif (NOT CMAKE_INSTALL_PREFIX)

# 安装？
install(TARGETS ${PROJECT_NAME}
    DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
    )
```