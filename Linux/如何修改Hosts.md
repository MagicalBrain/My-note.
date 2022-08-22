# 如何修改Hosts

有时候我们下载软件或者依赖，会碰到连接不上下载不了的情况。

这个时候我们就需要修改hosts了

例如`raw.githubusercontent.com`连不上

那我们就需要先去`www.ipaddress.com`这个网站搜一下`raw.githubusercontent.com`

然后就可以拿到这个网站的ip地址，写道hosts里去

```bash
sudo vim /etc/hosts
```

hosts文件内容

```bash
192.128.xx.xx raw.githubusercontent.com
```
