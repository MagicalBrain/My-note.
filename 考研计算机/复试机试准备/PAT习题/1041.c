/*
* 1041题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stu{
    char ID[20];
    int test_id;
    int exam_id;
}stu;

int main() {
    int stu_num, ask_num;
    stu *data;
    int *ask;
    scanf("%d", &stu_num);

    data = (stu*) malloc( stu_num * sizeof(stu));
    for (int i = 0; i < stu_num; i++)
    {
        scanf("%s %d %d", data[i].ID, &data[i].test_id, &data[i].exam_id);
    }

    scanf("%d", &ask_num);
    ask = (int*) malloc(ask_num * sizeof(int));
    for (int i = 0; i < ask_num; i++)
    {
        scanf("%d", &ask[i]);
    }
    
    for (int i = 0; i < ask_num; i++)
    {
        for (int j = 0; j < stu_num; j++)
        {
            if (ask[i] == data[j].test_id)
                printf("%s %d\n", data[j].ID, data[j].exam_id);
        }
        
    }
    
    return 0;
}