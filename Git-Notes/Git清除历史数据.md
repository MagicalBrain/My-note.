# Git清除历史数据

```bash
git checkout --orphan latest_branch
git add -A
git commit -am "clean history"
git branch -D master
git branch -m master
git reflog expire --expire=now --all
git gc --prune=now
git gc --aggressive --prune=now
git push -f origin master
```
