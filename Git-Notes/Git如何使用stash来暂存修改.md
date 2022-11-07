# Git如何使用stash来暂存修改

我们在切换分支的时候常常会遇到有文件修改没有commit的问题，这个时候我们既不想commit也不想用checkout来丢弃这些修改，那我们该怎么办呢？

这个时候我们就可以使用git stash命令来暂存这些修改了

## 暂存当前修改

```bash
# 暂存当前修改
git stash
# 或
git stash push

# 暂存当前修改并添加备注
git stash save "message"
```

将当前的修改入栈（stash）

## 查看暂存列表

```bash
git stash list
```

## 查看暂存修改的内容

```bash
# 查看最近一次stash的内容
git stash show  # 等价：git stash@{0} show 命令

# 查看倒数第二次stash的内容 具体是哪个可以通过stash列表来查看
git stash show stash@{1}
```

## 应用暂存的修改

```bash
# 恢复修改，且不在stash列表中删除
git stash apply
# 恢复倒数第二次修改，且不在stash列表中删除
git stash apply stash@{1}

# 恢复修改，且在stash列表中删除
git stash pop
# 恢复倒数第二次修改，且在stash列表中删除
git stash pop stash@{1}
```

**如果应用修改的时候出现unlink错误**：
别紧张，其实就是恢复的文件被占用了，关掉对应的软件就行了。
一般是vs正在运行调试或者其它IDE占用了这个dll，这个时候只要把vs的调试暂停了就可以了。

## 丢弃某次暂存

```bash
git stash drop stash
```

## 删除所有暂存

```bash
git stash clear
```
