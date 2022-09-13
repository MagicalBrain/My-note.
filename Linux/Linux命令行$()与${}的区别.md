# Linux命令行$()与${}的区别

## $(command)

这种是命令替换
即用该命令的输出结果来填充$指定的位置

```bash
# data is a command
date
```

```bash
# 使用命令替换，直接用date命令的输出结果来填充$(date)的位置来输出
echo $(date)
# output:
Mon Sep 12 17:27:49 PDT 2022
```

## ${parameter}

这种是变量替换。
即用该变量的值来填充$指定的位置

```bash
# define a parameter
animal=lion

# print animal
echo ${animal}
# output
lion
```
