# 如何在Linux系统上将不同编码的文件转换为uft-8

## 使用iconv命令

如果没有则可以直接使用
```bash
sudo apt install libiconv
```
安装

## 查看文件编码

```
file -i filename
```

**注意**：
有时候该命令查到的编码不是真正的编码，因为已经在别的平台上修改过。

## 将ISO-8859-1编码的文件转换为utf-8

```bash
iconv -f iso-8859-1 -t UTF-8 HYSensorClient.h > HYSensorClient.txt
# 或者
iconv -f iso-8859-1 -t UTF-8 HYSensorClient.h -o HYSensorClient.txt
```

讲道理，这两种用法应该是一样的，但不知为何只能用第一种，指定输出文件只能用`>`

**注意**：
如果`-f`后面的编码不是文件原来的编码那么转换要么失败，要么就还是乱码。

参考链接：
https://stackoverflow.com/questions/48688283/iconv-inside-for-loop-cant-find-output-directory
