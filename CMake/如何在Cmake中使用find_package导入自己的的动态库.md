# 如何在Cmake中使用find_package导入自己的的动态库

## 设置XXConfig.cmake

首先要在库目录下新建`XXConfig.cmake`

以下是示例代码：

```cmake
find_path(YYL_INCLUDE_DIR NAMES yyl.h PATHS “Your_own_path/YYL/include”)
find_library(YYL_LIBRARY NAMES yyl.lib PATHS “Your_own_path/YYL/lib” )
set(YYL_FOUND TRUE)
set(YYL_INCLUDE_DIRS ${YYL_INCLUDE_DIR})
set(YYL_LIBS ${YYL_LIBRARY })
mark_as_advanced(YYL_INCLUDE_DIRS YYL_LIBS )
```

其中`YYL`是库目录文件夹名，`yyl`是库文件名

`HYDeviceSDK`目录下的`HYDeviceSDKConfig.cmake`
```
find_library(HYDeviceSDK_LIBRARYS NAMES HYDeviceSDK PATHS "/usr/local/lib" )
HYDeviceSDK_LIBRARY_DIRS
find_path(HYDeviceSDK_INCLUDE_DIRS  
    NAMES HYDeviceSDK.h HYGRPCClient.h HYWebSocketClient.h HYSensorClient.h  
    PATHS "/usr/local/include")
set(HYDeviceSDK_FOUND TRUE)
```
