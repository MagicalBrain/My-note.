# ROS2如何Publish-PointCloud

## 源码

### c++

[参考链接-github](https://github.com/lucasw/imgui_ros/tree/crystal/imgui_ros)
[参考链接-ros论坛](https://answers.ros.org/question/312587/generate-and-publish-pointcloud2-in-ros2/)

这个人自己写了个框架，然后再弄个ros2功能包调用。

```cpp
/*
 * Copyright (c) 2019 Lucas Walter
 * October 2019
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Willow Garage, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <chrono>
// this brings in a boost system dependency,
// will get undefined reference to `boost::system::generic_category()
#include <pcl_conversions/pcl_conversions.h>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
using namespace std::chrono_literals;


class GeneratePointCloud2 : public rclcpp::Node
{
public:
  GeneratePointCloud2() : Node("generate_point_cloud2")
  {
    get_parameter_or("num_lat", num_lat_, num_lat_);
    set_parameter_if_not_set("num_lat", num_lat_);
    get_parameter_or("num_long", num_long_, num_long_);
    set_parameter_if_not_set("num_long", num_long_);

    get_parameter_or("frame_id", frame_id_, frame_id_);
    set_parameter_if_not_set("frame_id", frame_id_);

    generatePointCloud2();

    pub_ = create_publisher<sensor_msgs::msg::PointCloud2>("point_cloud");
    timer_ = this->create_wall_timer(1000ms,
        std::bind(&GeneratePointCloud2::update, this));
  }

  ~GeneratePointCloud2()
  {
  }
private:
  void generatePointCloud2()
  {
    // TODO(lucasw) generate a cube or sphere instead, more interesting than 2di
    const float radius = 1.0;
    for (int i = 0; i < num_lat_; ++i) {
      const float fr_lat = static_cast<float>(i) / static_cast<float>(num_lat_);
      const float phi = (fr_lat - 0.5) * M_PI;
      for (int j = 0; j < num_long_; ++j) {
        const float fr_long = static_cast<float>(j) / static_cast<float>(num_long_);
        const float theta = fr_long * M_PI * 2.0;

        // TODO(lucasw) normals
        pcl::PointXYZRGB pt;
        pt = pcl::PointXYZRGB(50 + fr_lat * 205, 255 - fr_long * 100, 255);
        pt.x = radius * cos(phi) * cos(theta);
        pt.y = radius * cos(phi) * sin(theta);
        pt.z = radius * sin(phi);

#if 1
        const uint8_t& pixel_r = 255 * fr_lat;
        const uint8_t& pixel_g = 255 * (1.0 - fr_long);
        const uint8_t& pixel_b = 255;
        // Define point color
        uint32_t rgb = (static_cast<uint32_t>(pixel_r) << 16
            | static_cast<uint32_t>(pixel_g) << 8
            | static_cast<uint32_t>(pixel_b));
        pt.rgb = *reinterpret_cast<float*>(&rgb);
#endif
        cloud_.points.push_back(pt);
      }
    }

    pc2_msg_ = std::make_shared<sensor_msgs::msg::PointCloud2>();
    pcl::toROSMsg(cloud_, *pc2_msg_);

    // TEMP test
#if 1
    {
      pcl::PointCloud<pcl::PointXYZRGB> cloud2;
      pcl::fromROSMsg(*pc2_msg_, cloud2);
      std::cout << cloud2.points.size() << "\n";
    }
#endif

    pc2_msg_->header.frame_id = frame_id_;
  }

  void update()
  {
    if (!pc2_msg_) {
      return;
    }

    // TODO(lucasw) regenerate if num_points has changed

    pc2_msg_->header.stamp = now();

    pub_->publish(pc2_msg_);
  }

  int num_lat_ = 36;
  int num_long_ = 36;
  std::string frame_id_ = "map";

  pcl::PointCloud<pcl::PointXYZRGB> cloud_;
  sensor_msgs::msg::PointCloud2::SharedPtr pc2_msg_;

  rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr pub_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);

  // Force flush of the stdout buffer.
  // This ensures a correct sync of all prints
  // even when executed simultaneously within a launch file.
  setvbuf(stdout, NULL, _IONBF, BUFSIZ);
  rclcpp::spin(std::make_shared<GeneratePointCloud2>());
  rclcpp::shutdown();
  return 0;
}
```

#### pcl::PointCloud<pcl::PointXYZRGB> 转 sensor_msgs::msg::PointCloud2

```cpp
pcl::PointCloud<pcl::PointXYZRGB> cloud_;
sensor_msgs::msg::PointCloud2::SharedPtr pc2_msg_;

pc2_msg_ = std::make_shared<sensor_msgs::msg::PointCloud2>();
pcl::toROSMsg(cloud_, *pc2_msg_);
```

### python

[参考链接](https://www.guyuehome.com/38880)

只不过这个用的是激光雷达的数据

分析：

```python
from sensor_msgs.msg import PointCloud2 as PCL2
from sensor_msgs.msg import PointField
from sensor_msgs_py import point_cloud2    # for creating point cloud

self._publisher = self.create_publisher(PCL2, 'pointcloud2', 10)
```

```python
import numpy as np

import rclpy
from rclpy.node import Node
from std_msgs.msg import Header
from sensor_msgs.msg import PointCloud2 as PCL2
from sensor_msgs.msg import PointField
from sensor_msgs_py import point_cloud2    # for creating point cloud
from .pylvx import *     # a single python script file for parse livox file in same directory

class PointCloudToPCL2(Node):
    def __init__(self):
        super().__init__('livox_pointcloud_publisher')
        lvx_file_path = \
            '/home/wangjg/datasets/livox_pointcloud_data/Horizon_poincloud_data.lvx'
        self.frames = []
        frames = []
        self.frame_index = 0
        index = 0
        timer_period = 0.1
        lf = LvxFile(lvx_file_path)
        duration = lf.private_header_block.frame_duration
        for frame in lf.point_data_block:
            frames.append(frame)
            if (index + 1) % int(timer_period * 1000 / duration) == 0:
                self.frames.append(frames)
                frames = []
            index += 1
        self.frames_number = len(self.frames)
        print('Number of Frames: %d'%self.frames_number)
 
        self._publisher = self.create_publisher(PCL2, 'pointcloud2', 10)
        self.timer = self.create_timer(timer_period, self.publish_pcl2)

    def publish_pcl2(self):
        """Callback to publish"""
        frames = self.frames[self.frame_index]
        points = read_points_from_lvxfile(frames)    # call the function defined after
        header = Header()
        header.frame_id = 'livox'
        header.stamp = self.get_clock().now().to_msg()
        fields = [
            PointField(name='x', offset=0, datatype=PointField.FLOAT32, count=1),
            PointField(name='y', offset=4, datatype=PointField.FLOAT32, count=1),
            PointField(name='z', offset=8, datatype=PointField.FLOAT32, count=1),
            PointField(name='intensity', offset=12, datatype=PointField.FLOAT32, count=1)    # must be 'intensity', noted by kenny wang
        ]    # the fourth field must be 'intensity' for color visualization in rviz2
        pcl2_msg = point_cloud2.create_cloud(header, fields, points)
        self._publisher.publish(pcl2_msg)    # publish the pointcloud messages
        self.get_logger().info("point cloud data published %d " % self.frame_index)
        self.frame_index += 1
        if self.frame_index == self.frames_number:    # for loop publishing purpose
            self.get_logger().info("no more velodyne points to publish. Loop again !")
            self.frame_index = 0

def read_points_from_lvxfile(frames):    # function definition to read points from *.lvx file
    points = []
    data_type = None
    for frame in frames:
        for package in frame.packages:
            package: Package
            if data_type is None and package.data_type != DataType.IMU_INFO:
                data_type = package.data_type
            for point in package.points:
                if package.data_type == data_type:
                    if data_type == DataType.CARTESIAN_MID or \
                        data_type == DataType.CARTESIAN_SINGLE:    # for single return
                        fields = 'x y z reflectivity'.split(' ')
                        values = [getattr(point, field) for field in fields]
                        pt = livox_pointcloud_mm2m(values)
                        points.append(np.array(pt))
                    elif data_type == DataType.CARTESIAN_DOUBLE:    # for double return
                        fields = 'x y z reflectivity'.split(' ')
                        values = [getattr(point, field + '1') for field in fields]
                        pt = livox_pointcloud_mm2m(values)
                        points.append(np.array(pt))
                        fields = 'x y z reflectivity'.split(' ')
                        values = [getattr(point, field + '2') for field in fields]
                        pt = livox_pointcloud_mm2m(values)
                        points.append(np.array(pt))
                    else:
                       return
    if data_type not in [DataType.CARTESIAN_MID, DataType.CARTESIAN_SINGLE, \
        DataType.CARTESIAN_DOUBLE]:
        print(data_type)
        return
    return points

def livox_pointcloud_mm2m(values):    # function to transform coordinate unit from mm to m
    pt = [0,0,0,0]
    pt[0] = values[0]/1000.
    pt[1] = values[1]/1000.
    pt[2] = values[2]/1000.
    pt[3] = values[3]/1.
    return pt

def main(args=None):
    rclpy.init(args=args)
    point_cloud_to_pcl2 = PointCloudToPCL2()
    try:
        rclpy.spin(point_cloud_to_pcl2)
    except KeyboardInterrupt:
        point_cloud_to_pcl2.get_logger().info("User Keyboard interrupt, exit !")
    # destroy node explicity
    point_cloud_to_pcl2.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
```
