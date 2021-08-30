# 区域生长分割(Region Growing Segmentation)

## 基本原理

### 知乎大佬的总结加上自己的一些理解

[Daniel Liu][Daniel Liu]

区域生长的基本思想是将具有相似性质的像素集中起来构建成分割区域。该算法的步骤是：

a.随机选取图像中的一个像素作为种子像素，并将其表示出来，如：label 1

![](https://pic2.zhimg.com/80/v2-1e60ca3be4181cb73d465eb42f209601_720w.jpg)

b.检索种子附近的未被标记的像素点，如果他们的差值在所规定的阈值内（阈值需要根据不同的情况进行设置），则合并到分割区域中

![](https://pic3.zhimg.com/80/v2-f8fc33e0696bb15a6af78e1951e4285e_720w.jpg)

c.重复b步骤，直到区域停止扩张，并在此时再次随机选择非选定区域的一个像素做为种子像素

![](https://pic4.zhimg.com/80/v2-740286a8e604c05b605b437f8e41fdef_720w.jpg)

d.重复上述步骤，直到图像中的每个像素均被分配到不同的区域中

![](https://pic1.zhimg.com/80/v2-26e058de372b7c014d08fd61bfdc23b0_720w.jpg)

优点：计算简单，特别适用于分割小的结构，如肿瘤和伤疤

缺点：对噪音敏感，导致抽取的区域有空洞

[Daniel Liu]:https://zhuanlan.zhihu.com/p/89488964

以上的区域生长分割算法是用来处理二维图像的，三维的略有不同。

在二维图像的区域生长分割算法里，生长的阈值是点的灰度值或者RGB值；而在三维区域生长分割算法里则是点与点之间法向量的角度。

因为在三维图像里我们比较的不再是点与点之间的颜色、亮度而是点是否在一个平滑的平面上。

### PCL库官方的解释

In this tutorial we will learn how to use the region growing algorithm implemented in the pcl::RegionGrowing class. The purpose of the said algorithm is to merge the points that are close enough in terms of the smoothness constraint. Thereby, the output of this algorithm is the set of clusters, where each cluster is a set of points that are considered to be a part of the same smooth surface. The work of this algorithm is based on the comparison of the angles between the points normals.

在本教程中，我们将学习如何使用在`pcl::RegionGrowing`类中实现的区域增长算法。该算法的目的是合并在平滑约束条件下足够接近的点。因此，该算法的输出是聚类的集合，其中每个聚类都是被认为是同一光滑表面的一部分的点的集合。该算法是基于两点法线之间的角度比较。

#### 理论基础 Theoretical Primer

Let’s take a look at how the algorithm works.

让我们一起来看看这个算法是如何工作的。

First of all it sorts the points by their curvature value. It needs to be done because the region begins its growth from the point that has the minimum curvature value. The reason for this is that the point with the minimum curvature is located in the flat area (growth from the flattest area allows to reduce the total number of segments).

首先通过曲率的值给所有的点排序。
这一步是因为区域生长算法是从曲率最小的点开始的，这个点就是所谓“种子”。
原因很简单，因为曲率最小的点肯定是在一个平面区域上的（从最平滑的区域开始生长能够减少最终分割出来的聚类的个数）。

So we have the sorted cloud. Until there are no unlabeled points in the cloud, the algorithm picks up the point with minimum curvature value and starts the growth of the region. This process occurs as follows:

我们有了分类过的点云。
然后这个算法会挑选出最小曲率的点并从该点开始长出一片区域，直到点云中没有未被标记的区域为止。
整个过程的步骤如下：

* The picked point is added to the set called seeds.
* For every seed point, the algorithm finds its neighbouring points.
  * Every neighbour is tested for the angle between its normal and normal of the current seed point. If the angle is less than the threshold value then current point is added to the current region.
  * After that every neighbour is tested for the curvature value. If the curvature is less than the threshold value then this point is added to the seeds.
  * Current seed is removed from the seeds.

1. 挑选曲率最小的点，并将其加入到名为种子的集合中
2. 对于每一个“种子”，该算法开始找它的近邻点。对于每一个近邻点：
   1. 比较它的法线和当前的“种子”的法线的角度。如果这个角度小于某个阈值，那么这个点就会被加入到当前种子所在的区域
   2. 比较近邻点的曲率，如果小于某个阈值则将其加入到“种子”集合里
   3. 将当前种子从种子集合里移出

If the seeds set becomes empty this means that the algorithm has grown the region and the process is repeated from the beginning. You can find the pseudocode for the said algorithm below.

如果种子集合为空，则意味着算法已经生长出了一片区域，且回到了一开始的情况。
算法的伪代码在下方。

Inputs:
    Point cloud = $\{P\}$
    Point normals = $\{N\}$
    Points curvatures = $\{c\}$
    Neighbour finding function $\Omega(.)$
    Curvature threshold $c_{th}$
    Angle threshold $\theta_{th}$

Initialize:
    Region list $\{R\} \leftarrow\{O\}$
    Available points list $\{A\}\leftarrow\{1,...,|P|\}$

Algorithm:

While $\{A\}$ is not empty do

Current region $\{R_c\}\leftarrow\{O\}$

Current seeds $\{S_c\}\leftarrow\{O\}$

Point with minimum curvature in $\{A\}\rightarrow P_{min}$

$\{S_c\}\leftarrow\{S_c\}\cup P_{min}$

$\{R_c\}\leftarrow\{R_c\}\cup P_{min}$

$\{A\}\leftarrow\{A\}\setminus P_{min}$

for i=0 to size ( $\{S_c\}$ ) do

Find nearest neighbours of current seed point $\{B_c\}\leftarrow\Omega(S_c\{i\})$

for j=0 to size ( $\{B_c\}$ ) do

Current neighbour point $P_j\leftarrow B_c\{j\}$

If $\{A\}$ contains $P_j$ and $cos^{-1}(|(N\{S_c\{i\}\},N\{S_c\{j\}\})|)<\theta_{th}$ then

$\{R_c\}\leftarrow\{R_c\}\cup P_j$

$\{A\}\leftarrow\{A\}\setminus P_j$

If $c\{P_j\}<c_{th}$ then

$\{S_c\}\leftarrow\{S_c\}\cup P_j$
end if

end if

end for

end for

Add current region to global segment list $\{R\}\leftarrow\{R\}\cup\{R_c\}$

end while
Return $\{R\}$



## PCL官方代码示例

```cpp
#include "RegionGrowing.h"

//cloud即输入的点云
int RegionGrowing(pcl::PointCloud<PointT>::Ptr cloud)
{
    /* --- 首先得计算出各个点的法向量 --- */
    pcl::search::Search<pcl::PointXYZ>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZ>);
    pcl::PointCloud <pcl::Normal>::Ptr normals(new pcl::PointCloud <pcl::Normal>);
    pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> normal_estimator;
    normal_estimator.setSearchMethod(tree);
    normal_estimator.setInputCloud(cloud);
    normal_estimator.setKSearch(50);
    normal_estimator.compute(*normals);

    //使用直通滤波器进行降采样？
    pcl::IndicesPtr indices(new std::vector <int>);
    pcl::PassThrough<pcl::PointXYZ> pass;
    pass.setInputCloud(cloud);
    pass.setFilterFieldName("z");
    pass.setFilterLimits(0.0, 1.0);
    pass.filter(*indices);

    //定义区域生长类
    pcl::RegionGrowing<pcl::PointXYZ, pcl::Normal> reg;
    
    reg.setMinClusterSize(800);     //设置最小聚类的点数    改太多大的话，点云将会为空
    reg.setMaxClusterSize(100000);  //设置最大聚类的点数
    
    reg.setSearchMethod(tree);      //设置搜索方法为Kd tree
    reg.setNumberOfNeighbours(30);  //设置搜索的近邻点的数量为30
    reg.setInputCloud(cloud);
    //reg.setIndices (indices);
    reg.setInputNormals(normals);
    reg.setSmoothnessThreshold(3.0 / 180.0 * M_PI);
    reg.setCurvatureThreshold(1.0);

    std::vector <pcl::PointIndices> clusters;
    reg.extract(clusters);

    std::cout << "Number of clusters is equal to " << clusters.size() << std::endl;
    std::cout << "First cluster has " << clusters[0].indices.size() << " points." << std::endl;
    std::cout << "These are the indices of the points of the initial" <<
        std::endl << "cloud that belong to the first cluster:" << std::endl;
    int counter = 0;
    while (counter < clusters[0].indices.size())
    {
        std::cout << clusters[0].indices[counter] << ", ";
        counter++;
        if (counter % 10 == 0)
            std::cout << std::endl;
    }
    std::cout << std::endl;

    pcl::PointCloud <pcl::PointXYZRGB>::Ptr colored_cloud = reg.getColoredCloud();
    std::cout << "The size of ouput point cloud is:" << colored_cloud->size() << std::endl;
    if (colored_cloud->size() <= 0) {
        std::cout << "The point cloud is empty." << std::endl;
        return 0;
    }
    pcl::visualization::CloudViewer viewer("Cluster viewer");
    viewer.showCloud(colored_cloud);
    while (!viewer.wasStopped())
    {
    }

    return (0);
}
```

### 官方解释

Now let’s study out what is the purpose of this code. First few lines will be omitted, because they are obvious.

现在一起来看看这段代码是干啥的。
前面几行可以不用讲，用处太明显了。

First lines that are of interest are these:

我们首先要关注的是：
```cpp
pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
  if ( pcl::io::loadPCDFile <pcl::PointXYZ> ("region_growing_tutorial.pcd", *cloud) == -1)
  {
    std::cout << "Cloud reading failed." << std::endl;
    return (-1);
  }
```

They are simply loading the cloud from the .pcd file. No doubt that you saw how it is done hundreds of times, so let’s move on.

简单地从pcd文件中读取点云。
毫无疑问，你已经讲过上百次了，下一段。

```cpp
pcl::search::Search<pcl::PointXYZ>::Ptr tree (new pcl::search::KdTree<pcl::PointXYZ>);
pcl::PointCloud <pcl::Normal>::Ptr normals (new pcl::PointCloud <pcl::Normal>);
pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> normal_estimator;
normal_estimator.setSearchMethod (tree);
normal_estimator.setInputCloud (cloud);
normal_estimator.setKSearch (50);
normal_estimator.compute (*normals);
```

As mentioned before, the algorithm requires normals. Here the `pcl::NormalEstimation` class is used to compute them. To learn more about how it is done you should take a look at the Estimating Surface Normals in a PointCloud tutorial in the Features section.

之前提到过，这个算法需要计算法线。
这里调用的`pcl::NormalEstimation`类就是用来计算法线的。
如果要学习这个类是如何计算法线的，你应该去看看 Feature那章里的Estimating Surface Normals的部分

```cpp
pcl::IndicesPtr indices (new std::vector <int>);
pcl::PassThrough<pcl::PointXYZ> pass;
pass.setInputCloud (cloud);
pass.setFilterFieldName ("z");
pass.setFilterLimits (0.0, 1.0);
pass.filter (*indices);
```

These lines are given only for example. You can safely comment this part. Insofar as `pcl::RegionGrowing` is derived from `pcl::PCLBase`, it can work with indices. It means you can instruct that you only segment those points that are listed in the indices array instead of the whole point cloud.

这几行代码仅仅是作为个例子。你可以随意评论或修改。
由于`pcl::RegionGrowing`派生自`pcl::PCLBase`，所以它可以使用索引。
这意味着你可以只分割那些在索引数组中列出的点而不是整个点云。

```cpp
pcl::RegionGrowing<pcl::PointXYZ, pcl::Normal> reg;
reg.setMinClusterSize(50);
reg.setMaxClusterSize(1000000);
```

You have finally reached the part where `pcl::RegionGrowing` is instantiated. It is a template class that has two parameters:

PointT - type of points to use(in the given example it is pcl::PointXYZ)
NormalT - type of normals to use(in the given example it is pcl::Normal)

终于讲到了`pcl::RegionGrowing`初始化的部分。
`pcl::RegionGrowing`是一个有两个参数的模板类：

1. PointT：所使用的点的类型（在这个例子里是`pcl::PointXYZ`）
2. NormalT：所使用的法线的类型（在这个例子里是`pcl::Normal`）

After that minimum and maximum cluster sizes are set. It means that after the segmentation is done all clusters that have less points than minimum(or have more than maximum) will be discarded. The default values for minimum and maximum are 1 and ‘as much as possible’ respectively.

设置最小和最大聚类的大小意味着分割结束后，所有少于最小点数的聚类或者大于最大点数的聚类都将被舍弃。
最小和最大值的默认值分别是1和“尽可能多”。

```cpp
reg.setSearchMethod (tree);
reg.setNumberOfNeighbours (30);
reg.setInputCloud (cloud);
//reg.setIndices (indices);
reg.setInputNormals (normals);
```

The algorithm needs K nearest search in its internal structure, so here is the place where a search method is provided and number of neighbours is set. After that it receives the cloud that must be segmented, point indices and normals.

由于这个算法在它的内部结构里是需要K近邻搜索的，所以这个地方需要提供搜索方法和设置近邻点的数量。
在此之后，它才能接收到分割所必须的点云、点索引和法线。

```cpp
reg.setSmoothnessThreshold (3.0 / 180.0 * M_PI);
reg.setCurvatureThreshold (1.0);
```

These two lines are the most important part in the algorithm initialization, because they are responsible for the mentioned smoothness constraint. First method sets the angle in radians that will be used as the allowable range for the normals deviation. If the deviation between points normals is less than the smoothness threshold then they are suggested to be in the same cluster (new point - the tested one - will be added to the cluster). The second one is responsible for the curvature threshold. If two points have a small normals deviation then the disparity between their curvatures is tested. And if this value is less than the curvature threshold then the algorithm will continue the growth of the cluster using the newly added point.

这两行是算法初始化中最重要的部分，因为它们负责上述的平滑约束。

//to be continued
