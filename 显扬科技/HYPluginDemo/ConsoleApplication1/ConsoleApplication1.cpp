// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "AlgorithmDemo.h"

#include <common/LoggerHelper.hpp>
#include <common/PointCloudHelper.hpp>

using namespace hy;

int main()
{
    LoggerHelperInstance()->file(".", boost::log::trivial::debug);
    std::vector<std::string> ids;
    PluginFactoryInstance()->all(ids, PLUGIN_TYPE_ALGORITHM);

    HY_LOG_SEV(debug) << ids.front();

    HYAlgorithmPlugin::Ptr plugin = PluginFactoryInstance()->find<HYAlgorithmPlugin>(ids.front());

    plugin->initialize();
    plugin->param("config.json");
    HYAlgorithmData::Ptr data = std::make_shared< HYAlgorithmData>();
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud = PointCloudHelper<pcl::PointXYZ>::Load("scene.pcd");

    PointCloudHelper<pcl::PointXYZ>::View(cloud);

    data->Clouds.push_back(cloud);
    plugin->input(data);
    plugin->compute();
    HYAlgorithmData::Ptr output = plugin->output();
    
    std::cout << output->Results.size() << std::endl;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
