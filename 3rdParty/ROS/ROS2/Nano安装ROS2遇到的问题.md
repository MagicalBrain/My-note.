# Nano安装ROS2遇到的问题

## 安装ros报错

### ubuntu版本不对导致的问题

报错信息：

```bash
sudo apt install ros-humble-desktop

# 报错：
E: Unable to locate package ros-humble-desktop
```

解决方法：
安装对应版本的ros2即可。

### 问题

ubuntu18.04 安装ros-

```bash
sudo apt install ros-eloquent-desktop

# 报错：
Errors were encountered while processing:
 nvidia-l4t-bootloader
 nvidia-l4t-xusb-firmware
 nvidia-l4t-initrd
E: Sub-process /usr/bin/dpkg returned an error code (1)
```

这个问题可能是由于info文件夹太大导致的

解决方法：

```bash
cd /var/lib/dpkg
sudo mv info info.bak
sudo mkdir info
sudo apt-get upgrade
```

其实就是把原来的info文件夹备份然后删除，再重新新建一个info文件夹

重新运行一下命令即可：

```bash
sudo apt install ros-eloquent-desktop
```
