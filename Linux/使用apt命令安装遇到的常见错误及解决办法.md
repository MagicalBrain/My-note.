# 使用apt命令安装遇到的常见错误及解决办法

## Could not get lock /var/lib/dpkg/lock-frontend

如果使用`sudo apt`及相关命令之后出现如此报错：

```bash
waiting for cache lock: Could not get lock /var/lib/dpkg/lock-frontend.It is held by process 3374
```

## 解决方法

### 方法一

运行一下命令：

```bash
sudo killall apt apt-get
```

如果提示

```bash
apt: no process found
apt-get: no process found
```

那就是没有apt进程，方法失效。

### 方法二

运行命令：

```bash
sudo rm /var/lib/apt/lists/lock
sudo rm /var/cache/apt/archives/lock
sudo rm /var/lib/dpkg/lock*
sudo dpkg --configure -a
sudo apt update
```

然后再运行之前出问题的`sudo apt`命令试试

### 参考连接

https://blog.csdn.net/lun55423/article/details/108907779
https://zhuanlan.zhihu.com/p/126538251
