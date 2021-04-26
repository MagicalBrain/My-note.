/*
* 1007题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_Prime(int n) {
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    int len;
    scanf("%d",&len);

    int s[100000];
    int top = 0;
    int re;
    for (int i = 2; i <= len; i++)
    {
        if ( is_Prime(i))
            s[top++] = i;
    }

    for (int i = 0; i < top; i++)
    {
        printf("%d ", s[i]);
    }
    printf("\n");

    for (int i = 0, j = 1; j < top; i++, j++)
    {
        if (s[j] - s[i] == 2)
            re++;
    }
    printf("%d\n", re);
    
    return 0;
}