/*
* 1025题 代码存档
*/
#include<stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct node
{
    int address;
    int value;
    int next;
}LNode;

int main() {
    LNode *base;
    //base = (LNode*) malloc(sizeof(LNode));
    int base_address = 0;
    int len = 0, K;
    scanf("%d%d%d", &base_address, &len, &K);
    //printf("%d %d %d\n", base->address, len, K);
    base = (LNode*) malloc(len * sizeof(LNode));
    for (int i = 0; i < len; i++)
    {
        scanf("%d%d%d", &base[i].address, base[i].value, base[i].next);
    }
    
    return 0;
}