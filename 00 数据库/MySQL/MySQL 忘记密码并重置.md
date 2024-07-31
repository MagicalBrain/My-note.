# MySQL 忘记密码并重置

## MySQL 8.0 修改root密码

连接到MySQL：

```bash
sudo mysql # 或 mysql 都试试
```

执行以下命令修改root用户的密码：

```bash
ALTER USER 'root'@'localhost' IDENTIFIED BY '你的密码';
```

## 参考链接

https://blog.csdn.net/qq_39689711/article/details/134961248
