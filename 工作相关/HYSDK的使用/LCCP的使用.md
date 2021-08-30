# LCCP的使用

```cpp
#pragma once
#include <algorithm/HYAlgorithmTask.h>


namespace hy
{
    struct SuperVoxelLCCPParam
    {
        float voxel_resolution = 2.0;//体素分辨率（点之间的距离）
        float seed_resolution = 80.0;//结晶核分辨率（结晶核之间的距离),越小越精确
        float color_importance = 0.0;//颜色权重
        float spatial_importance = 20.0;//空间权重
        float normal_importance = 20.0;//法线权重

        float concavity_tolerance_threshold = 0.9;//凹度容忍阈值
        //Normal Threshold in degrees [0,180] used for merging
        float smoothness_threshold = 15.0;//平滑阈值
        //Two supervoxels are unsmooth if their plane-to-plane distance DIST >  (expected_distance + smoothness_threshold_*voxel_resolution_)
        int k_factor = 1;//cc校验的K临点,判断两个超体素为凸性时需要相邻的K个超体素也是凸性、
        bool smooth_check = true;//是否进行平滑检查
        bool sanity_check = true;//是否进行SC检查
        float min_segment_size = 20;//分割块的最小size
        float min_seg_num = 500;//分割后点云最小点数
        float max_seg_num = 50000;//分割后点云最大点数

        friend cv::FileStorage& operator<<(cv::FileStorage& fs, const SuperVoxelLCCPParam& mp)
        {
            fs << "{";
            fs << "voxel_resolution" << mp.voxel_resolution;
            fs << "seed_resolution" << mp.seed_resolution;
            fs << "color_importance" << mp.color_importance;
            fs << "spatial_importance" << mp.spatial_importance;
            fs << "normal_importance" << mp.normal_importance;
            fs << "concavity_tolerance_threshold" << mp.concavity_tolerance_threshold;
            fs << "smoothness_threshold" << mp.smoothness_threshold;
            fs << "k_factor" << mp.k_factor;
            fs << "smooth_check" << mp.smooth_check;
            fs << "sanity_check" << mp.sanity_check;
            fs << "min_segment_size" << mp.min_segment_size;
            fs << "min_seg_num" << mp.min_seg_num;
            fs << "max_seg_num" << mp.max_seg_num;
            fs << "}";
            return fs;
        }

        friend void operator>>(const cv::FileNode& node, SuperVoxelLCCPParam& mp)
        {
            node["voxel_resolution"] >> mp.voxel_resolution;
            node["seed_resolution"] >> mp.seed_resolution;
            node["color_importance"] >> mp.color_importance;
            node["spatial_importance"] >> mp.spatial_importance;
            node["normal_importance"] >> mp.normal_importance;
            node["concavity_tolerance_threshold"] >> mp.concavity_tolerance_threshold;
            node["smoothness_threshold"] >> mp.smoothness_threshold;
            node["k_factor"] >> mp.k_factor;
            node["smooth_check"] >> mp.smooth_check;
            node["sanity_check"] >> mp.sanity_check;
            node["min_segment_size"] >> mp.min_segment_size;
            node["min_seg_num"] >> mp.min_seg_num;
            node["max_seg_num"] >> mp.max_seg_num;
        }
    };

	class SuperVoxelLCCPSegmentation : public HYAlgorithmTask
	{
	public:
        SuperVoxelLCCPSegmentation() {}
        virtual ~SuperVoxelLCCPSegmentation() {}

        virtual int param(const cv::FileNode& fn) override;
        virtual int compute(int index = -1, int max = 5) override;

        static void Segmentation(const pcl::PointCloud<pcl::PointXYZ>::Ptr& cloud, std::vector<pcl::PointCloud<pcl::PointXYZ>::Ptr>& clusters,
            int min_seg_num, int max_seg_num, float voxel, float seed, float color, float spatial, float normal, float concavity, bool smooth_check, float smoothness_threshold,
            int k, bool sanity_check, int min_segment_size);

    protected:
        SuperVoxelLCCPParam param_;
	};
}
```
