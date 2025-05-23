# Bash补全功能

Bash是大多数Linux发行版默认的shell

## 安装 补全功能

Debian/Ubuntu 系统：

```bash
sudo apt-get install bash-completion
```

CentOS/RHEL 系统：

```bash
sudo yum install bash-completion
```

## 启动

```bash
vim ~/.bashrc
```

添加：

```bash
if [ -f /etc/bash_completion ]; then
    . /etc/bash_completion
fi
```

这个一般默认都安装了
如果是git 命令没有补全请参考笔记

## 参考

https://zhuanlan.zhihu.com/p/620027385#:~:text=Linux%20%E5%91%BD%E4%BB%A4%E8%A1%8C%E8%87%AA%E5%8A%A8%E8%A1%A5%E5%85%A8%20%E6%98%AF%E6%8C%87%E5%9C%A8%E8%BE%93%E5%85%A5%E5%91%BD%E4%BB%A4%E6%88%96%E8%B7%AF%E5%BE%84%E6%97%B6%EF%BC%8C%E9%80%9A%E8%BF%87%E6%8C%89%E4%B8%8B%20Tab%20%E9%94%AE%E8%87%AA%E5%8A%A8%E5%8C%B9%E9%85%8D%E5%B9%B6%E8%A1%A5%E5%85%A8%E5%91%BD%E4%BB%A4%E6%88%96%E8%B7%AF%E5%BE%84%E7%9A%84%E5%8A%9F%E8%83%BD%E3%80%82%20%E8%BF%99%E6%98%AF%20Linux%20%E5%91%BD%E4%BB%A4%E8%A1%8C%E4%B8%AD%E9%9D%9E%E5%B8%B8%E5%AE%9E%E7%94%A8%E7%9A%84%E5%8A%9F%E8%83%BD%E4%B9%8B%E4%B8%80%EF%BC%8C%E5%8F%AF%E4%BB%A5%E8%8A%82%E7%9C%81%E5%A4%A7%E9%87%8F%E6%97%B6%E9%97%B4%E5%92%8C%E5%87%8F%E5%B0%91%E8%BE%93%E5%85%A5%E9%94%99%E8%AF%AF%E3%80%82,%E6%98%AF%E9%BB%98%E8%AE%A4%E7%9A%84%20shell%20%E7%A8%8B%E5%BA%8F%EF%BC%8C%E5%9B%A0%E6%AD%A4%E4%BB%A5%E4%B8%8B%E4%BB%8B%E7%BB%8D%E5%A6%82%E4%BD%95%E5%9C%A8%20Bash%20%E4%B8%AD%E5%90%AF%E7%94%A8%E5%91%BD%E4%BB%A4%E8%A1%8C%E8%87%AA%E5%8A%A8%E8%A1%A5%E5%85%A8%EF%BC%9A%20%E5%AE%89%E8%A3%85%20Bash%20%E8%87%AA%E5%8A%A8%E8%A1%A5%E5%85%A8%E6%8F%92%E4%BB%B6%E3%80%82
