/*
* 1026题 代码存档
*/
#include<stdio.h>
#include <stdlib.h>
#include<string.h>

int main() {
    int num;
    int max = 0, tmp = 0;
    int sum = 1;
    char c;
    scanf("%d %c", &num, &c);
    //printf("%d %c\n", num, c);
    
    int i = 3;
    for (; sum <= num; i+=2)
    {
        sum += i*2;
        //printf("%d\n", sum);
    }
    tmp = i - 2;
    max = tmp - 2;

    //打印上三角
    for (i = max; i > 0; i-= 2)
    {
        int j = max - i;
        while (j > (max - i) / 2)
        {
            printf(" ");
            j--;
        }
        for (j = i; j > 0; j--)
        {
            printf("%c", c);
        }
        printf("\n");
    }
    
    //打印下三角
    for (i = 3; i <= max; i+=2)
    {
        int j = max - i;
        while (j > (max - i) / 2)
        {
            printf(" ");
            j--;
        }
        for (j = i; j > 0; j--)
        {
            printf("%c", c);
        }
        printf("\n");
    }
    
    sum = sum - tmp * 2;
    num = num - sum;
    printf("%d\n", num);
    return 0;
}