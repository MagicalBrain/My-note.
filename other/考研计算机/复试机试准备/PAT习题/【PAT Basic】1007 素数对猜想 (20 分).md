# 【PAT Basic】1007 素数对猜想 (20 分)

## 题目描述

让我们定义$d​_n$为：$d​_n​​ =p_​n+1​​ −p_n$​​ ，其中$p_​i$​​ 是第i个素数。显然有$d_​1​​ =1$，且对于$n>1$有$d​_n$​​ 是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。
现给定任意正整数N(<10​5​​ )，请计算不超过N的满足猜想的素数对的个数。

输入格式:
输入在一行给出正整数N。

输出格式:
在一行中输出不超过N的满足猜想的素数对的个数。

输入样例:
20

输出样例:
4

## 基本思路

先对2到n的数进行遍历，将其中的所有素数存到一个数组里，然后再对数组进行遍历，查找相邻素数差为2的对数。

## 代码

```c++
/*
* 1007题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_Prime(int n) {
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    int len;
    scanf("%d",&len);

    int s[100000];
    int top = 0;
    int re;
    for (int i = 2; i <= len; i++)
    {
        if ( is_Prime(i))
            s[top++] = i;
    }

    for (int i = 0, j = 1; j < top; i++, j++)
    {
        if (s[j] - s[i] == 2)
            re++;
    }
    printf("%d\n", re);
    
    return 0;
}
```

## 总结
