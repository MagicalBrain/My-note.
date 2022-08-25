# OpenCV的安装和配置(Linux)

一开始时想在笔记本上win10+Ubuntu 20.04的。
结果Ubuntu 20.04 死活装不上。

后来换了一台台式机，结果好不容易装好后，用不了WiFi无线网卡

遂又回到笔记本上折腾，这回搞Ubuntu 18.04，结果一下就搞定了。

## 首先要安装opencv的相关依赖

如果安装失败，可能要换软件源来解决。

在Ubuntu 16.04上，就因为libgtk2.0-dev的依赖出现错误而失败了好几次，这回就没这问题了。

相关依赖有：
1. cmake
2. build-essential
3. libgtk2.0-dev 
4. libavcodec-dev 
5. libavformat-dev 
6. libjpeg.dev 
7. libtiff4.dev 
8. libswscale-dev 
9. libjasper-dev

```
sudo apt-get install cmake
sudo apt-get install build-essential libgtk2.0-dev libavcodec-dev libavformat-dev libjpeg.dev libtiff4.dev libswscale-dev libjasper-dev
```

**注意**：
```
libjasper-dev
```
这个库的安装可能会有问题，貌似不装也可以成功编译安装opencv？
暂时还不知道如果这个库不装会有什么问题，后面你编译安装opencv应该是可以的。

## 编译opencv

先去官网的github上下载source.zip和contribute.zip

```bash
mkdir build && cd build
cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D WITH_GTK=ON -D OPENCV_GENERATE_PKGCONFIG=YES -D OPENCV_EXTRA_MODULES_PATH=/home/hrl/opencv-4.4.0/opencv_contrib-4.4.0/modules ..
```

注意最后的```..```前面有空格的，不要漏了

## 安装opencv

```bash
cd build
make -j$(nproc)
make install
```

问题1：找不到 feature2d/test/test_detectors_regression.impl.hpp 文件

https://blog.csdn.net/xiewenrui1996/article/details/108683866

## 配置opencv环境变量

## 验证安装是否成功

查看版本号：
```
pkg-config --modversion opencv4
```

## 参考链接

https://blog.csdn.net/qq_37975595/article/details/109179388

## 测试Demo

`CMakeList.txt`:

```cmake
# project name
PROJECT(HELLO_WORLD)

# requirement of cmake version
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

# set the directory of executable files (指定可执行文件的路径为bin目录)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# add source code files to SRC_LIST (添加源码文件)
SET(SRC_LIST ${PROJECT_SOURCE_DIR}/src/main.cpp)

# find required opencv (cmake可以自动寻找OpenCV相关路径，
# 当找到OpenCV程序库之后，就会定义几个变量：OpenCV_FOUND、
# OpenCV_INCLUDE_DIRS、OpenCV_LIBRARY_DIRS、OpenCV_LIBS，
# 它们分别指是否找到OpenCV、OpenCV的头文件目录、OpenCV的库文件目录、
# OpenCV的所有库文件列表)
FIND_PACKAGE(OpenCV REQUIRED)

# directory of opencv headers (OpenCV_INCLUDE_DIRS是cmake自动找到的目录)
INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})

# name of executable file and path of source file (指定可执行文件的名称为helloopencv以及源码文件)
ADD_EXECUTABLE(helloopencv ${SRC_LIST})

# directory of opencv library (OpenCV_LIBRARY_DIRS是cmake自动找到的目录)
LINK_DIRECTORIES(${OpenCV_LIBRARY_DIRS})

# opencv libraries (指定链接的对象)
TARGET_LINK_LIBRARIES(helloopencv ${OpenCV_LIBS})
```

测试用的`main.cpp`文件：

```cpp
#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	Mat src_image = imread("../test.png");

	imshow("", src_image);
	waitKey(0);

	return 0;
}
```
