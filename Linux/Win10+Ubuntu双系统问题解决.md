# Win10+Ubuntu双系统问题解决

## 时间不一致问题

### 问题表现

Ubuntu 时间对， Win10时间不对。

### 问题原因

Ubuntu和Win10计算时间的方式不同：

### 解决方案

现在Ubuntu上运行命令：

```bash
# 更新ubuntu的系统时间
sudo apt-get update
sudo apt-get install ntpdate
sudo ntpdate time.windows.com
# 将时间更新到硬件上
sudo hwclock --localtime --systohc
```

重启进Win10后时间正常了。

但为了让Win10和Ubuntu两边的时间都正常同步，还得在Win10里运行（管理员权限）：

```bash
Reg add HKLM\SYSTEM\CurrentControlSet\Control\TimeZoneInformation /v RealTimeIsUniversal /t REG_DWORD /d 1
```

### sudo apt-get install ntpdate 遇到问题

```bash
E: 无法获得锁 /var/lib/dpkg/lock-frontend - open (11: 资源暂时不可用)
E: 无法获取 dpkg 前端锁 (/var/lib/dpkg/lock-frontend)，是否有其他进程正占用它？
```

输入命令检查是否有之前的进程占用了`apt-get`：

```bash
ps -e|grep apt-get
```

如果有进程占用了，则记住ID，用kill杀死进程：

```bash
sudo kill [ID]
```

不幸的事，我的电脑并没有进程占用`apt-get`

那就试试——强制解锁：

```bash
sudo rm /var/cache/apt/archives/lock
sudo rm /var/lib/dpkg/lock
```

### 重启Ubuntu进Win10卡住

一直卡在关机的页面，还显示文字：

```bash
Unattended-upgrade in progress during ……
```

原来不是卡住而是得等，得等半个小时啊

### 参考链接

https://zhuanlan.zhihu.com/p/149192081

