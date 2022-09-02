# pcl库的安装(Linux)

[toc]

https://blog.csdn.net/mystyle_/article/details/109827365

以Ubuntu 18.04为例

## 直接安装预编译版本

```
sudo apt install libpcl-dev
```

**注意**：
安装预编译版本默认是1.8版本的

可能还需要安装`pcl-tools`

```
sudo apt install pcl-tools
```

### 预编译版本的pcl的卸载

```
sudo apt remove libpcl-dev
```

## 使用cmake从源码编译安装

https://blog.csdn.net/mystyle_/article/details/109827365

```
cd pcl 
mkdir release 
cd release
cmake -DCMAKE_BUILD_TYPE=None -DCMAKE_INSTALL_PREFIX=/usr \ -DBUILD_GPU=ON -DBUILD_apps=ON -DBUILD_examples=ON \ -DCMAKE_INSTALL_PREFIX=../ ..
```

这里的`-DCMAKE_BUILD_TYPE=None`，因为不知道装boost库的时候，boost是release还是啥版本的，要注意一下，如果后面编译有问题，可能是这里出问题

### cmake可能遇到的错误

#### flann包没有找到

```
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

## 测试安装是否成功

https://blog.csdn.net/fsencen/article/details/79386570

### 测试代码

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

```
cmake 
make -j

```

### 运行错误

```c
ERROR: In /build/vtk6-VHOYAG/vtk6-6.3.0+dfsg1/Rendering/OpenGL/vtkXOpenGLRenderWindow.cxx, line 1475
vtkXOpenGLRenderWindow (0x7f29f000ff70): bad X server connection. DISPLAY=Aborted (core dumped)
```

错误原因：
不能在远程ssh连接Linux的终端上运行该测试程序，因为这是个gui程序，无法将输出返回到远程终端。
可以尝试使用`xming`
但最好还是在Linux Desktop GUI界面测试这个程序
