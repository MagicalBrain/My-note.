# HyDeviceSDK 代码分析

本项目主要包括三个项目：
1. HyDeviceSDK
2. HyGRPCCClient
3. HyWebsocketClient

## HyDeviceSDK

### HYSensorClient

### HYGRPCClient

### HYWebSocketClient.cpp

这里才是SDK的源代码

@import "./code/src/HYWebSocketClient.cpp"

## HyGRPCCClient

## HyWebsocketClient

这其实是单独的一个类实现使用`Websocket`的

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

### 构造函数与析构函数

析构函数为空，为什么好说的，因为释放内存的操作有专门一个release函数（应该）。

构造函数

### json解析部分

#### read_json

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

####  write_json

写入json文件。

```cpp
/// <summary>
/// parser property tree to json string
/// </summary>
/// <param name="ptree"></param>
/// <param name="json"></param>
void write_json(const boost::property_tree::ptree& ptree, std::string& json)
{
    std::ostringstream ss;
    try
    {
        boost::property_tree::write_json(ss, ptree);
        json = ss.str();
        std::cout << "request: " << json << std::endl;
    }
    catch (const std::exception& ex)
    {
        std::cout << "write json catch exception: " << ex.what() << std::endl;
    }
}
```

### 点云处理部分

#### write_pointcloud

```cpp
/// <summary>
/// depth image to pcl::PointCloud
/// </summary>
/// <param name="color"></param>
/// <param name="depth"></param>
void write_pointcloud(const cv::Mat& color, const cv::Mat& depth)
{
    if (depth.size().area() == 0 || depth.size() != color.size()) {
        return;
    }
    if (color.type() != CV_8UC1 && color.type() != CV_8UC3) {
        return;
    }
    if (depth.type() != CV_32FC3) {
        return;
    }

    pcl::PointCloud<pcl::PointXYZRGB> cloud;    
    for (int i = 0; i < depth.rows; ++i)
    {
        for (int j = 0; j < depth.cols; ++j)
        {
            pcl::PointXYZRGB point;
            point.x = depth.at<cv::Vec3f>(i, j)[0];
            point.y = depth.at<cv::Vec3f>(i, j)[1];
            point.z = depth.at<cv::Vec3f>(i, j)[2];
            if (point.z < 0)
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

            cloud.push_back(point);
        }
    }

    if (cloud.size() > 0)
    {
        pcl::PCDWriter writer;
        writer.writeBinaryCompressed("cloud.pcd", cloud);
    }
}
```

### websocket消息处理部分

#### on_message

```cpp
/// <summary>
/// handle websocket message
/// </summary>
/// <param name=""></param>
/// <param name="message"></param>
void on_message(websocketpp::connection_hdl, wsclient::message_ptr message) {
    if (message->get_opcode() == websocketpp::frame::opcode::text) /// text message
    {        
        read_json(message, text_message);
        if (text_message.count("Action") == 0) /// invalid response
        {
            std::cout << "response: " << message->get_payload() << std::endl;
            return;
        }            

        if (text_message.get<std::string>("Action") == "GetInfo")
        {
            std::cout << "response: " << message->get_payload() << std::endl;
            boost::property_tree::write_json("info.json", text_message); /// save sensor info
            return;
        }

        if (text_message.get<std::string>("Action") == "LivePlayback")
        {
            int pos = text_message.get<int>("Position");
            std::string data = websocketpp::base64_decode(text_message.get<std::string>("Data"));
            std::vector<uint8_t> buffer(data.begin(), data.end());
            cv::Mat image = cv::imdecode(buffer, cv::IMREAD_COLOR);
            const char* name = nullptr;
            if (pos == 0)
            {
                name = "Live - Left";
            }
            else
            {
                name = "Live - Right";
            }
            cv::namedWindow(name, cv::WINDOW_NORMAL | cv::WINDOW_KEEPRATIO | cv::WINDOW_GUI_EXPANDED);
            cv::imshow(name, image);
            cv::waitKey(1);
            return;
        }
        else
            std::cout << "response: " << message->get_payload() << std::endl;
        
        auto payloads = text_message.get_child_optional("Payloads");
        if (payloads.has_value()) /// has binary payloads
        {
            int i = 0;
            cv::Mat color, depth;
            for (auto it = payloads.get().find(""); it != payloads.get().not_found(); ++it)
            {
                if (i >= binary_message.size())
                    break;

                std::string payload = it->second.get<std::string>("Payload");
                std::string stype = it->second.get<std::string>("Type");
                std::cout << "parser payload[" << i << "]: " << payload << ", type: " << stype << std::endl;
                if (payload == "Mat") /// parser opencv mat
                {
                    int cols = it->second.get<int>("Cols");
                    int rows = it->second.get<int>("Rows");
                    if (stype == "CV_8UC1")
                    {
                        color = cv::Mat(rows, cols, CV_8UC1, const_cast<char*>(binary_message[i].data()));
                    }                        
                    else if(stype == "CV_8UC3")
                    {
                        color = cv::Mat(rows, cols, CV_8UC3, const_cast<char*>(binary_message[i].data()));
                    }
                    else if (stype == "CV_32FC3") {
                        depth = cv::Mat(rows, cols, CV_32FC3, const_cast<char*>(binary_message[i].data()));
                    }
                    else {
                        continue;
                    }
                }
                ++i;
            }

            write_pointcloud(color, depth);
        }
    }
    else /// binary message
    {
        binary_message.emplace_back(message->get_payload());
    }
}
```

## wsclient 的类型
以下是```wsclient```的定义：

```cpp
using wsclient = websocketpp::client<websocketpp::config::asio_client>;
```

即```wsclient```本质就是```client```类。

#### client类

这个```client```类是```endpoint```的公有继承子类

<details>
<summary>点击查看定义代码</summary>

```cpp
template <typename config>
class client : public endpoint<connection<config>,config> {
public:
    /// Type of this endpoint
    typedef client<config> type;

    /// Type of the endpoint concurrency component
    typedef typename config::concurrency_type concurrency_type;
    /// Type of the endpoint transport component
    typedef typename config::transport_type transport_type;

    /// Type of the connections this server will create
    typedef connection<config> connection_type;
    /// Type of a shared pointer to the connections this server will create
    typedef typename connection_type::ptr connection_ptr;

    /// Type of the connection transport component
    typedef typename transport_type::transport_con_type transport_con_type;
    /// Type of a shared pointer to the connection transport component
    typedef typename transport_con_type::ptr transport_con_ptr;

    /// Type of the endpoint component of this server
    typedef endpoint<connection_type,config> endpoint_type;

    friend class connection<config>;

    explicit client() : endpoint_type(false)
    {
        endpoint_type::m_alog->write(log::alevel::devel, "client constructor");
    }

    /// Get a new connection
    /**
     * Creates and returns a pointer to a new connection to the given URI
     * suitable for passing to connect(connection_ptr). This method allows
     * applying connection specific settings before performing the opening
     * handshake.
     *
     * @param [in] location URI to open the connection to as a uri_ptr
     * @param [out] ec An status code indicating failure reasons, if any
     *
     * @return A connection_ptr to the new connection
     */
    connection_ptr get_connection(uri_ptr location, lib::error_code & ec) {
        if (location->get_secure() && !transport_type::is_secure()) {
            ec = error::make_error_code(error::endpoint_not_secure);
            return connection_ptr();
        }

        connection_ptr con = endpoint_type::create_connection();

        if (!con) {
            ec = error::make_error_code(error::con_creation_failed);
            return con;
        }

        con->set_uri(location);

        ec = lib::error_code();
        return con;
    }

    /// Get a new connection (string version)
    /**
     * Creates and returns a pointer to a new connection to the given URI
     * suitable for passing to connect(connection_ptr). This overload allows
     * default construction of the uri_ptr from a standard string.
     *
     * @param [in] u URI to open the connection to as a string
     * @param [out] ec An status code indicating failure reasons, if any
     *
     * @return A connection_ptr to the new connection
     */
    connection_ptr get_connection(std::string const & u, lib::error_code & ec) {
        uri_ptr location = lib::make_shared<uri>(u);

        if (!location->get_valid()) {
            ec = error::make_error_code(error::invalid_uri);
            return connection_ptr();
        }

        return get_connection(location, ec);
    }

    /// Begin the connection process for the given connection
    /**
     * Initiates the opening connection handshake for connection con. Exact
     * behavior depends on the underlying transport policy.
     *
     * @param con The connection to connect
     *
     * @return The pointer to the connection originally passed in.
     */
    connection_ptr connect(connection_ptr con) {
        // Ask transport to perform a connection
        transport_type::async_connect(
            lib::static_pointer_cast<transport_con_type>(con),
            con->get_uri(),
            lib::bind(
                &type::handle_connect,
                this,
                con,
                lib::placeholders::_1
            )
        );

        return con;
    }
private:
    // handle_connect
    void handle_connect(connection_ptr con, lib::error_code const & ec) {
        if (ec) {
            con->terminate(ec);

            endpoint_type::m_elog->write(log::elevel::rerror,
                    "handle_connect error: "+ec.message());
        } else {
            endpoint_type::m_alog->write(log::alevel::connect,
                "Successful connection");

            con->start();
        }
    }
};
```
</details>

#### endpoint类

这个类是```config::transport_type```和```config::endpoint_base```的公有继承子类。

<details>
<summary>点击查看定义</summary>

```cpp

```
</details>

### 