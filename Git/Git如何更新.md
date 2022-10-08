# Git如何更新

## Windows

简单，直接卸载原来的，安装最新的？

## Ubuntu 18.04

```bash
sudo add-apt-repository ppa:git-core/ppa
# 回车执行
# 有报错可以不管，直接下一步
```

```bash
sudo apt-get install git
```

安装好后

```bash
git --version
# 可以看到 版本号发生了变化
```
