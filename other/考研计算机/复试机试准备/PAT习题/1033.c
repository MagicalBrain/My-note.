/*
* 1033题 代码存档
*/
#include<stdio.h>
#include <stdlib.h>
#include<string.h>

int num[10] = {0};
int ch[26] = {0};
int space = 0;      //空格
int comma = 0;      //逗号
int minus = 0;      //负号
int dot = 0;        //点
int shift = 0;   //上档键

int main()  {
    char error[100001];
    char right[100001];
    gets(error);
    gets(right);

    int i = 0;
    while (error[i] != '\0')
    {
        if (error[i] == '_')
            space++;
        if (error[i] == ',')
            comma++;
        if (error[i] == '.')
            dot++;
        if (error[i] == '-')
            minus++;
        if (error[i] == '+')
            shift++;
        
        if (error[i] >= 'A' && error[i] <= 'Z') {
            int t = error[i] - 'A';
            ch[t]++;
        }
        if (error[i] >= 'a' && error[i] <= 'z') {
            int t = error[i] - 'a';
            ch[t]++;
        }
        if (error[i] >= '0' && error[i] <= '9') {
            int t = error[i] - '0';
            num[t]++;
        }
        i++;
    }
    
    i = 0;
    while (right[i] != '\0')
    {
        if (right[i] == '_' && space > 0) {
            i++;
            continue;
        }
        if (right[i] == ',' && comma > 0)   {
            i++;
            continue;
        }
        if (right[i] == '.' && dot > 0)
            {
            i++;
            continue;
        }
        if (right[i] == '-' && minus > 0)
         {
            i++;
            continue;
        }
        
        if (right[i] >= 'A' && right[i] <= 'Z') {
            int t = right[i] - 'A';
            if (ch[t] > 0 || shift > 0) {
                i++;
                continue;
            }
        }
        if (right[i] >= 'a' && right[i] <= 'z') {
            int t = right[i] - 'a';
            if (ch[t] > 0)
         {
            i++;
            continue;
        }
        }
        if (right[i] >= '0' && right[i] <= '9') {
            int t = right[i] - '0';
            if (num[t] > 0)
         {
            i++;
            continue;
        }
        }
        printf("%c", right[i]);
        i++;
    }
    printf("\n");
    return 0;
}