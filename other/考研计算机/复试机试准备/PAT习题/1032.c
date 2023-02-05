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