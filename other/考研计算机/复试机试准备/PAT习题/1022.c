/*
* 1022题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    long long a, b;
    int D;
    int re;
    int num[31];
    int top = 0;
    scanf("%lld%lld%d", &a, &b, &D);
    re = a + b;
    if (re == 0)
        printf("0\n");
    else {
        while (re > 0)
        {
            num[top++] = re % D;
            re /= D;
        }
        for (int i = top - 1; i >= 0; i--)
        {
            printf("%d",num[i]);
        }
        printf("\n");
    }
    
    return 0;
}