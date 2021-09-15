#pragma once
#include <HYDeviceSDK.h>
#include <memory>
#include <functional>
#include <opencv2/opencv.hpp>

/// @brief HYDeviceSDK Device SDK 模块
/// @defgroup HYDeviceSDK HYDeviceSDK

namespace hy
{
    /// @addtogroup HYDeviceSDK
    /// @{
    
	const int STYLE_GRAY = 3;	/// 灰度
	const int STYLE_BGR = 4;	/// 彩色，需要传感器硬件支持

	//const int DECODE_MF_HETERODYNE = 5;	
	//const int DECODE_GRAYCODE = 6;		
	//const int DECODE_GRAYCODE_PHASE = 7;
	//const int DECODE_SPECKLE = 8;		

	enum DisplayBit
	{
		DISPLAY_BIT_1 = 1,
		DISPLAY_BIT_2 = 2,
		DISPLAY_BIT_3 = 3,
		DISPLAY_BIT_4 = 4,
		DISPLAY_BIT_5 = 5,
		DISPLAY_BIT_6 = 6,
		DISPLAY_BIT_7 = 7,
		DISPLAY_BIT_8 = 8
	};

	enum DisplayColor
	{
		DISPLAY_COLOR_NO_COLOR = 0,
		DISPLAY_COLOR_RED = 1,
		DISPLAY_COLOR_GREEN = 2,
		DISPLAY_COLOR_YELLOW = 3, // green + red
		DISPLAY_COLOR_BLUE = 4,
		DISPLAY_COLOR_MAGENTA = 5, // blue + red
		DISPLAY_COLOR_CYAN = 6, // blue + green
		DISPLAY_COLOR_WHITE = 7 // blue + green + red
	};

	struct HYSensorInfo
	{
		std::string Name, Model, Version, Manufacturer, ActiveDate, Protocol, ProtocolVersion;
		std::string SerialNo;
		int SupportColor;

		int DecodeType, PlainType, DisplayColor, DisplayBit;

		uint32_t MinExposure, MinPeriod, Exposure, Period, LiveExposure;
		uint8_t Red, Green, Blue;

		int X, Y, Width, Height, Min, Max;
	};

	class HYDEVICESDK_API HYSensorClient
	{
	public:
		using Ptr = std::shared_ptr<HYSensorClient>;

		HYSensorClient() {}
		virtual ~HYSensorClient() {}

		/// @brief 连接3D传感器
		/// @param uri 传感器路径，格式为ws://localhost:8080
		/// @return 传感器客户端实例
		static HYSensorClient::Ptr Connect(const std::string& uri);

		/// @brief 判断传感器是否连接
		/// @return true为连接状态
		virtual bool connected() = 0;

		/// @brief 与传感器断开连接
		virtual void disconnect() = 0;

		/// @brief 获取传感器信息
		/// @return 
		const HYSensorInfo& info() const {
			return info_;
		}

		/// @brief 配置采集风格
		/// @param plain 点云颜色为灰度或彩色，彩色需要传感器支持
		/// @param led 传感器LED灯颜色，需要传感器支持
		/// @param bit 传感器投影bit数，需要传感器支持
		virtual void style(int plain = STYLE_GRAY, int led = DISPLAY_COLOR_WHITE, int bit = DISPLAY_BIT_8) = 0;

		/// @brief 配置成像视野，相对于相机分辨率，单位为像素
		/// @param x 行起点
		/// @param y 列起点
		/// @param width 宽
		/// @param height 高
		virtual void fov(int x, int y, int width, int height) = 0;

		/// @brief 配置成像距离，传感器位置为z轴0点，单位为mm
		/// @param min 距离最小
		/// @param max 距离最大
		virtual void distance(int min, int max) = 0;

		/// @brief 配置传感器实时曝光
		/// @param us 曝光值，微秒
		virtual void live(uint32_t us) = 0;

		/// @brief 配置传感器实时回显，比较占用带宽，非必要不建议开启
		/// @param callback 实时回显回调函数
		/// @param width 实时回显图像宽，单位像素
		/// @param height 实时回显图像高，单位像素
		virtual void onPlayback(std::function<void(const cv::Mat&, int pos)> callback, int width = 320, int height = 240) = 0;

		/// @brief 配置传感器点云生成回调
		/// @param callback 点云生成回调函数
		//virtual void onComputeFinish(std::function<void(const std::vector<cv::Mat>&)> callback) = 0;

		/// @brief 配置传感器触发曝光，单位微秒
		/// @param exposure 触发曝光
		/// @param period 触发周期，0为自适应
		/// @return 0表示成功，其他表示失败
		virtual int exposure(uint32_t exposure, uint32_t period = 0) = 0;

		/// @brief 配置传感器电流，范围0~255
		/// @param r 红色LED电流
		/// @param g 绿色LED电流
		/// @param b 蓝色LED电流
		/// @return 0表示成功，其他表示失败
		virtual int current(uint8_t r, uint8_t g, uint8_t b) = 0;

		/// @brief 控制传感器取图，同时获取全亮图
		/// @param images 全亮灰度图（CV_8UC1)
		/// @return 0表示成功，其他表示失败
		virtual int capture(std::vector<cv::Mat>& images) = 0;

		/// @brief 控制传感器取图
		/// @return 0表示成功，其他表示失败
		virtual int capture() = 0;

		/// @brief 控制传感器生成2D图及深度图
		/// @param color 2D图，灰度（CV_8UC1)或彩色（CV_8UC3)
		/// @param depth 深度图（CV_32FC3)
		/// @return 0表示成功，其他表示失败
		virtual int compute(cv::Mat& color, cv::Mat& depth) = 0;

        /// @brief 控制传感器生成点云图
        /// @param cloud 点云图(CV_32FC1)，共6列，表示XYZRGB，行为点数据
        /// @return 0表示成功，其他表示失败
        virtual int compute(cv::Mat& cloud) = 0;

		protected:
			HYSensorInfo info_;
			std::function<void(const cv::Mat&, int pos)> playback_callback_;
			std::function<void(const std::vector<cv::Mat>&)> compute_callback_;
	};
    /// @}
}
