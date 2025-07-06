# 01 redis的安装

## docker 安装

强烈推荐

### 拉取docker redis镜像

```bash
docker pull redis
```

### 在docker外部创建配置文件

其实就是在物理机上创建配置文件，后面会创建文件链接，方便修改配置。
修改配置的时候就不用再进去容器里面了

```bash
mkdir -p /mydata/redis/conf
touch /mydata/redis/conf/redis.conf
```

### 创建Redis容器

```bash
docker run -p 6379:6379 --name redis \
-v /mydata/redis/data:/data \
-v /mydata/redis/conf/redis.conf:/etc/redis/redis.conf \
-d redis redis-server /etc/redis/redis.conf
```

----

注意：这里创建文件映射的物理机是linux系统，如果是windows或者macOS呢？

### 启动Redis

```bash
docker exec -it redis redis-cli
```

### 数据持久化存储

修改外部配置文件

```bash
vim redis.conf
```

输入：

```bash
appendonly yes
```

在容器内部验证配置文件是否修改，修改成功后以后都可以直接在外部进行修改配置了

```bash
docker exec -it [redis_docker_id_or_name] /bin/bash
```

```bash
cat redis.conf
```

----

参考链接

https://developer.aliyun.com/article/1589420#:~:text=%E7%AE%80%E4%BB%8B%EF%BC%9A%20%E8%BF%99%E7%AF%87%E6%96%87%E7%AB%A0%E8%AF%A6%E7%BB%86%E4%BB%8B%E7%BB%8D%E4%BA%86%E5%A6%82%E4%BD%95%E5%9C%A8Linux%E7%B3%BB%E7%BB%9F%E4%B8%AD%E4%BD%BF%E7%94%A8Docker%E5%AE%89%E8%A3%85Redis%EF%BC%8C%E5%B9%B6%E6%8F%90%E4%BE%9B%E4%BA%86%E4%BD%BF%E7%94%A8%E5%8F%AF%E8%A7%86%E5%8C%96%E5%B7%A5%E5%85%B7%E8%BF%9E%E6%8E%A5Redis%E7%9A%84%E6%AD%A5%E9%AA%A4%E3%80%82,%E5%86%85%E5%AE%B9%E5%8C%85%E6%8B%AC%E5%AE%89%E8%A3%85Redis%E9%95%9C%E5%83%8F%E3%80%81%E5%88%9B%E5%BB%BA%E5%A4%96%E9%83%A8%E9%85%8D%E7%BD%AE%E6%96%87%E4%BB%B6%E3%80%81%E6%98%A0%E5%B0%84%E6%96%87%E4%BB%B6%E5%92%8C%E7%AB%AF%E5%8F%A3%E3%80%81%E5%90%AF%E5%8A%A8%E5%92%8C%E6%B5%8B%E8%AF%95Redis%E5%AE%9E%E4%BE%8B%E3%80%81%E9%85%8D%E7%BD%AE%E6%95%B0%E6%8D%AE%E6%8C%81%E4%B9%85%E5%8C%96%E5%AD%98%E5%82%A8%EF%BC%8C%E4%BB%A5%E5%8F%8A%E4%BD%BF%E7%94%A8%E5%8F%AF%E8%A7%86%E5%8C%96%E5%B7%A5%E5%85%B7%E8%BF%9E%E6%8E%A5%E5%92%8C%E6%93%8D%E4%BD%9CRedis%E6%95%B0%E6%8D%AE%E5%BA%93%E7%9A%84%E8%BF%87%E7%A8%8B%E3%80%82%20%E5%9C%A8windows%E4%B8%8A%E5%AE%89%E8%A3%85%E8%BF%87reids%E3%80%81%E5%9C%A8linux%E4%B8%8A%E4%B9%9F%E5%AE%89%E8%A3%85%E8%BF%87redis%EF%BC%8C%E4%BD%86%E6%98%AF%E9%83%BD%E6%B2%A1%E6%9C%89docker%E4%B8%8A%E5%AE%89%E8%A3%85redis%E6%96%B9%E4%BE%BF%E3%80%82

## Ubuntu

### apt安装

```bash
sudo apt update
sudo apt install redis-server
```

### 源码安装

## 验证安装

### 1 启动 Redis

```bash
redis-server
```

### 2 查看 redis 是否启动？

```bash
redis-cli
```

以上命令将打开以下终端：

```bash
redis 127.0.0.1:6379>
```

127.0.0.1 是本机 IP ，6379 是 redis 服务端口。现在我们输入 PING 命令。

```bash
redis 127.0.0.1:6379> ping
PONG
```

![alt text](image.png)

## Windows


