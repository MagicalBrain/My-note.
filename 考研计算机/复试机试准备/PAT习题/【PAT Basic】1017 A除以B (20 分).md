# 【PAT Basic】1017 A除以B (20 分)

## 题目描述

本题要求计算 $A \div B$，其中 $A$ 是不超过 1000 位的正整数，B 是 1 位正整数。你需要输出商数 Q 和余数 R，使得 $A=B \times Q+R$ 成立。

输入格式：
输入在一行中依次给出 A 和 B，中间以 1 空格分隔。

输出格式：
在一行中依次输出 Q 和 R，中间以 1 空格分隔。

输入样例：
123456789050987654321 7

输出样例：
17636684150141093474 3

## 基本思路

## 代码

```c++
/*
* 1017题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char A[1001];
    int b;
    int *num;
    int i = 0, len, Q = 0, R = 0;

    scanf("%s%d", A, &b);
    len = strlen(A);
    num = (int*) malloc(len * sizeof(int));
    memset(num, 0, len * sizeof(int));

    for (int i = 0; i < len; i++)
    {
        if (i == 0) {
            int t = A[i] - '0';
            if (t - b >= 0) {
                num[i] = t / b;
                R = t % b;
            }
            else 
                R = t;
            continue;
        }

        int tmp = R * 10 + A[i] - '0';
        num[i] = tmp / b;
        R = tmp % b;
    }
    //输出商
    for (int i = 0; i < len; i++)
    {
        if (len == 1 && i == 0)
            printf("%d", num[i]);
        else if (i == 0 && num[i] == 0)
            continue;
        else if (i == 0)
            printf("%d",num[i]);
        else
            printf("%d",num[i]);
    }
    printf(" %d\n", R);
    return 0;
}
```

## 总结

