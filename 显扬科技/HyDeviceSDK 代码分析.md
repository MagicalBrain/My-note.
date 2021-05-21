# HyDeviceSDK 代码分析

本项目主要包括三个项目：
1. HyDeviceSDK
2. HyGRPCCClient
3. HyWebsocketClient

## HyDeviceSDK

## HyGRPCCClient

## HyWebsocketClient

### 头文件依赖

```cpp
/// json parser：json 解析器
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
/// websocket client：
#include <websocketpp/config/asio_no_tls_client.hpp>
#include <websocketpp/client.hpp>
/// Mat parser：Mat对象解析器
#include <opencv2/opencv.hpp>
/// PointCloud parser：点云解析器
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
```

### read_json

作用：解析websocket文本信息给属性树
两个形参：message、ptree

```cpp
/// <summary>
/// parser websocket text message to property tree
/// </summary>
/// <param name="message"></param>
/// <param name="ptree"></param>
void read_json(wsclient::message_ptr message, boost::property_tree::ptree& ptree)
{
    ptree.clear();
    std::istringstream ss(message->get_payload());
    try
    {
        boost::property_tree::read_json(ss, ptree);
    }
    catch (const std::exception& ex)
    {
        std::cout << "read json catch exception: " << ex.what() << std::endl;
    }
}
```

### 