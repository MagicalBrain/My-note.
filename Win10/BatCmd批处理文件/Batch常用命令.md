# Batch常用命令

## 文件处理

### 打开文件 or 文件夹

```batch
start [filename]
```

### 显示目录

```batch
dir
```


### 删除文件

```batch
del
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

