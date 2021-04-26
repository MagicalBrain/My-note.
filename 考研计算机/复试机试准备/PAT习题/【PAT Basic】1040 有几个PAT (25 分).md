# 【PAT Basic】1040 有几个PAT (25 分)

## 题目描述

字符串 APPAPT 中包含了两个单词 PAT，其中第一个 PAT 是第 2 位(P)，第 4 位(A)，第 6 位(T)；第二个 PAT 是第 3 位(P)，第 4 位(A)，第 6 位(T)。
现给定字符串，问一共可以形成多少个 PAT？

输入格式：
输入只有一行，包含一个字符串，长度不超过10​5​​ ，只包含 P、A、T 三种字母。

输出格式：
在一行中输出给定字符串中包含多少个 PAT。由于结果可能比较大，只输出对 1000000007 取余数的结果。

输入样例：
APPAPT

输出样例：
2

## 基本思路

## 代码

```c++
/*
* 1040题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[100001];
    gets(str);
    int np = 0, na = 0, nt = 0;
    long long cnt = 0, sum = 0;
    
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == 'T')
            nt++;
        i++;
    }

    while (str[na] != '\0') {
        if (str[na] == 'T')
            nt--;
        if (str[na] == 'P')
            np++;
        if (str[na] == 'A')
            sum += np * nt;
        na++;
    }
    printf("%lld\n", sum %  1000000007);
    return 0;
}
```

## 总结

根据柳婼的代码思路来写的，真的牛逼。
以后如果遇到类似的题目，应当想到同样的思路。