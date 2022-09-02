# pcl点云中常见的可视化函数

## 添加点云 addPointCloud()

### 用例

```cpp
viewer->addPointCloud<pcl::PointXYZ> (cloud, "sample cloud");
```

我们添加一个点云到viewer里去，并且给它一个id字符串。
这个字符串可以使用其它方法来对点云进行区分。

多次调用这个函数可以添加多个点云，只要每次的点云id不同即可

如果你想要更新已经显示出来的点云，那么更新之前你需要先调用`removePointCloud()`然后再添加点云（id最好不一样）

注意：
1.1 版本以后，可以使用新的方法来更新点云：`updatePointCloud()`这样我们就不用手动调用`removePointCloud()`了。

这个函数一共有14个重载（注意，这是pcl 1.12的不一定适用于pcl 1.8或其它版本的）

### 1 Add a binary blob Point Cloud to screen.

```cpp
bool pcl::visualization::PCLVisualizer::addPointCloud	(	const pcl::PCLPointCloud2::ConstPtr & 	cloud,
  const ColorHandlerConstPtr & 	color_handler,
  const Eigen::Vector4f & 	sensor_origin,
  const Eigen::Quaternion< float > & 	sensor_orientation,
  const std::string & 	id = "cloud",
  int 	viewport = 0 
)		
```

Add a binary blob Point Cloud to screen.

Because the geometry/color handler is given as a pointer, it will be pushed back to the list of available handlers, rather than replacing the current active handler. This makes it possible to switch between different handlers 'on-the-fly' at runtime, from the PCLVisualizer interactor interface (using [Alt+]0..9).

Parameters
[in]	cloud	the input point cloud dataset
[in]	color_handler	a specific PointCloud visualizer handler for colors
[in]	sensor_origin	the origin of the cloud data in global coordinates (defaults to 0,0,0)
[in]	sensor_orientation	the orientation of the cloud data in global coordinates (defaults to 1,0,0,0)
[in]	id	the point cloud object id (default: cloud)
[in]	viewport	the view port where the Point Cloud should be added (default: all)

### 2 

```cpp
bool pcl::visualization::PCLVisualizer::addPointCloud	(	const pcl::PCLPointCloud2::ConstPtr & 	cloud,
  const GeometryHandlerConstPtr & 	geometry_handler,
  const ColorHandlerConstPtr & 	color_handler,
  const Eigen::Vector4f & 	sensor_origin,
  const Eigen::Quaternion< float > & 	sensor_orientation,
  const std::string & 	id = "cloud",
  int 	viewport = 0 
)		
```

Add a binary blob Point Cloud to screen.

Because the geometry/color handler is given as a pointer, it will be pushed back to the list of available handlers, rather than replacing the current active handler. This makes it possible to switch between different handlers 'on-the-fly' at runtime, from the PCLVisualizer interactor interface (using [Alt+]0..9).

Parameters
[in]	cloud	the input point cloud dataset
[in]	geometry_handler	a specific PointCloud visualizer handler for geometry
[in]	color_handler	a specific PointCloud visualizer handler for colors
[in]	sensor_origin	the origin of the cloud data in global coordinates (defaults to 0,0,0)
[in]	sensor_orientation	the orientation of the cloud data in global coordinates (defaults to 1,0,0,0)
[in]	id	the point cloud object id (default: cloud)
[in]	viewport	the view port where the Point Cloud should be added (default: all)

### 3

```cpp
bool pcl::visualization::PCLVisualizer::addPointCloud	(	const pcl::PCLPointCloud2::ConstPtr & 	cloud,
  const GeometryHandlerConstPtr & 	geometry_handler,
  const Eigen::Vector4f & 	sensor_origin,
  const Eigen::Quaternion< float > & 	sensor_orientation,
  const std::string & 	id = "cloud",
  int 	viewport = 0 
)		
```

Add a binary blob Point Cloud to screen.

Because the geometry/color handler is given as a pointer, it will be pushed back to the list of available handlers, rather than replacing the current active handler. This makes it possible to switch between different handlers 'on-the-fly' at runtime, from the PCLVisualizer interactor interface (using [Alt+]0..9).

Parameters
[in]	cloud	the input point cloud dataset
[in]	geometry_handler	a specific PointCloud visualizer handler for geometry
[in]	sensor_origin	the origin of the cloud data in global coordinates (defaults to 0,0,0)
[in]	sensor_orientation	the orientation of the cloud data in global coordinates (defaults to 1,0,0,0)
[in]	id	the point cloud object id (default: cloud)
[in]	viewport	the view port where the Point Cloud should be added (default: all)

### 4

只需要点云类型为`pcl::PointCloud< pcl::PointXYZ >` 的一个 const ptr

```cpp
bool pcl::visualization::PCLVisualizer::addPointCloud	(	const pcl::PointCloud< pcl::PointXYZ >::ConstPtr & 	cloud,
  const std::string & 	id = "cloud",
  int 	viewport = 0 
)	
```

Add a PointXYZ Point Cloud to screen.

Parameters
[in]	cloud	the input point cloud dataset
[in]	id	the point cloud object id (default: cloud)
[in]	viewport	the view port where the Point Cloud should be added (default: all)

Definition at line 871 of file pcl_visualizer.h.

### 5

只需要点云类型为`pcl::PointCloud< pcl::PointXYZL >` 的一个 const ptr

```cpp
bool pcl::visualization::PCLVisualizer::addPointCloud	(	const pcl::PointCloud< pcl::PointXYZL >::ConstPtr & 	cloud,
const std::string & 	id = "cloud",
int 	viewport = 0 
)		
inline
```

Add a PointXYZL Point Cloud to screen.

Parameters
[in]	cloud	the input point cloud dataset
[in]	id	the point cloud object id (default: cloud)
[in]	viewport	the view port where the Point Cloud should be added (default: all)
Definition at line 910 of file pcl_visualizer.h.

### 6

只需要点云类型为`pcl::PointCloud< pcl::PointXYZRGB >` 的一个 const ptr

```cpp
bool pcl::visualization::PCLVisualizer::addPointCloud	(	const pcl::PointCloud< pcl::PointXYZRGB >::ConstPtr & 	cloud,
const std::string & 	id = "cloud",
int 	viewport = 0 
)		
inline
```

Add a PointXYZRGB Point Cloud to screen.

Parameters
[in]	cloud	the input point cloud dataset
[in]	id	the point cloud object id (default: cloud)
[in]	viewport	the view port where the Point Cloud should be added (default: all)

Definition at line 884 of file pcl_visualizer.h.

### 7

```cpp
bool pcl::visualization::PCLVisualizer::addPointCloud	(	const pcl::PointCloud< pcl::PointXYZRGBA >::ConstPtr & 	cloud,
const std::string & 	id = "cloud",
int 	viewport = 0 
)		
inline
```

Add a PointXYZRGBA Point Cloud to screen.

Parameters
[in]	cloud	the input point cloud dataset
[in]	id	the point cloud object id (default: cloud)
[in]	viewport	the view port where the Point Cloud should be added (default: all)

Definition at line 897 of file pcl_visualizer.h.

### 8

```cpp
template<typename PointT >
bool pcl::visualization::PCLVisualizer::addPointCloud	(	const typename pcl::PointCloud< PointT >::ConstPtr & 	cloud,
const ColorHandlerConstPtr & 	color_handler,
const std::string & 	id = "cloud",
int 	viewport = 0 
)		
```

Add a Point Cloud (templated) to screen.

Because the color handler is given as a pointer, it will be pushed back to the list of available handlers, rather than replacing the current active color handler. This makes it possible to switch between different color handlers 'on-the-fly' at runtime, from the PCLVisualizer interactor interface (using 0..9).

Parameters
[in]	cloud	the input point cloud dataset
[in]	color_handler	a specific PointCloud visualizer handler for colors
[in]	id	the point cloud object id (default: cloud)
[in]	viewport	the view port where the Point Cloud should be added (default: all)

Definition at line 153 of file pcl_visualizer.hpp.

References pcl::PointCloud< PointT >::sensor_orientation_, and pcl::PointCloud< PointT >::sensor_origin_.

### 9

```cpp
template<typename PointT >
bool pcl::visualization::PCLVisualizer::addPointCloud	(	const typename pcl::PointCloud< PointT >::ConstPtr & 	cloud,
const GeometryHandlerConstPtr & 	geometry_handler,
const ColorHandlerConstPtr & 	color_handler,
const std::string & 	id = "cloud",
int 	viewport = 0 
)		
```

Add a Point Cloud (templated) to screen.

Because the geometry/color handler is given as a pointer, it will be pushed back to the list of available handlers, rather than replacing the current active handler. This makes it possible to switch between different handlers 'on-the-fly' at runtime, from the PCLVisualizer interactor interface (using [Alt+]0..9).

Parameters
[in]	cloud	the input point cloud dataset
[in]	geometry_handler	a specific PointCloud visualizer handler for geometry
[in]	color_handler	a specific PointCloud visualizer handler for colors
[in]	id	the point cloud object id (default: cloud)
[in]	viewport	the view port where the Point Cloud should be added (default: all)

Definition at line 174 of file pcl_visualizer.hpp.

References pcl::PointCloud< PointT >::sensor_orientation_, and pcl::PointCloud< PointT >::sensor_origin_.

### 10

```cpp
template<typename PointT >
bool pcl::visualization::PCLVisualizer::addPointCloud	(	const typename pcl::PointCloud< PointT >::ConstPtr & 	cloud,
const GeometryHandlerConstPtr & 	geometry_handler,
const std::string & 	id = "cloud",
int 	viewport = 0 
)		
```

Add a Point Cloud (templated) to screen.

Because the geometry handler is given as a pointer, it will be pushed back to the list of available handlers, rather than replacing the current active geometric handler. This makes it possible to switch between different geometric handlers 'on-the-fly' at runtime, from the PCLVisualizer interactor interface (using Alt+0..9).

Parameters
[in]	cloud	the input point cloud dataset
[in]	geometry_handler	use a geometry handler object to extract the XYZ data
[in]	id	the point cloud object id (default: cloud)
[in]	viewport	the view port where the Point Cloud should be added (default: all)

Definition at line 110 of file pcl_visualizer.hpp.

References pcl::PointCloud< PointT >::sensor_orientation_, and pcl::PointCloud< PointT >::sensor_origin_.

### 11

template<typename PointT >
bool pcl::visualization::PCLVisualizer::addPointCloud	(	const typename pcl::PointCloud< PointT >::ConstPtr & 	cloud,
const PointCloudColorHandler< PointT > & 	color_handler,
const PointCloudGeometryHandler< PointT > & 	geometry_handler,
const std::string & 	id = "cloud",
int 	viewport = 0 
)		
Add a Point Cloud (templated) to screen.

Parameters
[in]	cloud	the input point cloud dataset
[in]	color_handler	a specific PointCloud visualizer handler for colors
[in]	geometry_handler	use a geometry handler object to extract the XYZ data
[in]	id	the point cloud object id (default: cloud)
[in]	viewport	the view port where the Point Cloud should be added (default: all)
Definition at line 195 of file pcl_visualizer.hpp.

References pcl::PointCloud< PointT >::sensor_orientation_, and pcl::PointCloud< PointT >::sensor_origin_.

### 12

template<typename PointT >
bool pcl::visualization::PCLVisualizer::addPointCloud	(	const typename pcl::PointCloud< PointT >::ConstPtr & 	cloud,
const PointCloudColorHandler< PointT > & 	color_handler,
const std::string & 	id = "cloud",
int 	viewport = 0 
)		
Add a Point Cloud (templated) to screen.

Parameters
[in]	cloud	the input point cloud dataset
[in]	color_handler	a specific PointCloud visualizer handler for colors
[in]	id	the point cloud object id (default: cloud)
[in]	viewport	the view port where the Point Cloud should be added (default: all)
Definition at line 131 of file pcl_visualizer.hpp.

References pcl::PointCloud< PointT >::sensor_orientation_, and pcl::PointCloud< PointT >::sensor_origin_.

### 13

template<typename PointT >
bool pcl::visualization::PCLVisualizer::addPointCloud	(	const typename pcl::PointCloud< PointT >::ConstPtr & 	cloud,
const PointCloudGeometryHandler< PointT > & 	geometry_handler,
const std::string & 	id = "cloud",
int 	viewport = 0 
)		
Add a Point Cloud (templated) to screen.

Parameters
[in]	cloud	the input point cloud dataset
[in]	geometry_handler	use a geometry handler object to extract the XYZ data
[in]	id	the point cloud object id (default: cloud)
[in]	viewport	the view port where the Point Cloud should be added (default: all)
Definition at line 88 of file pcl_visualizer.hpp.

References pcl::PointCloud< PointT >::sensor_orientation_, and pcl::PointCloud< PointT >::sensor_origin_.

### 14

template<typename PointT >
bool pcl::visualization::PCLVisualizer::addPointCloud	(	const typename pcl::PointCloud< PointT >::ConstPtr & 	cloud,
const std::string & 	id = "cloud",
int 	viewport = 0 
)		
Add a Point Cloud (templated) to screen.

Parameters
[in]	cloud	the input point cloud dataset
[in]	id	the point cloud object id (default: cloud)
viewport	the view port where the Point Cloud should be added (default: all)
Definition at line 77 of file pcl_visualizer.hpp.

## updatePointCloud()

### 用例

```cpp
viewer->updatePointCloud(cloud, "cloud");
```

更新已经显示的点云中id为"cloud"的点云

### 1

## 添加箭头 addArrow()

```cpp
template<typename P1 , typename P2 >
bool pcl::visualization::PCLVisualizer::addArrow(	
    const P1 & 	pt1,
    const P2 & 	pt2,
    double 	r,
    double 	g,
    double 	b,
    bool 	display_length,
    const std::string & 	id = "arrow",
    int 	viewport = 0 
)		
{
  if (contains (id))
  {
    PCL_WARN ("[addArrow] The id <%s> already exists! Please choose a different id and retry.\n", id.c_str ());
    return (false);
  }

  // Create an Actor
  vtkSmartPointer<vtkLeaderActor2D> leader = vtkSmartPointer<vtkLeaderActor2D>::New ();
  leader->GetPositionCoordinate ()->SetCoordinateSystemToWorld ();
  leader->GetPositionCoordinate ()->SetValue (pt1.x, pt1.y, pt1.z);
  leader->GetPosition2Coordinate ()->SetCoordinateSystemToWorld ();
  leader->GetPosition2Coordinate ()->SetValue (pt2.x, pt2.y, pt2.z);
  leader->SetArrowStyleToFilled ();
  leader->SetArrowPlacementToPoint1 ();
  if (display_length)
    leader->AutoLabelOn ();
  else
    leader->AutoLabelOff ();

  leader->GetProperty ()->SetColor (r, g, b);
  addActorToRenderer (leader, viewport);

  // Save the pointer/ID pair to the global actor map
  (*shape_actor_map_)[id] = leader;
  return (true);
}
```

Add a line arrow segment between two points, and (optionally) display the distance between them.

可以选择是否显示箭头的长度

Arrow head is attached on the start point (pt1) of the arrow.

Parameters
[in]	pt1	the first (start) point on the line
[in]	pt2	the second (end) point on the line
[in]	r	the red channel of the color that the line should be rendered with
[in]	g	the green channel of the color that the line should be rendered with
[in]	b	the blue channel of the color that the line should be rendered with
[in]	display_length	true if the length should be displayed on the arrow as text
[in]	id	the line id/name (default: "arrow")
[in]	viewport	(optional) the id of the new viewport (default: 0)
Definition at line 541 of file pcl_visualizer.hpp.

```cpp
template <typename P1, typename P2> 
bool pcl::visualization::PCLVisualizer::addArrow(
    const P1 &pt1, 
    const P2 &pt2, 
    double r, 
    double g, 
    double b, 
    const std::string &id, int viewport
)
{
  if (contains (id))
  {
    PCL_WARN ("[addArrow] The id <%s> already exists! Please choose a different id and retry.\n", id.c_str ());
    return (false);
  }

  // Create an Actor
  vtkSmartPointer<vtkLeaderActor2D> leader = vtkSmartPointer<vtkLeaderActor2D>::New ();
  leader->GetPositionCoordinate ()->SetCoordinateSystemToWorld ();
  leader->GetPositionCoordinate ()->SetValue (pt1.x, pt1.y, pt1.z);
  leader->GetPosition2Coordinate ()->SetCoordinateSystemToWorld ();
  leader->GetPosition2Coordinate ()->SetValue (pt2.x, pt2.y, pt2.z);
  leader->SetArrowStyleToFilled ();
  leader->AutoLabelOn ();

  leader->GetProperty ()->SetColor (r, g, b);
  addActorToRenderer (leader, viewport);

  // Save the pointer/ID pair to the global actor map
  (*shape_actor_map_)[id] = leader;
  return (true);
}
```

Add a line arrow segment between two points, and display the distance between them.

显示箭头的长度

Arrow heads are attached to both end points of the arrow.

Parameters
[in]	pt1	the first (start) point on the line
[in]	pt2	the second (end) point on the line
[in]	r	the red channel of the color that the line should be rendered with
[in]	g	the green channel of the color that the line should be rendered with
[in]	b	the blue channel of the color that the line should be rendered with
[in]	id	the arrow id/name (default: "arrow")
[in]	viewport	(optional) the id of the new viewport (default: 0)

```cpp
template <typename P1, typename P2> 
bool pcl::visualization::PCLVisualizer::addArrow (
    const P1 &pt1, 
    const P2 &pt2,
    double r_line, double g_line, double b_line,
    double r_text, double g_text, double b_text,
    const std::string &id, int viewport)
{
  if (contains (id))
  {
    PCL_WARN ("[addArrow] The id <%s> already exists! Please choose a different id and retry.\n", id.c_str ());
    return (false);
  }

  // Create an Actor
  vtkSmartPointer<vtkLeaderActor2D> leader = vtkSmartPointer<vtkLeaderActor2D>::New ();
  leader->GetPositionCoordinate ()->SetCoordinateSystemToWorld ();
  leader->GetPositionCoordinate ()->SetValue (pt1.x, pt1.y, pt1.z);
  leader->GetPosition2Coordinate ()->SetCoordinateSystemToWorld ();
  leader->GetPosition2Coordinate ()->SetValue (pt2.x, pt2.y, pt2.z);
  leader->SetArrowStyleToFilled ();
  leader->AutoLabelOn ();

  leader->GetLabelTextProperty()->SetColor(r_text, g_text, b_text);
  
  leader->GetProperty ()->SetColor (r_line, g_line, b_line);
  addActorToRenderer (leader, viewport);

  // Save the pointer/ID pair to the global actor map
  (*shape_actor_map_)[id] = leader;
  return (true);
}
```

显示箭头的长度，控制显示长度的颜色

## 添加字符串

### addText()

```cpp

```

```cpp

```

### addText3D()

```cpp
template<typename PointT>
bool pcl::visualization::PCLVisualizer::addText3D(	
    const std::string & 	text,
    const PointT & 	position,
    double 	orientation[3],
    double 	textScale = 1.0,
    double 	r = 1.0,
    double 	g = 1.0,
    double 	b = 1.0,
    const std::string & 	id = "",
    int 	viewport = 0 
)	
```

## setPointCloudRenderingProperties()

## initCameraParameters()

```cpp
void pcl::visualization::PCLVisualizer::initCameraParameters	(		)	
```

Initialize camera parameters with some default values.

## setBackgroundColor()

设置背景颜色

## setCameraPosition()

## removeAllPointClouds()

```cpp
bool pcl::visualization::PCLVisualizer::removeAllPointClouds	(	int 	viewport = 0	)	
```

Remove all point cloud data on screen from the given viewport.

Parameters
[in]	viewport	view port from where the clouds should be removed (default: all)

## removeAllShapes()

```cpp
bool pcl::visualization::PCLVisualizer::removeAllShapes	(	int 	viewport = 0	)	
```

Remove all 3D shape data on screen from the given viewport.

Parameters
[in]	viewport	view port from where the shapes should be removed (default: all)

## 参考链接

[官方api文档](https://pointclouds.org/documentation/index.html)
[官方文档](https://pcl.readthedocs.io/projects/tutorials/en/latest/index.html)
