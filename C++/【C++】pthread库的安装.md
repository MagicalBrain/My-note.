# pthread库的安装

pthread是一个linux系统上的多进程库，本来应该是自带的，但我想在WSL2上的Ubuntu 20.04用，仍然需要自己安装

## 安装命令

```
sudo apt-get install glibc-doc
```

有些命令安装不全，还需：

```
sudo apt-get install manpages-posix manpages-posix-dev
```

[参考链接][参考链接]

[参考链接]:https://blog.csdn.net/n_fly/article/details/88601197
