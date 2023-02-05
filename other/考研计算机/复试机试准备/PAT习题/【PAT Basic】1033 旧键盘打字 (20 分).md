# 【PAT Basic】1033 旧键盘打字 (20 分)

## 题目

旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及坏掉的那些键，打出的结果文字会是怎样？

输入格式：
输入在 2 行中分别给出坏掉的那些键、以及应该输入的文字。其中对应英文字母的坏键以大写给出；每段文字是不超过 10​5​​  个字符的串。可用的字符包括字母 [a-z, A-Z]、数字 0-9、以及下划线 _（代表空格）、,、.、-、+（代表上档键）。题目保证第 2 行输入的文字串非空。

注意：如果上档键坏掉了，那么大写的英文字母无法被打出。

输出格式：
在一行中输出能够被打出的结果文字。如果没有一个字符能被打出，则输出空行。

输入样例：
7+IE.
7_This_is_a_test.

输出样例：
_hs_s_a_tst

## 基本思路

首先建立一个表，记录所有的坏键，然后在读入正确的字符串时，
如果是非字母，则检查键是否是坏的，坏的则跳过
字母键检查完键是好的以后，还得检查是不是大写键键坏了

## 代码

```c++
/*
* 1033题 代码存档
*/
#include<stdio.h>
#include <stdlib.h>
#include<string.h>

int num[10] = {0};
int ch[26] = {0};
int space = 0;      //空格
int comma = 0;      //逗号
int minus = 0;      //负号
int dot = 0;        //点
int shift = 0;   //上档键

int main()  {
    char error[100001];
    char right[100001];
    gets(error);
    gets(right);

    int i = 0;
    while (error[i] != '\0')
    {
        if (error[i] == '_')
            space++;
        if (error[i] == ',')
            comma++;
        if (error[i] == '.')
            dot++;
        if (error[i] == '-')
            minus++;
        if (error[i] == '+')
            shift++;
        
        if (error[i] >= 'A' && error[i] <= 'Z') {
            int t = error[i] - 'A';
            ch[t]++;
        }
        if (error[i] >= 'a' && error[i] <= 'z') {
            int t = error[i] - 'a';
            ch[t]++;
        }
        if (error[i] >= '0' && error[i] <= '9') {
            int t = error[i] - '0';
            num[t]++;
        }
        i++;
    }
    
    i = 0;
    while (right[i] != '\0')
    {
        if (right[i] == '_' && space > 0) {
            i++;
            continue;
        }
        if (right[i] == ',' && comma > 0)   {
            i++;
            continue;
        }
        if (right[i] == '.' && dot > 0)
            {
            i++;
            continue;
        }
        if (right[i] == '-' && minus > 0)
         {
            i++;
            continue;
        }
        
        if (right[i] >= 'A' && right[i] <= 'Z') {
            int t = right[i] - 'A';
            if (ch[t] > 0 || shift > 0) {
                i++;
                continue;
            }
        }
        if (right[i] >= 'a' && right[i] <= 'z') {
            int t = right[i] - 'a';
            if (ch[t] > 0)
         {
            i++;
            continue;
        }
        }
        if (right[i] >= '0' && right[i] <= '9') {
            int t = right[i] - '0';
            if (num[t] > 0)
         {
            i++;
            continue;
        }
        }
        printf("%c", right[i]);
        i++;
    }
    printf("\n");
    return 0;
}
```

## 总结

1、每一次定义字符数组的时候都要小心，如果题目说字符串长度不超过1000，那么你要定义长度为1001的字符串数组，不然'\0'没地放，就会导致运行错误
2、一定要注意题目所说的空格是'_'而不是' '，切记切记切记！