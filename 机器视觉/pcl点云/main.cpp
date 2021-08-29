#include <pcl/ModelCoefficients.h>

#include <pcl/point_types.h>

#include <pcl/io/pcd_io.h>

#include <pcl/filters/extract_indices.h>
#include <pcl/filters/voxel_grid.h>

#include <pcl/features/normal_3d.h>

#include <pcl/kdtree/kdtree.h>

#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>

#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/segmentation/extract_clusters.h>

#include <pcl/visualization/pcl_visualizer.h>

int main(int argc, char** argv)
{
    // Read in the cloud data
    pcl::PCDReader reader;
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>), cloud_f(new pcl::PointCloud<pcl::PointXYZ>);

    reader.read("table_scene_lms400.pcd", *cloud);
    
    std::cout << "PointCloud before filtering has: " << cloud->points.size() << " data points." << std::endl; //*

    // 下采样滤波
    pcl::VoxelGrid<pcl::PointXYZ> vg;
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZ>);

    vg.setInputCloud(cloud);
    vg.setLeafSize(0.01f, 0.01f, 0.01f);
    vg.filter(*cloud_filtered);
    
    std::cout << "PointCloud after filtering has: " << cloud_filtered->points.size() << " data points." << std::endl; //*

    //创建分割对象和参数
    pcl::SACSegmentation<pcl::PointXYZ> seg;
    pcl::PointIndices::Ptr inliers(new pcl::PointIndices);
    pcl::ModelCoefficients::Ptr coefficients(new pcl::ModelCoefficients);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_plane(new pcl::PointCloud<pcl::PointXYZ>());
    pcl::PCDWriter writer;
    
    seg.setOptimizeCoefficients(true);
    seg.setModelType(pcl::SACMODEL_PLANE);
    seg.setMethodType(pcl::SAC_RANSAC);
    seg.setMaxIterations(100);
    seg.setDistanceThreshold(0.02);

    int i = 0, nr_points = (int)cloud_filtered->points.size();
    while (cloud_filtered->points.size() > 0.3 * nr_points)
    {
        // Segment the largest planar component from the remaining cloud
        seg.setInputCloud(cloud_filtered);
        seg.segment(*inliers, *coefficients);
        //提取点
        pcl::ExtractIndices<pcl::PointXYZ> extract;
        extract.setInputCloud(cloud_filtered);
        extract.setIndices(inliers);
        extract.setNegative(false);
        // 提取的平面上的点保存到cloud_plane
        extract.filter(*cloud_plane);
        std::cout <<cloud_plane->points.size() <<std::endl;
        // Remove the planar inliers, extract the rest
        extract.setNegative(true);
        extract.filter(*cloud_f);
        cloud_filtered = cloud_f;
    }
    
    //创建一个Kd树对象作为提取点云时所用的方法，
    pcl::search::KdTree<pcl::PointXYZ>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZ>);
    tree->setInputCloud(cloud_filtered);
    std::vector<pcl::PointIndices> cluster_indices;
    pcl ::EuclideanClusterExtraction<pcl::PointXYZ> ec;//聚类
    
    ec.setClusterTolerance(0.02); //设置近邻搜索的搜索半径为2cm
    ec.setMinClusterSize(100);    //设置一个聚类需要的最少点数目为100
    ec.setMaxClusterSize(25000);  //设置一个聚类需要的最大点数目为25000
    ec.setSearchMethod(tree);     //设置点云的搜索机制
    ec.setInputCloud(cloud_filtered); //设置原始点云 
    ec.extract(cluster_indices);  //从点云中提取聚类

    // 可视化部分
    pcl::visualization::PCLVisualizer viewer("segmention");
    int j = 0;
    for (std::vector<pcl::PointIndices>::const_iterator it = cluster_indices.begin(); it != cluster_indices.end(); ++it)
    {
        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_cluster(new pcl::PointCloud<pcl::PointXYZ>);
        for (std::vector<int>::const_iterator pit = it->indices.begin(); pit != it->indices.end(); pit++)
            cloud_cluster->points.push_back(cloud_filtered->points[*pit]); //*
        cloud_cluster->width = cloud_cluster->points.size();
        cloud_cluster->height = 1;
        cloud_cluster->is_dense = true;
        std::cout << "PointCloud representing the Cluster: " << cloud_cluster->points.size() << " data points." << std::endl;
        std::stringstream ss;
        ss << "cloud_cluster_" << j << ".pcd";
        
        int v2(0);
        pcl::visualization::PointCloudColorHandlerRandom<pcl::PointXYZ> cloud_in_color_h(cloud);//赋予显示点云的颜色,随机
        viewer.addPointCloud(cloud_cluster, cloud_in_color_h, std::to_string(j));
        j++;
    }
    
    //等待直到可视化窗口关闭。
    while (!viewer.wasStopped())
    {
        viewer.spinOnce(100);//刷新屏幕显示一次，100为允许重新渲染一次的最大时间ms数。
        boost::this_thread::sleep(boost::posix_time::microseconds(100000));
    }

    return (0);
}
