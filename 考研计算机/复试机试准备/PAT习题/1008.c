/*
* 1008题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>

void reverse(int *n, int l, int r) {
    if (r - l < 0)
        return ;
    
    for (int i = l, j = r; i < j; i++, j--)
    {
        int t = n[i];
        n[i] = n[j];
        n[j] = t;
    }
}

int main()
{
    int m,n;
    scanf("%d %d", &n, &m);

    m = m % n;  //关键一步，如果没有考虑到m可以大过n的话，会有几个测试用例过不了的。

    int *data = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
    }

    reverse(data, n - m, n - 1);
    reverse(data, 0, n - m - 1);
    reverse(data, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
            printf("%d ", data[i]);
        else
            printf("%d\n", data[i]);
    }
    return 0;
}