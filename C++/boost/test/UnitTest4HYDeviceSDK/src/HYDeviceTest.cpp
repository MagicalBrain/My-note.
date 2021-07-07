#define BOOST_TEST_MODULE MyTest
#define BOOST_TEST_DYN_LINK HYDeviceSDK
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

std::string uri = "ws://192.168.3.82:8080";

HYSensorClient::Ptr sensor;

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
    BOOST_TEST(sensor != nullptr);
    BOOST_TEST(sensor->connected() == false);
}

BOOST_AUTO_TEST_CASE(Test_websocket_SetDistance)
{
    BOOST_LOG_TRIVIAL(info) << "connecting sensor at " << uri;
    sensor = HYSensorClient::Connect(uri);
    BOOST_REQUIRE(sensor->connected() == false);
    
    int min, max;
    //std::cout << "请输入最小距离 最大距离" << std::endl;
    //std::cin >> min >> max;
    min = 500, max = 2000;
    sensor->distance(min, max);
    BOOST_LOG_TRIVIAL(info) << boost::format("sensor distance set to %1% - %2%") % sensor->info().Min % sensor->info().Max;
    BOOST_TEST(sensor->info().Min);
    BOOST_TEST(sensor->info().Max);
}

BOOST_AUTO_TEST_CASE(Test01) 
{
    std::string str = "My test!";
    BOOST_TEST(str.empty() == false);
}