# vscode使用问题解决

## 用vscode打开某个文件夹报错

报错内容：

```bash
vscode 尝试创建目录但失败，没有访问权限……
```

解决办法：

打开vscode的安装目录（文件夹）

右击文件夹的属性。

点击**安全**

添加，新增一个Everyone的用户，权限为完全控制

点击应用保存即可。

参考链接：

https://blog.csdn.net/LearnerzzZ/article/details/115406542
