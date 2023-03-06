# ROS2点云（PCL）订阅发布问题

https://blog.csdn.net/qq_27865227/article/details/125002311

## 直接从 sensor_msg 中获取点位信息

### cpp

我自己的代码：

```cpp
void SingleCamera::pointcloud_sub_callback(sensor_msgs::msg::PointCloud2::SharedPtr msg) {
    RCLCPP_INFO_STREAM(this->get_logger(), "pointcloud sub start");
    
    sensor_msgs::PointCloud2Iterator<float> iter_x(*msg, "x");
    sensor_msgs::PointCloud2Iterator<float> iter_y(*msg, "y");
    sensor_msgs::PointCloud2Iterator<float> iter_z(*msg, "z");
    
    int pc_size = msg->width * msg->height;
    for (size_t i = 0; i < pc_size; i++, ++iter_x, ++iter_y, ++iter_z)
    {
        std::cout << "point " << i << " is: (" 
            << *iter_x << ", " << *iter_y << ", " << *iter_z << ")\n";
    }
    
}
```

获取到的点位信息（以米为单位的）

```bash
point 875516 is: (0.797129, 0.477234, 1.286)
point 875517 is: (0.798541, 0.477234, 1.286)
point 875518 is: (0.799954, 0.477234, 1.286)
point 875519 is: (0.802612, 0.477976, 1.288)
point 875520 is: (0.804027, 0.477976, 1.288)
point 875521 is: (0.805441, 0.477976, 1.288)
point 875522 is: (0.806855, 0.477976, 1.288)
point 875523 is: (0.80827, 0.477976, 1.288)
point 875524 is: (0.809684, 0.477976, 1.288)
point 875525 is: (0.812988, 0.479089, 1.291)
point 875526 is: (0.814406, 0.479089, 1.291)
point 875527 is: (0.817087, 0.479831, 1.293)
point 875528 is: (0.818507, 0.479831, 1.293)
point 875529 is: (0.819927, 0.479831, 1.293)
point 875530 is: (0.821347, 0.479831, 1.293)
point 875531 is: (0.824676, 0.480945, 1.296)
point 875532 is: (0.826099, 0.480945, 1.296)
point 875533 is: (0.827522, 0.480945, 1.296)
point 875534 is: (0.830225, 0.481687, 1.298)
point 875535 is: (0.830369, 0.480945, 1.296)
point 875536 is: (0.831792, 0.480945, 1.296)
point 875537 is: (0.833215, 0.480945, 1.296)
point 875538 is: (0.835927, 0.481687, 1.298)
point 875539 is: (0.837352, 0.481687, 1.298)
```

转换为毫米：

```cpp

```

由于没有什么好的文档，我就直接从ros2的源码里的测试代码里看

```cpp
// this file is originally ported from ROS1:
// https://github.com/ros/common_msgs/blob/4148d041bae4f284819b980ff50577344147cd5b/sensor_msgs/test/main.cpp

#include <gtest/gtest.h>

#include <vector>

#include "sensor_msgs/msg/point_cloud2.hpp"
#include "sensor_msgs/point_cloud2_iterator.hpp"

TEST(sensor_msgs, PointCloud2Iterator)
{
  // Create a dummy PointCloud2
  size_t n_points = 4;
  sensor_msgs::msg::PointCloud2 cloud_msg_1, cloud_msg_2;
  cloud_msg_1.height = static_cast<uint32_t>(n_points);
  cloud_msg_1.width = 1;
  sensor_msgs::PointCloud2Modifier modifier(cloud_msg_1);
  modifier.setPointCloud2FieldsByString(2, "xyz", "rgb");
  cloud_msg_2 = cloud_msg_1;

  // Fill 1 by hand
  float point_data_raw[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0};
  std::vector<float> point_data(point_data_raw, point_data_raw + 3 * n_points);
  // colors in RGB order
  uint8_t color_data_raw[] = {40, 80, 120, 160, 200, 240, 20, 40, 60, 80, 100, 120};
  std::vector<uint8_t> color_data(color_data_raw, color_data_raw + 3 * n_points);

  float * data = reinterpret_cast<float *>(&cloud_msg_1.data.front());
  for (size_t n = 0, i = 0; n < n_points; ++n) {
    for (; i < 3 * (n + 1); ++i) {
      *(data++) = point_data[i];
    }
    // Add an extra float of padding
    ++data;
    uint8_t * bgr = reinterpret_cast<uint8_t *>(data++);
    // add the colors in order BGRA like PCL
    size_t j_max = 2;
    for (size_t j = 0; j <= j_max; ++j) {
      *(bgr++) = color_data[3 * n + (j_max - j)];
    }
    // Add 3 extra floats of padding
    data += 3;
  }

  // Fill 2 using an iterator
  sensor_msgs::PointCloud2Iterator<float> iter_x(cloud_msg_2, "x");
  sensor_msgs::PointCloud2Iterator<uint8_t> iter_r(cloud_msg_2, "r");
  sensor_msgs::PointCloud2Iterator<uint8_t> iter_g(cloud_msg_2, "g");
  sensor_msgs::PointCloud2Iterator<uint8_t> iter_b(cloud_msg_2, "b");
  for (size_t i = 0; i < n_points; ++i, ++iter_x, ++iter_r, ++iter_g, ++iter_b) {
    for (size_t j = 0; j < 3; ++j) {
      iter_x[j] = point_data[j + 3 * i];
    }
    *iter_r = color_data[3 * i];
    *iter_g = color_data[3 * i + 1];
    *iter_b = color_data[3 * i + 2];
  }


  // Check the values using an iterator
  sensor_msgs::PointCloud2ConstIterator<float> iter_const_1_x(cloud_msg_1, "x"), iter_const_2_x(
    cloud_msg_2, "x");
  sensor_msgs::PointCloud2ConstIterator<float> iter_const_1_y(cloud_msg_1, "y"), iter_const_2_y(
    cloud_msg_2, "y");
  sensor_msgs::PointCloud2ConstIterator<float> iter_const_1_z(cloud_msg_1, "z"), iter_const_2_z(
    cloud_msg_2, "z");
  sensor_msgs::PointCloud2ConstIterator<uint8_t> iter_const_1_r(cloud_msg_1, "r"), iter_const_2_r(
    cloud_msg_2, "r");
  sensor_msgs::PointCloud2ConstIterator<uint8_t> iter_const_1_g(cloud_msg_1, "g"), iter_const_2_g(
    cloud_msg_2, "g");
  sensor_msgs::PointCloud2ConstIterator<uint8_t> iter_const_1_b(cloud_msg_1, "b"), iter_const_2_b(
    cloud_msg_2, "b");

  size_t i = 0;
  for (; iter_const_1_x != iter_const_1_x.end();
    ++i, ++iter_const_1_x, ++iter_const_2_x, ++iter_const_1_y, ++iter_const_2_y,
    ++iter_const_1_z, ++iter_const_2_z, ++iter_const_1_r, ++iter_const_1_g, ++iter_const_1_b)
  {
    EXPECT_EQ(*iter_const_1_x, *iter_const_2_x);
    EXPECT_EQ(*iter_const_1_x, point_data[0 + 3 * i]);
    EXPECT_EQ(*iter_const_1_y, *iter_const_2_y);
    EXPECT_EQ(*iter_const_1_y, point_data[1 + 3 * i]);
    EXPECT_EQ(*iter_const_1_z, *iter_const_2_z);
    EXPECT_EQ(*iter_const_1_z, point_data[2 + 3 * i]);
    EXPECT_EQ(*iter_const_1_r, *iter_const_2_r);
    EXPECT_EQ(*iter_const_1_r, color_data[3 * i + 0]);
    EXPECT_EQ(*iter_const_1_g, *iter_const_2_g);
    EXPECT_EQ(*iter_const_1_g, color_data[3 * i + 1]);
    EXPECT_EQ(*iter_const_1_b, *iter_const_2_b);
    EXPECT_EQ(*iter_const_1_b, color_data[3 * i + 2]);
    // This is to test the different operators
    ++iter_const_2_r;
    iter_const_2_g += 1;
    iter_const_2_b = iter_const_2_b + 1;
  }
  EXPECT_EQ(i, n_points);
}
```

### python

这个是用python写的，cpp应该也有类似的接口可以用

```python
#! /usr/bin/env python

from sensor_msgs.msg import PointCloud2
from sensor_msgs import point_cloud2
import rospy
import time

def callback_pointcloud(data):
    assert isinstance(data, PointCloud2)
    gen = point_cloud2.read_points(data, field_names=("x", "y", "z"), skip_nans=True)
    time.sleep(1)
    print type(gen)
    for p in gen:
      print " x : %.3f  y: %.3f  z: %.3f" %(p[0],p[1],p[2])

def main():
    rospy.init_node('pcl_listener', anonymous=True)
    rospy.Subscriber('/my_camera/depth/points', PointCloud2, callback_pointcloud)
    rospy.spin()

if __name__ == "__main__":
    main()

```

https://blog.csdn.net/SJTUzhou/article/details/85308805
