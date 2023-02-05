/*
* 1015题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct stu{
    char ID[9];
    int de;
    int cai;
    int sum;
}stu;

int compare_func(const void* A, const void* B) {
    stu* a = (stu*) A;
    stu* b = (stu*) B;

    //    若总分相同，再比较德分
    if (b->sum == a->sum) {
        //  若德分相同，按准考证号升序
        if (b->de == a->de)
            return strcmp(a->ID, b->ID);
        else
            return b->de - a->de;
    }
    return b->sum - a->sum;
}

int main() {
    int N, L, M;
    scanf("%d%d%d", &N, &L, &M);

    stu *data = (stu*) malloc( (N + 1) * sizeof(stu));
    stu *level1 = (stu*) malloc( (N + 1) * sizeof(stu));
    int len1 = 0;
    stu *level2 = (stu*) malloc( (N + 1) * sizeof(stu));
    int len2 = 0;
    stu *level3 = (stu*) malloc( (N + 1) * sizeof(stu));
    int len3 = 0;
    stu *level4 = (stu*) malloc( (N + 1) * sizeof(stu));
    int len4 = 0;

    for (int i = 0; i < N; i++)
    {
        scanf("%s%d%d",data[i].ID, &data[i].de, &data[i].cai);
        data[i].sum = data[i].de + data[i].cai;
        if (data[i].de < L || data[i].cai < L)
            continue;
        //才德全尽——德才兼备的圣人
        else if (data[i].de >= M && data[i].cai >= M) {
            level1[len1++] = data[i];
        }
        //德胜才——君子
        else if (data[i].de >= M) {
            level2[len2++] = data[i];
        }
        //才德皆亡，也有德胜才者
        else if (data[i].de >= data[i].cai) {
            level3[len3++] = data[i];
        }
        else {
            level4[len4++] = data[i];
        }
    }
    
    printf("%d\n", len1 + len2 + len3 + len4);
    //排序
    //1
    qsort(level1, len1, sizeof(stu), compare_func);
    for (int i = 0; i < len1; i++)
    {
        printf("%s %d %d\n", level1[i].ID, level1[i].de, level1[i].cai);
    }
    //2
    qsort(level2, len2, sizeof(stu), compare_func);
    for (int i = 0; i < len2; i++)
    {
        printf("%s %d %d\n", level2[i].ID, level2[i].de, level2[i].cai);
    }
    //3
    qsort(level3, len3, sizeof(stu), compare_func);
    for (int i = 0; i < len3; i++)
    {
        printf("%s %d %d\n", level3[i].ID, level3[i].de, level3[i].cai);
    }
    //4
    qsort(level4, len4, sizeof(stu), compare_func);
    for (int i = 0; i < len4; i++)
    {
        printf("%s %d %d\n", level4[i].ID, level4[i].de, level4[i].cai);
    }
    return 0;
}