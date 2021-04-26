/*
* 1024题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int str2num(char str[], int len) {
    int re = 0;
    int t = 1;
    for (int i = len - 1; i >= 0; i--)
    {
        //printf("%d\n", re);
        re += (str[i] - '0') * t;
        t *= 10;
    }
    
    return re;
}

int main() {
    char flag1, flag2;
    char str[10000];
    
    char num[20000];
    int top = 0;
    int n;

    char exp[5];
    int top_e = 0;
    int exp_num;
    
    scanf("%s", str);
    //printf("%s\n", str);

    int i = 0;
    while (str[i] != 'E')
    {
        if (i == 0) 
            flag1 = str[i];
        else if (str[i] != '.')
            num[top++] = str[i];
        i++;
    }
    num[top] = '\0';

    flag2 = str[++i];
    i++;
    while (str[i] != '\0')
    {
        exp[top_e++] = str[i];
        i++;
    }
    exp[top_e] = '\0';
    
    exp_num = str2num(exp, top_e);

    int zero = str2num(num, top);
    if (zero == 0) {
        printf("%d\n", zero);
        return 0;
    }
    
    //如果是负数就打印负号  
    if (flag1 == '-')
        printf("-");
    //如果指数为0就打印原来的数不变
    if (exp_num == 0) {
        for ( i = top - 1; i > 0; i--)
        {
            num[i + 1] = num[i];
        }
        top++;
        num[top] = '\0';
        num[1] = '.';
        printf("%s",num);
    }
    //如果指数是负数就在前面加 0.0……
    else if (flag2 == '-') {
        printf("%d.",0);
        for (i = 0; i < exp_num - 1; i++)
        {
            printf("%d",0);
        }
        printf("%s",num);
    }
    //如果指数是正数就在后面添0
    else  {
        if (exp_num < top - 1) {
            for (i = top - 1; i > exp_num; i--)
            {
                num[i + 1] = num[i];
            }
            top++;
            num[exp_num + 1] = '.';
            num[top] = '\0';
            printf("%s",num);
        }
        else {
            printf("%s",num);
            for (i = top; i <= exp_num; i++)
            {
                printf("%d",0);
            }
            num[i] = '\0';
        }
    }
    printf("\n");
    //printf("%s\n", num);
    //printf("%d\n", exp_num);
    
    
    return 0;
}