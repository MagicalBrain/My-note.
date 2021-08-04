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

1、an entire point cloud dataset, given via setInputCloud (PointCloudConstPtr &) - mandatory

Any feature estimation class will attempt to estimate a feature at every point in the given input cloud.

2、a subset of a point cloud dataset, given via setInputCloud (PointCloudConstPtr &) and setIndices (IndicesConstPtr &) - optional

Any feature estimation class will attempt to estimate a feature at every point in the given input cloud that has an index in the given indices list. By default, if no set of indices is given, all points in the cloud will be considered.*

一个完整的点云数据集，通过setInputCloud (PointCloudConstPtr &)给出——必选

任何特征估计类都将尝试估计给定输入云中的每个点上的特征。

点云数据集的子集，通过setInputCloud (PointCloudConstPtr &)和setIndices (IndicesConstPtr &)给出——可选

任何特征估计类都将尝试在给定的索引列表中具有索引的给定输入云中的每个点上估计一个特征。默认情况下，如果没有给出索引集，将考虑云中的所有点。*
