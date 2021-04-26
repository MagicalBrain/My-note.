# 【PAT Basic】1042 字符统计 (20 分)

## 题目描述

请编写程序，找出一段给定文字中出现最频繁的那个英文字母。

输入格式：
输入在一行中给出一个长度不超过 1000 的字符串。字符串由 ASCII 码表中任意可见字符及空格组成，至少包含 1 个英文字母，以回车结束（回车不算在内）。

输出格式：
在一行中输出出现频率最高的那个英文字母及其出现次数，其间以空格分隔。如果有并列，则输出按字母序最小的那个字母。统计时不区分大小写，输出小写字母。

输入样例：
This is a simple TEST.  There ARE numbers and other symbols 1&2&3...........

输出样例：
e 7

## 基本思路

## 代码

```c++
/*
* 1042题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[1001];
    int c[26] = {0};
    gets(str);
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' ') {
            i++;
            continue;
        }
        else {
            int t;
            if (str[i] >= 'A' && str[i] <= 'Z') {
                t = str[i] - 'A';
                c[t]++;
            }
            if (str[i] >= 'a' && str[i] <= 'z') {
                t = str[i] - 'a';
                c[t]++;
            }   
        }
        i++;
    }

    int max = 0;
    char max_char;
    for (int i = 0; i < 26; i++)
    {
        if (max < c[i]) {
            max = c[i];
            max_char = 'a' + i;
        }
    }
    
    printf("%c %d\n", max_char, max);
    return 0;
}
```

## 总结