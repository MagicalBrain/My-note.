# 【PAT Basic】1006 换个格式输出整数 (15 分)

## 题目描述

让我们用字母 B 来表示“百”、字母 S 表示“十”，用 12...n 来表示不为零的个位数字 n（<10），换个格式来输出任一个不超过 3 位的正整数。例如 234 应该被输出为 BBSSS1234，因为它有 2 个“百”、3 个“十”、以及个位的 4。

输入格式：

每个测试输入包含 1 个测试用例，给出正整数 n（<1000）。

输出格式：

每个测试用例的输出占一行，用规定的格式输出 n。

输入样例 1：

234
输出样例 1：

BBSSS1234
输入样例 2：

23
输出样例 2：

SS123

## 基本思路

先一位一位数地取，压栈，然后一个个地出栈，根据出栈元素来进行相应的操作。

## 代码

```c++
/*
* 1006题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    int s[10];
    int top = 0;

    int num;
    scanf("%d", &num);

    while (num > 0)
    {
        s[top++] = num % 10;
        num /= 10;
    }

    for (int i = top - 1; i >= 0; i--)
    {
        if (i == 2)
            for (int j = 0; j < s[i]; j++)
                printf("B");
        if (i == 1)
            for (int j = 0; j < s[i]; j++)
                printf("S");
        if (i == 0)
            for (int j = 1; j <= s[i]; j++)
                printf("%d",j);
            
    }
    printf("\n");
    
    return 0;
}
```

## 总结
