# 【PAT Basic】1032 挖掘机技术哪家强 (20 分)

## 题目描述

为了用事实说明挖掘机技术到底哪家强，PAT 组织了一场挖掘机技能大赛。现请你根据比赛结果统计出技术最强的那个学校。
输入格式：

输入在第 1 行给出不超过 10​5​​  的正整数 N，即参赛人数。随后 N 行，每行给出一位参赛者的信息和成绩，包括其所代表的学校的编号（从 1 开始连续编号）、及其比赛成绩（百分制），中间以空格分隔。

输出格式：
在一行中给出总得分最高的学校的编号、及其总分，中间以空格分隔。题目保证答案唯一，没有并列。

输入样例：
6
3 65
2 80
1 100
2 70
3 40
3 0

输出样例：
2 150

## 基本思路

## 代码

```c++
/*
* 1032题 代码存档
*/
#include<stdio.h>
#include <stdlib.h>
#include<string.h>

int main() {
    int name_sum[100000] = {0};
    int max = 0;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int id, score;
        scanf("%d%d", &id, &score);
        name_sum[id] += score;
    }
    
    int max_id = 1;
    max = name_sum[max_id];
    for (int i = 0; i < n; i++)
    {
        if (max < name_sum[i]) {
            max = name_sum[i];
            max_id = i;
        }   
    }
    printf("%d %d\n", max_id, max);
    
    return 0;
}
```

## 总结

注意题目要求的n是一个正整数，特殊情况在于n为1的时候。
