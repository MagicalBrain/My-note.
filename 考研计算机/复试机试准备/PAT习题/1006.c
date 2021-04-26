/*
* 1006题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    int s[10];
    int top = 0;

    int num;
    scanf("%d", &num);

    while (num > 0)
    {
        s[top++] = num % 10;
        num /= 10;
    }

    for (int i = top - 1; i >= 0; i--)
    {
        if (i == 2)
            for (int j = 0; j < s[i]; j++)
                printf("B");
        if (i == 1)
            for (int j = 0; j < s[i]; j++)
                printf("S");
        if (i == 0)
            for (int j = 1; j <= s[i]; j++)
                printf("%d",j);
            
    }
    printf("\n");
    
    return 0;
}