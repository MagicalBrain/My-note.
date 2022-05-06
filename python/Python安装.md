# Python安装

## win10

如果是安装了WSL的话，那么就和Ubuntu Linux没啥区别了。

## Linux

以Ubuntu为例

----

不过一般Ubuntu自带python2和python3，所以我就不装了

## Docker

这个首先就得下载并安装Docker

然后直接拉官方的python的image

```bash
docker pull python
```

## 安装pip

安装完python后，还需要安装pip来下载python的包比较方便。

### 为python2安装pip

```bash
sudo apt install python-pip
```

### 为python3安装pip

```bash
sudo apt install python3-pip
```
