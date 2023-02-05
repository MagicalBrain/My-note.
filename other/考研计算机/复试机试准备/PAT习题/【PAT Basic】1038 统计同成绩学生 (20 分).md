# 【PAT Basic】1038 统计同成绩学生 (20 分)

## 题目描述

本题要求读入 N 名学生的成绩，将获得某一给定分数的学生人数输出。

输入格式：
输入在第 1 行给出不超过$ 10^​5 $​​  的正整数 N，即学生总人数。随后一行给出 N 名学生的百分制整数成绩，中间以空格分隔。最后一行给出要查询的分数个数 K（不超过 N 的正整数），随后是 K 个分数，中间以空格分隔。

输出格式：
在一行中按查询顺序给出得分等于指定分数的学生人数，中间以空格分隔，但行末不得有多余空格。

输入样例：
10
60 75 90 55 75 99 82 90 75 50
3 75 90 88

输出样例：
3 2 0

## 基本思路

## 代码

```c++
/*
* 1038题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n1, n2;
    int *in1, *in2;
    int *cnt;
    scanf("%d", &n1);
    in1 = (int*) malloc(n1 * sizeof(int));
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &in1[i]);
    }

    scanf("%d", &n2);
    in2 = (int*) malloc(n2 * sizeof(int));
    cnt = (int*) malloc(n2 * sizeof(int));
    memset(cnt, 0, n2 * sizeof(int));
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &in2[i]);
    }
    
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (in1[i] == in2[j])
                cnt[j]++;
        }
    }
    
    for (int i = 0; i < n2; i++)
    {
        if (i == 0)
            printf("%d", cnt[i]);
        else 
            printf(" %d", cnt[i]);
    }
    printf("\n");
    return 0;
}
```

最后一个测试点超时了，考虑使用哈希数组。

```c++
/*
* 1038题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n1, n2;
    int *in1, *in2;
    int cnt[100001] = {0};
    
    scanf("%d", &n1);
    in1 = (int*) malloc(n1 * sizeof(int));
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &in1[i]);
        cnt[ in1[i] ]++;
    }

    scanf("%d", &n2);
    in2 = (int*) malloc(n2 * sizeof(int));
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &in2[i]);
    }
    
    for (int i = 0; i < n2; i++)
    {
        if (i == 0)
            printf("%d", cnt[ in2[i] ]);
        else 
            printf(" %d", cnt[ in2[i] ]);
    }
    printf("\n");
    return 0;
}
```

这下就不会超时了。

## 总结

这次反应很不错，看到超时就知道要用哈希数组了。
