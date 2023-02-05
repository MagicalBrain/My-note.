/*
* 1021题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct number{
    int num;
    int Hz;
}number;

int cmp(const void *A, const void *B) {
    number a = *(number*)A;
    number b = *(number*)B;
    if (b.num == a.num)
        return b.Hz - a.Hz;
    return a.num - b.num;
}

int main() {
    char in[1001];
    scanf("%s", in);
    number num[10];
    for (int i = 0; i < 10; i++)
    {
        num[i].num = 0;
        num[i].Hz = 0;
    }
    for (int i = 0; in[i] != '\0'; i++)
    {
        int t = in[i] - '0';
        num[t].num = t;
        num[t].Hz++;
    }
    
    qsort(num,10,sizeof(number), cmp);
    for (int i = 0; i < 10; i++)
    {
        if (num[i].Hz == 0)
            continue;
        printf("%d:%d\n", num[i].num, num[i].Hz);
    }
    
    return 0;
}