/*
* 求[m,n]区间内的所有非对称的素数
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//一个判断是否是素数的函数
int is_Sushu(int n) {
    int false = 0, true = 1;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    
    return true;
}

//一个判断是否对称的函数
int is_com(int n) {
    int *s;
    int true = 1, false = 0;
    int t = n;
    int re = 0;
    int len = 0;
    
    while (t > 0) {
        t /= 10;
        len++;
    }

    s = (int*) malloc( len * sizeof(int));

    int top = 0;
    while (n > 0)
    {
        s[top++] = n % 10;
        n /= 10;
    }
    for (int i = 0, j = top - 1; i < j; i++, j--)
    {
        if (s[i] != s[j])
            return false;
    }
    return true;
}

int main() {
    int m,n;
    puts("请输入m,n");
    scanf("%d%d",&m, &n);
    for (int i = m; i <= n; i++)
    {
        if (is_com(i) == 0 && is_Sushu(i) == 1)
            printf("%d ",i);
    }
    printf("\n");
    //printf("%d\n",is_Sushu(num));
    //printf("%d\n",is_com(num));
    return 0;
}