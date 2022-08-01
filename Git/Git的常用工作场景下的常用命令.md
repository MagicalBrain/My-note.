# Git的常用工作场景下的常用命令

作者：FreewheelLee
链接：https://zhuanlan.zhihu.com/p/250493093
来源：知乎
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

## 备注

他这里将一些命令都用alias设置成简写了

```bash
git st = git status
git ci = git commit
git br = git branch
git co = git checkout
git unstage = git reset HEAD --
git last = git log -1 HEAD
git logl = git log --oneline
```

## 工作场景一 新任务（开发新特性 / 修bug）

1. ```git st``` 查看当前项目的状态，如果有未保存的修改，就git add . 和  git ci -m "xyz" 保存下来
2. 切换到开发主分支，假如项目的主分支叫develop 就使用 git co develop
3. 确保主分支是最新版本 git pull origin develop
4. 创建新分支 git co -b feat-1 (创建一个叫做 feat-1的新分支)
5. 开始写代码
6. 如果当前任务比较复杂，代码量比较多，我通常会多次使用 git add . 和 git ci -m "xxx" 保存当前代码 (记得把 xxx 换成更有意义的文字， 如 git ci -m "init feature-1" )
7. 代码开发结束，整理 commit message 
   1. 首先仍然是用 git st 确保所有代码都commit了（没有就 git add 和 git ci )
   2. 第二步 git logl 查看当前分支下最近的 commit message，如 

```bash
1d23813 (HEAD -> feat-1) develop feat-1 phase 3
a7e5705 develop feat-1 phase 2
2685240 init feat-1
```

假设我开发 feat-1 中 commit 了3次，三次的commit message如上所示。前面说过 commit 是为了防止意外丢失代码，但是在推到远端之前，最好把一次开发的 commit 合并成一个，避免污染远端的 git commit message 
因为这个例子中有3个 commit，所以执行 git rebase -i HEAD~3  然后就会看到一个 vim 界面 （不熟悉 vim 基础操作的读者请自行查阅搜索）:

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

## 工作场景二 —— 开发进行一半，需要远端主分支的最新代码

有些时候，你在本地开发某个功能，代码写到一半，某个同事将某些重要代码合进了远端的主分支（如 develop 分支）里。这些重要代码可能是可以极大提升本地开发效率，可能是加入了某些规范检查或者是跟你当前开发相关的代码 

—— 总之需要你将那部分代码融入你当前的本地开发环境里。

这种情况下，我会git st 查看当前项目的状态，如果有未保存的修改，就git add . 和  git ci -m "xyz" 保存下来

git pull --rebase origin develop 使用这个指令将远端的主分支以 rebase 的形式 “合进”当前分支 

git logl 查看当前分支下的 commit message 是否符合预期

为什么用 --rebase 呢？因为这么做，可以让git历史最干净、整洁 —— 所有本地开发的  commit 都会出现在远端主分支里的 commit 之后；并且可以避免额外引入一次 merge 的 commit

## 工作场景三 —— 希望把某个分支中的某个 commit 对应的代码复制到当前分支

有时我会创建一些实验性的分支，写一些实验性的代码，如果代码不可行，我可以直接废弃掉这个分支，返回原本的开发分支中；如果这些实验性代码可行，我会返回开发分支中，然后把实验性分支的那部分代码“复制”过来，具体操作如下：

git st 查看当前项目的状态，如果有未保存的修改，就git add . 和  git ci -m "xyz" 保存下来

假设我们需要的是 feat-1 这个分支的某个 commit ，使用 git logl feat-1 查看最近这个分支的所有 commit 记录，如 记下对应的 commit 的 hash 值，即开头的7个字符乱码 如上图的 c843c37 使用 git cherry-pick c843c37 将这个 commit 对应的代码复制到当前分支

另外 git cherry-pick 有时还可以用来救场 —— 找回“丢失”的代码，前提是能找到对应的 commit hash 值。
