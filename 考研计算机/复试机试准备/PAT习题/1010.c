/*
* 1010题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num[100];
    int top = 0, top1 = 0;
    int in;
    while (~scanf("%d",&in))
    {
        num[top++] = in;
    }
    //int i1 = 0, j1 = 0;
    for (int i = 0, j = 1; j < top; i+=2,j+=2)
    {
        if (num[j] != 0) {
            num[top1] = num[i] * num[j];
            num[top1 + 1] = num[j] - 1;
            top1 += 2;

        }
        else if (num[i] == 0) {
            num[top1] = num[i] * num[j];
            num[top1 + 1] = num[j];
            top1 += 2;
        }
    }
    for (int i = 0; i < top1; i++)
    {
        if (i != top1 - 1)
            printf("%d ",num[i]);
        else 
            printf("%d\n",num[i]);
    }
    
    return 0;
}