# Git的各种撤销命令

## 撤销 git add

有时候git add错误的东西，或者git add完了才发现这东西不是想要的，怎么办呢？

趁着还没有commit，赶紧输入命令`git reset HEAD`来撤销。

其实好像没这么麻烦，趁着还没有commit，删掉add错的东西，再`git add *`就行了。

## 撤销 git commit

先用`git log`命令查看commit的历史记录。

再用`git reset --hard id`将当前分支回退到上一个commit。

但是回退后，正常`git push`是不行的，只能强制push：
```bash
git push -f origin main
```

## 撤销 git push

先回退，再强制push：

```bash
git push -f origin main
```
