# HYSDK计算质心

hysdk里计算质心的接口都在这个`SortByMessCenter.hpp`

```cpp
#pragma once
#include <algorithm/HYAlgorithmTask.h>
#include <common/EstimationHelper.hpp>

namespace hy
{
    struct SortParam
    {
        std::string axis = "z";//按Z轴排序//0为按X轴排序，1为按Y轴排序
        bool filter_shape_unmatched = false;//是否启用判断点云的形状与实际形状的差值来过滤不合理的抓取目标
        float box_length = 50;
        float box_width = 30;
        float length_tolerance = 0.1;
        float width_tolerance = 0.1;

        //读取json文件里的参数
        friend cv::FileStorage& operator<<(cv::FileStorage& fs, const SortParam& param)
        {
            fs << "{";
            fs << "axis" << param.axis;
            fs << "filter_shape_unmatched" << param.filter_shape_unmatched;
            fs << "box_length" << param.box_length;
            fs << "box_width" << param.box_width;
            fs << "length_tolerance" << param.length_tolerance;
            fs << "width_tolerance" << param.width_tolerance;
            fs << "}";
            return fs;
        }

        ////写参数到json文件里
        friend void operator>>(const cv::FileNode& fn, SortParam& param)
        {
            fn["axis"] >> param.axis;
            fn["filter_shape_unmatched"] >> param.filter_shape_unmatched;
            fn["box_length"] >> param.box_length;
            fn["box_width"] >> param.box_width;
            fn["length_tolerance"] >> param.length_tolerance;
            fn["width_tolerance"] >> param.width_tolerance;
        }
    };


    class HYPROCESS_API SortByMessCenter :public HYAlgorithmTask
    {
    public:
        HY_SHARED_PTR(SortByMessCenter);
        SortByMessCenter() {}
        virtual ~SortByMessCenter() {}

        virtual int param(const cv::FileNode& fn) override;
        virtual int compute(int index = -1, int max = 5) override;

        template<typename PointT>        
        static void Sort(const std::vector<std::shared_ptr<pcl::PointCloud<PointT>>>& clouds, const std::string& axis,
                std::vector<ProcessResult>& results)
        {
            results.clear();
            for (int i = 0; i < clouds.size(); ++i)
            {
                ProcessResult result;
                EstimationHelper<PointT>::MassCenterEstimation(clouds[i],
                    result.centroid, result.eigen_vectors[0], result.eigen_vectors[1], result.eigen_vectors[2]);
                result.cloud = clouds[i];
                if (axis == "x")
                    result.score = result.centroid.x();
                else if (axis == "y")
                    result.score = result.centroid.y();
                else
                    result.score = result.centroid.z();
                
                if (result.eigen_vectors[2][2] < 0)
                {
                    result.eigen_vectors[2][0] = -result.eigen_vectors[2][0];
                    result.eigen_vectors[2][1] = -result.eigen_vectors[2][1];
                    result.eigen_vectors[2][2] = -result.eigen_vectors[2][2];

                    //使坐标系符合卡尔右手坐标系
                    result.eigen_vectors[1][0] = -result.eigen_vectors[1][0];
                    result.eigen_vectors[1][1] = -result.eigen_vectors[1][1];
                    result.eigen_vectors[1][2] = -result.eigen_vectors[1][2];
                   

                }
                results.emplace_back(result);
            }

            //高度排序，把高度按照从小到大的顺序排序(从高到低排序）
            std::sort(results.begin(), results.end(), [=](const ProcessResult& p1, const ProcessResult& p2)
                {
                    return p1.score < p2.score;
                });
        }
    private:
        SortParam param_;
        void filterShapeUnmatched();
    };
}
```
