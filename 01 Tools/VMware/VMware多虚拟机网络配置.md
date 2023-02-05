# VMware多虚拟机网络配置

配置目标：
1. 虚拟机能够ping通主机（既然能够ping同主机，那么主机所在局域网的其他设备也能够ping通）
2. 虚拟机之间能够ping通

## 设置主机网络共享

## VMware虚拟机网络设置NAT

## 重启虚拟机

不行就重启网卡：

```bash
sudo nmcli networking off
sudo nmcli networking on
```
