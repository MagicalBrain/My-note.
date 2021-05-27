# Git的常用命令

## 设置Git账户

设置账户名：
```
git --config global user.name "[yourname]"
```

设置账户的电子邮箱
```
git --config global user.email "[youremail]"
```

## 检查本地分支的更改

```git status```

## 添加更改

```git add```命令

**注意**:
除非是自己一个人维护的仓库，否则一般是要让提交的更改尽可能的少改动东西，即```git add```不能添加非必要的更改进去

```git add *```：添加所有更改文件，这其实是一个**危险指令**，如果远程仓库是由多人一起维护、贡献的话，一些不必要的更改可能会覆盖掉别人的有用更改从而导致所谓的“bug”

## 提交更改

```git commit```

通常的用法是：
```
git commit -m
```