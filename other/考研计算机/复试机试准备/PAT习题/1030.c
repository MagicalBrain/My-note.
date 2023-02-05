/*
* 1030题 代码存档
*/
#include<stdio.h>
#include <stdlib.h>
#include<string.h>

int compare(const void *A, const void *B) {
    long a = *(long*)A;
    long b = *(long*)B;
    return a - b;
}

int main() {
    int n;
    long p;
    long *num;
    
    int cnt = 0;
    int max_cnt = 0;

    scanf("%d%ld", &n, &p);

    num = (long*) malloc( n * sizeof(long));
    for (int i = 0; i < n; i++)
    {
        scanf("%ld", &num[i]);
    }

    qsort(num, n, sizeof(long), compare);
    
    for (int i = 0; i < n; i++)
    {
        //cnt = 0;
        for (int j = i + cnt; j < n; j++)
        {
            if (num[j] <= num[i] * p) {
                cnt++;
            }
            else
                break;      //不break会超时
        }
        if (cnt > max_cnt)
            max_cnt = cnt;
        cnt--;
    }
    
    printf("%d\n", max_cnt);
    
    return 0;
}