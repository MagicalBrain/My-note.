# Git多用户使用

写这个笔记的目的在于让多用户使用和切换变得方便

**注意**
这个笔记仅仅是基于我自己的理解来写的，不保证能够适应所有情况

## 准备工作

* 创建一个自己的文件夹`MyFile`
* 用git bash打开这个文件夹
  
## 密钥配置

* 生成密钥
```bash
ssh-keygen -t rsa -C "xxxxx@xxxxx.com" -f [key file path]

# 例如
ssh-keygen -t rsa -C "hrl@github.com" -f hrl
# 这样就会在当前文件夹下生成名为hrl的密钥文件和hrl.pub的公钥文件
```
* 将生成的密钥添加到你用的代码托管平台里绑定（github或者gitee啥的）
* 编辑`~/.ssh/config`
```bash
vim ~/.ssh/config
```
输入以下内容
```bash
# 第一个账户名的设置
Host abc
HostName github.com
PreferredAuthentications publickey
IdentityFile ~/.ssh/hrl

# 第二个账户名的设置
Host def
HostName github.com
PreferredAuthentications publickey
IdentityFile ~/.ssh/def
```

* 在文件夹`MyFile`下配置
```bash
eval $(ssh-agent -s)
# 此时命令会打印类似的内容：
Agent pid 2492
```
这是继续输入以下命令：
```bash
# 添加ssh密钥
ssh-add ~/.ssh/hrl
# 测试配置是否成功
ssh -T abc@github.com
# 输出以下内容则表示配置成功
Hi abc! You've successfully authenticated, but GITEE.COM does not provide shell access.
```

接下来就可以在当前文件夹里用自己的account愉快地玩耍了

**注意**

以上方法并不是一劳永逸的，一劳永逸则需要下面的脚本

## 编写脚本

编写一个`.sh`脚本

```bash
eval $(ssh-agent -s)
# id_name 就是私钥文件的名字
ssh-add ~/.ssh/id_name
# test the setting
ssh -T name@gitee.com
```

其他配置也可仿照这个来。
