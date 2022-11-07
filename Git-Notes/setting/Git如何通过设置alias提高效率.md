# Git如何通过设置alias提高效率

`git.alias`即git命令的别名，可以设置缩写，从而提高`git bash`的使用效率。

## 我自己常用的git.alias设置

```bash
git config --global alias.st status

git config --global alias.cm commit

git config --global alias.cmm 'commit -m'
```

```bash
git status => git st
git commit => git commit
git commit -m => git cmm
```
