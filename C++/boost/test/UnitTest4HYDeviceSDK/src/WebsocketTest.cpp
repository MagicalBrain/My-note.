#define BOOST_TEST_MODULE MyTest
#define BOOST_TEST_DYN_LINK 
#include <boost/test/included/unit_test.hpp>

#include <iostream>
#include <string>

#include <HYSensorClient.h>

#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/io/pcd_io.h>

#include <boost/log/trivial.hpp>
#include <boost/format.hpp>

using namespace hy;

void playback(const cv::Mat& image, int pos)
{
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
}

//变量初始化
std::string uri = "ws://192.168.3.82:8080";

//HYSensorClient::Ptr sensor = nullptr;
HYSensorClient::Ptr sensor;

cv::Mat color, depth, live_image;
pcl::PointCloud<pcl::PointXYZRGB> cloud;
std::vector<cv::Mat> images;

BOOST_AUTO_TEST_CASE(Test_Connect_websocket_str)
{
    BOOST_TEST(uri.empty() == false);
}

BOOST_AUTO_TEST_CASE(Test_Connect_websocket)
{
    //std::string uri = "ws://192.168.3.82:8080";
    BOOST_LOG_TRIVIAL(info) << "connecting sensor at " << uri;
    sensor = HYSensorClient::Connect(uri);
    
    std::cout << "sensor: " << sensor.use_count() << std::endl;
    if (sensor == nullptr)
        BOOST_LOG_TRIVIAL(info) << "sensor is nullptr! " ;
    BOOST_TEST(sensor != nullptr);
    //BOOST_TEST(sensor->connected() == false);
}

BOOST_AUTO_TEST_CASE(Test_websocket_SetDistance)
{
    BOOST_LOG_TRIVIAL(info) << "Start to test setDistance.";
    //sensor = HYSensorClient::Connect(uri);
    BOOST_REQUIRE(sensor != nullptr);
    
    int min, max;
    //std::cout << "请输入最小距离 最大距离" << std::endl;
    //std::cin >> min >> max;
    min = 500, max = 2000;
    sensor->distance(min, max);
    BOOST_LOG_TRIVIAL(info) << boost::format("sensor distance set to %1% - %2%") % sensor->info().Min % sensor->info().Max;
    BOOST_TEST(sensor->info().Min);
    BOOST_TEST(sensor->info().Max);
}

BOOST_AUTO_TEST_CASE(Test_websocket_SetFov)
{
    BOOST_LOG_TRIVIAL(info) << "Start to test setFov.";
    BOOST_REQUIRE(sensor != nullptr);
    int x, y, w, h;
    x = 100, y = 100;
    w = 1440, h = 1080;
    sensor->fov(x, y, w, h);
    BOOST_LOG_TRIVIAL(info) << boost::format("sensor fov set to (%1% , %2%) , (%3% , %4%).") % sensor->info().X % sensor->info().Y
                % sensor->info().Width % sensor->info().Height;
    BOOST_TEST(sensor->info().X);
    BOOST_TEST(sensor->info().Y);
    BOOST_TEST(sensor->info().Width);
    BOOST_TEST(sensor->info().Height);
}

BOOST_AUTO_TEST_CASE(Test_websocket_SetCurrent)
{
    BOOST_LOG_TRIVIAL(info) << "Start to test setCurrent.";
    BOOST_REQUIRE(sensor != nullptr);

    int r, g, b;
    r = 110, g = 110, b = 110;
    sensor->current(r, g, b);
    BOOST_LOG_TRIVIAL(info) << boost::format("sensor current set to %1%, %2%, %3%") % (int)sensor->info().Red % (int)sensor->info().Green
                % (int)sensor->info().Blue;

    BOOST_TEST(sensor->info().Red);
    BOOST_TEST(sensor->info().Green);
    BOOST_TEST(sensor->info().Blue);
}

BOOST_AUTO_TEST_CASE(Test_websocket_SetLive)
{
    BOOST_LOG_TRIVIAL(info) << "Start to test setLive.";
    BOOST_REQUIRE(sensor != nullptr);

    int live = 20000;
    sensor->live(live);
            
    BOOST_LOG_TRIVIAL(info) << boost::format("sensor LiveExposure set to %1%") % sensor->info().LiveExposure;
    BOOST_TEST(sensor->info().LiveExposure);
}

BOOST_AUTO_TEST_CASE(Test_websocket_SetExposure)
{
    BOOST_LOG_TRIVIAL(info) << "Start to test setExposure.";
    BOOST_REQUIRE(sensor != nullptr);

    // 根据实际需要配置触发曝光时间和周期，单位为us
    int e, p;
    //std::cout << "请输入触发曝光，周期" << std::endl;
    //std::cin >> e >> p;
    e = 3000, p = 30000;
    sensor->exposure(e, p);
    BOOST_LOG_TRIVIAL(info) << boost::format("sensor exposure set to %1%, period %2%") % sensor->info().Exposure % sensor->info().Period;
    
    BOOST_TEST(sensor->info().Exposure);
    BOOST_TEST(sensor->info().Period);
}

BOOST_AUTO_TEST_CASE(Test_websocket_SetStyle)
{
    BOOST_LOG_TRIVIAL(info) << "Start to test setStyle.";
    BOOST_REQUIRE(sensor != nullptr);

    // 根据实际需要设置编码风格
    int plain , led , bit ;
    //std::cout << "bit: Pattern的位数（范围：1~8）" << std::endl;
    //std::cin >> plain >> led >> bit;
    /*
    std::cout << "请根据实际需要设置编码风格" << std::endl; //STYLE_GRAY = 3;	const int STYLE_BGR = 4;
    std::cout << "plain: 3--灰度图" << std::endl;
    std::cout << "       4--彩色图" << std::endl;
    std::cout << "led: 0--无颜色" << std::endl;
    std::cout << "     1--红色" << std::endl;
    std::cout << "     2--绿色" << std::endl;
    std::cout << "     3--黄色" << std::endl;
    std::cout << "     4--蓝色" << std::endl;
    std::cout << "     5--紫红色" << std::endl;
    std::cout << "     6--蓝绿色" << std::endl;
    std::cout << "     7--白色" << std::endl;
    */
    plain = 3, led = 4, bit = 8;
    sensor->style(plain, led, bit);
    BOOST_LOG_TRIVIAL(info) << boost::format("sensor style plain: %1%; led: %2%; bit:%3%") 
        % sensor->info().PlainType % sensor->info().DisplayColor % sensor->info().DisplayBit;
    
    BOOST_TEST(sensor->info().PlainType);
    BOOST_TEST(sensor->info().DisplayColor);
    BOOST_TEST(sensor->info().DisplayBit);
}

BOOST_AUTO_TEST_CASE(Test_websocket_SetDecode)
{
    BOOST_LOG_TRIVIAL(info) << "Start to test setDecode.";
    //BOOST_REQUIRE(sensor != nullptr);

    /*
    DECODE_MF_HETERODYNE = 5;	// 多频外差
	const int DECODE_GRAYCODE = 6;		// 格雷码
	const int DECODE_GRAYCODE_PHASE = 7;	// 格雷码+相移
	const int DECODE_SPECKLE = 8;			// 散斑
    */
    int type;
    type = 5;
    //21-07-08: decoder(type = 6)有问题
    //sensor->decoder(type);
    //BOOST_LOG_TRIVIAL(info) << boost::format("sensor style decoder is %1%;") % sensor->info().DecodeType;
    
    //BOOST_TEST(sensor->info().DecodeType);
}

BOOST_AUTO_TEST_CASE(Test_websocket_SetCallback)
{
    BOOST_LOG_TRIVIAL(info) << "Start to test setCallback.";
    BOOST_REQUIRE(sensor != nullptr);

    //获取相机的实时图像
    // set sensor playback, grpc protcol is not support this feature
    sensor->onPlayback(&playback);
}

BOOST_AUTO_TEST_CASE(Test_websocket_SetCapture)
{
    BOOST_LOG_TRIVIAL(info) << "Start to test setCapture.";
    //BOOST_REQUIRE(sensor != nullptr);

    // 控制相机取图，如果需要做手眼标定，可以使用int capture(std::vector<cv::Mat>& images)接口获取相机图片
    if(0 != sensor->capture(images))
    {
        BOOST_LOG_TRIVIAL(error) << "sensor capture fail";
        //return -1;
    }
    BOOST_LOG_TRIVIAL(info) << "sensor capture sucess";
    
    BOOST_TEST(images.empty() == false);
    
}

BOOST_AUTO_TEST_CASE(Test_websocket_SetCompute)
{
    BOOST_LOG_TRIVIAL(info) << "Start to test setCompute.";
    BOOST_REQUIRE(sensor != nullptr);
    BOOST_REQUIRE(images.empty() == false);

    // 生成并获取彩色图和深度图
    BOOST_TEST(0 == sensor->compute(color, depth));
    
    BOOST_LOG_TRIVIAL(info) << boost::format("color image type: %1%, size %2%") % color.type() % color.size();
    BOOST_LOG_TRIVIAL(info) << boost::format("depth image type: %1%, size %2%") % depth.type() % depth.size();
            
    cv::imwrite("color.bmp", color);
    cv::imwrite("depth.tiff", depth);
    cv::imwrite("depth.png", depth);

    // 深度图可直接生成点云，以pcl为例：

    for (int i = 0; i < depth.rows; ++i)
    {
        for (int j = 0; j < depth.cols; ++j)
        {
            pcl::PointXYZRGB point;
            point.x = depth.at<cv::Vec3f>(i, j)[0];
            point.y = depth.at<cv::Vec3f>(i, j)[1];
            point.z = depth.at<cv::Vec3f>(i, j)[2];
            if (point.z <= 0)
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

            cloud.emplace_back(point);
        }
    }

    if (cloud.size() > 0)
    {
        BOOST_LOG_TRIVIAL(info) << boost::format("get point cloud sucess, total %1% points") % cloud.size();
        pcl::PCDWriter writer;
        writer.writeBinaryCompressed("cloud.pcd", cloud);
    }
    else
        BOOST_LOG_TRIVIAL(error) << "point cloud is empty";
}

BOOST_AUTO_TEST_CASE(Test_websocket_Disconnected) 
{
    BOOST_LOG_TRIVIAL(info) << "Start to test setStyle.";
    BOOST_REQUIRE(sensor != nullptr);

    //sensor->disconnect();

    //BOOST_TEST(sensor->disconnect());
}
