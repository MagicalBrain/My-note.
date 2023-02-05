/*
* 1038题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n1, n2;
    int *in1, *in2;
    int cnt[100001] = {0};
    
    scanf("%d", &n1);
    in1 = (int*) malloc(n1 * sizeof(int));
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &in1[i]);
        cnt[ in1[i] ]++;
    }

    scanf("%d", &n2);
    in2 = (int*) malloc(n2 * sizeof(int));
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &in2[i]);
    }
    
    for (int i = 0; i < n2; i++)
    {
        if (i == 0)
            printf("%d", cnt[ in2[i] ]);
        else 
            printf(" %d", cnt[ in2[i] ]);
    }
    printf("\n");
    return 0;
}