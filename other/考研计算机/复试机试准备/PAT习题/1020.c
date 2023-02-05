/*
* 1020题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct yb {
    double item;
    double value;
    double danjia;
}yb;

int compare(const void *A, const void *B) {
    yb a = *(yb*)A;
    yb b = *(yb*)B;
    if (b.danjia - a.danjia > 0.0)
        return 1;
    else if (b.danjia - a.danjia == 0.0)
        return 0;
    else 
        return -1;
    //return a.danjia - b.danjia;
}

int main() {
    int type, need;
    double sum = 0.0;
    yb *y;
    scanf("%d%d", &type, &need);
    
    y = (yb*) malloc(type * sizeof(yb));

    for (int i = 0; i < type; i++)
        scanf("%lf", &y[i].item);
    
    for (int i = 0; i < type; i++)
    {
        scanf("%lf", &y[i].value);
        y[i].danjia = y[i].value / y[i].item;
    }

    qsort(y, type, sizeof(yb), compare);

    int cnt = 0;
    for (int i = 0; i < type; i++)
    {
        cnt += y[i].item;
        if (cnt > need) {
            if (i != 0)
                sum += (double)(need - (cnt - y[i].item) ) * y[i].danjia;
            else 
                sum += (double)(need) * y[i].danjia;
            break;
        }
        else if (cnt == need) {
            sum += y[i].value;
            break;
        }
        else 
            sum += y[i].value;
        //测试的时候可能会用到这行代码
        //printf("%d %lf %lf\n",i ,y[i].item, y[i].danjia);
    }
    
    printf("%.2lf\n",sum);
    return 0;
}