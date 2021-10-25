# ROS安装-Windows教程

## hhp写的部分（存在问题）

打开这个控制台：x64 Native Tools Command Prompt for VS 2019

一、安装ROS(ROS自带moveit，不用再额外安装)
1、安装教程用这个：http://wiki.ros.org/Installation/Windows    
然后直接从 4 开始，跳过123步  /* 注意c++那些组件*/ 

2、注意版本要对应，meiodic和noetic两个版本看着装，我装的是meiodic

二、装好ROS后为 MoveIt 教程创建工作区


1、按步骤输入下面命令：
:: activate ROS environment
c:\opt\ros\melodic\x64\setup.bat

:: checkout MoveIt tutorial packages
mkdir c:\moveit_ws\src
cd c:\moveit_ws\src

/* 这里是从显扬的库下载的*/

git clone https://e.coding.net/hinyeung/ros/moveit_tutorials.git -b melodic-devel
git clone https://e.coding.net/hinyeung/ros/panda_moveit_config.git -b melodic-devel
git clone https://e.coding.net/hinyeung/ros/franka_ros-release.git -b release/kinetic/franka_description

:: build packages
cd c:\moveit_ws
catkin_make

2、构建完成后，激活开发工作区

c:\moveit_ws\devel\setup.bat

3、启动演示

roslaunch  panda_moveit_config 演示。启动 rviz_tutorial : = true

到了这一步，你应该在 RViz 中看到一个空的世界

![](./asset/RViz演示界面.png)

