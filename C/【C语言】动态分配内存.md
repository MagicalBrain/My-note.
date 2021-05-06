# 动态分配内存

头文件：```<stdlib.h>```

## malloc

```c
char *str = (char*) malloc (n * sizeof(char));
```

## reallocate

```c
more_number = (int*) realloc (numbers, count * sizeof(int));
```

## 如何给二维数组（矩阵）分配空间

重点和难点在于如何给二维数组（矩阵）分配空间
