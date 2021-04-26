/*
* 1001题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Callatz_Cnt(int x) {
    int cnt = 0;
    
    while (x != 1)
    {
        if (x % 2 ==0)
            x /= 2;
        else 
            x = (3 * x + 1) / 2;
            cnt++;
    }
    
    return cnt;
}

int main()
{
    int n;
    puts("请输入一个正整数");
    scanf("%d", &n);
    printf("需要 %d 步\n", Callatz_Cnt(n));

    return 0;
}