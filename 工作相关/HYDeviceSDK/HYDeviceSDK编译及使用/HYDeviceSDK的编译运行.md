# HYDeviceSDK的编译运行

[toc]

## HYDeviceSDK的编译

### 依赖库的安装

HYDeviceSDK的依赖库有：
1. opencv4.4.0
2. grpc 1.38
3. websocketpp 0.82
4. vtk 9.0
5. flann 1.9
6. pcl 1.11
7. boost 1.74.0

#### opencv 

**首先要安装opencv的相关依赖**

如果安装失败，可能要换软件源来解决。

在Ubuntu 16.04上，就因为libgtk2.0-dev的依赖出现错误而失败了好几次，而在Ubuntu 18.04就没这问题了。

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
这个库的安装可能会有问题，如果有问题不装问题也不大

##### 编译opencv

先去官网的github上下载4.4.0版本的`opencv-4.4.0.tar.gz`文件及其对应的contribute.zip

先将tar文件解压，再将contribute.zip解压出来的文件放到`opencv-4.4.0`文件夹（该文件夹是tar.gz解压出来的）里面。

在`opencv-4.4.0`文件夹里新建一个`release`文件夹，并在其路径下运行命令：

```bash
cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D WITH_GTK=ON -D OPENCV_GENERATE_PKGCONFIG=YES -D OPENCV_EXTRA_MODULES_PATH=/home/hrl/opencv-4.4.0/opencv_contrib-4.4.0/modules ..
make -j
sudo make install
```
注意`cmake`命令最后的```..```前面有空格的，不要漏了

##### 安装opencv可能遇到的问题

问题1：找不到 feature2d/test/test_detectors_regression.impl.hpp 文件

https://blog.csdn.net/xiewenrui1996/article/details/108683866

##### 配置opencv环境变量

##### 验证安装是否成功

输入命令查看版本号：

```bash
pkg-config --modversion opencv4
```

[参考链接][参考链接]

[参考链接]:https://blog.csdn.net/qq_37975595/article/details/109179388



#### grpc

#### websocketpp

#### vtk 

#### flann

安装flann包就好

推荐使用`apt-get`安装

```bash
sudo apt-get install libflann1.9 libflann-dev
```

#### pcl

推荐使用cmake从源码编译安装

https://blog.csdn.net/mystyle_/article/details/109827365

下载 `pcl-1.11.tar.gz`文件到本地，解压。

```bash
cd pcl 
mkdir release 
cd release
cmake -DCMAKE_BUILD_TYPE=None -DCMAKE_INSTALL_PREFIX=/usr \ -DBUILD_GPU=ON -DBUILD_apps=ON -DBUILD_examples=ON \ -DCMAKE_INSTALL_PREFIX=../ ..
```


##### cmake编译可能遇到的错误

##### flann包没有找到

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

那是之前的`flann`没有装好

##### 测试pcl安装是否成功

https://blog.csdn.net/fsencen/article/details/79386570

测试代码：

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

find_package(PCL 1.11 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable(pcl_test pcl_test.cpp)

target_link_libraries (pcl_test ${PCL_LIBRARIES})

install(TARGETS pcl_test RUNTIME DESTINATION bin)
```

```
cmake 
make -j
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
不能在远程ssh连接Linux的终端上运行该测试程序，因为这是个gui程序，无法将输出返回到远程终端。

#### boost
