# gdb调试器的使用方法

## 开启gdb调试功能

### gcc开启gdb调试

添加`-g`命令参数

### cmake开启gdb调试

```
SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
```

## 确认可执行文件是否支持gdb调试

运行命令

```bash
gdb filename
```

如果最后打印的一行为：
```
Reading symbols from HYDeviceDemo...done.
(gdb)
```

那么是可以调试的。
如果被测试的程序时不需要在命令行输入参数的情况下，可以直接在`(gdb)`后面输入调试的指令

否则，需要

```bash
run value……
```

## 启动gdb调试的方法

参考：《C++服务器开发精髓》第二章

### 1、直接调试目标程序

```bash
gdb filename
```

### 2、attach到进程

在某些情况下，一个程序已经启动，想调试这个程序但又不想或者说不能重启程序。
假设：我们的聊天服务器程序运行了一段时间，却再也无法接受新的客户端连接了，那么我们肯定不能为了调试重启程序。

我们只需用gdb attach程序的id将gdb程序调试器attach到我们的聊天测试服务器程序上。
假设聊天程序名为：chatserver

使用ps命令获取该进程的PID，然后gdb attach上去，即可调试了：

```bash
ps -ef | grep chatserver 
```

假设获取到的PID为42921，然后：

```bash
gdb attach 42921
```

当提示出现：

```bash
Attaching to process 42921
```

说明attach成功了，可以开始调试了。

### 3、调试core文件

#### 打开生成core文件

当程序core dump时，可能会产生core文件，它能够很大程序帮助我们定位问题。
但是系统默认设置是没有core文件产生的。
可以使用命令ulimit -c查看：

```bash
ulimit -c
```

另外还可以使用命令```ulimit -a```查看，且该命令还可以查看其它系统信息。

如果结果是0，那么恭喜你，即便程序core dump了也不会有core文件留下。我们需要让core文件能够产生：

```bash
ulimit -c unlimited  #表示不限制core文件大小
ulimit -c 10        #设置最大大小，单位为块，一块默认为512字节
```
上面两种方式可选其一。第一种无限制，第二种指定最大产生的大小。

还有个问题是，如果关闭了当前的终端会话，以后调试的时候还需要重新将core文件生成选项打开，这样调试起来不太方便。
永久打开此选项的方法：

**方法一**：
```bash
vim /etc/security/limits.conf
```

如果权限不够可能需要加sudo

加一行：

```
#<domain>   <type>  <item>  <value>
*           soft    core    unlimited
```

**方法二**：
在`/etc/profile`文件中的最后一行加入：
```ulimit -c unlimited```
然后执行命令：
```bash
source /etc/profile
```

这样只作用与root用户，如果想要某个用户下也起作用，那么得在对应用户的`~/.bashrc/`的最后一行加```ulimit -c unlimited```

调试core文件也很简单：

```bash
gdb filename corefilename
```

在gdb里使用bt命令查看程序崩溃时的调用堆栈：

```bash
(gdb) bt
```

**注意**：
一般堆栈#0~#3是系统函数调用的堆栈，是经过反复测试的，一般不会有问题。
debug的重点应该在其它堆栈，那是我们自己写的业务业务逻辑调用序列。

#### 多个程序崩溃后调试core文件

## 设置断点

使用`break`命令

```bash
break line-number
```

`line-number`即为行号

使用`info break`即可查看当前设置的所有断点的信息。

### 清楚断点

断点清除
断点清除主要用到clear和delete命令。常见使用如下：

```bash
clear   #删除当前行所有breakpoints
clear function  #删除函数名为function处的断点
clear filename:function #删除文件filename中函数function处的断点
clear lineNum #删除行号为lineNum处的断点
clear f:lename：lineNum #删除文件filename中行号为lineNum处的断点
delete  #删除所有breakpoints,watchpoints和catchpoints
delete bnum #删除断点号为bnum的断点
```

## 单步调试

next

## 单步进入

step

## 继续运行

```
continue
```

## 查看变量




## 参考链接

https://zhuanlan.zhihu.com/p/74897601
https://www.yanbinghu.com/2018/09/26/61877.html
