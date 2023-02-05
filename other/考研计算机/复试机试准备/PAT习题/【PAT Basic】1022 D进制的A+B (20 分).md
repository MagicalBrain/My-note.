# 【PAT Basic】1022 D进制的A+B (20 分)

## 题目描述

输入两个非负 10 进制整数 $A$ 和 $B (≤2​^{30}​​ −1)$，输出 A+B 的 $D (1 < D \leqslant 10)$进制数。

输入格式：
输入在一行中依次给出 3 个整数 A、B 和 D。

输出格式：
输出 A+B 的 D 进制数。

输入样例：
123 456 8

输出样例：
1103

## 基本思路

## 代码

第一次运行18分。

```c++
/*
* 1022题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    long long a, b;
    int D;
    int re;
    int num[31];
    int top = 0;
    scanf("%lld%lld%d", &a, &b, &D);
    re = a + b;
    if (re == 0)
        printf("0\n");
    else {
        while (re > 0)
        {
            num[top++] = re % D;
            re /= D;
        }
        for (int i = top - 1; i >= 0; i--)
        {
            printf("%d",num[i]);
        }
        printf("\n");
    }
    
    return 0;
}
```

## 总结
