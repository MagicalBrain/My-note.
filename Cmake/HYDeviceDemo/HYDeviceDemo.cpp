#include <iostream>
#include <string>

#include <HYSensorClient.h>

#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/io/pcd_io.h>

#include <boost/log/trivial.hpp>
#include <boost/format.hpp>

using namespace hy;

void LiveShow(const cv::Mat& image, int pos) ;

int main(int argc, char** argv)
{
    /*
    * 使用SDK前，建议使用HYPick对相机进行调试，可以更方便的获得合适的FoV、曝光时间及亮度
    * 1. 在开始菜单-》HYPick打开HYDeviceManager，点击“Open”打开相机，点击“Start Server”启动设备服务
    * 2. 确保SDK与设备服务主机处于同一网段，并可以Ping通
    */

    // 使用grpc协议，uri格式为：设备服务器ip:设备服务器监听端口号
    // 使用websocket协议，uri格式为：ws://设备服务器ip:设备服务器监听端口号
    ////使用grpc协议连接服务主机
    std::string uri_grpc = "192.168.3.82:8080"; 
    ////使用websocket协议连接服务主机
    std::string uri_websocket = "ws://192.168.3.82:8080"; 
    std::string uri;

    int flag_break = 1;
    do
    {
        puts("请选择grpc协议 or websocket协议：");
        puts("1 -> grpc协议;");
        puts("2 -> websocket协议;");
        char flag_protocol;
        flag_protocol = getchar();

        if (flag_protocol == '1')
            uri = uri_grpc;
        else if (flag_protocol == '2')
            uri = uri_websocket;
        else { 
            puts("输入非法请重新输入！");
            flag_break = 0;
        }
    } while (flag_break == 0);

    if (argc > 1)
        uri = argv[1];

    //连接服务主机
    BOOST_LOG_TRIVIAL(info) << "connecting sensor at " << uri;
    HYSensorClient::Ptr sensor = HYSensorClient::Connect(uri);
    if (sensor == nullptr) {                
        BOOST_LOG_TRIVIAL(error) << "connect sensor fail";
        return -1;
    }
    BOOST_LOG_TRIVIAL(info) << boost::format("%1% version: %2%") % sensor->info().Protocol % sensor->info().ProtocolVersion;

    int key = -1;
    do
    {
        puts("请选择测试API：");
        puts("-1 -> disconnect;");
        puts("1 -> distance;");
        puts("2 -> fov;");
        puts("3 -> current;");
        puts("4 -> live;");
        puts("5 -> ex;");
        puts("6 -> style 编码风格;");
        puts("7 -> decoder;");
        puts("8 -> playback;");
        puts("9 -> 拍照、计算、生成点云;");
        //puts("7 -> current;");
        //puts("8 -> current;");
        //puts("9 -> current;");
        puts("0 -> 退出测试;");

        std::cin >> key;
        std::cin.clear();

        cv::Mat color, depth, live_image;
        pcl::PointCloud<pcl::PointXYZRGB> cloud;

        std::vector<cv::Mat> images;
        std::function<void(const cv::Mat&, int pos)> callback;

        switch (key)
        {
        case 1:
            // 根据需要配置成像距离
            int min, max;
            std::cout << "请输入最小距离 最大距离" << std::endl;
            std::cin >> min >> max;
            sensor->distance(min, max);
            BOOST_LOG_TRIVIAL(info) << boost::format("sensor distance set to %1% - %2%") % sensor->info().Min % sensor->info().Max;
            break;
        case 2:
            // 根据需要配置成像FoV，(0, 0, 0, 0)表示全场景
            int x, y, re_x, re_y;
            std::cout << "请输入x, y, 分辨率x * y" << std::endl;
            std::cin >> x >> y >> re_x >> re_y;
            sensor->fov(x, y, re_x, re_y);
            BOOST_LOG_TRIVIAL(info) << boost::format("sensor fov set to %1%, %2%, %3%, %4%") % sensor->info().X % sensor->info().Y
                % sensor->info().Width % sensor->info().Height;
            break;
        case 3:
            // 根据需要配置亮度，范围0~255
            int r, g, b;
            std::cout << "请输入r, g, b" << std::endl;
            std::cin >> r >> g >> b;
            sensor->current(r, g, b);
            BOOST_LOG_TRIVIAL(info) << boost::format("sensor current set to %1%, %2%, %3%") % (int)sensor->info().Red % (int)sensor->info().Green
                % (int)sensor->info().Blue;
            break;
        case 4:
            // 根据实际需要配置实时曝光时间，单位为us
            int live;
            std::cout << "请输入实时曝光" << std::endl;
            std::cin >> live;
            sensor->live(live);
            
            BOOST_LOG_TRIVIAL(info) << boost::format("sensor LiveExposure set to %1%") % sensor->info().LiveExposure;
            break;
        case 5:
            // 根据实际需要配置触发曝光时间和周期，单位为us
            int e, p;
            std::cout << "请输入触发曝光，周期" << std::endl;
            std::cin >> e >> p;
            sensor->exposure(e, p);
            BOOST_LOG_TRIVIAL(info) << boost::format("sensor exposure set to %1%, period %2%") % sensor->info().Exposure % sensor->info().Period;
            break;
        case 6:
            // 根据实际需要设置编码风格
            int plain , led , bit ;
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
            /*
            DISPLAY_COLOR_NO_COLOR = 0,
		    DISPLAY_COLOR_RED = 1,
		    DISPLAY_COLOR_GREEN = 2,
		    DISPLAY_COLOR_YELLOW = 3, // green + red
		    DISPLAY_COLOR_BLUE = 4,
		    DISPLAY_COLOR_MAGENTA = 5, // blue + red
		    DISPLAY_COLOR_CYAN = 6, // blue + green
		    DISPLAY_COLOR_WHITE = 7 // blue + green + red 
            */
            std::cout << "bit: Pattern的位数（范围：1~8）" << std::endl;
            std::cin >> plain >> led >> bit;
            sensor->style(plain, led, bit);
            BOOST_LOG_TRIVIAL(info) << boost::format("sensor style plain: %1%; led: %2%; bit:%3%") 
                % sensor->info().PlainType % sensor->info().DisplayColor % sensor->info().DisplayBit;
            break;
        case 7:
            int type;
            std::cout << "请根据实际需要设置解码器" << std::endl;
            std::cout << "5 --- 多频外差" << std::endl;
            std::cout << "6 --- 格雷码" << std::endl;
            std::cout << "7 --- 格雷码+相移" << std::endl;
            std::cout << "8 --- 散斑" << std::endl;
            /*
            DECODE_MF_HETERODYNE = 5;	// 多频外差
	        const int DECODE_GRAYCODE = 6;		// 格雷码
	        const int DECODE_GRAYCODE_PHASE = 7;	// 格雷码+相移
	        const int DECODE_SPECKLE = 8;			// 散斑
            */
            std::cin >> type;
            sensor->decoder(type);
            BOOST_LOG_TRIVIAL(info) << boost::format("sensor style decoder is %1%;") % sensor->info().DecodeType;
            break;
        case 8:
            //获取相机的实时图像
            callback = LiveShow;
            
            sensor->playback(callback);
            //sensor->playback();

            break;
        case 9:
            // 控制相机取图，如果需要做手眼标定，可以使用int capture(std::vector<cv::Mat>& images)接口获取相机图片
            if(0 != sensor->capture(images))
            {
                BOOST_LOG_TRIVIAL(error) << "sensor capture fail";
                return -1;
            }
            BOOST_LOG_TRIVIAL(info) << "sensor capture sucess";

            // 生成并获取彩色图和深度图
    
            if (0 != sensor->compute(color, depth))
            {
                BOOST_LOG_TRIVIAL(error) << "sensor compute fail";
                return -1;
            }
            BOOST_LOG_TRIVIAL(info) << boost::format("color image type: %1%, size %2%") % color.type() % color.size();
            BOOST_LOG_TRIVIAL(info) << boost::format("depth image type: %1%, size %2%") % depth.type() % depth.size();
            
            cv::imwrite("color.bmp", color);
            cv::imwrite("depth.tiff", depth);
            cv::imwrite("depth.png", depth);

            std::cout << depth.rows << " " << depth.cols << std::endl;

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

            break;
        
        case -1:
            // 断开与设备服务的连接
            sensor->disconnect();
            BOOST_LOG_TRIVIAL(info) << "disconnected.";
            break;
       
        default:
            key = 0;
            sensor->disconnect();
            BOOST_LOG_TRIVIAL(info) << "disconnected.";
            break;
        }
    } while (key);

    return 0;
}

void LiveShow(const cv::Mat& image, int pos) {
    std::cout << "获取实时图像" << std::endl;
    cv::imshow("LiveImage", image);
}
