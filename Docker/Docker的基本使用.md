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

```
docker pull ubuntu:18.04
```

win10和Linux其实也就创建镜像，并用该镜像启动容器有一些差异之外，其它并没有很大差别。

### 查看镜像

```
docker images
```

**注意**：别漏了“s”

### 保存和载入镜像

这个有点像玩游戏的时候，游戏报错和游戏载入。保存是为了将做好的镜像分享复制出去，载入是为了使用别人分享的镜像。

#### 保存镜像

```
docker save filename.tar
```

#### 载入镜像

```
docker load filename.tar
```

## 容器

### 查看容器

```
docker ps
```

### 启动容器

```
docker run -it ubuntu:18.04
```

启动用过的容器
```
docker start ID
docker exec -it ID /bin/bash
# 或
docker exec -it name /bin/bash
```

### 在容器和宿主机之间复制文件

推荐使用`powershell`。

```
docker cp filename1 name:filename2
```

命令类似`scp`
