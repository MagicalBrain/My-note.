# Git多用户使用

写这个笔记的目的在于让多用户使用和切换变得方便

**注意**
这个笔记仅仅是基于我自己的理解来写的，不保证能够适应所有情况

## 准备工作

* 创建一个自己的文件夹
* 用git bash打开这个文件夹
  
## 密钥配置

* 生成密钥
```bash
ssh-keygen -t rsa -C "xxxxx@xxxxx.com" [yourname]

# 例如
ssh-keygen -t rsa -C "hrl@github.com" hrl
# 这样就会生成名为hrl的密钥文件和hrl.pub的公钥文件
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
```
