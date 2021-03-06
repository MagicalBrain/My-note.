# WSL（win10 subsystem for Linux）的安装

## 安装WSL1

1、确保系统内核版本号满足要求

系统内核号 大于等于1941

版本号大于等于2004

2、BIOS打开了虚拟化功能

华硕主板：
进BIOS按键 F2，在高级选项那里将virtual调成enable，最后按F10保存退出，会自动重启电脑

Thinkpad

3、下载WSL相关的组件
用管理员权限打开powershell，运行以下代码：
```bash
dism.exe /online /enable-feature /featurename:Microsoft-Windows-Subsystem-Linux /all /norestart
```

**注意**
如果只是想装WSL1，到这一步就可以了，重启电脑下载商店的Ubuntu安装即可使用WSL。

4、下载Linux内核组件
到官网下载 wsl_update_x64.msi

其他常用组件的安装：
1、安装Windows terminal并将其设置为默认启动WSL（如果找不到，重启以下terminal即可）
2、安装gcc
3、安装 oh-my-zsh

1、安装Windows terminal并将其设置为默认启动WSL

2、安装gcc

sudo apt update
sudo apt install build-essential
sudo apt install make （可选）

3、安装 oh-my-zsh

先安装zsh：

```bash
sudo apt update
sudo apt install git zsh -y
```

再安装oh-my-zsh:

```bash
sh -c "$(curl -fsSL https://gitee.com/shmhlsy/oh-my-zsh-install.sh/raw/master/install.sh)"
```

接下来按提示走即可。

## 将WSL1 升级到WSL2

其实有了前面的WSL的一系列的设置，如果系统正常的话，直接输入一下命令即可升级。

```bash
wsl --set-version [Linux分发版本] 2
```

例如我是将Ubuntu 18.04升级到wsl2：

```bash
wsl --set-version Ubuntu-18.04 2
```

### 可能会遇到的问题

上面的命令运行后可能会有报错：
```bash
由于未安装所需的组件，安装已终止
```

这时需要我们看一下win10系统功能里的Hyper-V：

https://zhuanlan.zhihu.com/p/356397851

装好Hyper-V之后，别忘了在`services.msc`里启用`Hyper-V主机计算服务`

https://blog.csdn.net/qq_36191272/article/details/119191992

## 流程参考链接

https://zhuanlan.zhihu.com/p/273237897
