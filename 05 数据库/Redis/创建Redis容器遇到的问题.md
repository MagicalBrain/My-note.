# 创建Redis容器遇到的问题

## macOS

由于我是在用户文件夹下创建文件的：

```bash
docker run -p 6379:6379 --name redis-hrl \
-v /Users/hrl/redis/data:data \
/Users/hrl/redis/conf/redis.conf:/etc/redis/redis.conf \
-d redis redis-server /etc/redis/redis.conf
```

报错：

```bash
docker: invalid reference format: repository name (/Users/hrl/redis/conf/redis.conf) must be lowercase
```

修改后：

```bash
docker run -p 6379:6379 --name redis-hrl \
-v /Users/hrl/redis/data:data \
-v /Users/hrl/redis/conf/redis.conf:/etc/redis/redis.conf \
-d redis redis-server /etc/redis/redis.conf
```

报错：

```bash
docker: Error response from daemon: invalid volume specification: '/host_mnt/Users/hrl/redis/data:data': invalid mount config for type "bind": invalid mount path: 'data' mount path must be absolute
```

原因，输入错误，正确的输入：

```bash
docker run -p 6379:6379 --name redis-hrl \
-v /Users/hrl/redis/data:/data \
-v /Users/hrl/redis/conf/redis.conf:/etc/redis/redis.conf \
-d redis redis-server /etc/redis/redis.conf
```

<!-- ```bash
docker run -p 6379:6379 --name redis \
-v /mydata/redis/data:/data \
-v /mydata/redis/conf/redis.conf:/etc/redis/redis.conf \
-d redis redis-server /etc/redis/redis.conf
``` -->
