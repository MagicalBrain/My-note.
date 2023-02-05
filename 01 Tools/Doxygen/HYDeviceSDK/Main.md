/*!
\mainpage
<!--HYDeviceSDK-->

本文档描述了显扬3D视觉设备SDK的基本用法。有关硬件以及开发的更多信息，请联系[深圳显扬科技有限公司 ](http://www.hinyeung.com/)相关人员。

本文档定义了使用设备的接口类，其中类的方法是控制显扬3D视觉设备的接口。HYDeviceSDK基于C++14开发。

使用SDK前，建议使用HYPick对相机进行调试，可以更方便的获得合适的FoV、曝光时间及亮度。
1. 在开始菜单->HYPick打开HYDeviceManager，点击“Open”打开相机，点击“Start Server”启动设备服务
2. 确保SDK与设备服务主机处于同一网段，并可以Ping通。

## 安装与HYDeviceSDK环境部署

SDK跟随HyPick一起安装。`HYDeviceSDK.dll `在HyPick安装目录下的`sdk` 目录下的`bin` 文件夹中，`HYDeviceSDK.h` 在`include` 文件夹， `HYDeviceSDK.lib` 在`lib` 文件夹中。

`HYDeviceDemo.cpp` 中包含显扬三维视觉设备SDK使用的演示代码。

开发前需要先安装[OpenCV4.4.0](https://www.cnblogs.com/yunshangyue71/p/13617033.html)和 [PCL 1.11.1](https://blog.csdn.net/qq_36686437/article/details/108803098)并进行环境部署。

### 安装HyPick

安装HinYeungInstaller-x64-2.7.3.0.exe。详细安装过程请查阅《HyPick帮助文档》

![](HYDeviceSDK说明文档/hypick安装.png)

### 安装OpenCV4.4.0

选择优盘中opencv-4.4.0-vc14_vc15.exe 进行安装。安装完毕之后添加OPENCV_ROOT和Path系统环境变量如下，必须确保路径正确。

![](HYDeviceSDK说明文档/opencvroot.png)

![](HYDeviceSDK说明文档/opencvpath.png)

### 安装PCL1.11.1

选择优盘中PCL-1.11.1-AllInOne-msvc2019-win64.exe 进行安装。并续选择给所有用户安装环境变量，随后按默认选项进行安装。

![](HYDeviceSDK说明文档/pcl安装.png)

之后进行环境变量配置，添加PCL_ROOT和Path。确保pcl1.11.1 和 OpenNI2 正确添加。

![](HYDeviceSDK说明文档/pclroot.png)
![](HYDeviceSDK说明文档/pclpath.png)

### 添加sdk环境变量

添加HYDEVICE_SDK_ROOT和sdk环境变量。HYDEVICE_SDK_ROOT在安装HyPick之后就会自动添加

![](HYDeviceSDK说明文档/sdkroot.png)

![](HYDeviceSDK说明文档/sdkpath.png)

### 检查关键环境变量

上述过程执行完之后，检查关键环境变量情况如下。保证opencv 和pcl 安装正常。

![](HYDeviceSDK说明文档/keyroot.png)

![](HYDeviceSDK说明文档/keypath.png)

### 开启服务

1、先关闭HyPick，等待相机空闲后，在开始菜单 HyPick 中 运行HYDeviceManager 程序。在开启服务期间，需要保持屏幕常亮。

![](HYDeviceSDK说明文档/startserver.png)

2、点击 open ，等待右侧 start server 按钮禁用被解除，随后点击start server就可以开启服务。若未解除禁用可再次点击。
![](HYDeviceSDK说明文档/点击open.png)

![](HYDeviceSDK说明文档/showform.png)
3、关闭服务。点击 stop Server 即可关闭服务。
![](HYDeviceSDK说明文档/closeform.png)

### 运行SDK演示程序

运行演示程序需要事先开启服务。

使用Visual Studio 2019 社区版，选择 打开项目或解决方案。如下图，选择HyPick安装目录下的HYDeviceDemo.vcxproj 文件打开。如果途中需要 选择不同凭据重新启动程序，则点击重启，然后再次打开即可。

![](HYDeviceSDK说明文档/vs1.png)

![](HYDeviceSDK说明文档/files1.png)

添加调试参数，选择项目->属性->配置属性->调试->命令参数，输入已开启服务的服务端IP和端口，如 10.0.0.21:8080。如果是同一台PC进行调试，则使用localhost:8080

![](HYDeviceSDK说明文档/vs2.png)
选择 重新生成解决方案即可运行演示程序。

![](HYDeviceSDK说明文档/vsbuild.png)
运行结果如下。结束后，打开程序所在文件夹，可以看到生成的点云图像cloud.pcd 文件，2D图像color.bmp ，深度图 depth.tiff  点云文件可以通过 CloudCompareStereo 软件打开观看。

![](HYDeviceSDK说明文档/vsresult.png)

![](HYDeviceSDK说明文档/results.png)

![](HYDeviceSDK说明文档/pointcloud.png)
### 在VS2019下进行二次开发

新建控制台程序。在对应环境（Debug或者Release）下先加载OpenCV和PCL的属性表，再对HYDeviceSDK进行开发环境配置。

1、添加包含目录。在项目->属性->C/C++->常规 中将 sdk\include 目录添加进 附加包含目录 。
![](HYDeviceSDK说明文档/vsinclude.png)
2、添加库目录。在项目->属性->链接器->常规 中将 sdk\lib 加入 附加库目录
![](HYDeviceSDK说明文档/vslib.png)
3、添加附加依赖项。项目->属性->链接器->输入 中 添加 HYDeviceSDK.lib 
![](HYDeviceSDK说明文档/addlib.png)
### 客户端调试

在开启服务后，添加 #include "HYSensorClient.h" ，即可进行调试。
![](HYDeviceSDK说明文档/testcode.png)
![](HYDeviceSDK说明文档/testresult.png)
## HYSensorClient

HYSensorClient 中公共成员函数承担了与三维视觉设备建立连接、参数设置、相机取图和获取深度图等功能。与设备建立连接时使用其它接口的前提。

添加头文件 `#include "HYSensorClient.h"`

部分公共成员函数列表

| 返回值类型 | 函数定义                                                     |
| ---------- | ------------------------------------------------------------ |
| bool       | connect(**const** std::string**&** uri) //视觉设备连接       |
| void       | disconnect( )//断开连接                                      |
| void       | distance(**int** min, **int** max)//设置成像距离             |
| void       | fov(**int** x, **int** y, **int** width, **int** height)//配置成像fov |
| int        | current(**uint8_t** r, **uint8_t** g, **uint8_t** b)//配置亮度 |
| int        | exposure(**uint32_t** exposure, **uint32_t** period)//配置曝光时间 |
| int        | capture( )//控制相机取图                                     |
| int        | capture(std::vector<cv::Mat>& images)//触发取图并获取相机图片 |
| int        | compute(cv::Mat**&** color, cv::Mat**&** depth)//生成获取彩色图和深度图 |

### 视觉设备连接

```cpp
bool hrl::HYGRPCClient::connect(const std::string& uri)
```

函数功能：在开启设备服务的前提下，按照指定ip和端口与视觉设备进行连接。

参数描述：

1、uri  格式为 设备服务器ip:设备服务器监听端口号，如 "localhost:8080"

返回值：连接成功返回true；失败返回false。

### 断开连接

```cpp
void hrl::HYGRPCClient::disconnect()
```

函数功能：与视觉设备断开连接。

### 设置成像距离

```cpp
void hrl::HYGRPCClient::distance(int min, int max)
```

函数功能：设置物距最小值和最大值，成像后只保留物距范围内的数据。

参数描述：

1、min  最小成像距离

2、max 最大成像距离

### 配置成像fov

```cpp
void hrl::HYGRPCClient::fov(int x, int y, int width, int height)
```

函数功能：绘制一块由顶点坐标和宽、高定义的矩形区域，只保留区域内的数据。(0, 0, 0, 0)表示全场景。

参数描述：

1、x 矩形顶点x坐标

2、y 矩形顶点y坐标

3、width 矩形的宽

4、height 矩形的高

### 配置亮度

```cpp
int hrl::HYGRPCClient::current(uint8_t r, uint8_t g, uint8_t b)
```

函数功能：设置投影仪亮度 。

参数描述：

1、r 红光亮度 范围0~255

2、g 绿光亮度 范围0~255

3、b 蓝光亮度 范围0~255

返回值：设置成功返回0；设置失败返回非零值。

### 配置曝光时间

```cpp
int hrl::HYGRPCClient::exposure(uint32_t exposure, uint32_t period)
```

函数功能：设置投影仪触发曝光和触发周期 。

参数描述：

1、exposure 触发曝光 

2、period 触发周期

返回值：设置成功返回0；设置失败返回非零值。

### 控制相机取图

```cpp
int hrl::HYGRPCClient::capture()
```

函数功能：控制相机进行取图操作 。

返回值：设置成功返回0；设置失败返回非零值。

### 触发取图并获取相机图片

```cpp
int hrl::HYGRPCClient::capture(std::vector<cv::Mat>& images)
```

函数功能：控制相机进行取图操作并获取图像 。

参数描述：

1、images 相机获取的图片队列

返回值：设置成功返回0；设置失败返回非零值。

### 生成获取彩色图和深度图

```cpp
int hrl::HYGRPCClient::compute(cv::Mat& color, cv::Mat& depth)
```

函数功能：控制相机进行取图操作并生成彩色图和深度图。

参数描述：

1、color 生成的彩色图

2、depth 生成的深度图

返回值：设置成功返回0；设置失败返回非零值。
