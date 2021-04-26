/*
* 02【面试 编程题】32 已排序数组两数之差最小的数（远景智能-2021秋季招聘软件技术笔试题（第二批）
* 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    char *input_data = (char*) malloc(10010 * sizeof(char));
    memset(input_data, 0, 10010 * sizeof(char));

    char *c = (char*) malloc(10001 * sizeof(char));

    int *data = (int*) malloc(10000 * sizeof(int));
    memset(data, 0, 10000 * sizeof(int));

    int *tmp;
    int num = 0, cnt = 0;
    int k, x;
    
    gets(input_data);
    scanf("%d", &k);
    scanf("%d", &x);
    //printf("k = %d \n x = %d\n", k, x);
    
    int ic = 0;
    while (input_data[cnt] != '\0')
    {
        if (input_data[cnt] != ',')
        {
            c[ic] = input_data[cnt];
            ic++;
        }
        else {
            c[ic] = '\0';
            data[num++] = atoi(c);
            ic = 0;
        }
        cnt++;
    }
    c[ic] = '\0';
    data[num++] = atoi(c);
    
    //num = cnt - 2;
    //printf("num = %d\n", num);
    //printf("ic = %d\n", ic);
    
    tmp = (int*) malloc(num * sizeof(int));
    memset(tmp, 0, num * sizeof(int));
    for (int i = 0; i < num; i++)
    {
        tmp[i] = abs(data[i] - x);
    }

    int st = 0, ed = num -1;
    while ( ed > st )
    {
        if (ed - st == k - 1) {
            //printf("st = %d\ned = %d\n", st, ed);
            break;
        }
        if (tmp[st] == tmp[ed]) {
            ed--;
            continue;
        }
        while (tmp[st] > tmp[ed] && ed - st != k - 1)
            st++;
        while (tmp[ed] > tmp[st] && ed - st != k - 1)
            ed--;
    }
    for (int i = st; i <= ed; i++)
    {
        //printf("i = %d ",i);
        if (i == st)
            printf("%d", data[i]);
        else 
            printf(",%d", data[i]);
        //printf("\n");
    }
    printf("\n");
    
    free(tmp);
    free(data);
    free(input_data);
    return 0;
}