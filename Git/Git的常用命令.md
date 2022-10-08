# Git的常用命令

## 设置Git账户

设置账户名：
```bash
git config --global user.name "[yourname]"
```

设置账户的电子邮箱
```bash
git config --global user.email "[youremail]"
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

### 上传前合并commit

如果在push前发现最近几次的commit的信息是重复或者是相近的，那么可以对commit进行合并。

使用`git log`命令查看commit

输入命令`git rebase -i HEAD~3`，注意最后面的3指的是最近3次commit，即我们要对最近3次commit进行合并。

然后就会看到一个 vim 界面 （不熟悉 vim 基础操作的读者请自行查阅搜索）:

```bash
pick 2685240 init feat-1
pick a7e5705 develop feat-1 phase 2
pick 1d23813 develop feat-1 phase 3
```

记住不要动最上面的那行，把下面几行开头的 pick 换成 s , 然后保存这时会显示另一个 vim 界面:

```bash
# This is a combination of 3 commits.
# This is the 1st commit message:

init feat-1

# This is the commit message #2:

develop feat-1 phase 2

# This is the commit message #3:

develop feat-1 phase 3
```

删除所有内容( #开头的可以忽略），然后写一句简短、准确的句子作为这次开发的 commit message，
如 :

```bash
enable user to login with phone number
```

然后保存

如果成功了就能看见这么一些文字:

```bash
$ git rebase -i HEAD~3
[detached HEAD 4ff0ac1] update usual git's commands of development
Date: Tue Dec 14 22:47:44 2021 +0800
3 files changed, 130 insertions(+), 1 deletion(-)
                                                                                                                                          create mode 100644 Git/Git的常用工作场景下的常用命令.md
Successfully rebased and updated refs/heads/main.
```

==如果失败了==，如果显示：

```bash
branch | rebase
git status # 显示：
interactive rebase in progress; onto
```

那么只要输入以下命令：

```bash
git rebase --continue
```

就可以看见上面编辑commit信息的vim界面了。

最后使用 git logl 确认所有这次开发中的 commit message 都被压缩成了一个 (这边只介绍了 git rebase的最简单直接的用法，有兴趣的读者可以去阅读官方文档，了解更详细、高级的用法，如第一次vim界面里使用 f 替代 s 有时候更方便）

最后 git push origin feat-1 把本地仓库推到远端仓库

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

```bash
git checkout -b [locate branch name] [remote name]/[remove branch name]
```

例如我想拉取sample库（sample是`git remote -v`里的名字）的old分支

```bash
git checkout -b old sample/old
```

#### 没有克隆远程仓库

如果本地没有clone，那么可以用以下命令来clone

```bash
git clone -b [branch name] [git repo address]
```

#### 已经克隆远程仓库

如果已经clone了，那么可以用以下命令单独拉下分支

```bash
git checkout -b [branch name] [remote repo name]/[branch name]
```

如果上面的命令失败了，那要先运行`git branch -a`看看有没有要拉下来的远程分支；
如果没有就需要运行`git fetch`命令

### 切换分支

```bash
git checkout [Branch]
```

### 拉取远程库的分支

往往我们开发到一半需要拉取远程库的代码，这时我们可以：

先`git add`我们的修改并commit，然后`git pull`再进行merge。

如果我们不想merge，因为有时候发生冲突还需要手动进行处理，那该怎么办呢？

先`git add`我们的修改并commit，
然后`git pull --rebase origin master`
这样就可以让git历史最干净、整洁 —— 所有本地开发的  commit 都会出现在远端主分支里的 commit 之后；并且可以避免额外引入一次 merge 的 commit

## 把某个分支中的某个 commit 对应的代码复制到当前分支

有时我会创建一些实验性的分支，写一些实验性的代码，如果代码不可行，我可以直接废弃掉这个分支，返回原本的开发分支中；如果这些实验性代码可行，我会返回开发分支中，然后把实验性分支的那部分代码“复制”过来，具体操作如下：

git st 查看当前项目的状态，如果有未保存的修改，就`git add .` 和  `git ci -m "xyz"` 保存下来

假设我们需要的是 feat-1 这个分支的某个 commit ，使用 git logl feat-1 查看最近这个分支的所有 commit 记录，如 记下对应的 commit 的 hash 值，即开头的7个字符乱码 如上图的 c843c37 使用 `git cherry-pick c843c37` 将这个 commit 对应的代码复制到当前分支

另外 git cherry-pick 有时还可以用来救场 —— 找回“丢失”的代码，前提是能找到对应的 commit hash 值。
