# ROS2安装-Linux教程

[toc]

## 安装方式 

ROS提供两种方式安装，一是二进制安装，（二进制又分为 Debian packages 和 "fat" archive两种方式），二是源码安装。这里采用二进制方式安装（Debian packages）

## 安装步骤

1、设置软件源 
```bash
sudo apt update && sudo apt install curl gnupg2 lsb-release
```

```bash
sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
```

```bash
sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key  -o /usr/share/keyrings/ros-archive-keyring.gpg

```

[**可能有用的参考链接**](https://blog.csdn.net/tfb760/article/details/119601032)

 然后添加至系统软件源列表 
 
 ```bash
 echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(lsb_release -cs) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null
```

4）安装ROS2 

```bash
sudo apt update sudo apt install ros-foxy-desktop 
```

推荐安装desktop，当然也可以选择安装base版本

5）环境设置 安装完成后 

```bash
echo “source /opt/ros/foxy/setup.bash” >> ~/.bashrc
```

