# Git的常用命令

## 设置Git账户

设置账户名：
```bash
git --config global user.name "[yourname]"
```

设置账户的电子邮箱
```bash
git --config global user.email "[youremail]"
```

### 生成ssh密钥

```bash
ssh-keygen -t rsa -C "xxxxx@xxxxx.com"
```

然后将密钥添加到对应代码托管平台应该就可以了。

## 检查本地分支的更改

```git status```

## 添加更改

```git add```命令

**注意**:
除非是自己一个人维护的仓库，否则一般是要让提交的更改尽可能的少改动东西，即```git add```不能添加非必要的更改进去

```git add *```：添加所有更改文件，这其实是一个**危险指令**，如果远程仓库是由多人一起维护、贡献的话，一些不必要的更改可能会覆盖掉别人的有用更改从而导致所谓的“bug”

假设你只修改了名为`Myfile`的文件，那么添加更改命令应为：
```bash
git add Myfile
```

## 提交更改

```git commit```

通常的用法是：

```bash
git commit -m "注释"
```

注释一定要用简短的语言清晰地描述修改的内容

### 修改commit

如果上一次的commit信息需要修改，那么可以：

```bash
git commit --amend
# 或者
git commit --am
```

## 提交更改上库

```bash
git push origin master
```

这个是默认的命令，大多情况下可用，但有时候不行。
这时可以给用以下命令检查远程库的连接情况：

```bash
git remote -v
```

例如我的一个代码库，同时连接了`gitee`和`github`（具体怎么添加的，自行bing一下）

```bash
gitee   git@gitee.com:CPLASF000000/my-note.git (fetch)
gitee   git@gitee.com:CPLASF000000/my-note.git (push)
github  git@github.com:MagicalBrain/My-note..git (fetch)
github  git@github.com:MagicalBrain/My-note..git (push)
```

为了区分提交更改是到gitee还是github所以，修改了对应的分支名，默认是`origin/master`，我这里修改成了`gitee/master`和`github/master`。
这样我如果想提交更改到gitee，则运行命令：

```bash
git push gitee master
```

这样我如果想同时提交更改到gitee和github，则运行命令
```bash
git push gitee master
git push github master
```

当然，写成脚本更方便（Win用cmd脚本，Linux用shell脚本）

## 读取log

```bash
git log
```

但是更好用的命令是

```bash
git log --oneling
```

这个命令我强烈建议用alias设置成

```bash
git logl
```

## 冲突的处理

### 回退

先用`git log`命令查看commit的历史记录。

再用`git reset --hard id`将当前分支回退到id对应的commit

那么直接回退上一个版本呢？

```bash
git reset --hard HEAD^
```

回退上两个个版本命令：
```bash
git reset --hard HEAD^^
```

回退上三个版本命令：

```bash
git reset --hard HEAD~3
```

回退上第$n$个版本命令：
```bash
git reset --hard HEAD~n
```

----

但是回退后，正常`git push`是不行的，只能强制push：
```bash
git push -f origin main
```

### 强制拉取远程仓库覆盖本地仓库

先将远程仓库的代码下载下来，但先不合并：

```bash
git fetch --all
```

然后修改当前分支`head`指向的版本：
```bash
git reset --hard origin/main
```

注意：这里main还是master要根据仓库分支的实际情况来设置

再直接拉取即可：
```bash
git pull
```

## 查看commit的内容

使用`git show`命令

```bash
# 查看某个commit id的内容
git show commitid
```

例如：

```bash
git show 97a74e2aa8c4a0d311b60e12ee2dba301d3ed8d0
```

## 分支的管理

### 新建分支

有时候，没有权限上传到主分支，由懒得PR，那只能本地新建一个分支将更改提交上库：

```bash
git checkout -b [NewBranch]
```

此命令会新建分支并转到新建的分支上来。

```bash
git branch [NewBranch]
```

此命令会新建分支但不会转到新建的分支上来。

### 单独从远程库拉下某分支

如果本地没有clone，那么可以用以下命令来clone

```bash
git clone -b [branch name] [git repo address]
```

如果已经clone了，那么可以用以下命令单独拉下分支

```bash
git checkout -b [branch name] [remote repo name]/[branch name]
```

### 切换分支

```bash
git checkout [Branch]
```


