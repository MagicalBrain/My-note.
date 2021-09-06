# pcl点云中常见的可视化函数

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
