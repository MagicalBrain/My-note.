# Docker的安装

## windows

直接到官网下载二进制.exe文件

注意：

这玩意需要安装==WSL2==

## macOS

直接到官网下载二进制.dmg文件

## Linux

### 下载库版本

```bash
sudo apt install docker.io
sudo systemctl start docker
sudo systemctl enable docker
```

查看是否安装成功:

```bash
docker -v
```

如果显示如下，就是安装成功了：

```bash
Docker version 20.10.7, build 20.10.7-0ubuntu1~18.04.2
```

但是安装成功不代表能用，还要配置镜像源，否则会报错：

```bash
Got permission denied while trying to connect to the Docker daemon socket at unix:///var/run/docker.sock: Get http://%2Fvar%2Frun%2Fdocker.sock/v1.24/images/json: dial unix /var/run/docker.sock: connect: permission denied
```

### 下载最新版

https://blog.csdn.net/LuffysMan/article/details/89393965

### 配置镜像源


