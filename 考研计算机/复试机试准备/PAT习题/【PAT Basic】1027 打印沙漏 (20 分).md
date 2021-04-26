# 【PAT Basic】1027 打印沙漏 (20 分)

## 题目描述

本题要求你写个程序把给定的符号打印成沙漏的形状。例如给定17个“*”，要求按下列格式打印
```
*****
 ***
  *
 ***
*****
```
所谓“沙漏形状”，是指每行输出奇数个符号；各行符号中心对齐；相邻两行符号数差2；符号数先从大到小顺序递减到1，再从小到大顺序递增；首尾符号数相等。

给定任意N个符号，不一定能正好组成一个沙漏。要求打印出的沙漏能用掉尽可能多的符号。

输入格式:
输入在一行给出1个正整数N（≤1000）和一个符号，中间以空格分隔。

输出格式:
首先打印出由给定符号组成的最大的沙漏形状，最后在一行中输出剩下没用掉的符号数。

输入样例:
19 *

输出样例:
```
*****
 ***
  *
 ***
*****
2
```
## 基本思路

## 代码

```c++
/*
* 1026题 代码存档
*/
#include<stdio.h>
#include <stdlib.h>
#include<string.h>

int main() {
    int num;
    int max = 0, tmp = 0;
    int sum = 1;
    char c;
    scanf("%d %c", &num, &c);
    //printf("%d %c\n", num, c);
    
    int i = 3;
    for (; sum <= num; i+=2)
    {
        sum += i*2;
        //printf("%d\n", sum);
    }
    tmp = i - 2;
    max = tmp - 2;

    //打印上三角
    for (i = max; i > 0; i-= 2)
    {
        int j = max - i;
        while (j > (max - i) / 2)
        {
            printf(" ");
            j--;
        }
        for (j = i; j > 0; j--)
        {
            printf("%c", c);
        }
        printf("\n");
    }
    
    //打印下三角
    for (i = 3; i <= max; i+=2)
    {
        int j = max - i;
        while (j > (max - i) / 2)
        {
            printf(" ");
            j--;
        }
        for (j = i; j > 0; j--)
        {
            printf("%c", c);
        }
        printf("\n");
    }
    
    sum = sum - tmp * 2;
    num = num - sum;
    printf("%d\n", num);
    return 0;
}
```

## 总结
