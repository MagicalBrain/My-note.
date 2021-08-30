# Git如何管理分支

## 如何新建分支

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
