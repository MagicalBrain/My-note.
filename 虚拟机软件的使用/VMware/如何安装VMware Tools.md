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

## VMware Tool 使用问题

如果使用虚拟机的时候，用着用着突然发现无法复制和粘贴了

解决办法：
1. 重新安装open-vm-tools
2. 方法1不行就关掉虚拟机，然后将虚拟机所在的根目录重新命名一下再打开

例如，虚拟机原先安装的目录为：`./Ubuntu18-local`，修改为：`./Ubuntu18-22-11-18`，有时这样就能解决问题
