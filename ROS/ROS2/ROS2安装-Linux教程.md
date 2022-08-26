# ROS2安装-Linux教程

[toc]

## ROS2版本支持的系统

在下载安装ros2支持我们需要知道ros2支持的系统版本是不是我们目前正在使用的版本

[官方文档对ROS2各版本支持的系统列表](https://www.ros.org/reps/rep-2000.html#foxy-fitzroy-may-2020-may-2023)

[Ubuntu18.04安装ROS2](https://blog.csdn.net/fanshuaifang/article/details/114399792?spm=1001.2101.3001.6650.10&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-10-114399792-blog-122810537.t0_searchtargeting_v1&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-10-114399792-blog-122810537.t0_searchtargeting_v1&utm_relevant_index=17)

## 安装方式 

ROS提供两种方式安装，一是二进制安装，（二进制又分为 Debian packages 和 "fat" archive两种方式），二是源码安装。这里采用二进制方式安装（Debian packages）

## 安装步骤

* 1、设置软件源 
```bash
sudo apt update
sudo apt install curl gnupg2 lsb-release
```

```bash
sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
```

如果允许的时候报错：

```bash
url: (7) Failed to connect to raw.githubusercontent.com port 443 after 8 ms: Connection refused
```

上面的指令运行不了的解决方案：
1. 修改hosts



 然后添加至系统软件源列表 
 
```bash
 echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(lsb_release -cs) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null
```

* 2、安装ROS2 

```bash
sudo apt update 

# 注意这里的ros版本
sudo apt install ros-foxy-desktop 
```

推荐安装desktop，当然也可以选择安装base版本

`sudo apt install ros-foxy-desktop`这条指令可能会出问题，报错：

```bash
E: Unable to locate package ros-humble-desktop
```

这个问题就是安装的ros2版本和ubuntu的版本不对应导致的



* 3、环境设置 安装完成后 

```bash
# 仅在当前终端中生效
source /opt/ros/humble/setup.bash
# 终端窗口永久生效，其实就是以后每次打开新的终端，都会自动执行以上命令
echo " source /opt/ros/humble/setup.bash" >> ~/.bashrc
```

