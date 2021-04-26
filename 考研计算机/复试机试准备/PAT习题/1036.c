/*
* 1036题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    char c;
    scanf("%d %c",&n, &c);
    int h = n / 2;
    if (n % 2 != 0)
        h += 1;
    for (int i = 0; i < h; i++)
    {
        if (i == 0 || i == h - 1) {
            for (int j = 0; j < n; j++)
                printf("%c", c);
        }
        else {
            printf("%c", c);
            for (int j = 1; j < n - 1; j++)
                printf(" ");
            printf("%c", c);
        }
        printf("\n");
    }
    
    return 0;
}