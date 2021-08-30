# 在编译HYDeviceDemo可执行文件的时候遇到奇怪的问题（pcl-1.8+websocketpp) 21-06-11

## 问题描述

CMakeLists.txt文件代码为；
```cmake

```

这个项目的依赖有：
pcl 1.8
websocket
opencv4.4.0
boost 1.74.0

当可执行文件运行起来后，报错：
奇怪的是Connect()这里，gRPC协议不会报错，我仅仅是改了下url改用websocket协议，就报错，甚是奇怪

报错详情：
![](asset/屏幕截图%202021-06-11%20154941.png)

是这一行代码报错：
```cpp
HYSensorClient::Ptr sensor = HYSensorClient::Connect(uri);
```

然后我在报错里提到的`libpcl_io.so.1.8`库和`HYDeviceSDK.so`库里查了一下`equivalent`这个符号。

`libpcl_io.so.1.8`库结果：

![](asset/屏幕截图%202021-06-11%20160736.png)

```
00000000000e9380 W _ZNK5boost6system14error_category10equivalentEiRKNS0_15error_conditionE
00000000000e8bb0 W _ZNK5boost6system14error_category10equivalentERKNS0_10error_codeEi
00000000000e9860 W _ZNK5boost6system14error_category12std_category10equivalentEiRKSt15error_condition
00000000000e93f0 W _ZNK5boost6system14error_category12std_category10equivalentERKSt10error_codei
```

`HYDeviceSDK.so`库结果：

![](asset/屏幕截图%202021-06-11%20160752.png)

```
00000000003cab0c W _ZNK5boost6system14error_category10equivalentEiRKNS0_15error_conditionE
00000000003cab7c W _ZNK5boost6system14error_category10equivalentERKNS0_10error_codeEi
00000000003cb59a W _ZNK5boost6system6detail12std_category10equivalentEiRKSt15error_condition
00000000003cb7c2 W _ZNK5boost6system6detail12std_category10equivalentERKSt10error_codei
                 U _ZNKSt3_V214error_category10equivalentEiRKSt15error_condition
                 U _ZNKSt3_V214error_category10equivalentERKSt10error_codei

```

程序最后是从`_ZNK5boost6system14error_category10equivalentERKNS0_10error_codeEi`这个符号退出的，但是这两个库都有这个符号

## 待选的解决方案

1. 卸载pcl 1.8，编译安装pcl 1.11

