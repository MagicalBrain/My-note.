# 【Bash】基本语法

## 注释

```bash
# 单行注释
```

## 变量

### 变量的定义

```bash
var_name=100
```

### 变量的调用

```bash
echo "$var_name"
```

## 算术运算符

记得用上双括号`(())`

```bash
sum=$((1+2))
echo $sum
```

## 逻辑控制语句

### if 语句

#### 单if

```bash
if [ expression ];  
then  
statements  
fi
```

```bash
if [ expression_1 ] && [ expression_2 ];  
then  
statements  
fi
```

```bash
if [ expression_1 ] || [ expression_2 ];  
then  
statements  
fi
```

```bash
if [ expression_1 && expression_2 || expression_3 ];  
then  
statements  
fi
```

用例：

```bash
#!/bin/bash  

read -p " Enter number : " number  

if [ $number -gt 100 ]  
then  
echo "Value is greater than 100"  
fi
```

#### if-else

```bash

```

#### elseif



### switch-case 语句

```bash
case expression in  
    pattern_1)  
        statements  
        ;;  
    pattern_2)  
        statements  
        ;;  
    pattern_3|pattern_4|pattern_5)  # 这几个条件这样列在一起都会进入这个case分支
        statements  
        ;;  
    pattern-n)  
        statements  
        ;;  
    *)  # 相当于default
        statements  
        ;;  
esac
```

用例：

```bash
#!/bin/bash

read id

case $id in
    1)
    # todo 1
    ;;
    2)
    # todo 2
    ;;
esac
```

从终端读入一个输入，然后根据输入变量id的值来决定执行todo1还是todo2位置的语句。

## 循环语句

### for

### while

### until

## 字符串操作

### 查找字符串

### 拆分字符串

### 提取字符串

### 连接字符串

### 判断字符串是否相等

@import "./code/string.sh"

注意这里面的括号（圆括号还是方括号？）
注意括号两边要有空格，否则会出错：

```bash
# ...
if [["$option" == "y"]]     # 错误的用法
if [[ "$option" == "y" ]]   # 正确的用法，注意区分！
# ...
```

## 文件操作

### 文件路径

#### 相对路径

#### 绝对路径

### 文件系统简介

### 文件权限
### 读取文件

### 写入文件

## 定义函数

## 定义数组