# Nvidia Driver

## 显卡驱动分类

显卡驱动分为：
1. GRD  游戏驱动
2. SD   ？

一般最好安装游戏驱动，暂时不知道为啥，搞开发应该都行才对。

## 驱动安装

### 关闭Security Boot

现在的新PC都会默认启动这个功能，安装nvidia驱动需要关闭这个功能

### 安装依赖

```bash
sudo apt-get update
sudo apt-get install build-essential make
```

### 禁用默认驱动

```bash
sudo gedit /etc/modprobe.d/blacklist.conf
# or
sudo gedit /etc/modprobe.d/blacklist-nouveau.conf
```

在文件末尾输入：

```bash
blacklist nouveau
options nouveau modeset=0
```

```bash
sudo update-initramfs -u
```

```bash
sudo reboot now
```

```bash
lsmod | grep nouveau
# 如果没有输出说明禁用成功
```

### 进入tty模式

```bash
sudo telinit 3
```

### 开始安装

```bash
cd .
sudo ./NVIDIA... .run
```

Install Nvidia's 32-bit compatibility libraries?

选择 "No"

Would you like to run the nvidia-xconfig utility to automatically update your X configuration file so that the NVIDIA X driver dill be used dhen you restart X? Any pre-existing X configuration file will be backed up.

选择 "Yes"


### 恢复图形界面

```bash
sudo telinit 5
```


### 参考链接

https://blog.csdn.net/huiyoooo/article/details/128015155#:~:text=cd%E8%BF%9B%E5%85%A5%E5%AD%98%E6%94%BE%E9%A9%B1%E5%8A%A8%E6%96%87%E4%BB%B6%E7%9A%84%E7%9B%AE%E5%BD%95%E4%B8%AD%EF%BC%8Cls%E6%9F%A5%E7%9C%8B%E7%9B%AE%E5%BD%95%E4%B8%AD%E7%9A%84%E6%96%87%E4%BB%B6%20%E3%80%82%20%E8%BE%93%E5%85%A5%E4%BB%A5%E4%B8%8B%E5%91%BD%E4%BB%A4%E5%AE%89%E8%A3%85%E3%80%82%20sudo%20chmod%20777%20NVIDIA-Linux-x86_64,-525.53.run%20%23%E7%BB%99%E4%B8%8B%E8%BD%BD%E7%9A%84%E9%A9%B1%E5%8A%A8%E8%B5%8B%E4%BA%88%E5%8F%AF%E6%89%A7%E8%A1%8C%E6%9D%83%E9%99%90%20sudo.%2FNVIDIA-Linux-x86_64%20-525.53.run%20%E2%80%93no-opengl-files%20-no-x-check%20%23%E5%AE%89%E8%A3%85

## 驱动卸载

```bash
sudo apt-get --purge remove "*cublas*" "*cufft*" "*curand*" \
 "*cusolver*" "*cusparse*" "*npp*" "*nvjpeg*" "cuda*" "nsight*" 
```

https://linuxconfig.org/how-to-uninstall-the-nvidia-drivers-on-ubuntu-20-04-focal-fossa-linux
