# 【PAT Basic】1012 数字分类 (20 分)

## 题目描述

给定一系列正整数，请按要求对数字进行分类，并输出以下 5 个数字：
$A​$1​​  = 能被 5 整除的数字中所有偶数的和；
$A​2$​​  = 将被 5 除后余 1 的数字按给出顺序进行交错求和，即计算$ n1​​ −n​2​​ +n​3​​ −n​4​​ \cdots$；
$A​3$​​  = 被 5 除后余 2 的数字的个数；
$A​4​$​  = 被 5 除后余 3 的数字的平均数，精确到小数点后 1 位；
$A​5​​$  = 被 5 除后余 4 的数字中最大数字。

输入格式：

每个输入包含 1 个测试用例。每个测试用例先给出一个不超过 1000 的正整数 N，随后给出 N 个不超过 1000 的待分类的正整数。数字间以空格分隔。

输出格式：

对给定的 N 个正整数，按题目要求计算 A​1​​ ~A​5​​  并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。
若其中某一类数字不存在，则在相应位置输出 N。

输入样例 1：

13 1 2 3 4 5 6 7 8 9 10 20 16 18

输出样例 1：

30 11 2 9.7 9

输入样例 2：

8 1 2 4 5 6 7 9 16

输出样例 2：

N 11 2 N 9

## 基本思路

## 代码

```c++
/*
* 1012题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, n;
    int a1 = 0, a2 = 0, a3 = 0,  a5 = 0;
    int flag = 1;
    float a4 = 0.0;
    
    int len[5] = {0};
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        if (num % 5 == 0 && num % 2 == 0) {
            a1 += num;
            len[0]++;
        }
        if (num % 5 == 1) {
            if (flag)
                a2 += num;
            else 
                a2 -= num;  
            flag = !flag;
            len[1]++;
        }
        if (num % 5 == 2) {
            a3++;
            len[2]++;
        }
        if (num % 5 == 3) {
            a4 += num;
            len[3]++;
        }
        if (num % 5 == 4) {
            if (num > a5)
                a5 = num;
            len[4]++;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        if (len[i] == 0)
            printf("%c", 'N');
        else if (i == 0)
            printf("%d",a1);
        else if (i == 1)
            printf("%d",a2);
        else if (i == 2)
            printf("%d",a3);
        else if (i == 3)
            printf("%0.1f",a4 / len[3]);
        else if (i == 4)
            printf("%d",a5);
        
        if (i != 4)
            printf(" ");
        else 
            printf("\n");
    }
    
    return 0;
}
```

## 总结

注意审题，多次无法AC的原因就在于输出字符'N'的条件没搞清楚，是这类数字不存在的时候在对应位置输出'N'。
即这类数字的个数为0时，在对应位置输出'N'。
