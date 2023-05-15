# Win11安装WSL2

## 安装WSL2

https://zhuanlan.zhihu.com/p/475462241

## 安装WSL2遇到的问题

打开ubuntu20.04时报错：

```bash
WslRegisterDistribution failed with error: 0x800701bc
Error: 0x800701bc WSL 2 ?????????????????? https://aka.ms/wsl2kernel
```

https://blog.csdn.net/microsoft_mos/article/details/123627295

## 启用WSL2图形化显示

```bash
wsl --update
wsl --shutdown
```

然后重新打开ubuntu的终端即可

## 2

```bash
/sbin/ldconfig.real: /usr/lib/wsl/lib/libcuda.so.1 is not a symbolic link
```

wsl更新后需要重新链接库文件
https://blog.csdn.net/u011715038/article/details/113733006

