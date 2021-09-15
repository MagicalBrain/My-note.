#include "HYWebSocketClient.h"
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

//int hy::HYWebSocketClient::decoder(int type)
//{
//	//std::lock_guard<std::mutex> lock(mutex_);
//	boost::property_tree::ptree request;
//	request.add<std::string>("Action", "SetDecodeType");
//	request.add<int>("DecodeType", type); // 
//
//	return this->send(request);
//}

void hy::HYWebSocketClient::live(uint32_t us)
{
	//std::lock_guard<std::mutex> lock(mutex_);
	boost::property_tree::ptree request;
	request.add<std::string>("Action", "SetLiveExposure");
	request.add<uint32_t>("Live", us);

	this->send(request);
}

void hy::HYWebSocketClient::onPlayback(std::function<void(const cv::Mat&, int pos)> callback, int width, int height)
{
	playback_callback_ = callback;
	playback_size_ = cv::Size(width, height);

	boost::property_tree::ptree request;
	request.add<std::string>("Action", "SetPlayback");
	request.add<bool>("Playback", playback_callback_ != nullptr);
	request.add<std::string>("Payload", "png");
	request.add<int>("Width", width);
	request.add<int>("Height", height);

	this->send(request);
}

//void hy::HYWebSocketClient::onComputeFinish(std::function<void(const std::vector<cv::Mat>&)> callback)
//{
//	compute_callback_ = callback;
//}

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
    images_.clear();
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
    request.add<std::string>("Payload", "Depth");
	int status = this->send(request);
	if (status == 0 && images_.size() > 1) {
		color = images_.front();
		depth = images_.back();
	}
	return status;
}

int hy::HYWebSocketClient::compute(cv::Mat& cloud)
{
    boost::property_tree::ptree request;
    binary_message_.clear();
    images_.clear();
    request.add<std::string>("Action", "Compute");
    request.add<std::string>("Payload", "PointCloud");
    int status = this->send(request);
    if (status == 0 && images_.size() > 0) {
        cloud = images_.front();
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
	if (response.get<int>("Status") != 0)
		return;

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

void hy::HYWebSocketClient::on_message(websocketpp::connection_hdl hdl, wsclient::message_ptr message)
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
		
		std::string action = text_message_.get<std::string>("Action");
		if (action == "LivePlayback" && playback_callback_ != nullptr)
		{
			int pos = text_message_.get<int>("Position");
			std::string data = websocketpp::base64_decode(text_message_.get<std::string>("Base64"));
			std::vector<uint8_t> buffer(data.begin(), data.end());
			cv::Mat image = cv::imdecode(buffer, cv::IMREAD_COLOR);
            if(playback_callback_ != nullptr)
			    playback_callback_(image, pos);
			return;
		}

		if (action != action_)
			return;

		int code = text_message_.get<int>("Status");
		this->info(text_message_);

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
                int type = -1;
                if (stype == "CV_8UC1")
                {
                    type = CV_8UC1;
                }
                else if (stype == "CV_8UC3")
                {
                    type = CV_8UC3;
                }
                else if (stype == "CV_32FC1")
                {
                    type = CV_32FC1;
                }
                else if (stype == "CV_32FC3")
                {
                    type = CV_32FC3;
                }
                else if (stype == "CV_64FC3")
                {
                    type = CV_64FC3;
                }

                if(type != -1)
                    images_.emplace_back(cv::Mat(rows, cols, type, const_cast<char*>(binary_message_[i].data())).clone());
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
