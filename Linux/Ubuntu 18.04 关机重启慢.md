# Ubuntu 18.04 关机重启慢

## 问题描述

其实就是关机或者重启的时候出现：

```bash
a stop job is running for daily apt upgrade ...(1 min 30 sec)
```

**解决办法**：
很简单就是设置默认时间：

```bash
vim /etc/systemd/system.conf
```

然后在文件找到并修改：

```bash
DefaultTimeoutStartSec=10s
DefaultTimeoutStopSec=10s
```
