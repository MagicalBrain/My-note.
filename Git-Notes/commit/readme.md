# git commit的用法

## 创建commit

## 撤销commit

## 合并commit

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

### 总结

```bash
git rebase -i HEAD~[n]
# 最上面一行不要动
# pick改s
# 保存
# 编辑commit信息，保存
```

然后就可以提交了

## commit帮助

```bash
usage: git commit [<options>] [--] <pathspec>...

    -q, --quiet           suppress summary after successful commit
    -v, --verbose         show diff in commit message template

Commit message options
    -F, --file <file>     read message from file
    --author <author>     override author for commit
    --date <date>         override date for commit
    -m, --message <message>
                          commit message
    -c, --reedit-message <commit>
                          reuse and edit message from specified commit
    -C, --reuse-message <commit>
                          reuse message from specified commit
    --fixup [(amend|reword):]commit
                          use autosquash formatted message to fixup or amend/reword specified commit
    --squash <commit>     use autosquash formatted message to squash specified commit
    --reset-author        the commit is authored by me now (used with -C/-c/--amend)
    --trailer <trailer>   add custom trailer(s)
    -s, --signoff         add a Signed-off-by trailer
    -t, --template <file>
                          use specified template file
    -e, --edit            force edit of commit
    --cleanup <mode>      how to strip spaces and #comments from message
    --status              include status in commit message template
    -S, --gpg-sign[=<key-id>]
                          GPG sign commit

Commit contents options
    -a, --all             commit all changed files
    -i, --include         add specified files to index for commit
    --interactive         interactively add files
    -p, --patch           interactively add changes
    -o, --only            commit only specified files
    -n, --no-verify       bypass pre-commit and commit-msg hooks
    --dry-run             show what would be committed
    --short               show status concisely
    --branch              show branch information
    --ahead-behind        compute full ahead/behind values
    --porcelain           machine-readable output
    --long                show status in long format (default)
    -z, --null            terminate entries with NUL
    --amend               amend previous commit
    --no-post-rewrite     bypass post-rewrite hook
    -u, --untracked-files[=<mode>]
                          show untracked files, optional modes: all, normal, no. (Default: all)
    --pathspec-from-file <file>
                          read pathspec from file
    --pathspec-file-nul   with --pathspec-from-file, pathspec elements are separated with NUL character
```
