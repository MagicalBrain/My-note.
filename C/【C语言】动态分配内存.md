# 动态分配内存

<stdlin.h

## malloc

```c
char *str = (char*) malloc (n * sizeof(char));
```

## reallocate

```c
more_number = (int*) realloc (numbers, count * sizeof(int));
```