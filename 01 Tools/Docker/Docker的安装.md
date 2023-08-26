# Docker的安装

## windows

直接到官网下载二进制.exe文件

注意：

这玩意需要安装==WSL2==

## macOS

直接到官网下载二进制.dmg文件

## Linux

如果之前安装过docker则需要先[卸载](#卸载docker)

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

----

下载依赖：

```bash
apt update
apt-get install ca-certificates curl gnupg lsb-release
```

通过阿里的源安装证书：

```bash
curl -fsSL http://mirrors.aliyun.com/docker-ce/linux/ubuntu/gpg | sudo apt-key add -
```

写入源信息：

```bash
add-apt-repository "deb [arch=amd64] http://mirrors.aliyun.com/docker-ce/linux/ubuntu $(lsb_release -cs) stable"
```

安装最新版本：

```bash
sudo apt-get install -y docker-ce
#或：
sudo apt-get install docker-ce docker-ce-cli containerd.io
```

[csdn博客](https://blog.csdn.net/qq_53217531/article/details/127646728#:~:text=%E6%96%87%E7%AB%A0%E7%9B%AE%E5%BD%95%20Ubuntu22.04%E4%B8%8B%E5%AE%89%E8%A3%85Docker%201%E3%80%81%E5%85%88%E5%8D%B8%E8%BD%BD%E6%97%A7%E7%89%88%E3%80%82%202%E3%80%81%E5%AE%89%E8%A3%85%E4%BE%9D%E8%B5%96%E3%80%82,3%E3%80%81%E9%80%9A%E8%BF%87%E9%98%BF%E9%87%8C%E7%9A%84%E6%BA%90%E5%AE%89%E8%A3%85%E8%AF%81%E4%B9%A6%E3%80%82%204%E3%80%81%E5%86%99%E5%85%A5%E6%BA%90%E4%BF%A1%E6%81%AF%E3%80%82%205%E3%80%81%E5%AE%89%E8%A3%85%E6%96%B0%E7%89%88%E6%9C%AC%E3%80%82%206%E3%80%81%E5%90%AF%E5%8A%A8docker%E3%80%82)

### 配置镜像源

### 卸载docker

```bash
apt-get remove docker docker-engine docker.io containerd runc
```
