# 【PAT Basic】1030 完美数列 (25 分)

## 题目描述

给定一个正整数数列，和正整数 p，设这个数列中的最大值是 M，最小值是 m，如果 M≤mp，则称这个数列是完美数列。
现在给定参数 p 和一些正整数，请你从中选择尽可能多的数构成一个完美数列。

输入格式：
输入第一行给出两个正整数 N 和 p，其中 $N（≤ 10^5​​ ）$是输入的正整数的个数，$p（≤10^9​​ ）$是给定的参数。第二行给出 N 个正整数，每个数不超过 $ 10^9 $​​ 。

输出格式：
在一行中输出最多可以选择多少个数可以用它们组成一个完美数列。

输入样例：
10 8
2 3 20 4 5 1 6 7 8 9

输出样例：
8

## 基本思路

排序 + 滑动窗口

## 代码

### 排序 + 滑动窗口

```c++
/*
* 1030题 代码存档
*/
#include<stdio.h>
#include <stdlib.h>
#include<string.h>

int compare(const void *A, const void *B) {
    long a = *(long*)A;
    long b = *(long*)B;
    return a - b;
}

int main() {
    int n;
    long p;
    long *num;
    
    int cnt = 0;
    int max_cnt = 0;

    scanf("%d%ld", &n, &p);

    num = (long*) malloc( n * sizeof(long));
    for (int i = 0; i < n; i++)
    {
        scanf("%ld", &num[i]);
    }

    qsort(num, n, sizeof(long), compare);
    
    int i = 0 ,j = n - 1;
    for (int i = 0; i < n; i++)
    {
        cnt = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (num[j] <= num[i] * p) {
                cnt++;
            }
            else {
                break;
            }
        }
        if (cnt > max_cnt)
            max_cnt = cnt;
    }
    
    printf("%d\n", max_cnt);
    
    return 0;
}
```

超时

对比了知乎大佬的代码，修改了一下，思路基本一致的

```c++
/*
* 1030题 代码存档
*/
#include<stdio.h>
#include <stdlib.h>
#include<string.h>

int compare(const void *A, const void *B) {
    long a = *(long*)A;
    long b = *(long*)B;
    return a - b;
}

int main() {
    int n;
    long p;
    long *num;
    
    int cnt = 0;
    int max_cnt = 0;

    scanf("%d%ld", &n, &p);

    num = (long*) malloc( n * sizeof(long));
    for (int i = 0; i < n; i++)
    {
        scanf("%ld", &num[i]);
    }

    qsort(num, n, sizeof(long), compare);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i + cnt; j < n; j++)
        {
            if (num[j] <= num[i] * p) {
                cnt++;
            }
            else
                break;      //不break会超时
        }
        if (cnt > max_cnt)
            max_cnt = cnt;
        cnt--;
    }
    
    printf("%d\n", max_cnt);
    
    return 0;
}
```

## 总结
