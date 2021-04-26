/*
* 1029题 代码存档
*/
#include<stdio.h>
#include <stdlib.h>
#include<string.h>

int main() {
    char str[81];
    char right[81];

    int c[26] = {0};
    int num[10] = {0};
    int space = 0;

    scanf("%s", right);
    scanf("%s", str);
    
    int i = 0, j = 0;
    while (right[j] != '\0')
    {
        if (str[i] != right[j]) {
            //大写字母处理
            if (right[j] >= 'A' && right[j] <= 'Z') {
                int id = right[j] - 'A';
                if (c[id] == 0)
                    printf("%c", right[j]);
                c[id]++;
            }
            //小写字母处理
            if (right[j] >= 'a' && right[j] <= 'z') {
                int id = right[j] - 'a';
                if (c[id] == 0)
                    printf("%c", right[j] - ('a' - 'A') );
                c[id]++;
            }
            //数字键处理
            if (right[j] >= '0' && right[j] <= '9') {
                int id = right[j] - '0';
                if (num[id] == 0)
                    printf("%c", right[j]);
                num[id]++;
            }
            //空格键处理
            if (right[j] == '_') {
                if (space == 0)
                    printf("%c", '_');
                space++;
            }
        }
        else {
            if (str[i] != '\0')
                i++;
        }
        j++;
    }
    printf("\n");
    return 0;
}