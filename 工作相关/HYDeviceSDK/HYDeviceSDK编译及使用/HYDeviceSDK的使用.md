# HYDeviceSDK的使用

[toc]

## 需安装的依赖

### cmake

**注意**：cmake的版本需3.13及以上

下载新版的Cmake

先```cd```进要下载的文件加目录，命令行输入：

```bash
wget http://www.cmake.org/files/v3.14/cmake-3.14.7.tar.gz
```

下载好后解压：
```bash
tar -zxvf cmake-3.14.7-rc1.tar.gz
```

进入目录会看到只有 bin、  doc、  man、  share三个文件夹，没有 bootstrap文件，因为新版本的好像是已经编译好的，所以只要加入path里面就可以在命令行直接使用命令了

打开个人path配置
```bash
sudo vim ~/.bashrc
```

在末尾添加如下的内容

```bash
export PATH=/home/[usrname]/cmake-3.14.7-Linux-x86_64/bin:$PATH
```
**注意**：这里的路径应该根据自己的电脑和Cmake版本的实际情况来设置。
即将刚才解压出来的路径里的bin文件夹的路径添加进PATH。

接着在终端source一下.bashrc文件让path立即生效
```bash
source ~/.bashrc
```
注意：
这里source完后，在别的终端窗口里是不会生效的，需要重启终端才可生效。

安装完毕测试版本
```bash
cmake --version
```
如果显示的是刚才安装的Cmake版本号，就说明安装成功了。

### boost 1.74

先去[boost官网][boost官网]下载`boost-1.74.tar.gz`

[boost官网]:https://www.boost.org/users/history/

将文件移到`/usr/local`目录下。

解压到一个目录

cd到目录里，```./bootstrap.sh```编译生成

然后```./b2```编译生成动态库
（**注意**：这里版本不同的话，运行安装的脚本可能不同）

然后```./b2 header```编译生成头文件

最后`./b2 install`安装

#### 验证安装

新建一个`src.cpp`文件，将下列代码复制进去：

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

### opencv 4.4.0

**首先要安装opencv的相关依赖**

如果安装失败，可能要换软件源来解决。

在Ubuntu 16.04上，就因为libgtk2.0-dev的依赖出现错误而失败了好几次，而在Ubuntu 18.04就没这问题了。

相关依赖有：
1. build-essential
2. libgtk2.0-dev 
3. libavcodec-dev 
4. libavformat-dev 
5. libjpeg.dev 
6. libtiff4.dev 
7. libswscale-dev 
8. libjasper-dev

```bash
sudo apt-get install build-essential libgtk2.0-dev libavcodec-dev libavformat-dev libjpeg.dev libtiff4.dev libswscale-dev libjasper-dev
```

**注意**：
```bash
libjasper-dev
```
这个库的安装可能会有问题，如果有问题不装问题也不大

#### 编译opencv

先去官网的github上下载4.4.0版本的`opencv-4.4.0.tar.gz`文件及其对应的contribute.zip

先将tar文件解压，再将contribute.zip解压出来的文件放到`opencv-4.4.0`文件夹（该文件夹是tar.gz解压出来的）里面。

在`opencv-4.4.0`文件夹里新建一个`release`文件夹，并在其路径下运行命令：

```bash
cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D WITH_GTK=ON -D OPENCV_GENERATE_PKGCONFIG=YES -D OPENCV_EXTRA_MODULES_PATH=/home/hrl/opencv-4.4.0/opencv_contrib-4.4.0/modules ..
make -j
sudo make install
```
注意`cmake`命令最后的```..```前面有空格的，不要漏了

#### 安装opencv可能遇到的问题

问题1：找不到 feature2d/test/test_detectors_regression.impl.hpp 文件

https://blog.csdn.net/xiewenrui1996/article/details/108683866

#### 配置opencv环境变量

#### 验证安装是否成功

输入命令查看版本号：

```bash
pkg-config --modversion opencv4
```

[参考链接][参考链接]

[参考链接]:https://blog.csdn.net/qq_37975595/article/details/109179388

### pcl 1.11

**首先要安装pcl的相关依赖**

1. VTK9.0
2. flann1.9

先去[VTK官网][VTK官网]下9.0版本的tar.gz文件

[VTK官网]:https://vtk.org/download/

运行安装命令：

```bash
tar -xzvf VTK-9.0.tar.gz
cd VTK-9.0
mkdir build
cd build
cmake ..
make -j$(nproc)
sudo make install
```

flann1.9 就可以直接运行命令；

```bash
sudo apt-get install libflann1.9 libflann-dev
```

然后就可以开始安装pcl1.11了，去[pcl github网站][pcl官网]下载tar.gz文件

[pcl官网]:https://github.com/PointCloudLibrary/pcl/releases

运行命令安装：

```bash
tar -xzvf pcl-1.11.tar.gz
cd pcl 
mkdir release 
cd release
cmake -DCMAKE_BUILD_TYPE=None -DCMAKE_INSTALL_PREFIX=/usr \ -DBUILD_GPU=ON -DBUILD_apps=ON -DBUILD_examples=ON \ -DCMAKE_INSTALL_PREFIX=../ ..
make -j$(nproc)
sudo make install
```

#### 验证pcl是否安装成功

新建一个名为`pcl_test.cpp`文件，将下面的测试代码复制进去：

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

在`pcl_test.cpp`文件同一个目录下新建`CMakeLists.txt`文件，内容如下：

```cmake
cmake_minimum_required(VERSION 2.6)
project(pcl_test)

find_package(PCL 1.11 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable(pcl_test pcl_test.cpp)

target_link_libraries (pcl_test ${PCL_LIBRARIES})

install(TARGETS pcl_test RUNTIME DESTINATION bin)
```

运行命令：
```
cmake 
make -j$(nproc)
```

然后就会弹出点云文件。

注意：
1. `make -j`命令中的`-j`后面接数字是CPU的最大线程数，可使用`echo $(nproc)`命令查看（不加数字等于是单核编译，速度很慢）
2. 如果生成的点云文件打开只有个红框，通过缩放就可以看到点云了。

如果遇到以下类似的运行错误

```c
ERROR: In /build/vtk6-VHOYAG/vtk6-6.3.0+dfsg1/Rendering/OpenGL/vtkXOpenGLRenderWindow.cxx, line 1475
vtkXOpenGLRenderWindow (0x7f29f000ff70): bad X server connection. DISPLAY=Aborted (core dumped)
```

错误原因：
应该是在远程ssh连接主机来运行该程序，而这是个gui程序，无法将图形输出返回到远程终端。

## HYDeviceSDK的基本使用

我们一个demo为例来说明`HYDeviceSDK`的使用。

新建一个`src`文件夹，在`src`里新建一个`HYDeviceDemo.cpp`文件，复制以下代码：

```cpp
#include <iostream>
#include <string>

#include <HYSensorClient.h>

#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/io/pcd_io.h>

#include <boost/log/trivial.hpp>
#include <boost/format.hpp>

using namespace hy;

int main(int argc, char** argv)
{
    /*
    * 使用SDK前，建议使用HYPick对相机进行调试，可以更方便的获得合适的FoV、曝光时间及亮度
    * 1. 在开始菜单-》HYPick打开HYDeviceManager，点击“Open”打开相机，点击“Start Server”启动设备服务
    * 2. 确保SDK与设备服务主机处于同一网段，并可以Ping通
    */

    // 使用grpc协议，uri格式为：设备服务器ip:设备服务器监听端口号
    // 使用websocket协议，uri格式为：ws://设备服务器ip:设备服务器监听端口号
    std::string uri = "localhost:8080"; 
    if (argc > 1)
        uri = argv[1];

    BOOST_LOG_TRIVIAL(info) << "connecting sensor at " << uri;
    HYSensorClient::Ptr sensor = HYSensorClient::Connect(uri);
    if (sensor == nullptr) {
        BOOST_LOG_TRIVIAL(error) << "connect sensor fail";
        return -1;
    }
    
    BOOST_LOG_TRIVIAL(info) << boost::format("%1% version: %2%") % sensor->info().Protocol % sensor->info().ProtocolVersion;
    
    // 根据需要配置成像距离
    sensor->distance(100, 2500);
    BOOST_LOG_TRIVIAL(info) << boost::format("sensor distance set to %1% - %2%") % sensor->info().Min % sensor->info().Max;
    
    // 根据需要配置成像FoV，(0, 0, 0, 0)表示全场景
    sensor->fov(0, 0, 0, 0);
    BOOST_LOG_TRIVIAL(info) << boost::format("sensor fov set to %1%, %2%, %3%, %4%") % sensor->info().X % sensor->info().Y
        % sensor->info().Width % sensor->info().Height;
    
    // 根据需要配置亮度，范围0~255
    sensor->current(180, 180, 180);
    BOOST_LOG_TRIVIAL(info) << boost::format("sensor current set to %1%, %2%, %3%") % (int)sensor->info().Red % (int)sensor->info().Green
        % (int)sensor->info().Blue;
    
    // 根据实际需要配置曝光时间，单位为us
    sensor->exposure(10000);
    BOOST_LOG_TRIVIAL(info) << boost::format("sensor exposure set to %1%, period %2%") % sensor->info().Exposure % sensor->info().Period;
    
    // 控制相机取图，如果需要做手眼标定，可以使用int capture(std::vector<cv::Mat>& images)接口获取相机图片
    if(0 != sensor->capture())
    {
        BOOST_LOG_TRIVIAL(error) << "sensor capture fail";
        return -1;
    }
    BOOST_LOG_TRIVIAL(info) << "sensor capture sucess";
    
    cv::Mat color, depth;
    // 生成并获取彩色图和深度图
    if (0 != sensor->compute(color, depth))
    {
        BOOST_LOG_TRIVIAL(error) << "sensor compute fail";
        return -1;
    }
    BOOST_LOG_TRIVIAL(info) << boost::format("color image type: %1%, size %2%") % color.type() % color.size();
    BOOST_LOG_TRIVIAL(info) << boost::format("depth image type: %1%, size %2%") % depth.type() % depth.size();
    cv::imwrite("color.bmp", color);
    cv::imwrite("depth.tiff", depth);

    // 深度图可直接生成点云，以pcl为例：
    pcl::PointCloud<pcl::PointXYZRGB> cloud;
    for (int i = 0; i < depth.rows; ++i)
    {
        for (int j = 0; j < depth.cols; ++j)
        {
            pcl::PointXYZRGB point;
            point.x = depth.at<cv::Vec3f>(i, j)[0];
            point.y = depth.at<cv::Vec3f>(i, j)[1];
            point.z = depth.at<cv::Vec3f>(i, j)[2];
            if (point.z <= 0)
                continue;

            if (color.type() == CV_8UC3)
            {
                point.b = color.at<cv::Vec3b>(i, j)[0];
                point.g = color.at<cv::Vec3b>(i, j)[1];
                point.r = color.at<cv::Vec3b>(i, j)[2];
            }
            else
            {
                point.b = point.g = point.r = color.at<uint8_t>(i, j);
            }

            cloud.emplace_back(point);
        }
    }

    if (cloud.size() > 0)
    {
        BOOST_LOG_TRIVIAL(info) << boost::format("get point cloud sucess, total %1% points") % cloud.size();
        pcl::PCDWriter writer;
        writer.writeBinaryCompressed("cloud.pcd", cloud);
    }
    else
        BOOST_LOG_TRIVIAL(error) << "point cloud is empty";
   
    // 断开与设备服务的连接
    sensor->disconnect();
    return 0;
}
```

同目录下新建一个`CMakeLists.txt`文件，复制以下内容：

```cmake
cmake_minimum_required (VERSION 3.13)
project(HYDeviceDemo LANGUAGES CXX)

# 导入boost库
#find_package(Boost REQUIRED)
#if (Boost_FOUND)
#    include_directories(${Boost_INCLUDE_DIRS})
#    link_directories(${Boost_LIBRARY_DIRS})
#    add_definitions(${Boost_DEFINITIONS})
#    message(STATUS "found Boost ${Boost_VERSION} Library ${Boost_LIBRARIES}")
#endif (Boost_FOUND)

find_package(Boost 1.74.0 COMPONENTS thread log log_setup)
include_directories(${Boost_INCLUDE_DIRS})

# 导入opencv库
find_package(OpenCV REQUIRED)
if (OpenCV_FOUND)
    include_directories(${OpenCV_INCLUDE_DIRS})
    link_directories(${OpenCV_LIBRARY_DIRS})
    add_definitions(${OpenCV_DEFINITIONS})
    message(STATUS "found OpenCV ${OpenCV_VERSION} Library ${OpenCV_LIBRARIES}")
endif (OpenCV_FOUND)

# 导入pcl库
find_package(PCL REQUIRED)
if (PCL_FOUND)
    include_directories(${PCL_INCLUDE_DIRS})
    link_directories(${PCL_LIBRARY_DIRS})
    add_definitions(${PCL_DEFINITIONS})
    message(STATUS "found PCL ${PCL_VERSION} Library ${PCL_LIBRARIES}")
endif (PCL_FOUND)

# 导入HYDeviceSDK库
set(HYDeviceSDK_DIR "/home/hrl/hydevicesdk/HYDeviceSDK")
find_package(HYDeviceSDK REQUIRED)
if (HYDeviceSDK_FOUND)
    include_directories(${HYDeviceSDK_INCLUDE_DIRS})
    link_directories(${HYDeviceSDK_LIBRARY_DIRS})
    add_definitions(${HYDeviceSDK_DEFINITIONS})
    message(STATUS "found HYDeviceSDK ${HYDeviceSDK_VERSION} Library ${HYDeviceSDK_LIBRARIES}")

    message("*****")
    message("HYDeviceSDK include ${HYDeviceSDK_INCLUDE_DIRS}")
    message("HYDeviceSDK link ${HYDeviceSDK_LIBRARY_DIRS}")
    message("HYDeviceSDK definitions ${HYDeviceSDK_DEFINITIONS}")
    message("HYDeviceSDK Library ${HYDeviceSDK_LIBRARIES}")
    message("HYDeviceSDK Library_dirs ${HYDeviceSDK_LIBRARY_DIRS}")
endif (HYDeviceSDK_FOUND)

# add_compile_options(-std=c++14)
# add_definitions(-std=c++14)

#add_definitions(-D _USRDLL)

#启动对C++14标准的支持
set(CMAKE_CXX_STANDARD 14)
# 显式要求指明支持C++标准
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加头文件
# include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/proto/Generated)

# 添加源代码文件
# aux_source_directory(${PROJECT_SOURCE_DIR}/src PROJECT_SRCS)
add_executable(${PROJECT_NAME} ${PROJECT_NAME}.cpp)

# 链接库
target_link_libraries(${PROJECT_NAME} 
    ${Boost_LIBRARIES}
    Boost::log
    Boost::log_setup
    ${OpenCV_LIBRARIES}
    ${PCL_LIBRARIES}
    ${HYDeviceSDK_LIBRARIES}
)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
```

```bash
mkdir build && cd build
cmake ..
make -j$(nproc)
sudo make install
```

运行结果