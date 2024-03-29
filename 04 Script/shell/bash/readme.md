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

##### 比较变量的值是否是整数

```bash
# 检查当前是否处于root状态，否则提示“需要root权限”并退出

if [ "$UID" -eq 0 ]; then
    echo "Yes, has been root."
else
    echo "需要root权限"
    exit 1
fi
```

##### 判断字符串变量是否相等

```bash
# 作为编译脚本的范本

sudo rm -r build
echo "start build my process"
mkdir build && cd build
cmake .. -DBUILD_LIB=TRUE
make -j$(nproc)

echo "make is finished, do you want to install it?(y/n)"
read y
if [[ "$y" == "y" ]]; then
	sudo make install
fi
```

##### 测试变量 判断是否存在

```bash
#! /bin/bash

# 检查系统中是否存在 HRL环境变量

if [ -v HOME ]
then
    echo "env exists!"
    echo $HOME
else
    echo "env doesn't exists"
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

### 打印当前路径

<!-- ```bash
echo $(pwd)
``` -->

@import "./code/print-pwd.sh"

#### 相对路径

#### 绝对路径

### 文件系统简介

### 文件权限

chmod 命令

### 读取文件

假设读取的文件为当期目录下的 test.txt 文件，内容如下：

```bash
Google 
Runoob
Taobao
```

实例 1
```bash
#!/bin/bash

while read line
do
    echo $line
done < test.txt
```

执行输出结果为：

```bash
Google
Runoob
Taobao
```

https://www.runoob.com/w3cnote/shell-read-line.html

### 写入文件

```bash

```

@import "./code/write-file/write-file.sh"

即可实现在末尾加入你想要的内容了

https://www.yiibai.com/bash/bash-write-file.html#:~:text=%E8%A6%81%E5%B0%86Bash%E5%91%BD%E4%BB%A4%E7%9A%84%E8%BE%93%E5%87%BA%E5%86%99%E5%85%A5%E6%96%87%E4%BB%B6%EF%BC%8C%E5%8F%AF%E4%BB%A5%E4%BD%BF%E7%94%A8%E5%8F%B3%E5%B0%96%E6%8B%AC%E5%8F%B7%E7%AC%A6%E5%8F%B7,%28%3E%29%E6%88%96%E5%8F%8C%E5%8F%B3%E5%B0%96%E7%AC%A6%E5%8F%B7%20%28%3E%3E%29%EF%BC%9A

## 定义函数

## 定义数组
