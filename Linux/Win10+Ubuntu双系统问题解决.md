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

### 参考链接

https://zhuanlan.zhihu.com/p/149192081

