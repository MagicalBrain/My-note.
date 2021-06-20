# gdb调试器的使用方法

## gcc开启gdb调试

添加`-g`命令参数

## cmake开启gdb调试

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


## 调试core文件

当程序core dump时，可能会产生core文件，它能够很大程序帮助我们定位问题。但前提是系统没有限制core文件的产生。可以使用命令ulimit -c查看：

```bash
ulimit -c
```

如果结果是0，那么恭喜你，即便程序core dump了也不会有core文件留下。我们需要让core文件能够产生：

```bash
ulimit -c unlimited  #表示不限制core文件大小
ulimit -c 10        #设置最大大小，单位为块，一块默认为512字节
```
上面两种方式可选其一。第一种无限制，第二种指定最大产生的大小。
调试core文件也很简单：

$ gdb 程序文件名 core文件名

## 参考链接

https://zhuanlan.zhihu.com/p/74897601
https://www.yanbinghu.com/2018/09/26/61877.html
