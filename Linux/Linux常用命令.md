# Linux常用的命令

[toc]

## 一、进程管理

**查看进程**

```
top
```

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
file1是要修改的文件名，file2是修改后的名字

### 文件复制

```
cp filename1 filename2
```

将```filename1```文件复制到```filename2```路径下。
如果```filename2```不写，就是在当前目录下复制一份。

### 查看文件创建时间和最近访问时间

即```stat filename```命令，使用后即可查看。

## 四、文件删除

### rm命令

删除文件直接使用`rm`命令

但是删除文件夹、目录

`rm -r`
或者`rmdir`

但是如果目录非空，里面有东西的话就只能换个命令了：
`rm -rf`

## 四、文件压缩和解压

### tar命令

用来解压和压缩```tar.xxx```文件的

#### tar.gz

压缩```tar.gz```文件

解压```tar.gz```文件

```
tar -zxvf 文件名.tar.gz
```

[参考链接][参考链接]

[参考链接]:https://www.cnblogs.com/anno-ymy/p/10429396.html

使用`tar`指令解压文件到指定目录：
```
tar -zxvf filename.tar.gz -C file
```

## 五、文件传输

### 1、上传文件到远程服务器

无论是上传还是下载，都是在本地主机上打开终端执行命令

```
scp -r filename01 ubuntu@129.204.104.75:filename02
```

### 2、下载远程服务器的文件到本地

首先要在本地机打开终端，并执行命令：

```
scp -r [host]@[IP_address]:filename02 filename01 
```

```host```为远程主机名
```IP_address```为远程主机的IP地址
```filename02```为要下载下来的远程主机上的文件名。
```filename01```为要下载的目录。

例如：下载名为ubuntu的远程主机上的文件

```
scp -r ubuntu@129.204.104.75:filename02 filename01 
```

## 六、管理文件编辑权限

使用```chmod```命令

例如将只读文件改权限为```all user```均可编辑，则可：
```
sudo chmod a+w filename
```

[参考链接][参考链接]

[参考链接]:[[参考链接]](https://www.runoob.com/linux/linux-comm-chmod.html)

## 七、网络设置

### WiFi

#### 查看WiFi

```bash
nmcli dev wifi
```

#### 连接WiFi

```bash
nmcli dev wifi connect [wifiname/ssid] password [wifi password]
```

### 查看网络地址（IP）

#### ifconfig

```bash
ifconfig
```

输入该命令找就行了。

如果显示没有安装，就按提示安装`net tools`就行了

##### 使用ifconfig命令设置ip

ifconfig除了能够查看ip地址之外还可以设置ip地址和子网掩码，例如：

```bash
ifconfig [ip-address] netmask [netmask]
```

一般来讲设置ip和子网掩码都需要管理员权限，子网掩码一般都是`255.255.255.0`

```bash
sudo ifconfig 192.168.6.6 netmask 255.255.255.0
```

#### ip address

这个命令应该可以直接用

```bash
ip address
```

### 永久设置ip地址

https://zhuanlan.zhihu.com/p/42118356
