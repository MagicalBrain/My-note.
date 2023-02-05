/*
* 1002题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum_this_number(char *n) {
    int sum = 0;
    int i = 0;
    while (n[i] != '\0')
    {
        sum += (n[i++] - '0');
    }
    return sum;
}

void write_this_number(int n) {
    int s[100];
    int top = 0;

    while (n > 0)
    {
        s[top++] = n % 10;
        n /= 10;
    }
    //s[top++] = n;
    for (top = top - 1; top >= 0; top--)
    {
        switch (s[top])
        {
            case 0:
                printf("ling");
                break;
            case 1:
                printf("yi");
                break;
            case 2:
                printf("er");
                break;
            case 3:
                printf("san");
                break;
            case 4:
                printf("si");
                break;
            case 5:
                printf("wu");
                break;
            case 6:
                printf("liu");
                break;
            case 7:
                printf("qi");
                break;
            case 8:
                printf("ba");
                break;
            case 9:
                printf("jiu");
                break;
            default:
                break;
        }
        if (top != 0)
            //printf("<>");
            printf(" ");
    }
    printf("\n");
}

int main()
{
    char n[101];
    char *str = n;
    int re = 0;
    //scanf("%s", n);    //输入一个数n
    gets(str);
    //puts(str);
    re = sum_this_number(str);
    //printf("各位数字和为：%d\n", re);
    printf("%d\n", re);
    write_this_number(re);
    return 0;
}