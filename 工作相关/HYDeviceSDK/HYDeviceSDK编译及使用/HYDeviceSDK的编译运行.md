# HYDeviceSDK的编译运行

[toc]

# 依赖库的安装

HYDeviceSDK的依赖库有：
1. opencv4.4.0
2. grpc 1.38
3. websocketpp 0.82
4. vtk 9.0
5. flann 1.9
6. pcl 1.11
7. boost 1.74.0

@import "../../../OpenCV学习/OpenCV的安装和配置(Linux).md"


@import "../../../gRPC/gRPC的安装(Linux).md"


@import "../../../C++/websocketpp/websocketpp的安装（Linux）.md"

# vtk 

下载`VTK-9.0.1.tar.gz`文件到本地

运行以下命令安装

```bash
cd VTK-9.0.1
mkdir build && cd build
cmake .. CMAKE_BUILD_TYPE=Release CMAKE_INSTALL_PREFIX =/usr/local
```


# flann

推荐使用`apt-get`安装

```bash
sudo apt-get install libflann1.9 libflann-dev
```

@import "../../../pcl/pcl库的安装(Linux).md"



@import "../../../C++/boost/boost库的安装(Linux).md"

# HYDeviceSDK的安装

依赖库都安装好后，就可以开始安装HYDviceSDK了，运行以下命令：

```bash
tar -zxvf hydevicesdk-1.0.0.tar.gz
cd hydevicesdk-1.0.0
./build.sh
```

## 运行示例程序

```bash
cd hydevicesdk-1.0.0/HYDeviceDemo
mkdir build && cd build
cmake .. && make -j
./HYDeviceDemo
```

运行输出：

![](asset/Screenshot%20from%202021-07-09%2015-24-27.png)
