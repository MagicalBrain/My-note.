/*
* 4.2题 2/4 [编程题]糕点问题 代码存档
* 【面试 编程题】2/4 美团
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *A, const void *B) {
    int a = *(int*) A;
    int b = *(int*) B;
    return b - a;
}

int main() {
    int n, x;
    int *in;
    int cnt = 0;
    scanf("%d%d", &n, &x);
    
    in = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &in[i]);
    }

    qsort(in, n, sizeof(int), cmp);

    int t = in[x - 1];
    if (t == 0) {
        for (int i = 0; i < x; i++)
        {
            if (in[i] != 0)
                cnt++;
        }
    }
    else {
        for (int i = 0; i < n; i++)
        {
            if (in[i] >= t)
                cnt++;
            else 
                break;
        }
    }
    
    printf("%d\n", cnt);
    return 0;
}