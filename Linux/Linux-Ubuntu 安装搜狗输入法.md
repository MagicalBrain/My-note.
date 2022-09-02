# Linux-Ubuntu 安装搜狗输入法

## 下载输入法

先去官网下载搜狗中文输入法的deb包

## Ubuntu 18.04

首先先确认有没有安装fctix，如果没有就需要安装fcitx：

```bash
sudo apt-get install fcitx-bin
sudo apt-get install fcitx-table
```

然后打开语言设置，添加Chinese Simplified

然后apply

重启电脑

安装搜狗输入法：

```bash
sudo dpkg -i [path souguo]
```

如果按照后输入中文只显示`suogou`的一个半透明的弹窗而没有中文字选项;
按官方指导，说明还需要按照依赖：

```bash

```
