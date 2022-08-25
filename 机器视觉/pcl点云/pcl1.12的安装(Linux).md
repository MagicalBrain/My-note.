# pcl1.12的安装(Linux)

## 先安装依赖

```bash
sudo apt-get update
sudo apt-get install libboost-all-dev
sudo apt-get install libflann-dev
sudo apt-get install libusb-1.0-0-dev 
sudo apt-get install libopenni-dev libopenni2-dev 		#可选 用于kinect等io
sudo apt-get install libqhull*     	#可选，用于pcl_surface
CUDA    	#可选，GPU加速（如需请参考cuda官方安装示例）

```

## 安装vtk

```bash
sudo apt-get install cmake-curses-gui
sudo apt-get install freeglut3-dev

```

打开[VTK官方网址](http://www.vtk.org/download/)

下拉找到VTK-8.2.0.zip下载
下载，解压后进入VTK-8.2.0文件夹，执行：

```bash
mkdir build && cd build
sudo cmake ..
sudo make
sudo make install
```

## 现在开始安装PCL 1.12

下载：pcl1.12源码（sourse.zip）
解压并进入pcl-pcl-1.12.0文件夹

```bash
mkdir build && cd build
sudo cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo ..
sudo make
sudo make install

```
