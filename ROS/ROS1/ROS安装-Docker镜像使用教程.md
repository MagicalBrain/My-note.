# ROS安装-Docker镜像使用教程

## 下载Docker

详见Docker部分的笔记

## 拉取官方镜像

（以`ros:melodic`为例）：

在终端运行命令

```bash
docker pull ros:melodic
```

## 使用镜像启动容器

### macos

```bash
docker run --name MyROS \
--mount type=bind,source=/Users/hrl/Docker_filesystem,target=/root/ros_workspaces \
-itd -p 6080:6080 -p 7777:7777 -p 9111:9111 -p 1314:1314 -p 1222:1222 \
library/ros:melodic
```

### win10

```bash
docker run --name MyROS --mount type=bind,source=/C/hrl/docker-filesystem,target=/root/catkin_ws -itd -p 6080:80 -p 7777:7777 -p 9111:9111 -p 1314:1314 -p 1222:1222 library/ros:melodic
```

## 使用bash（类vim）访问容器

```bash
docker exec -it MyROS /bin/bash
```

## 使用vscode访问容器

https://code.visualstudio.com/docs/remote/containers

### 参考链接

https://zhuanlan.zhihu.com/p/152330470
