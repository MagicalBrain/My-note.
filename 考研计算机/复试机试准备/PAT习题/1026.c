/*
* 1026题 代码存档
*/
#include<stdio.h>
#include <stdlib.h>
#include<string.h>

int main() {
    int c1, c2, CLK_TCK = 100, tmp;
    int hours = 3600, mins = 60;
    int hh = 0, mm = 0;
    
    scanf("%d%d",&c1, &c2);
    
    tmp = (c2 - c1) / 100;
    if ( c2 - c1 - tmp * 100 >= 50)
        tmp += 1;
    hh = tmp / hours;
    tmp -= hh * hours;
    mm = tmp / mins;
    tmp -= mm * mins;

    printf("%.2d:%.2d:%.2d\n",hh ,mm ,tmp);
    return 0;
}