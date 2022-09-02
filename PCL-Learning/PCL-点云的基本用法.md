# PCL-点云初始化及赋值

## 点云的类型

## 初始化一个点云

```cpp
pcl::PointCloud<pcl::PointXYZRGB>::Ptr point_cloud_ptr (new pcl::PointCloud<pcl::PointXYZRGB>);
```

## 给点云添加一个点

```cpp
// 首先初始化一个要被添加进去的点
pcl::PointXYZRGB point;

// 给这个点的坐标赋值
point.x = 0.5 * cosf (pcl::deg2rad(angle));
point.y = sinf (pcl::deg2rad(angle));
point.z = z;

// 设置这个点的rgb颜色
uint8_t r(255), g(15), b(15);
uint32_t rgb = (static_cast<uint32_t>(r) << 16 |
	static_cast<uint32_t>(g) << 8 | static_cast<uint32_t>(b));

point.rgb = *reinterpret_cast<float*>(&rgb);

// 将这个点添加进点云
point_cloud_ptr->points.push_back (point);
```

## 点云可视化

### 头文件

```cpp
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/visualization/cloud_viewer.h>
```

### 显示一个点云

显示一个点云并且一直显示

```cpp
// 定义了一个名为 test 的点云显示窗口
pcl::visualization::CloudViewer viewer ("test");
// 显示点云
viewer.showCloud(point_cloud_ptr);
// 开始循环，一直显示点云
while (!viewer.wasStopped()){ };
```

### 显示点云并刷新

```cpp
//pcl::visualization::CloudViewer viewer ("test");
pcl::visualization::PCLVisualizer::Ptr viewer(new pcl::visualization::PCLVisualizer("test"));
while (true) {
	// 不管viewer里有什么全都清除掉
	viewer->removeAllPointClouds();
	viewer->removeAllShapes();
	
	// todo 计算点云

	// 给点云上色
	pcl::visualization::PointCloudColorHandlerRGBField<pcl::PointXYZRGB> rgb(point_cloud_ptr);
	// 将点云加入到显示的viewer对象中去
	viewer->addPointCloud<pcl::PointXYZRGB>(point_cloud_ptr, rgb, "sample cloud");
	viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "sample cloud");
	//viewer->addCoordinateSystem(1.0);//显示坐标轴，有时看着碍事...所以我把他注释掉了。
	viewer->initCameraParameters();
 
	viewer->setBackgroundColor(0, 0, 0);
	viewer->setCameraPosition(0, 0, -2, 0, -1, 0, 0);
}
```

https://blog.csdn.net/gaoenyang760525/article/details/78168937

## 点云的读取和保存

### 头文件

```cpp

```

### 读取点云

```cpp

```


### 保存点云

```cpp

//保存点云数据
pcl::io::savePCDFileASCII ("test_pcd.pcd", cloud);
```
