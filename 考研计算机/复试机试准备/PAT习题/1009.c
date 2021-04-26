/*
* 1009题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>

void reverse(char *str, int l,int r) {
    if (NULL == str)
        return ;
    for (int i = l, j = r; i < j; i++, j--)
    {
        char t = str[i];
        str[i] = str[j];
        str[j] = t;
    }
}

int main() {
    char in[81];
    int len = 0;
    int temp = 0;

    gets(in);
    while (in[len] != '\0')
    {
        len++;
    }
    
    reverse(in,0, len - 1);
    for (int i = 0; i <= len; i++)
    {
        if (in[i] == ' ' || i == len) {
            reverse(in, temp, i - 1);
            temp = i + 1;
        }
    }
    puts(in);

    return 0;
}