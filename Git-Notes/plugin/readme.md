# Git（及其各大IDE插件） 的使用

## 从Github下载代码覆盖原有代码

### 更新类型（Update Type）

#### Merge
merge：将两个分支，合并提交为一个新提交，并且新提交有2个parent

```
git merge
```

#### Rebase

rebase：会取消分支中的每个提交，并把他们临时存放，然后把当前分支更新到最新的origin分支，最后再吧所有提交应用到分支上。

```
git rebase
```

[参考链接](https://www.cnblogs.com/shuimuzhushui/p/9000253.html)
https://www.cnblogs.com/xueweihan/p/5743327.html

### Clean working tree before update