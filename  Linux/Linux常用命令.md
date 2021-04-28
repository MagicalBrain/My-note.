# Linux常用的命令

## 一、进程管理

**杀死该用户所用进程**

```
sudo pkill -u username
```
或
```
killall -u username
```

**查看用户信息**

```
cat /etc/passwd
```

**删除用户密码**

```
sudo userdel -r username
```

## 二、查找命令

### find命令

find 【搜索目录】【-name或者-iname】【搜索字符】：-name和-iname的区别一个区分大小写，一个不区分大小写

eg：在/etc 目录下搜索名字为init的文件或目录

①、find /etc -name init (精准搜索，名字必须为 init 才能搜索的到)
②、find /etc -iname init (精准搜索，名字必须为 init或者有字母大写也能搜索的到)
③、find /etc -name *init (模糊搜索，以 init 结尾的文件或目录名)
④、find /etc -name init??? (模糊搜索，？ 表示单个字符，即搜索到 init___)

### 参考链接

https://blog.csdn.net/qq_33205418/article/details/83026617

## 三、文件管理

### 文档编辑

**修改文件名称**：
先使用cd命令使当前路径下有要编辑的文件夹，后使用mv命令：

```
mv file1 file2
```

### 文件复制



## 四、文件传输

### 1、上传文件到远程服务器

```
scp
```

### 2、下载远程服务器的文件到本地

```
scp
```