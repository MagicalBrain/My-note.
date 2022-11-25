# 如何给Linux虚拟机配置ssh

这里以Ubuntu为例

![](asset/vmware-ssh.png)

然后配置好用户名就可以了

但Ubuntu一开始有的是预装了`openssh-client`，而没有装`openssh-server`

这个时候运行以下命令即可安装：

```bash
sudo apt-get install openssh-server
```
