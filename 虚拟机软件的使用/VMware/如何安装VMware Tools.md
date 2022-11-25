# 如何安装VMware Tools

## 正常安装

## 手动安装

### 命令行安装

依次运行以下命令：

```bash
sudo apt-get autoremove open-vm-tools
sudo apt-get install open-vm-tools
sudo apt-get install open-vm-tools-desktop
```

上面的安装语句可以合并成下面一条命令
```bash
sudo apt-get install open-vm-tools open-vm-tools-desktop
```

然后重启虚拟机即可
