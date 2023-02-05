/*
* 1005题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int hash[101];
    memset(hash, 0, 101 * sizeof(int));
    int key[101];
    memset(key, 0, 101 * sizeof(int));
    int max = 0, min = 101;

    int *num;
    int len;
    scanf("%d", &len);
    num = (int*) malloc(len * sizeof(int));
    
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &num[i]);
        if (num[i] > max)
            max = num[i];
        if (num[i] < min)
            min = num[i];
        
        key[num[i]]++;

        int t = num[i];
        while (t != 1 )
        {
            if (t % 2 == 0)
                t /= 2;
            else 
                t = (3 * t + 1) / 2;
            if (t <= 100)
                hash[t] += 1;
        }        
    }

    int first = 1;
    for (int i = max; i >= min; i--)
    {
        if (hash[i] == 0 && key[i] == 1 && first == 1) {
            printf("%d", i);
            first = 0;
        }
        else if (hash[i] == 0 && key[i] == 1)
            printf(" %d",i);
    } 
    printf("\n");
    
    return 0;
}