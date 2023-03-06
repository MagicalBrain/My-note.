# ROS2点云（PCL）订阅发布问题

https://blog.csdn.net/qq_27865227/article/details/125002311

## 直接从 sensor_msg 中获取点位信息

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
