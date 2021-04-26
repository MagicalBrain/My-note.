# 【PAT Basic】1043 输出PATest (20 分)

## 题目描述

给定一个长度不超过 $10^​$4​​  的、仅由英文字母构成的字符串。请将字符重新调整顺序，按 PATestPATest.... 这样的顺序输出，并忽略其它字符。当然，六种字符的个数不一定是一样多的，若某种字符已经输出完，则余下的字符仍按 PATest 的顺序打印，直到所有字符都被输出。

输入格式：
输入在一行中给出一个长度不超过 $10​^4$​​  的、仅由英文字母构成的非空字符串。

输出格式：
在一行中按题目要求输出排序后的字符串。题目保证输出非空。

输入样例：
redlesPayBestPATTopTeePHPereatitAPPT

输出样例：
PATestPATestPTetPTePePee

## 基本思路

## 代码

```c++
/*
* 1043题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[10001];
    char need[7] = "PATest";
    int map[6] = {0};
    gets(str);

    int i = 0;
    while (str[i] != '\0')
    {
        for (int j = 0; j < 6; j++)
        {
            if (str[i] == need[j])
                map[j]++;
        }
        
        i++;
    }

    int cnt = 0;
    while (cnt < 6)
    {
        cnt = 0;
        for (int i = 0; i < 6; i++)
        {
            if (map[i] != 0) {
                printf("%c", need[i]);
                map[i]--;
            }
            else 
                cnt++;
        }
    }
    printf("\n");
    
    return 0;
}
```

## 总结
