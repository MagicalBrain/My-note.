# 02-Redis的配置

Redis 的配置文件位于 Redis 安装目录下，文件名为 redis.conf(Windows 名为 redis.windows.conf)。

你可以通过 CONFIG 命令查看或设置配置项。

## redis的config命令

首先运行 redis-cli

然后执行：

```bash
CONFIG GET [CONFIG_SETTING_NAME]
```

其中 CONFIG_SETTING_NAME 就是你要获取的配置名称

如果不知道redis的配置名称，则可以使用 * 号获取所有的配置

```bash
CONFIG GET *
```

### CONFIG GET 获取配置信息

### CONFIG SET 设置配置信息

其实还可以直接编辑 redis.conf 文件来设置配置

## 参考链接

https://www.runoob.com/redis/redis-conf.html
