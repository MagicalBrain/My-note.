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

## 如何拉取远程库新分支



## 如何删除本地和远程分支

合并分需要将被合并的分支删除

删除本地分支：

* 当分支被推送到远程后删除本地分支：
```bash
git branch -d [branch name]
```

* 当分支没有被推送到远程后删除本地分支，这时需要强制删除本地分支：
```bash
git branch -D [branch name]
```

删除远程分支：

```bash
git push origin -d [remote_branch_name]
```

## 如何对分支进行重命名

**本地分支**

如果当前分支已经是需要重命名的分支，则运行以下命令：
```bash
git branch -m new_branch_name
```

如果需要重命名的分支不是当前所在的分支，则运行以下命令：

```bash
git branch -m old_branch_name new_branch_name
```

**远程分支**

* 1、重命名本地分支

* 2、删除远程分支

```bash
git push --delete origin old_branch_name
```

* 3、上传新命名的本地分支

```bash
git push origin new_branch_name
```

* 4、关联修改后的本地分支和远程的分支

```bash
git branch --set-upstream-to origin/new_branch_name
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
