# 【PAT Basic】1021 个位数统计 (15 分)

## 题目描述

给定一个 k 位整数 N=d​k−1​​ 10​k−1​​ +⋯+d​1​​ 10​1​​ +d​0​​  (0≤d​i​​ ≤9, i=0,⋯,k−1, d​k−1
​​ >0)，请编写程序统计每种不同的个位数字出现的次数。例如：给定 N=100311，则有 2 个 0，3 个 1，和 1 个 3。

输入格式：
每个输入包含 1 个测试用例，即一个不超过 1000 位的正整数 N。

输出格式：
对 N 中每一种不同的个位数字，以 D:M 的格式在一行中输出该位数字 D 及其在 N 中出现的次数 M。要求按 D 的升序输出。

输入样例：
100311

输出样例：

0:2
1:3
3:1

## 基本思路

## 代码

```c++
/*
* 1021题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct number{
    int num;
    int Hz;
}number;

int cmp(const void *A, const void *B) {
    number a = *(number*)A;
    number b = *(number*)B;
    if (b.num == a.num)
        return b.Hz - a.Hz;
    return a.num - b.num;
}

int main() {
    char in[1001];
    scanf("%s", in);
    number num[10];
    for (int i = 0; i < 10; i++)
    {
        num[i].num = 0;
        num[i].Hz = 0;
    }
    for (int i = 0; in[i] != '\0'; i++)
    {
        int t = in[i] - '0';
        num[t].num = t;
        num[t].Hz++;
    }
    
    qsort(num,10,sizeof(number), cmp);
    for (int i = 0; i < 10; i++)
    {
        if (num[i].Hz == 0)
            continue;
        printf("%d:%d\n", num[i].num, num[i].Hz);
    }
    
    return 0;
}
```

## 总结
