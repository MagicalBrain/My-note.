/*
* 01题 风电场风机发电问题 代码存档
* 【面试 编程题】31 风电场风机发电调度问题（远景智能-2021秋季招聘软件技术笔试题（第二批）
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    char str1[1000];
    char str2[1000];
    int *weight, *value, *dp;
    int num = 0, limit;
    //scanf("%d%d", &num, &limit);

    weight = (int*) malloc(1000 * sizeof(int));
    value = (int*) malloc(1000 * sizeof(int));
    dp = (int*) malloc( 1000 * sizeof(int));
    
    //输入数据
    int *input_data = (int*) malloc(1000 * sizeof(int));
    int cnt = 0;
    while (scanf("%d", &input_data[cnt]) != EOF)
    {
        cnt++;
    }
    num = cnt / 2;
    for (int i = 0; i < num; i++)
        weight[i] = input_data[i];
    for (int i = num; i < cnt - 1; i++)
        value[i - num] = input_data[i];
    
    limit = input_data[cnt - 1];
    printf("%d %d\n", num, limit);
    
    for (int i = 0; i < limit; i++)
    {
        dp[i] = 0;
    }
    
    for (int i = 0; i < num; i++)
    {
        for (int v = limit; v >= weight[i]; v--)
        {
            dp[v] = max(dp[v], dp[v - weight[i] ] + value[i]);
        }
    }
    
    int max_value = 0;
    for (int i = 0; i <= limit; i++)
    {
        max_value = max_value < dp[i] ? dp[i] : max_value;
    }
    printf("%d\n", max_value);
    return 0;
}