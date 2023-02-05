/*
* 1040题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[100001];
    gets(str);
    int np = 0, na = 0, nt = 0;
    long long cnt = 0, sum = 0;
    
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == 'T')
            nt++;
        i++;
    }

    while (str[na] != '\0') {
        if (str[na] == 'T')
            nt--;
        if (str[na] == 'P')
            np++;
        if (str[na] == 'A')
            sum += np * nt;
        na++;
    }
    printf("%lld\n", sum %  1000000007);
    return 0;
}