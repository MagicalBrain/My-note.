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

```cpp
#include "HYWebSocketClient.h"
//#include <iostream>
#include <chrono>
#include <boost/property_tree/json_parser.hpp>
#include <boost/algorithm/string.hpp>

using namespace std::literals::chrono_literals;

hy::HYWebSocketClient::HYWebSocketClient()
//	: client_(context_)
{
	client_.set_access_channels(websocketpp::log::alevel::none);
	//client_.clear_access_channels(websocketpp::log::alevel::frame_payload);
	client_.set_error_channels(websocketpp::log::elevel::none);

	client_.init_asio();
	client_.set_open_handler(std::bind(&HYWebSocketClient::on_open, this, std::placeholders::_1));
	client_.set_message_handler(std::bind(&HYWebSocketClient::on_message, this, std::placeholders::_1, std::placeholders::_2));
	client_.set_max_message_size(100000000); /// set max size to receive opencv mat and pcl pointcloud 

	info_.Protocol = "websocket";
	info_.ProtocolVersion = std::to_string(websocketpp::major_version) + "." 
		+ std::to_string(websocketpp::minor_version) + "." 
		+ std::to_string(websocketpp::patch_version);
}

hy::HYWebSocketClient::~HYWebSocketClient()
{
}

bool hy::HYWebSocketClient::connect(const std::string& uri)
{
	websocketpp::lib::error_code ec;
	wsclient::connection_ptr con = client_.get_connection(uri, ec);
	if (ec) {
		return false;
	}

	connection_ = con->get_handle();
	client_.connect(con);
	promise_ = std::promise<int>();
	thread_ = websocketpp::lib::thread(&wsclient::run, &client_);
	//future_ = std::async([&]() {
	//	client_.run();
	//	});
	promise_.get_future().get();
	//size_t pos = uri.find_last_of(':');
	//if (pos == std::string::npos)
	//	return false;
	//std::vector<std::string> v;
	//boost::split(v, uri, boost::is_any_of(":/"), boost::token_compress_on);
	//if (v.size() < 2)
	//	return false;
	//boost::asio::ip::tcp::endpoint endpoint(v[0], std::stoi(v[1]));
	//boost::asio::connect(client_.next_layer(), endpoint);
	//
	//resolver.resolve(v[0], v[1])
	return true;
}

bool hy::HYWebSocketClient::connected()
{	
	return client_.is_listening();
}

void hy::HYWebSocketClient::disconnect()
{
	try
	{
		client_.close(connection_, websocketpp::close::status::normal, "Close");
		client_.stop();
		thread_.join();
		//future_.get();
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
}

void hy::HYWebSocketClient::style(int plain, int led, int bit)
{
	//std::lock_guard<std::mutex> lock(mutex_);
	boost::property_tree::ptree request;
	request.add<std::string>("Action", "SetStyle");
	request.add<int>("PlainType", plain); // 3: Gray, 4: RGB
	request.add<int>("DisplayColor", led); // 7: White, 4: Blue
	request.add<int>("DisplayBit", bit);

	this->send(request);
}

void hy::HYWebSocketClient::fov(int x, int y, int width, int height)
{
	//std::lock_guard<std::mutex> lock(mutex_);
	boost::property_tree::ptree request;
	request.add<std::string>("Action", "SetFoV");
	request.add<int>("X", x);
	request.add<int>("Y", y);
	request.add<int>("Width", width);
	request.add<int>("Height", height);
	
	this->send(request);
}

void hy::HYWebSocketClient::distance(int min, int max)
{
	//std::lock_guard<std::mutex> lock(mutex_);
	boost::property_tree::ptree request;
	request.add<std::string>("Action", "SetDistance");
	request.add<int>("Min", min);
	request.add<int>("Max", max);

	this->send(request);
}

int hy::HYWebSocketClient::decoder(int type)
{
	//std::lock_guard<std::mutex> lock(mutex_);
	boost::property_tree::ptree request;
	request.add<std::string>("Action", "SetDecodeType");
	request.add<int>("DecodeType", type); // 

	return this->send(request);
}

void hy::HYWebSocketClient::live(uint32_t us)
{
	//std::lock_guard<std::mutex> lock(mutex_);
	boost::property_tree::ptree request;
	request.add<std::string>("Action", "SetLiveExposure");
	request.add<uint32_t>("Live", us);

	this->send(request);
}

void hy::HYWebSocketClient::playback(std::function<void(const cv::Mat&, int pos)> callback, int width, int height)
{
	callback_ = callback;
	playback_size_ = cv::Size(width, height);

	boost::property_tree::ptree request;
	request.add<std::string>("Action", "SetPlayback");
	request.add<bool>("Playback", callback_ != nullptr);
	request.add<std::string>("Payload", ".png");
	request.add<int>("Width", width);
	request.add<int>("Height", height);

	this->send(request);
}

int hy::HYWebSocketClient::exposure(uint32_t exposure, uint32_t period)
{
	//std::lock_guard<std::mutex> lock(mutex_);
	boost::property_tree::ptree request;
	request.add<std::string>("Action", "SetExposure");
	request.add<uint32_t>("Exposure", exposure);
	request.add<uint32_t>("Period", period);

	return this->send(request);
}

int hy::HYWebSocketClient::current(uint8_t r, uint8_t g, uint8_t b)
{
	//std::lock_guard<std::mutex> lock(mutex_);
	boost::property_tree::ptree request;
	request.add<std::string>("Action", "SetCurrent");
	request.add<uint8_t>("Red", r);
	request.add<uint8_t>("Green", g);
	request.add<uint8_t>("Blue", b);

	return this->send(request);
}

int hy::HYWebSocketClient::capture(std::vector<cv::Mat>& images)
{
	//std::lock_guard<std::mutex> lock(mutex_);
	boost::property_tree::ptree request;
	binary_message_.clear();
	request.add<std::string>("Action", "Capture");
	request.add<bool>("Image", true); /// enable image payload, default is false

	int status = this->send(request);
	if (status == 0) {
		images = images_;
	}
	return status;
}

int hy::HYWebSocketClient::capture()
{
	//std::lock_guard<std::mutex> lock(mutex_);
	boost::property_tree::ptree request;
	binary_message_.clear();
	images_.clear();
	request.add<std::string>("Action", "Capture");
	request.add<bool>("Image", false); /// enable image payload, default is false

	return this->send(request);
}

int hy::HYWebSocketClient::compute(cv::Mat& color, cv::Mat& depth)
{
	//std::lock_guard<std::mutex> lock(mutex_);
	boost::property_tree::ptree request;
	binary_message_.clear();
	images_.clear();
	request.add<std::string>("Action", "Compute");
	int status = this->send(request);
	if (status == 0 && images_.size() > 1) {
		color = images_[0];
		depth = images_[1];
	}
	return status;
}

void hy::HYWebSocketClient::read_json(wsclient::message_ptr message, boost::property_tree::ptree& ptree)
{
	if (message == nullptr)
		return;
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

void hy::HYWebSocketClient::write_json(const boost::property_tree::ptree& ptree, std::string& json)
{
	std::ostringstream ss;
	try
	{
		boost::property_tree::write_json(ss, ptree, false);
		json = ss.str();
		//std::cout << "request: " << json << std::endl;
	}
	catch (const std::exception& ex)
	{
		std::cout << "write json catch exception: " << ex.what() << std::endl;
	}
}

void hy::HYWebSocketClient::info(const boost::property_tree::ptree& response)
{
	info_.Name = response.get<std::string>("Name", info_.Name);
	info_.Manufacturer = response.get<std::string>("Manufacturer", info_.Manufacturer);
	info_.Model = response.get<std::string>("Model", info_.Model);
	info_.Version = response.get<std::string>("Version", info_.Version);
	info_.SerialNo = response.get<std::string>("SerialNo", info_.SerialNo);
	info_.ActiveDate = response.get<std::string>("ActiveDate", info_.ActiveDate);
	info_.SupportColor = response.get<int>("SupportColor", info_.SupportColor);
	info_.DecodeType = response.get<int>("DecodeType", info_.DecodeType);
	info_.PlainType = response.get<int>("PlainType", info_.PlainType);
	info_.DisplayColor = response.get<int>("DisplayColor", info_.DisplayColor);
	info_.DisplayBit = response.get<int>("DisplayBit", info_.DisplayBit);
	info_.MinExposure = response.get<uint32_t>("MinExposure", info_.MinExposure);
	info_.MinPeriod = response.get<uint32_t>("MinPeriod", info_.MinPeriod);
	info_.Exposure = response.get<uint32_t>("Exposure", info_.Exposure);
	info_.Period = response.get<uint32_t>("Period", info_.Period);
	info_.LiveExposure = response.get<uint32_t>("LiveExposure", info_.LiveExposure);
	info_.Red = response.get<uint8_t>("Current.Red", info_.Red);
	info_.Green = response.get<uint8_t>("Current.Green", info_.Green);
	info_.Blue = response.get<uint8_t>("Current.Blue", info_.Blue);
	info_.X = response.get<int>("FOV.X", info_.X);
	info_.Y = response.get<int>("FOV.Y", info_.Y);
	info_.Width = response.get<int>("FOV.Width", info_.Width);
	info_.Height = response.get<int>("FOV.Height", info_.Height);
	info_.Min = response.get<int>("Distance.Min", info_.Min);
	info_.Max = response.get<int>("Distance.Max", info_.Max);
}

void hy::HYWebSocketClient::on_message(websocketpp::connection_hdl, wsclient::message_ptr message)
{
	//std::lock_guard<std::mutex> lock(mutex_);
	if (message->get_opcode() == websocketpp::frame::opcode::text) /// text message
	{		
		read_json(message, text_message_);		
		if (text_message_.count("Action") == 0) /// invalid response
		{
			//status_ = -1;
			//promise_.set_value(-1);
			return;
		}

		this->info(text_message_);
		std::string action = text_message_.get<std::string>("Action");
		if (action == "LivePlayback" && callback_ != nullptr)
		{
			int pos = text_message_.get<int>("Position");
			std::string data = websocketpp::base64_decode(text_message_.get<std::string>("Data"));
			std::vector<uint8_t> buffer(data.begin(), data.end());
			cv::Mat image = cv::imdecode(buffer, cv::IMREAD_COLOR);
			callback_(image, pos);
			//promise_.set_value(-1);
			return;
		}

		if (action != action_)
			return;

		//std::cout << "response: " << message->get_payload() << std::endl;
		//if (action != action_)
		//{
			//std::cout << "response: " << message->get_payload() << std::endl;
			//boost::property_tree::write_json("info.json", text_message_); /// save sensor info
		//	return;
		//}

		std::string status = text_message_.get<std::string>("Status");
		int code = -1;
		if (status == "Sucess" || status == "Online")
			code = 0;
		else
			code = std::stoi(status);

		auto payloads = text_message_.get_child_optional("Payloads");
		if (!payloads) {
			status_ = code;
			//promise_.set_value(code);
			return;
		}

		/// has binary payloads	
		int i = 0;
		for (auto it = payloads.get().find(""); it != payloads.get().not_found(); ++it)
		{
			if (i >= binary_message_.size())
				break;

			std::string payload = it->second.get<std::string>("Payload");
			std::string stype = it->second.get<std::string>("Type");
			//::cout << "parser payload[" << i << "]: " << payload << ", type: " << stype << std::endl;
			if (payload == "Mat") /// parser opencv mat
			{
				int cols = it->second.get<int>("Cols");
				int rows = it->second.get<int>("Rows");
				if (stype == "CV_8UC1")
				{
					images_.emplace_back(cv::Mat(rows, cols, CV_8UC1, const_cast<char*>(binary_message_[i].data())));
				}
				else if (stype == "CV_8UC3")
				{
					images_.emplace_back(cv::Mat(rows, cols, CV_8UC3, const_cast<char*>(binary_message_[i].data())));
				}
				else if (stype == "CV_32FC3") {
					images_.emplace_back(cv::Mat(rows, cols, CV_32FC3, const_cast<char*>(binary_message_[i].data())));
				}
				else {
					continue;
				}
			}
			++i;
		}
		status_ = code;
		//promise_.set_value(code);
	}
	else /// binary message
	{
		binary_message_.emplace_back(message->get_payload());
	}
}

void hy::HYWebSocketClient::on_open(websocketpp::connection_hdl)
{
	//std::cout << "connect open" << std::endl;
	promise_.set_value(0);
}

void hy::HYWebSocketClient::on_close(websocketpp::connection_hdl)
{
}

int hy::HYWebSocketClient::send(const boost::property_tree::ptree& ptree)
{	
	std::lock_guard<std::mutex> lock(mutex_);
	std::string json;
	this->write_json(ptree, json);
	action_ = ptree.get<std::string>("Action");	
	status_ = 1;
	//promise_ = std::promise<int>();
	//auto future = promise_.get_future();
	try
	{
		//auto sf = std::async([&]() {
		websocketpp::lib::error_code ec;		
		client_.send(connection_, json, websocketpp::frame::opcode::text, ec);
		if (ec)
		{	
			wsclient::connection_ptr con = client_.get_con_from_hdl(connection_);
			std::cout << ec.message() << ", current state " << con->get_state() << std::endl;
			//promise_.set_value(-1);
			return -1;
		}
		//con->send(json);
		//connection_->write_frame();
		//connection_->interrupt();
		//});
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
		//promise_.set_value(-1);
		return -1;
	}	
	int count = 50000;
	while (status_ == 1 && count > 0)
	{
		std::this_thread::sleep_for(10ms);
		--count;
	}
		
	//return future.get();
	return status_;
}

```

## HyGRPCCClient

## HyWebsocketClient

这其实是单独测试`Websocket`的

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