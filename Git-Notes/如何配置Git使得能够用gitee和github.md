# 如何配置Git使得能够用gitee和github

## windows

搞来搞去太麻烦了

直接win上的git-gui设置为gitee的用户名配置；
WSL搞另外一套github的用户名配置得了。

两个互不干扰，多好。

----

其实很简单，先分别在github和gitee上创建一个仓库，名字最好和本地仓库同名，不同也没关系的。
然后在本地生产密钥，

```bash
ssh-keygen -t rsa -C "xxxxx@xxxxx.com"
```

并分别在github和gitee上添加密钥。

打开git bash，输入命令查看链接到的远程仓库版本：
```bash
git remote -v
```

例如：
```bash
origin  git@gitee.com:CPLASF000000/robotplugin-hrl.git (fetch)
origin  git@gitee.com:CPLASF000000/robotplugin-hrl.git (push)
```

git默认都是origin的，可以修改的，先把原来的remote信息删除：

```bash
git remote rm origin
```

分别添加github和gitee仓库的ssh地址：
```bash
git remote add github [github的ssh地址]
git remote add gitee [gitee的ssh地址]
```

然后push一下：

```bash
git push github main # main是主分支
git push gitee main
```

git pull操作同理

## Linux

同win10
