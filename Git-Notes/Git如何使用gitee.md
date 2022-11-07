# Git如何使用gitee

最近被公司的gitee库上传给整破防了，这玩意和github一样又不一样给爷整懵了。

赶紧记录下怎么回事。

如果push的时候出现：

```bash
remote: Incorrect username or password
......
```

那是用户名或密码不对，基本上都是用户名的问题，密码除非忘了不会填错的。因为gitee的用户名允许中文而git不行，所以git里要填的用户名应该是**登录的邮箱**

但就算是这样每次push的时候可能还是得输入用户名和密码

```bash
remote:Acces denied
......
```

那就是没权限得去找仓库的管理员，我公司仓库管理员一般都是部门主管。
