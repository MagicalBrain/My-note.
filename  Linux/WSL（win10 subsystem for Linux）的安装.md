# WSL（win10 subsystem for Linux）的安装

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

4、下载Linux内核组件
到官网下载 wsl_update_x64.msi

其他常用组件的安装：
1、安装Windows terminal并将其设置为默认启动WSL
2、安装gcc
3、安装 oh-my-zsh

1、安装Windows terminal并将其设置为默认启动WSL

2、安装gcc

sudo apt update
sudo apt install build-essential
sudo apt install make （可选）

3、安装 oh-my-zsh
查看我知乎 计算机收藏