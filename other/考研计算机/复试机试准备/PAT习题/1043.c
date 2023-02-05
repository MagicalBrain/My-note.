/*
* 1043题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[10001];
    char need[7] = "PATest";
    int map[6] = {0};
    gets(str);

    int i = 0;
    while (str[i] != '\0')
    {
        for (int j = 0; j < 6; j++)
        {
            if (str[i] == need[j])
                map[j]++;
        }
        
        i++;
    }

    int cnt = 0;
    while (cnt < 6)
    {
        cnt = 0;
        for (int i = 0; i < 6; i++)
        {
            if (map[i] != 0) {
                printf("%c", need[i]);
                map[i]--;
            }
            else 
                cnt++;
        }
    }
    printf("\n");
    
    return 0;
}