# 【PAT Basic】1003 我要通过！ (20 分)

## 题目描述

“答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于 PAT 的“答案正确”大派送 —— 只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。
得到“答案正确”的条件是：

字符串中必须仅有 P、 A、 T这三种字符，不可以包含其它字符；
任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a、 b、 c 均或者是空字符串，或者是仅由字母 A 组成的字符串。
现在就请你为 PAT 写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。

输入格式：

每个测试输入包含 1 个测试用例。第 1 行给出一个正整数 n (<10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过 100，且不包含空格。

输出格式：

每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出 YES，否则输出 NO。

输入样例：

8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA
输出样例：

YES
YES
YES
YES
NO
NO
NO
NO

## 基本思路

## 代码

### 网上博客的代码

```c++
#include <stdio.h>
#include <string.h>
#define L 101

int main(){
    int n;
    scanf("%d", &n);
    int a,b,c;//a,b,c分别为P之前的A的个数、PT间的A的个数、T之后的A的个数
    char string[L];
    for (int i = 0; i < n; ++i) {
        scanf("%s", string);
        int temp_t ;//temp_t暂时记录数组中字符为T时的下标
        int true = 1;//用于排除不符合题意的情况
        for (int j = 0; j < strlen(string); ++j) {
            if (string[j] == 'P')
                a = j;
            else if (string[j] == 'T')
                temp_t = j;
            else if (string[j] != 'A' )
                true = 0;//若字符串中没有A，则不符合题意
        }
        b = temp_t - a - 1;
        c = strlen(string) - temp_t -1;
        if (b == 0)//若PT之间无A，不符合题意
            true = 0;
        if (c == b * a && true == 1)//由题找规律得：c=ab
            printf("YES\n");
        else
            printf("NO\n");
    }
}


```

## 总结

这题看似简单，实则另有玄机，需要自己找出'A'字符的数量关系才可作出这道题。
