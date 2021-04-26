# 【PAT Basic】1029 旧键盘 (20 分)

## 题目描述

旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及实际被输入的文字，请你列出肯定坏掉的那些键。

输入格式：
输入在 2 行中分别给出应该输入的文字、以及实际被输入的文字。每段文字是不超过 80 个字符的串，由字母 A-Z（包括大、小写）、数字 0-9、以及下划线 _（代表空格）组成。题目保证 2 个字符串均非空。

输出格式：
按照发现顺序，在一行中输出坏掉的键。其中英文字母只输出大写，每个坏键只输出一次。题目保证至少有 1 个坏键。

输入样例：
7_This_is_a_test
_hs_s_a_es

输出样例：
7TI

## 基本思路

## 代码

```c++
/*
* 1028题 代码存档
*/
#include<stdio.h>
#include <stdlib.h>
#include<string.h>

int main() {
    char str[81];
    char right[81];

    int c[26] = {0};
    int num[10] = {0};
    int space = 0;

    scanf("%s", right);
    scanf("%s", str);
    
    int i = 0, j = 0;
    while (right[j] != '\0')
    {
        if (str[i] != right[j]) {
            //大写字母处理
            if (right[j] >= 'A' && right[j] <= 'Z') {
                int id = right[j] - 'A';
                if (c[id] == 0)
                    printf("%c", right[j]);
                c[id]++;
            }
            //小写字母处理
            if (right[j] >= 'a' && right[j] <= 'z') {
                int id = right[j] - 'a';
                if (c[id] == 0)
                    printf("%c", right[j] - ('a' - 'A') );
                c[id]++;
            }
            //数字键处理
            if (right[j] >= '0' && right[j] <= '9') {
                int id = right[j] - '0';
                if (num[id] == 0)
                    printf("%c", right[j]);
                num[id]++;
            }
            //空格键处理
            if (right[j] == '_') {
                if (space == 0)
                    printf("%c", '_');
                space++;
            }
        }
        else {
            if (str[i] != '\0')
                i++;
        }
        j++;
    }
    printf("\n");
    return 0;
}
```

## 总结
