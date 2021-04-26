/*
* 1028题 代码存档
*/
#include<stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct birthday {
    char name[6];
    int year;
    int month;
    int day;
}Bday;

int Bdaycom(Bday a, Bday b) {
    if (a.year == b.year) {
        if (a.month == b.month)
            return a.day - b.day;
        else 
            return a.month - b.month;
    }
    else
        return a.year - b.year;
}

int main() {
    int now_year = 2014, now_month = 9, now_day = 6;
    int n, cnt = 0;
    int first = 0;
    scanf("%d", &n);

    Bday max, min;
    Bday *b = (Bday*) malloc(n * sizeof(Bday));
    //getchar();
    for (int i = 0; i < n; i++)
    {
        scanf("%s", b[i].name);
        scanf("%d/%d/%d", &b[i].year, &b[i].month, &b[i].day);

        //printf("\n");
        //printf("%s %d/%d/%d\n", b[i].name, b[i].year, b[i].month, b[i].day);
        //设置过滤的生日。
        if (b[i].year > now_year || b[i].year < now_year - 200)
            continue;
        else if (b[i].year == now_year && b[i].month > now_month)
            continue;
        else if (b[i].year == now_year && b[i].month == now_month && b[i].day > now_day)
            continue;
        else if (b[i].year == now_year - 200 && b[i].month < now_month)
            continue;
        else if (b[i].year == now_year - 200 && b[i].month == now_month && b[i].day < now_day)
            continue;
        
        if (first == 0) {
            max = b[i];
            min = b[i];
            first = 1;
        }
        else {
            if (Bdaycom(max, b[i]) > 0)
                max = b[i];
            if (Bdaycom(min, b[i]) < 0) 
                min = b[i];
        }
        cnt++;
    }
    if (cnt == 0) {
        printf("%d\n", 0);
    }
    else
        printf("%d %s %s\n", cnt, max.name, min.name);
    return 0;
}