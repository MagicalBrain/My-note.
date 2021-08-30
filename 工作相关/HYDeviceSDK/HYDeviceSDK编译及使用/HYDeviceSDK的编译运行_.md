#  HYDeviceSDK的编译运行
  
- [HYDeviceSDK的编译运行](#hydevicesdk的编译运行)
- [依赖库的安装](#依赖库的安装)
- [OpenCV的安装和配置(Linux)](#opencv的安装和配置linux)
    - [首先要安装opencv的相关依赖](#首先要安装opencv的相关依赖)
    - [编译opencv](#编译opencv)
    - [安装opencv](#安装opencv)
    - [配置opencv环境变量](#配置opencv环境变量)
    - [验证安装是否成功](#验证安装是否成功)
    - [参考链接](#参考链接)
- [gRPC的安装(Linux)](#grpc的安装linux)
  - [安装依赖](#安装依赖)
  - [下载并安装grpc](#下载并安装grpc)
    - [如果这里的cmake出问题](#如果这里的cmake出问题)
  - [安装完gRPC，别忘了安装abseil](#安装完grpc别忘了安装abseil)
  - [如果protoc的安装有问题](#如果protoc的安装有问题)
  - [libprotoc.so.26找不到](#libprotocso26找不到)
  - [openssl找不到](#openssl找不到)
  - [跑一下官方的demo验证安装](#跑一下官方的demo验证安装)
    - [在cmake编译example时遇到的问题](#在cmake编译example时遇到的问题)
      - [openssl库找不到](#openssl库找不到)
      - [protobuf库找不到](#protobuf库找不到)
      - [abseil.....某个头文件找不到](#abseil某个头文件找不到)
- [Websocketpp的安装（Linux）](#websocketpp的安装linux)
- [vtk](#vtk)
- [flann](#flann)
- [pcl库的安装(Linux)](#pcl库的安装linux)
    - [直接安装预编译版本](#直接安装预编译版本)
      - [预编译版本的pcl的卸载](#预编译版本的pcl的卸载)
    - [使用cmake从源码编译安装](#使用cmake从源码编译安装)
    - [cmake可能遇到的错误](#cmake可能遇到的错误)
      - [flann包没有找到](#flann包没有找到)
  - [测试安装是否成功](#测试安装是否成功)
    - [测试代码](#测试代码)
    - [运行错误](#运行错误)
- [boost库的安装(Linux)](#boost库的安装linux)
    - [验证安装](#验证安装)
- [HYDeviceSDK的安装](#hydevicesdk的安装)
  - [运行示例程序](#运行示例程序)
  - [运行单元测试](#运行单元测试)
  
#  依赖库的安装
  
  
HYDeviceSDK的依赖库有：
1. opencv4.4.0
2. grpc 1.38
3. websocketpp 0.82
4. vtk 9.0
5. flann 1.9
6. pcl 1.11
7. boost 1.74.0
  
  
#  OpenCV的安装和配置(Linux)
  
  
一开始时想在笔记本上win10+Ubuntu 20.04的。
结果Ubuntu 20.04 死活装不上。
  
后来换了一台台式机，结果好不容易装好后，用不了WiFi无线网卡
  
遂又回到笔记本上折腾，这回搞Ubuntu 18.04，结果一下就搞定了。
  
###  首先要安装opencv的相关依赖
  
  
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
  
```bash
sudo apt-get install cmake
sudo apt-get install build-essential libgtk2.0-dev libavcodec-dev libavformat-dev libjpeg.dev libtiff4.dev libswscale-dev libjasper-dev
```
  
**注意**：
```bash
libjasper-dev
```
这个库的安装可能会有问题，貌似不装也可以成功编译安装opencv？
暂时还不知道如果这个库不装会有什么问题，后买你编译安装opencv应该是可以的。
  
###  编译opencv
  
  
先去官网的github上下载source.zip和contribute.zip
  
```bash
cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D WITH_GTK=ON -D OPENCV_GENERATE_PKGCONFIG=YES -D OPENCV_EXTRA_MODULES_PATH=/home/hrl/opencv-4.4.0/opencv_contrib-4.4.0/modules ..
```
注意最后的```..```前面有空格的，不要漏了
  
###  安装opencv
  
  
问题1：找不到 feature2d/test/test_detectors_regression.impl.hpp 文件
  
https://blog.csdn.net/xiewenrui1996/article/details/108683866
  
###  配置opencv环境变量
  
  
###  验证安装是否成功
  
  
查看版本号：
```
pkg-config --modversion opencv4
```
  
###  参考链接
  
  
https://blog.csdn.net/qq_37975595/article/details/109179388
  
  
  
  
  
  
#  gRPC的安装(Linux)
  
  
这里主要是跟着[官方教程][官方教程]来的，基于Ubuntu18.04
  
[官方教程]:https://grpc.io/docs/languages/cpp/quickstart/
  
但是官方教程有点问题。
  
##  安装依赖
  
  
```bash
sudo apt install -y build-essential autoconf libtool pkg-config
```
  
##  下载并安装grpc
  
  
**首先确保Cmake版本高于3.13**
Ubuntu18.04默认的cmake是3.10，需要卸载并安装更高版本的Cmake。
  
1、下载grpc
```bash
git clone --recurse-submodules -b v1.37.1 https://github.com/grpc/grpc
```
  
如果遇到网络问题，则试试
  
```bash
git clone -branch v1.37.1 https://github.com/grpc/grpc
cd grpc
git submodule update --init
```
  
这里要注意版本问题。
如果是要下载1.38.0，则是：
```bash
git clone -b v1.38.0 https://github.com/grpc/grpc
```
  
很有可能会遇到网络问题，多试几次就好。
  
2、编译安装grpc
  
a.
```bash
mkdir -p cmake/build && cd cmake/build
```
  
b.
```bash
cmake -DCMAKE_BUILD_TYPE=Release -DgRPC_INSTALL=ON -DBUILD_SHARED_LIBS=ON -DgRPC_BUILD_TESTS=OFF -DgRPC_ZLIB_PROVIDER=package -DgRPC_PROTOBUF_PROVIDER=package -DgRPC_SSL_PROVIDER=package ../..
```
  
c.
```bash
make -j$(nproc)
```

d.
```bash
sudo make install
```

就安装完成了。

### 如果这里的cmake出问题

protobuf库找不到，那就去安装protobuf库

```bash
cd /grpc/third_party/protobuf
mkdir-p cmake/build
cd cmake/build
cmake -Dprotobuf_BUILD_TESTS=OFF -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=ON ..
make -j
sudo make install
```


## 安装完gRPC，别忘了安装abseil

```bash
mkdir -p third_party/abseil-cpp/cmake/build
pushd third_party/abseil-cpp/cmake/build
cmake -DCMAKE_INSTALL_PREFIX=$MY_INSTALL_DIR \  -DCMAKE_POSITION_INDEPENDENT_CODE=TRUE \  ../..
make -j
make install
popd
```
  
##  如果protoc的安装有问题
  
  
[参考链接1][参考链接1]
  
[参考链接1]:https://blog.csdn.net/chenwr2018/article/details/105109987?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522162209950016780265478710%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=162209950016780265478710&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_v2~rank_v29-24-105109987.first_rank_v2_pc_rank_v29&utm_term=%E5%8D%B8%E8%BD%BDgRPC&spm=1018.2226.3001.4187
  
[参考链接2][参考链接2]
  
[参考链接2]:https://www.cnblogs.com/youxin/p/4073703.html
  
希望有用，如果不行，可能得卸载了重新安装，问题是卸载不知道怎么卸载才干净。
  
##  libprotoc.so.26找不到
  
```bash
/usr/local/bin/protoc: error while loading shared libraries: libprotoc.so.26: cannot open shared object file: No such file or directory
```
  
##  openssl找不到
  
  
```bash
CMake Error at /usr/local/share/cmake-3.14/Modules/FindPackageHandleStandardArgs.cmake:137 (message):
  Could NOT find OpenSSL, try to set the path to OpenSSL root folder in the
  system variable OPENSSL_ROOT_DIR (missing: OPENSSL_CRYPTO_LIBRARY
  OPENSSL_INCLUDE_DIR)
```
  
可能是没有安装openssl的开发库：
```bash
sudo apt install libssl-dev
```
  
如果还有其它问题，考虑重新装新版本的openssl吧。
  
https://blog.csdn.net/wanxuexiang/article/details/89647737
  
看样子还是得重新装openssl啊
  
https://blog.csdn.net/u012670181/article/details/104102110
  
可能会出现的错误：
```bash
ubuntu 18.04 openssl: relocation error: openssl: symbol EVP_mdc2 version OPENSSL_1_1_0 not defined i
```

解决方案：
  
https://blog.csdn.net/lc11535/article/details/111769295
  
https://www.5axxw.com/questions/content/b78m2c
  
使用export命令修改`LD_LIBRARY_PATH`
  
```bash
export LD_LIBRARY_PATH=/usr/local/ssl/lib${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}
```
  
`/usr/local/ssl/lib`即`openssl`安装的动态库路径
  
最后
  
https://blog.csdn.net/wanxuexiang/article/details/89647737
  
直接手动指明openssl的安装路径：
```bash
cmake -DOPENSSL_ROOT_DIR=/usr/local/ssl -DOPENSSL_LIBRARIES=/usr/local/ssl/lib ../..
```
  
##  跑一下官方的demo验证安装
  
  
首先cd到demo所在的目录：
```bash
cd examples/cpp/helloworld
```
  
创建`build`文件夹
```bash
mkdir -p cmake/build
```
  
在`build`文件夹里运行：
```bash
cmake -DCMAKE_PREFIX_PATH=$MY_INSTALL_DIR ../..
make -j$(nproc)
```
  
运行服务端程序：
```bash
./greeter_server
```
  
在另外一个终端里cd到当前目录运行客户端程序
```bash
./greeter_client
```
  
输出结果：
```bash
Greeter received: Hello world
```
  
###  在cmake编译example时遇到的问题
  
  
####  openssl库找不到
  
  
参照上面的openssl解决办法
  
####  protobuf库找不到
  
  
cmake报错信息：
```bash
CMake Error at CMakeLists.txt:5 (find_package):
  Could not find a package configuration file provided by "Protobuf" with any
  of the following names:
  
    ProtobufConfig.cmake
    protobuf-config.cmake
  
  Add the installation prefix of "Protobuf" to CMAKE_PREFIX_PATH or set
  "Protobuf_DIR" to a directory containing one of the above files.  If
  "Protobuf" provides a separate development package or SDK, be sure it has
  been installed.
```
  
如果之前安装过，那就时安装的方式不对，现在新版本只能用cmake来安装，之前可能是用脚本或者什么可执行文件安装的，都不行。
  
####  abseil.....某个头文件找不到
  
  
直接将`/grpc/third_party/abseil-cpp/`下的`absl`文件夹复制到`/usr/local/include`路径下
  
  
  
  
#  Websocketpp的安装（Linux）
  
  
以Ubuntu 18.04 为例
  
由于这个库只有头文件，所以编译安装比较简单
  
```bash
mkdir -p cmake/build && cd build
cmake ../..
make -j$(nproc)
sudo make install
```
  
  
#  vtk 
  
  
下载`VTK-9.0.1.tar.gz`文件到本地
  
运行以下命令安装
  
```bash
cd VTK-9.0.1
mkdir build && cd build
cmake .. CMAKE_BUILD_TYPE=Release CMAKE_INSTALL_PREFIX =/usr/local
```
  
  
#  flann
  
  
推荐使用`apt-get`安装
  
```bash
sudo apt-get install libflann1.9 libflann-dev
```
  
  
#  pcl库的安装(Linux)
  
https://blog.csdn.net/mystyle_/article/details/109827365
  
以Ubuntu 18.04为例
  
###  直接安装预编译版本
  
  
```bash
sudo apt install libpcl-dev
```
  
**注意**：
安装预编译版本默认是1.8版本的
  
可能还需要安装`pcl-tools`
  
```bash
sudo apt install pcl-tools
```
  
####  预编译版本的pcl的卸载
  
  
```bash
sudo apt remove libpcl-dev
```
  
###  使用cmake从源码编译安装
  
  
https://blog.csdn.net/mystyle_/article/details/109827365
  
```bash
cd pcl 
mkdir release 
cd release
cmake -DCMAKE_BUILD_TYPE=None -DCMAKE_INSTALL_PREFIX=/usr \ -DBUILD_GPU=ON -DBUILD_apps=ON -DBUILD_examples=ON \ -DCMAKE_INSTALL_PREFIX=../ ..
```
  
这里的`-DCMAKE_BUILD_TYPE=None`，因为不知道装boost库的时候，boost是release还是啥版本的，要注意一下，如果后面编译有问题，可能是这里出问题
  
###  cmake可能遇到的错误
  
  
####  flann包没有找到
  
  
```bash
No package 'flann' found
CMake Error at /home/hrl/cmake-3.14.7-Linux-x86_64/share/cmake-3.14/Modules/FindPackageHandleStandardArgs.cmake:137 (message):
  Could NOT find FLANN (missing: FLANN_LIBRARY FLANN_INCLUDE_DIR) (Required
  is at least version "1.7.0")
Call Stack (most recent call first):
  /home/hrl/cmake-3.14.7-Linux-x86_64/share/cmake-3.14/Modules/FindPackageHandleStandardArgs.cmake:378 (_FPHSA_FAILURE_MESSAGE)
  cmake/Modules/FindFLANN.cmake:124 (find_package_handle_standard_args)
  CMakeLists.txt:305 (find_package)
  
  
-- Configuring incomplete, errors occurred!
See also "/home/hrl/pcl/cmake/build/CMakeFiles/CMakeOutput.log".
```
  
那是因为flann包没有安装好
  
##  测试安装是否成功
  
  
https://blog.csdn.net/fsencen/article/details/79386570
  
###  测试代码
  
  
```cpp
#include <iostream>
#include <pcl/common/common_headers.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/console/parse.h>
  
int main(int argc, char **argv) {
  std::cout << "Test PCL !!!" << std::endl;
  
  pcl::PointCloud<pcl::PointXYZRGB>::Ptr point_cloud_ptr (new pcl::PointCloud<pcl::PointXYZRGB>);
  uint8_t r(255), g(15), b(15);
  for (float z(-1.0); z <= 1.0; z += 0.05)
  {
    for (float angle(0.0); angle <= 360.0; angle += 5.0)
    {
	    pcl::PointXYZRGB point;
	    point.x = 0.5 * cosf (pcl::deg2rad(angle));
	    point.y = sinf (pcl::deg2rad(angle));
	    point.z = z;
	    uint32_t rgb = (static_cast<uint32_t>(r) << 16 |
		    static_cast<uint32_t>(g) << 8 | static_cast<uint32_t>(b));
	    point.rgb = *reinterpret_cast<float*>(&rgb);
	    point_cloud_ptr->points.push_back (point);
    }
    if (z < 0.0)
    {
	    r -= 12;
	    g += 12;
    }
    else
    {
	    g -= 12;
	    b += 12;
    }
  }
  point_cloud_ptr->width = (int) point_cloud_ptr->points.size ();
  point_cloud_ptr->height = 1;
  
  pcl::visualization::CloudViewer viewer ("test");
  viewer.showCloud(point_cloud_ptr);
  while (!viewer.wasStopped()){ };
  return 0;
}
```
  
使用`cmake`编译：
  
`CMakeLists.txt`代码：
```cmake
cmake_minimum_required(VERSION 2.6)
project(pcl_test)
  
find_package(PCL 1.2 REQUIRED)
  
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})
  
add_executable(pcl_test pcl_test.cpp)
  
target_link_libraries (pcl_test ${PCL_LIBRARIES})
  
install(TARGETS pcl_test RUNTIME DESTINATION bin)
```
  
```bash
cmake 
make -j
```
  
###  运行错误
  
  
```bash
ERROR: In /build/vtk6-VHOYAG/vtk6-6.3.0+dfsg1/Rendering/OpenGL/vtkXOpenGLRenderWindow.cxx, line 1475
vtkXOpenGLRenderWindow (0x7f29f000ff70): bad X server connection. DISPLAY=Aborted (core dumped)
```
  
错误原因：
不能在远程ssh连接Linux的终端上运行该测试程序，因为这是个gui程序，无法将输出返回到远程终端。
可以尝试使用`xming`
但最好还是在Linux Desktop GUI界面测试这个程序
  
  
  
  
  
#  boost库的安装(Linux)
  
  
以Ubuntu 18.04 为例
  
下载好```tar.gz```文件或者```tar.bz```文件，并将文件移到`/usr/local`目录下。
  
解压到一个目录
  
cd到目录里，```./bootstrap.sh```编译生成
  
然后```./b2```编译生成动态库
（**注意**：这里版本不同的话，运行安装的脚本可能不同）
  
然后```./b2 header```编译生成头文件
  
最后`./b2 install`安装（注意，得用sudo权限！）
  
###  验证安装
  
  
```cpp
#include<iostream>
#include<boost/lexical_cast.hpp>
//using namespace std;
  
//using namespace boost;
int main()
{
   int a = boost::lexical_cast<int>("123456");
   std::cout << a <<std::endl;
   return 0;
}
```
运行命令
```bash
g++ src.cpp -o src
./src
```
输出结果：
```
123456
```
  
  
#  HYDeviceSDK的安装
  
  
依赖库都安装好后，就可以开始安装HYDviceSDK了，运行以下命令：
  
```bash
tar -zxvf hydevicesdk-1.0.0.tar.gz
cd hydevicesdk-1.0.0
./build.sh
```
  
##  运行示例程序
  
  
```bash
cd hydevicesdk-1.0.0/HYDeviceDemo
mkdir build && cd build
cmake .. && make -j
./HYDeviceDemo
```
  
运行输出：
  
![](asset/Screenshot%20from%202021-07-09%2015-24-27.png )

## 运行单元测试

请参考`HYDeviceTest`目录下的`README.md`。
  