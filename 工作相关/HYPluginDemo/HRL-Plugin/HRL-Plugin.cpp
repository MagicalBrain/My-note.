// HRL-Plugin.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include "AlgorithmDemo.h"

#include <common/LoggerHelper.hpp>
#include <common/PointCloudHelper.hpp>

using namespace hy;

int main()
{
    //LoggerHelperInstance()函数返回一个LoggerHelper类型的指针
    //通过这个指针调用LoggerHelper类的file方法
    //file方法在"."目录，即根目录下 生成debug级别的日志
    LoggerHelperInstance()->file(".", boost::log::trivial::debug);

    //定义一个 元素类型为string 的vector容器 名为ids
    std::vector<std::string> ids;

    //PluginFactoryInstance()函数返回一个PluginFactory类型的指针
    //通过这个指针调用 PluginFactory类的all方法
    //all方法根据PLUGIN_TYPE_ALGORITHM类型来获取PluginFactory中所有的插件id并赋值给ids
    PluginFactoryInstance()->all(ids, PLUGIN_TYPE_ALGORITHM);

    //在debug级别的日志中输出第一个插件的id
    HY_LOG_SEV(debug) << ids.front();

    //定义一个 HYAlgorithmPlugin类型的 shared_ptr类型的智能指针 名为plugin
    //根据ids中的第一个id找到对应的插件 让plugin指针指向该插件
    HYAlgorithmPlugin::Ptr plugin = PluginFactoryInstance()->find<HYAlgorithmPlugin>(ids.front());

    //初始化plugin
    plugin->initialize();

    //读取插件的json配置文件
    plugin->param("config.json");

    //为了消除显示的new，可用make_shared<T>来替代
    //其实就是初始化一个HYAlgorithmData 类型的 shared_ptr 智能指针
    HYAlgorithmData::Ptr data = std::make_shared< HYAlgorithmData>();
    
    //Ptr = shared_ptr<PointCloud<PointT> >
    //Ptr是一个 指向PointCloud<PointT>类型的 shared_ptr智能指针
    //Load函数 加载读取一个点云文件 返回一个指向该点云的 shared_ptr智能指针cloud
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud = PointCloudHelper<pcl::PointXYZ>::Load("scene.pcd");

    //显示cloud所指向的指针
    //PointCloudHelper<pcl::PointXYZ>::View(cloud);

    //调用 HYAlgorithmData 类型的 shared_ptr 智能指针 的 Clouds 成员（是一个容器）
    //将cloud指向的点云放进data的成员容器里
    data->Clouds.push_back(cloud);

    //调用plugin的输入函数
    plugin->input(data);

    //调用plugin的计算函数
    plugin->compute();

    //将plugin的成员函数output的返回值赋给 HYAlgorithmData 类型的 shared_ptr 智能指针 Ptr
    HYAlgorithmData::Ptr output = plugin->output();

    //输出output所指向的点云的大小？
    std::cout << output->Results.size() << std::endl;
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
