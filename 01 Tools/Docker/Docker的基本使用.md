# Docker的基本使用

## 镜像

先有了系统镜像，才能启动容器。

### 创建镜像

创建镜像有三种方法：
1. 直接从官方库拉取
2. 基于已有的镜像
3. 基于本地模板
4. 基于`Dockerfile`

#### 直接从官方库拉取（最简单）

由于工作上用的是Ubuntu18.04，这里就搞个Ubuntu18.04吧。

```bash
docker pull ubuntu:18.04
```

win10和Linux其实也就创建镜像，并用该镜像启动容器有一些差异之外，其它并没有很大差别。

### 查看镜像

```bash
docker images
```

**注意**：别漏了“s”

### 保存和载入镜像

这个有点像玩游戏的时候，游戏报错和游戏载入。保存是为了将做好的镜像分享复制出去，载入是为了使用别人分享的镜像。

#### 保存镜像

```bash
docker save -o filename.tar
```

#### 载入镜像

```bash
docker load -i filename.tar
```

#### 删除镜像

```bash
docker image rm [id]
```

注意这里保存导入的都是镜像而不是容器，启动后的修改不会保存下来

## 容器

### 创建容器

```bash
# docker create -it ubuntu:16.04

docker create -p 3000:80 --name [name] [image\'s repo]
sudo docker create -p 3000:80 --name dockcross01 dockcross/linux-arm64-lts
```

### 查看容器

创建过容器之后才能查看到容器，否则列表是空的

```bash
docker ps
```

```bash
docker ps -a --no-trunc
```

### 启动容器

一般创建容器之后，容器处于停止的状态，需要start命令来启动：

```bash
docker run -it ubuntu:18.04
```

启动用过的容器

```bash
docker start ID
docker exec -it ID /bin/bash
# 或
docker exec -it name /bin/bash
```

```bash
sudo docker run -it ubuntu:18.04 /bin/bash
```

### 在容器和宿主机之间复制文件

推荐使用`powershell`。

```bash
docker cp filename1 name:filename2
```

命令类似`scp`

### 删除容器

#### 删除制定的容器

```bash
docker rm -f <containerid>
```

#### 删除未启动成功的容器

```bash
docker rm $(docker ps -a|grep Created|awk '{print $1}')
或者
docker rm $(docker ps -qf status=created)
```

#### 删除退出状态的容器

```bash
docker rm $(docker ps -a|grep Exited|awk '{print $1}')
或者
docker rm $(docker ps -qf status=exited)
```

#### 删除所有未运行的容器

```bash
docker rm $(docker ps -a -q) #正在运行的删除不了，所有未运行的都被删除了
或者
docker container prune #Docker 1.13版本以后，可以使用 docker containers prune 命令，删除孤立的容器
```

### 保存容器的修改

```bash
# 使用 docker commit 命令
# 新建一个宿主机terminal 来查看容器id并执行命令
# option:
# -m "[注释，这次保存了？东西]]"
# [容器id]
# [镜像repo名] dockcross/linux-arm64-lts:20221230-9387e59
sudo docker commit -m "install ifconfig" e8355caf2c92 dockcross/linux-arm64-lts:20221230-9387e59
```

### 导出容器

```bash
docker export
```

应该不用`docker commit`也可以导出容器到宿主机

### 容器如何开放端口并绑定

如果没有容器需要先从镜像创建一个：

```bash
docker run -it --name [container_name] -p [主机端口:容器端口] -d [image_name]
```

例如：我用 `golang-hrl-images` 镜像创建一个名为 `golang-ssh` 的容器，并绑定容器的22端口到主机的5678，用来实现ssh登录：

```bash
docker run -it --name golang-ssh -p 5678:22 -d golang-hrl-images
```

如果容器已启动且已经安装了一些东西并修改了文件，那么只能先 `docker commit`将当前容器保存为一个新的镜像，然后从新的镜像创建容器，因为端口开放和绑定貌似只能在容器创建的时候设置:

```bash
# 假设当前已经有了一个名为 golang-ssh 的容器
# commit 信息：save ssh config files
# 然后保存的新镜像为 golang-hrl
docker commit -m "[commit_info]" golang-ssh golang-hrl:latest

# 保存成功后再从新镜像创建名为 golang-web 的容器并绑定端口 5678:22 8888:8080
docker run -it --name golang-web -p 5678:22 -p 8888:8080 -d golang-hrl
```
