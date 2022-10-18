# Batch常用命令

## 文件处理

### 打开文件 or 文件夹

```batch
start [filename]
```

如果是打开文件，会使用默认软件打开文件。

### 显示目录

```batch
dir
```


### 删除文件

```batch
del
```

### 切换目录

```batch
pushd
```

```batch
pushd /?

PUSHD [path | ..]

  path        指定要成为当前目录的目录。

如果命令扩展被启用，除了一般驱动器号和路径，PUSHD
命令还接受网络路径。如果指定了网络路径，PUSHD 将创建一个
指向指定网络资源的临时驱动器号，然后再用刚定义的驱动器
号更改当前的驱动器和目录。可以从 Z: 往下分配临时驱动器
号，使用找到的第一个没有用过的驱动器号。
```

常常与`popd`配合使用

```batch
:: 保存当前的目录并切换到想要的目录
pushd [your path]
:: 回到pushd之前所在的目录
:: 如果不知道当前路径的情况下非常有用
popd
```

## 编程

### 设置变量

```batch
set
```


### 设置系统变量

```batch
setx
```

### if-else语句

```batch
if [condition] (

)
else {

}
```

例子：

```batch
if [condition] (

)
else {

}
```

### 循环

```batch
for
```

```batch
@echo off
for %%i in (*) do (md %%~xi 
move *%%~xi %%~xi)
pause
```

### 读取键盘的输入

使用set命令的/p参数

```batch
set /p var=请输入----
echo 您输入的内容为%var%  
```

输出结果为：

```batch

```

## 其它

### 在屏幕上打印字符串

echo

#### 关闭回显

```batch
@echo off
```

#### 开启回显

```batch
@echo on
```

### 清除屏幕

```batch
cls
```

### 注释

```batch
rem
```

```batch
::
```

### 暂停脚本运行

```batch
pause
```

在读取键盘输入之前处于暂停状态
