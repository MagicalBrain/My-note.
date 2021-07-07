#include <iostream>
#include <string>

#include <HYSensorClient.h>

#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/io/pcd_io.h>

#include <boost/log/trivial.hpp>
#include <boost/format.hpp>

#define BOOST_TEST_MODULE MyTest
#include <boost/test/included/unit_test.hpp>

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

int main(int argc, char** argv)
{
    /*
    * Before using SDK, it is recommended to use HYPick to debug the camera for easier access to the right FoV, exposure time and brightness
    * 1. From "Start Menu" -> "HYPick" open "HYDevice Manager", click "Open" to open the camera, then click "Start Server" to start the device server
    * 2. Make sure that the SDK client is in the same network as the device server and can ping or access
    */
        
    // for websocket protcol, uri like: ws://<device server ip>:<device server port>
    // for grpc protcol, uri like: grpc://<device server ip>:<device server port>
    //std::string uri = "ws://192.168.3.82:8080"; 
    std::string uri = "grpc://192.168.3.82:8080";
    if (argc > 1)
        uri = argv[1];

    BOOST_LOG_TRIVIAL(info) << "connecting sensor at " << uri;
    HYSensorClient::Ptr sensor = HYSensorClient::Connect(uri);
    if (sensor == nullptr) {
        BOOST_LOG_TRIVIAL(error) << "connect sensor fail";
        return -1;
    }
    
    // set sensor playback, grpc protcol is not support this feature
    sensor->onPlayback(&playback);

    BOOST_LOG_TRIVIAL(info) << boost::format("%1% version: %2%") % sensor->info().Protocol % sensor->info().ProtocolVersion;
    // set sensor distance
    sensor->distance(100, 2500);
    BOOST_LOG_TRIVIAL(info) << boost::format("sensor distance set to %1% - %2%") % sensor->info().Min % sensor->info().Max;
    // set sensor fov, (0, 0, 0, 0) for all field
    sensor->fov(0, 0, 0, 0);
    BOOST_LOG_TRIVIAL(info) << boost::format("sensor fov set to %1%, %2%, %3%, %4%") % sensor->info().X % sensor->info().Y
        % sensor->info().Width % sensor->info().Height;
    // set sensor current, range 0~255
    sensor->current(180, 180, 180);
    BOOST_LOG_TRIVIAL(info) << boost::format("sensor current set to %1%, %2%, %3%") % (int)sensor->info().Red % (int)sensor->info().Green
        % (int)sensor->info().Blue;
    // set sensor exposure in us
    sensor->exposure(10000);
    BOOST_LOG_TRIVIAL(info) << boost::format("sensor exposure set to %1%, period %2%") % sensor->info().Exposure % sensor->info().Period;
    // sensor capture, if doing hand eye calibrate, using api: int capture(std::vector<cv::Mat>& images) to get image from camera
    if(0 != sensor->capture())
    {
        BOOST_LOG_TRIVIAL(error) << "sensor capture fail";
        return -1;
    }
    BOOST_LOG_TRIVIAL(info) << "sensor capture sucess";
    cv::Mat color, depth;
    // sensor compute color and depth image
    if (0 != sensor->compute(color, depth))
    {
        BOOST_LOG_TRIVIAL(error) << "sensor compute fail";
        return -1;
    }
    BOOST_LOG_TRIVIAL(info) << boost::format("color image type: %1%, size %2%") % color.type() % color.size();
    BOOST_LOG_TRIVIAL(info) << boost::format("depth image type: %1%, size %2%") % depth.type() % depth.size();
    cv::imwrite("color.bmp", color);
    cv::imwrite("depth.tiff", depth);
    // color and depth image generate point cloud, pcl for example:
    pcl::PointCloud<pcl::PointXYZRGB> cloud;
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
   
    // disconnect form sensor
    sensor->disconnect();
    return 0;
}


