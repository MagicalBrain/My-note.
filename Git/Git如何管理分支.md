# Git如何管理分支

## 如何新建分支

```bash
git branch [new branch name]
```

```bash
git checkout -b new-branch
```

新建一个名为new-branch的分支，然后切换为new-branch分支

## 如何切换分支

```bash
git checkout new-branch
```

## 如何合并分支

1、首先先切换到要合并的分支，例如要把其他分支合并到主分支master

```bash
git checkout master
git pull
```

检查是否所有分支都pull下来了

```bash
git pull -a
```

合并其他分支
```bash
git merge new-branch
```

查看合并之后的状态：
```bash
git status
```

然后提交，如果需要删除其他分支
```bash
git push origin --delete new-branch
```

## 如何同时push和pull多个分支

同时push本地所有分支：

```bash
git push --all origin
```

同时pull远程库所有分支：

```bash
git pull
```

## 管理多人协作的分支

如果在参与多人协作的项目时，自己的修改一定要在自己的分支上。

即git clone或者git pull之后一定要新建或者切换到自己的分支才能做修改。

上传也是上传到自己的分支，如果你的修改被管理员接收，那么他就会将你的分支合并到master主分支上去。

## 参考链接

https://www.runoob.com/git/git-branch.html
