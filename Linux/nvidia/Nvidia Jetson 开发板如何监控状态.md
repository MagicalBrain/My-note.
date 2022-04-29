# Nvidia Jetson 开发板如何监控状态

推荐使用jtop

## jtop

### 安装

```bash
sudo -H pip install -U jetson-stats
```

可能没有安装pip，先安装pip[^pip_install]

### 使用

直接：

```bash
jtop
```

即可

如下图：

![]()

## 参考链接

[jtop的使用](https://blog.csdn.net/weixin_41010198/article/details/109804101)

[pip的安装](https://ywnz.com/linuxjc/3316.html#:~:text=Ubuntu%2018.04%20%E9%BB%98%E8%AE%A4%E5%AE%89%E8%A3%85%E4%BA%86%20Python%202%20%E5%92%8C%20Python%203%E3%80%82,%E6%B3%A8%E6%84%8F%EF%BC%9A%E5%9C%A8%E6%9C%AC%E6%96%87%E4%B8%AD%E4%BD%BF%E7%94%A8%E7%9A%84%E6%98%AF%20Ubuntu%2018.04%20%E7%89%88%E6%9C%AC%E3%80%82%20%E4%BD%86%E6%98%AF%E5%AE%83%E5%BA%94%E8%AF%A5%E9%80%82%E7%94%A8%E4%BA%8E%E5%85%B6%E4%BB%96%E7%89%88%E6%9C%AC%EF%BC%8C%E5%A6%82%20Ubuntu%2016.04%E3%80%8118.10%20%E7%89%88%E6%9C%AC%E7%AD%89%E3%80%82)

[^pip_install]: 请参考链接
