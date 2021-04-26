/*
* 1003题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void is(char str[]) {
    int flag = 1;
    int a = 0, b = 0, c = 0 , i;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != 'P' &&
        str[i] != 'A' &&
        str[i] != 'T' ) {
            flag = 0;
            break;
        }
        if (str[i] == 'P')
            a = i;
        if (str[i] == 'T')
            b = i;
    }
    c = i - b- 1;
    b = b - a - 1;
    //printf("flag:%d; a:%d; b:%d; c:%d;\n", flag, a, b, c);
    if (a * b == c && flag == 1 && b != 0)
        puts("YES");
    else 
        puts("NO");
}

int main() {
    char str[100];
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        scanf("%s", str);
        is(str);
    }
    
    return 0;
}