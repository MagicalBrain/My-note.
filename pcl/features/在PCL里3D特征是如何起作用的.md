# How 3D Features work in PCL

## 理论基础 Theoretical primer

In their native representation, points as defined in the concept of 3D mapping systems are simply represented using their Cartesian coordinates x, y, z, with respect to a given origin. Assuming that the origin of the coordinate system does not change over time, there could be two points p1 and p2 , acquired at t1 and t2 , having the same coordinates. Comparing these points however is an ill-posed problem, because even though they are equal with respect to some distance measure (e.g. Euclidean metric), they could be sampled on completely different surfaces, and thus represent totally different information when taken together with the other surrounding points in their vicinity. That is because there are no guarantees that the world has not changed between t1 and t2. Some acquisition devices might provide extra information for a sampled point, such as an intensity or surface remission value, or even a color, however that does not solve the problem completely and the comparison remains ambiguous.

在它们的原生表示中，3D映射系统概念中定义的点可以简单地使用相对于给定原点的笛卡尔坐标x, y, z来表示。假设坐标系的原点不随时间变化，可以有两个点p1和p2，在t1和t2处，坐标相同。
然而，比较这些点是一个病态问题，因为即使它们相对于某些距离测量(如欧几里得度量)是相等的，它们可能在完全不同的表面上被采样，因此，当它们与周围的其他点一起被采集时，代表完全不同的信息。

ill-posed problem 即病态问题：在数学上结果不唯一的问题称之为 病态问题（简单理解为不唯一问题也行）。

这是因为不能保证世界在t1和t2之间没有变化。有些采集设备可能会为采样点提供额外的信息，如强度或表面缓解值，甚至颜色，但这并不能完全解决问题，比较仍然模糊不清。

Applications which need to compare points for various reasons require better characteristics and metrics to be able to distinguish between geometric surfaces. The concept of a 3D point as a singular entity with Cartesian coordinates therefore disappears, and a new concept, that of local descriptor takes its place. 
The literature is abundant of different naming schemes describing the same conceptualization, such as shape descriptors or geometric features but for the remaining of this document they will be referred to as point feature representations.

由于各种原因需要比较点的应用需要更好的特征和度量来区分几何表面。
因此，三维点作为一个具有笛卡尔坐标的单一实体的概念消失了，取而代之的是一个新的概念，即局部描述符。
文献中有大量描述相同概念的不同命名方案，如形状描述符或几何特征，但在本文的其余部分，它们将被称为点特征表示。

…

By including the surrounding neighbors, the underlying sampled surface geometry can be inferred and captured in the feature formulation, which contributes to solving the ambiguity comparison problem. Ideally, the resultant features would be very similar (with respect to some metric) for points residing on the same or similar surfaces, and different for points found on different surfaces, as shown in the figure below. A good point feature representation distinguishes itself from a bad one, by being able to capture the same local surface characteristics in the presence of:

通过包含周围的邻近点，可以推断和捕获采样曲面隐含的几何特征，这有助于解决模糊度比较问题。
理想情况下，对于位于相同或相似表面上的点，合成特征将非常相似(就某些度量而言)，而对于位于不同表面上的点，合成特征将不同，如下图所示。一个好的点特征表示与一个不好的点特征表示的区别在于，它能够在以下情况下捕获相同的局部表面特征:

**rigid transformations** - that is, 3D rotations and 3D translations in the data should not influence the resultant feature vector F estimation;
**varying sampling density** - in principle, a local surface patch sampled more or less densely should have the same feature vector signature;
**noise** - the point feature representation must retain the same or very similar values in its feature vector in the presence of mild noise in the data.

**刚性转换**——即数据中的3D旋转和3D平移不应影响最终的特征向量F估计;
**多种的采样密度**——原则上，采样密度无论多少，其局部表面patch应该具有相同的特征向量特征;
**噪声**-在数据中存在轻微噪声时，点特征表示必须在其特征向量中保持相同或非常相似的值。

In general, PCL features use approximate methods to compute the nearest neighbors of a query point, using fast kd-tree queries. There are two types of queries that we’re interested in:

通常，PCL特性使用近似方法计算查询点的最近邻，使用快速kd-tree查询。我们主要对一下两种查询（遍历）方式感兴趣:

1. 确定一个查询点的k(用户给定的参数)邻居(也称为k-search);
2. 确定一个查询点在半径为r的球面内的所有邻居(也称为半径搜索)。

**注意**：
For a discussion on what the right k or r values should be, please see [RusuDissertation].
关于正确的k或r值应该是什么，请参见[RusuDissertation]。

## 术语 Terminology

For the remainder of this article, we will make certain abbreviations and introduce certain notations, to simplify the in-text explanations. Please see the table below for a reference on each of the terms used.

在本文的其余部分，我们将使用某些缩写，并引入某些符号，以简化文本中的解释。请参阅下表，以参考每一个使用的术语。

## 如何传递输入 How to pass the input

As almost all classes in PCL that inherit from the base pcl::PCLBase class, the pcl::Feature class accepts input data in two different ways:

就像PCL中几乎所有继承自基类PCL::PCLBase的类一样，PCL::Feature类以两种不同的方式接受输入数据:

1、an entire point cloud dataset, given via `setInputCloud (PointCloudConstPtr &)` - mandatory

Any feature estimation class will attempt to estimate a feature at every point in the given input cloud.

2、a subset of a point cloud dataset, given via `setInputCloud (PointCloudConstPtr &)` and `setIndices (IndicesConstPtr &)` - optional

Any feature estimation class will attempt to estimate a feature at every point in the given input cloud that has an index in the given indices list. By default, if no set of indices is given, all points in the cloud will be considered.*

1、一个完整的点云数据集，通过`setInputCloud (PointCloudConstPtr &)`给出——必选

任何特征估计类都将尝试估计给定输入云中的每个点上的特征。

2、点云数据集的子集，通过`setInputCloud (PointCloudConstPtr &)`和`setIndices (IndicesConstPtr &)`给出——可选

任何特征估计类都将尝试在给定的索引列表中具有索引的给定输入云中的每个点上估计一个特征。默认情况下，如果没有给出索引集，将考虑点云中所有的点。*

In addition, the set of point neighbors to be used, can be specified through an additional call, `setSearchSurface (PointCloudConstPtr &)`. This call is optional, and when the search surface is not given, the input point cloud dataset is used instead by default.

此外，要使用的点邻居集可以通过附加调用`setSearchSurface (PointCloudConstPtr &)`指定。这个调用是可选的，当搜索面没有给出时，默认情况下使用输入点云数据集。

Because `setInputCloud()` is always required, there are up to four combinations that we can create using `<setInputCloud(), setIndices(), setSearchSurface()>`. Say we have two point clouds, $P={p_1, p_2, …p_n}$ and $Q={q_1, q_2, …, q_n}$. The image below presents all four cases:

因为`setInputCloud()`总是必需的，所以我们最多可以使用`<setinputcloud()， setindices(), setsearchsurface()>`创建四种组合。说我们有两个点云,P = {p_1、p_2…p_n}和Q = {q_1, q_2,…,q_n}。下图展示了所有四种情况:



1、`setIndices() = false, setSearchSurface() = false` - this is without a doubt the most used case in PCL, where the user is just feeding in a single PointCloud dataset and expects a certain feature estimated at all the points in the cloud.

1、`setIndices() = false, setSearchSurface() = false` -这无疑是PCL中最常用的情况，在这种情况下，用户只是输入一个PointCloud数据集，并期望在云中的所有点上估计某个特性。

Since we do not expect to maintain different implementation copies based on whether a set of indices and/or the search surface is given, whenever indices = false, PCL creates a set of internal indices (as a std::vector<int>) that basically point to the entire dataset (indices=1..N, where N is the number of points in the cloud).

由于我们不希望基于是否给定了一组索引和/或搜索面来维护不同的实现副本，每当indices= false时，PCL创建一组内部索引(作为std::vector<int>)，基本上指向整个数据集(indices=1..)。</int>N，其中N是云中的点数)。

In the figure above, this corresponds to the leftmost case. First, we estimate the nearest neighbors of p_1, then the nearest neighbors of p_2, and so on, until we exhaust all the points in P.

在上图中，这对应于最左边的情况。首先，我们估计p_1的最近邻居，然后是p_2的最近邻居，以此类推，直到穷尽P中的所有点。

2、`setIndices() = true, setSearchSurface() = false` - as previously mentioned, the feature estimation method will only compute features for those points which have an index in the given indices vector;

In the figure above, this corresponds to the second case. Here, we assume that p_2’s index is not part of the indices vector given, so no neighbors or features will be estimated at p2.

2、`setIndices() = true, setSearchSurface() = false` -如前所述，特征估计方法只会计算那些在给定索引向量中有索引的点的特征;

在上图中，这对应于第二种情况。在这里，我们假设$p_2$的索引不是给定索引向量的一部分，所以在$p_2$处不会估计邻居或特征。

`setIndices() = false, setSearchSurface() = true` - as in the first case, features will be estimated for all points given as input, but, the underlying neighboring surface given in setSearchSurface() will be used to obtain nearest neighbors for the input points, rather than the input cloud itself;

In the figure above, this corresponds to the third case. If Q={q_1, q_2} is another cloud given as input, different than P, and P is the search surface for Q, then the neighbors of q_1 and q_2 will be computed from P.

3、`setIndices() = false, setSearchSurface() = true`——就像在第一种情况下,特征将成为所有点估计作为输入,但底层邻近表面在setSearchSurface()将被用来获取最近的邻居的输入点,而不是输入点云本身;

在上图中，这对应于第三种情况。如果$Q={q_1, q_2}$是另一个作为输入的点云，与P不同，P是Q的搜索面，那么$q_1$和$q_2$的邻域将从P处计算。

`setIndices() = true, setSearchSurface() = true` - this is probably the rarest case, where both indices and a search surface is given. In this case, features will be estimated for only a subset from the <input, indices> pair, using the search surface information given in setSearchSurface().

Finally, in the figure above, this corresponds to the last (rightmost) case. Here, we assume that q_2’s index is not part of the indices vector given for Q, so no neighbors or features will be estimated at q2.

4、`setIndices() = true, setSearchSurface() = true`——这可能是最罕见的情况，在这种情况下，索引和搜索面都给出了。在这种情况下，使用setSearchSurface()中给出的搜索面信息，仅对`<input, indices>`对中的一个子集估计特性。

最后，在上图中，这对应于最后(最右边)的情况。在这里，我们假设q_2的指标不是Q给定的指标向量的一部分，所以q2没有邻居或特征被估计。

The most useful example when setSearchSurface() should be used, is when we have a very dense input dataset, but we do not want to estimate features at all the points in it, but rather at some keypoints discovered using the methods in pcl_keypoints, or at a downsampled version of the cloud (e.g., obtained using a pcl::VoxelGrid<T> filter). In this case, we pass the downsampled/keypoints input via setInputCloud(), and the original data as setSearchSurface().

`setSearchSurface()`最应该使用的地方在于,当我们有一个非常密集的输入数据集,但我们不想估计所有点的特征,而是在被发现的一些关键点,或者是在降采样后的点云中使用该方法处理pcl_keypoints(例如,使用pcl: VoxelGrid < T >过滤器进行处理)。
在本例中，我们让downsampling /关键点作为输入，通过setInputCloud()传递，作为setSearchSurface()的原始数据。

## 一个法线估计的例子 An example for normal estimation

Once determined, the neighboring points of a query point can be used to estimate a local feature representation that captures the geometry of the underlying sampled surface around the query point. An important problem in describing the geometry of the surface is to first infer its orientation in a coordinate system, that is, estimate its normal. Surface normals are important properties of a surface and are heavily used in many areas such as computer graphics applications to apply the correct light sources that generate shadings and other visual effects (See [RusuDissertation] for more information).

一旦确定，就可以使用查询点的邻近点来估计局部特征表示，该特征表示捕获了查询点周围的基础采样曲面的几何形状。描述曲面几何的一个重要问题是首先推断它在坐标系中的方向，即估计它的法线。表面法线是表面的重要属性，在许多领域被大量使用，如计算机图形应用程序，以应用正确的光源，生成阴影和其他视觉效果(参见[RusuDissertation]获取更多信息)。

The following code snippet will estimate a set of surface normals for all the points in the input dataset.

下面的代码片段将估计输入数据集中所有点的表面法线集。

```cpp
#include <pcl/point_types.h>
#include <pcl/features/normal_3d.h>

{
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);

  ... read, pass in or create a point cloud ...

  // Create the normal estimation class, and pass the input dataset to it
  pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> ne;
  ne.setInputCloud (cloud);

  // Create an empty kdtree representation, and pass it to the normal estimation object.
  // Its content will be filled inside the object, based on the given input dataset (as no other search surface is given).
  pcl::search::KdTree<pcl::PointXYZ>::Ptr tree (new pcl::search::KdTree<pcl::PointXYZ> ());
  ne.setSearchMethod (tree);

  // Output datasets
  pcl::PointCloud<pcl::Normal>::Ptr cloud_normals (new pcl::PointCloud<pcl::Normal>);

  // Use all neighbors in a sphere of radius 3cm
  ne.setRadiusSearch (0.03);

  // Compute the features
  ne.compute (*cloud_normals);

  // cloud_normals->size () should have the same size as the input cloud->size ()
}
```
