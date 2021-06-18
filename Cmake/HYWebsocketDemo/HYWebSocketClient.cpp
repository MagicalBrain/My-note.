#include <iostream>
/// json parser
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
/// websocket client
#include <websocketpp/config/asio_no_tls_client.hpp>
#include <websocketpp/client.hpp>
/// Mat parser
#include <opencv2/opencv.hpp>
/// PointCloud parser
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>

using wsclient = websocketpp::client<websocketpp::config::asio_client>;

std::vector<std::string> binary_message;  /// websocket binary message
boost::property_tree::ptree text_message; /// websocket text message in property tree

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
            //boost::property_tree::write_json("info.json", text_message); /// save sensor info
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
        if (!payloads)
            return;

        /// has binary payloads
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
    else /// binary message
    {
        binary_message.emplace_back(message->get_payload());
    }
}

int main()
{
    const std::string uri = "ws://192.168.3.82:8080"; /// sensor websocket address

    wsclient client;
    client.set_access_channels(websocketpp::log::alevel::all);
    client.clear_access_channels(websocketpp::log::alevel::frame_payload);
    client.set_error_channels(websocketpp::log::elevel::all);

    client.init_asio();
    client.set_message_handler(&on_message);
    client.set_max_message_size(100000000); /// set max size to receive opencv mat and pcl pointcloud 

    websocketpp::lib::error_code ec;
    wsclient::connection_ptr con = client.get_connection(uri, ec);
    if (ec) {
        std::cout << "could not create connection because: " << ec.message() << std::endl;
        return 0;
    }

    client.connect(con);
    std::cout << "connect to " << uri << " sucess";
    auto future = std::async([&]() {
        client.run();
        });

    boost::property_tree::ptree request;
    std::string json;

    int key = -1;
    bool run = true, live = false;
    do
    {
        std::cout << "Input options: ";
        std::cin >> key;
        std::cin.clear();
        request.clear();
        switch (key)
        {
        case 1:/// set sensor fov
            request.add<std::string>("Action", "SetFoV"); 
            request.add<int>("X", 0);
            request.add<int>("Y", 0);
            request.add<int>("Width", 0);
            request.add<int>("Height", 0);
            break;
        case 2:/// set sensor distance (mm)
            request.add<std::string>("Action", "SetDistance");
            request.add<int>("Min", 100);
            request.add<int>("Max", 1000);
            break;
        case 3:/// set pointcloud style
            request.add<std::string>("Action", "SetStyle");
            request.add<int>("PlainType", 3); // 3: Gray, 4: RGB
            request.add<int>("DisplayColor", 7); // 7: White, 4: Blue
            request.add<int>("DisplayBit", 8);
            break;
        case 4:/// set sensor decoder
            request.add<std::string>("Action", "SetDecodeType");
            request.add<int>("DecodeType", 5); // 
            break;
        case 5:///set live exposure
            request.add<std::string>("Action", "SetExposure");
            request.add<uint32_t>("Live", 21000);
            break;
        case 6:/// set sensor exposure and period
            request.add<std::string>("Action", "SetExposure");
            request.add<uint32_t>("Exposure", 10000);
            request.add<uint32_t>("Period", 20000);
            request.add<uint32_t>("Live", 80000);
            break;
        case 7:/// set sensor led current
            request.add<std::string>("Action", "SetCurrent");
            request.add<uint8_t>("Red", 180);
            request.add<uint8_t>("Green", 180);
            request.add<uint8_t>("Blue", 180);
            break;
        case 8:/// start capture images
            binary_message.clear();
            request.add<std::string>("Action", "Capture");
            request.add<bool>("Image", false); /// enable image payload, default is false
            break;
        case 9:/// compute pointcloud and depth image
            binary_message.clear();
            request.add<std::string>("Action", "Compute");
            break;
        case 10:/// compute pointcloud and depth image   
            live = !live;
            request.add<std::string>("Action", "SetPlayback");
            request.add<bool>("Playback", live);
            request.add<std::string>("Payload", ".png");
            request.add<int>("Width", 320);
            request.add<int>("Height", 240);
            break;
        case -1:
            run = false;
            //request.add<std::string>("Action", "RebootSensor");
            //break;
        default:/// get sensor info 
            request.add<std::string>("Action", "GetInfo");
            break;
        }

        write_json(request, json);
        con->send(json);
    } while (run);

    client.close(con, websocketpp::close::status::normal, "Close");
    return 0;
}

