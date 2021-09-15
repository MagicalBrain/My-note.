#pragma once

#include <HYSensorClient.h>

//#include <condition_variable>

#include <websocketpp/config/asio_no_tls_client.hpp>
#include <websocketpp/client.hpp>

//#include <boost/asio.hpp >
//#include <boost/beast/websocket.hpp>
//#include <boost/asio/ip/tcp.hpp>

#include <boost/property_tree/ptree.hpp>

namespace hy
{
	class HYWebSocketClient : public HYSensorClient
	{
	public:
		using Ptr = std::shared_ptr<HYWebSocketClient>;		

		HYWebSocketClient();
		virtual ~HYWebSocketClient();

		bool connect(const std::string& uri);

		// Inherited via HYSensorClient
		virtual bool connected() override;
		virtual void disconnect() override;
		virtual void style(int plain = STYLE_GRAY, int led = DISPLAY_COLOR_WHITE, int bit = DISPLAY_BIT_8) override;
		virtual void fov(int x, int y, int width, int height) override;
		virtual void distance(int min, int max) override;
		//virtual int decoder(int type) override;
		virtual void live(uint32_t us) override;
		virtual void onPlayback(std::function<void(const cv::Mat&, int pos)> callback, int width, int height) override;
		//virtual void onComputeFinish(std::function<void(const std::vector<cv::Mat>&)> callback) override;
		virtual int exposure(uint32_t exposure, uint32_t period) override;
		virtual int current(uint8_t r, uint8_t g, uint8_t b) override;
		virtual int capture(std::vector<cv::Mat>& images) override;
		virtual int capture() override;
		virtual int compute(cv::Mat& color, cv::Mat& depth) override;
        virtual int compute(cv::Mat& cloud) override;

	protected:
        using wsclient = websocketpp::client<websocketpp::config::asio_client>;

		wsclient client_;
		websocketpp::connection_hdl connection_;
		//boost::asio::io_context context_;
		//boost::beast::websocket::stream<boost::asio::ip::tcp> client_;
		int status_;
		std::future<void> future_;
		std::mutex mutex_;
		websocketpp::lib::thread thread_;
		std::string action_;
		std::promise<int> promise_;
		std::vector<cv::Mat> images_;
		cv::Size playback_size_;
		std::vector<std::string> binary_message_;  /// websocket binary message
		boost::property_tree::ptree text_message_; /// websocket text message in property tree

		void read_json(wsclient::message_ptr message, boost::property_tree::ptree& ptree);
		void write_json(const boost::property_tree::ptree& ptree, std::string& json);
		void info(const boost::property_tree::ptree& response);
		void on_message(websocketpp::connection_hdl, wsclient::message_ptr message);
		void on_open(websocketpp::connection_hdl);
		void on_close(websocketpp::connection_hdl);
		int send(const boost::property_tree::ptree& ptree);
	};
}
