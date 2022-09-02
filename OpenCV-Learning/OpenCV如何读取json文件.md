# OpenCV如何读取json文件

主要是使用opencv的FileStorage来进行

先编写一个参数设置类`MyParam` 在`JsonParam.h`里

```cpp
#pragma once

#include <opencv2/opencv.hpp>
#include <boost/filesystem.hpp>

using namespace std;
using namespace cv;

struct MyStruct
{
	// 是否打开测试模式以查看中间结果图片
	bool testMode = false;

	// 是否自定义形态学操作的核
	bool CustomKernel = false;
	// 设置自定义形态学核的类型和大小
	int Kernel_type = 0;
	int Kernel_size = 1;

	// 设置形态学操作迭代的次数
	int iterations = 1;

	/**
	 * @brief
	*/
	double cannyThreshold2 = 80;//

	/**
	 * @brief
	*/
	double cannyThreshold1 = 30;//

	/**
	 * @brief
	*/
	int filterContourSizeLow = 500;//

	/**
	 * @brief
	*/
	int filterContourSizeUp = 2200;

	/**
	 * @brief
	*/
	int connectedAreaLow = 4000;

	/**
	 * @brief
	*/
	int connectedAreaUp = 20000;

	/**
	 * @brief
	*/
	int lineType = 8;//

	/**
	 * @brief 设置高斯模糊的模糊核的大小
	 * @details 只能是奇数或者是0
	*/
	int GaussianBlurSize = 3;

	/**
	 * @brief 设置霍夫圆算法的变换方法
	 * @details 参数范围为 0~4
	 *			0 --- HOUGH_STANDARD
	 * 推荐使用3或4
	*/
	int Hough_Mode = 3;

	/**
	 * @brief 霍夫 缩小分辨率的比值
	*/
	double Hough_ratio = 1.5;

	/**
	 * @brief 检测圆之间的最小距离
	*/
	double Hough_minDst = 0.5;

	/**
	 * @brief 检测圆边缘的Canny阈值
	*/
	int Hough_Canny_Threshold = 300;

	/**
	 * @brief 霍夫累加器的阈值
	*/
	double Hough_Add_Threshold = 0.9;

	/**
	 * @brief 霍夫检测圆的最小半径
	*/
	int Hough_minRadius = 0;

	/**
	 * @brief 霍夫检测圆的最大半径
	*/
	int Hough_maxRadius = 100;

	friend cv::FileStorage& operator<<(cv::FileStorage& fs, const MyStruct& mp)
	{
		fs << "{";
		fs << "testMode" << mp.testMode;
		fs << "CustomKernel" << mp.CustomKernel;
		fs << "Kernel_type" << mp.Kernel_type;
		fs << "Kernel_size" << mp.Kernel_size;
		//fs << "morphology_type" << mp.morphology_type;
		fs << "iterations" << mp.iterations;
		fs << "cannyThreshold2" << mp.cannyThreshold2;
		fs << "cannyThreshold1" << mp.cannyThreshold2;
		fs << "filterContourSizeLow" << mp.filterContourSizeLow;
		fs << "filterContourSizeUp" << mp.filterContourSizeUp;
		fs << "connectedAreaLow" << mp.connectedAreaLow;
		fs << "connectedAreaUp" << mp.connectedAreaUp;
		fs << "lineType" << mp.lineType;

		fs << "GaussianBlurSize" << mp.GaussianBlurSize;

		fs << "HoughMode" << mp.Hough_Mode;
		fs << "HoughRatio" << mp.Hough_ratio;
		fs << "HoughMinDst" << mp.Hough_minDst;
		fs << "HoughCannyThreshold" << mp.Hough_Canny_Threshold;
		fs << "HoughAddThreshold" << mp.Hough_Add_Threshold;
		fs << "HoughMinRadius" << mp.Hough_minRadius;
		fs << "HoughMaxRadius" << mp.Hough_maxRadius;
		fs << "}";
		return fs;
	}

	friend void operator>>(const cv::FileNode& node, MyStruct& mp)
	{
		node["testMode"] >> mp.testMode;
		node["CustomKernel"] >> mp.CustomKernel;
		node["Kernel_type"] >> mp.Kernel_type;
		node["Kernel_size"] >> mp.Kernel_size;
		//node["morphology_type"] >> mp.morphology_type;
		node["iterations"] >> mp.iterations;
		node["cannyThreshold2"] >> mp.cannyThreshold2;
		node["cannyThreshold1"] >> mp.cannyThreshold1;
		node["filterContourSizeLow"] >> mp.filterContourSizeLow;
		node["filterContourSizeUp"] >> mp.filterContourSizeUp;
		node["connectedAreaLow"] >> mp.connectedAreaLow;
		node["connectedAreaUp"] >> mp.connectedAreaUp;
		node["lineType"] >> mp.lineType;

		node["GaussianBlurSize"] >> mp.GaussianBlurSize;

		node["HoughMode"] >> mp.Hough_Mode;
		node["HoughRatio"] >> mp.Hough_ratio;
		node["HoughMinDst"] >> mp.Hough_minDst;
		node["HoughCannyThreshold"] >> mp.Hough_Canny_Threshold;
		node["HoughAddThreshold"] >> mp.Hough_Add_Threshold;
		node["HoughMinRadius"] >> mp.Hough_minRadius;
		node["HoughMaxRadius"] >> mp.Hough_maxRadius;
	}

};

class MyParam
{
public:
	//HY_SHARED_PTR(MyParam);
	MyParam() {}
	virtual ~MyParam() {}

	int ReadParam(const cv::FileNode& fileNode);

	int ProcessParam(const std::string& file);

	int param(const cv::FileNode& fn);
	//int compute(int index = -1, int max = 5);

private:
	MyStruct param_;

	std::string workspace_;
};
```

以上只是我们一般用的算法参数中的一部分

```cpp
#include "JsonParam.h"

int MyParam::ReadParam(const cv::FileNode& fileNode)
{
    if (fileNode.empty() == true)
    {
        return -1;
    }
    fileNode >> param_;
    return 0;
}

int MyParam::ProcessParam(const std::string& file)
{
    try
    {
        FileStorage fs(file, FileStorage::READ);
        if (fs.isOpened())
        {
            //algorithm_task_.clear();
            
            workspace_ = boost::filesystem::path(file).parent_path().generic_string();
            FileNode fn = fs.root();
            string key;
            for (auto it = fn.begin(); it != fn.end(); it++)
            {
                key = (*it).name();
                this->ReadParam(*it);
                std::cout << std::format("the key is {}\n", key);
                //std::cout << std::format("invalid algorithm task key {}", key);

            }
            std::cout << std::format("read value HoughAddThreshold is {}\n", this->param_.Hough_Add_Threshold);
            return 0;
        }
        fs.release();
        //HY_LOG_SEV(error) << boost::format("open algorithm param file %1% fail") % file;
        //std::cout << std::format("open algorithm param file {} fail", file);

        

    }
    catch (const std::exception& ex)
    {
        //HY_LOG_SEV(error) << boost::format("open algorithm param file %1% catch exception: %2%")
        //  % file % ex.what();
        std::cout << std::format("open algorithm param file {} catch exception: {}", file, ex.what());
    }
    return -1;
    //return 0;
}
```

可见用opencv的这个来读json的话，只能用来读取简单的

目前还不知道能不能从json中读取数组和矩阵
