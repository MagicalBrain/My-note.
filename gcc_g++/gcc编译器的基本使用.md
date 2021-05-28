# gcc编译器的基本使用

## 生成可执行文件

一般只需要
```
gcc filename.c
```

会在当前目录下自动生成```a.out```可执行文件

```
./a.out
```
即可执行

如果要指定生成的可执行文件的名字，可用```-o```参数
例如：
```
gcc input.c -o output.out
```

## 检查内存溢出问题

需要用到AddressSanitizer

添加命令：
```
-fsanitize=address -g
```

在终端输入：
```
gcc -fsanitize=address -g twoSum.c
```
