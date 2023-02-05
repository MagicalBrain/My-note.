/*
* 1023题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int num[10];
    int *re;
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &num[i]);
        sum += num[i];
    }
    re = (int*) malloc (sum * sizeof(int));
    
    int i = 0, j = 0;
    while (i < sum)
    {
        if (i == 0) {
            while (j < 10)
            {
                if (j != 0 && num[j] != 0) {
                    re[i] = j;
                    num[j]--;
                    break;
                }
                j++;
            }
        }
        else {
            j = 0;
            while (j < 10)
            {
                if (num[j] != 0) {
                    re[i] = j;
                    num[j]--;
                    break;
                }
                j++;
            }
        }
        i++;
    }
    
    for (int i = 0; i < sum; i++)
    {
        printf("%d",re[i]);
    }
    printf("\n");
    return 0;
}