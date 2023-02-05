# 【PAT Basic】1008 数组元素循环右移问题 (20 分)

## 题目描述

一个数组A中存有$N（N>0）$个整数，在不允许使用另外数组的前提下，将每个整数循环向右移$M（M≥0）$个位置，即将A中的数据由$（A_​0​​, A_​1,​​ ⋯A_{​N−1}​​ ）$变换为$（A_{​N−M}​​ ⋯A_{​N−1},​​ A_​0,​​ A_​1,​​ ⋯A_{​N−M−1}​​ ）$（最后M个数循环移至最前面的M个位置）。如果需要考虑程序移动数据的次数尽量少，要如何设计移动的方法？

输入格式:
每个输入包含一个测试用例，第1行输入N（1≤N≤100）和M（≥0）；第2行输入N个整数，之间用空格分隔。

输出格式:
在一行中输出循环右移M位以后的整数序列，之间用空格分隔，序列结尾不能有多余空格。

输入样例:
6 2
1 2 3 4 5 6

输出样例:
5 6 1 2 3 4

## 基本思路

### 方法一：改变输入输出法

这个方法十分无赖，虽然能够AC但是是违背出题者本意的

### 方法二：交换前后对应的元素

需要考虑的细节比较多，为了减少错误，使用递归会好点。

### 方法三：三次逆序

右移m位，现将数组后m位逆序，再将前面的整体逆序，再将整个数组逆序即可。

## 代码

### 方法一：改变输入的

```c++
/*
* 1008题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n;
    scanf("%d %d", &n, &m);

    int *data = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data[(i + m) % n]);
    }

    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
            printf("%d ", data[i]);
        else
            printf("%d\n", data[i]);
    }
    return 0;
}
```

### 方法二

```c++

```

### 方法三

```c++
/*
* 1008题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>

void reverse(int *n, int l, int r) {
    if (r - l < 0)
        return ;
    
    for (int i = l, j = r; i < j; i++, j--)
    {
        int t = n[i];
        n[i] = n[j];
        n[j] = t;
    }
}

int main()
{
    int m,n;
    scanf("%d %d", &n, &m);

    m = m % n;  //关键一步，如果没有考虑到m可以大过n的话，会有几个测试用例过不了的。

    int *data = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
    }

    reverse(data, n - m, n - 1);
    reverse(data, 0, n - m - 1);
    reverse(data, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
            printf("%d ", data[i]);
        else
            printf("%d\n", data[i]);
    }
    return 0;
}
```

## 总结

三次逆序的方法真的太简单了
小心$m > n$的情况！

## 测试程序

```c++
/*
* 1008题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>

int flag = 1;
void swap(int *n, int l, int r, int m, int len) {
    if (r - l < 0)
        return ;
    
    for (int i = 0; i < m; i++)
    {
        int t = n[r - i];
        n[r - i] = n[(r - i + m) % len];
        n[(r - i + m) % len] = t;
    }
    if (flag) {
        swap(n, l + m, r, m, len);
        flag = 0;
    }
    else {
        swap(n, l, r - m, m, len);
        flag = 1;
    }
}

int main()
{
    int m,n;
    scanf("%d %d", &n, &m);

    int *data = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
    }

    swap(data, 0, n - 1, m, n);
    

    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
            printf("%d ", data[i]);
        else
            printf("%d\n", data[i]);
    }
    return 0;
}
```