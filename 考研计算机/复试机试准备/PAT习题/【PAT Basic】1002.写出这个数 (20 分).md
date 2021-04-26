# 【PAT Basic】1002.写出这个数 (20 分)

## 题目描述

读入一个正整数 n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

**输入格式：**
每个测试输入包含 1 个测试用例，即给出自然数 n 的值。这里保证 n 小于 $10^100$。

**输出格式：**
在一行内输出 n 的各位数字之和的每一位，拼音数字间有 1 空格，但一行中最后一个拼音数字后没有空格。

**输入样例：**

1234567890987654321123456789

**输出样例：**

yi san wu

## 基本思路

首先考虑对大数的读取，一般绝对值范围在$10^9$范围内，可以用int（注意，64位机可以，有些32位机器上也是不行的）；
绝对值范围在$10^18$以内可以用```long long```，在这之上就只能用处理字符串的方法来处理了。

在考虑到求和之后打出对应的拼音，由于取每一位数的操作是从个位开始的，所以我们需要用一个栈过度以达到逆序输出的目的。

## 代码

```c++
/*
* 1002题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum_this_number(char *n) {
    int sum = 0;
    int i = 0;
    while (n[i] != '\0')
    {
        sum += (n[i++] - '0');
    }
    return sum;
}

void write_this_number(int n) {
    int s[100];
    int top = 0;

    while (n > 0)
    {
        s[top++] = n % 10;
        n /= 10;
    }
    //s[top++] = n;
    for (top = top - 1; top >= 0; top--)
    {
        switch (s[top])
        {
            case 0:
                printf("ling");
                break;
            case 1:
                printf("yi");
                break;
            case 2:
                printf("er");
                break;
            case 3:
                printf("san");
                break;
            case 4:
                printf("si");
                break;
            case 5:
                printf("wu");
                break;
            case 6:
                printf("liu");
                break;
            case 7:
                printf("qi");
                break;
            case 8:
                printf("ba");
                break;
            case 9:
                printf("jiu");
                break;
            default:
                break;
        }
        if (top != 0)
            //printf("<>");
            printf(" ");
    }
    printf("\n");
}

int main()
{
    char n[101];
    char *str = n;
    int re = 0;
    //scanf("%s", n);    //输入一个数n
    gets(str);
    //puts(str);
    re = sum_this_number(str);
    //printf("各位数字和为：%d\n", re);
    printf("%d\n", re);
    write_this_number(re);
    return 0;
}
```

## 总结

**注意**：
1. 涉及到大数读取的时候要清楚各类型的数值范围
2. 字符串定义长度的时候要考虑到读取字符串时其后面要给'\0'预留一个位置，即最长100位的字符串，定义长度应为101.