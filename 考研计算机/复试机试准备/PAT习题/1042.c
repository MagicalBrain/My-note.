/*
* 1042题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[1001];
    int c[26] = {0};
    gets(str);
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' ') {
            i++;
            continue;
        }
        else {
            int t;
            if (str[i] >= 'A' && str[i] <= 'Z') {
                t = str[i] - 'A';
                c[t]++;
            }
            if (str[i] >= 'a' && str[i] <= 'z') {
                t = str[i] - 'a';
                c[t]++;
            }   
        }
        i++;
    }

    int max = 0;
    char max_char;
    for (int i = 0; i < 26; i++)
    {
        if (max < c[i]) {
            max = c[i];
            max_char = 'a' + i;
        }
    }
    
    printf("%c %d\n", max_char, max);
    return 0;
}