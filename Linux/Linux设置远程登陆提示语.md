# Linux设置远程登陆提示

主要是几个文件，我一般就在以下两个文件里设置。

## /etc/motd

## /etc/issue

https://blog.csdn.net/hunanchenxingyu/article/details/45293199

## 查看修改结果

这个方法不用注销登录

```
sudo run-parts /etc/update-motd.d
```
