/*
* 4.3题 3/4 [编程题]糕点问题 代码存档
* 【面试 编程题】3/4 美团
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    while (n)
    {
        int num;
        int *data;
        scanf("%d", &num);

        data = (int*) malloc(num * sizeof(int));
        for (int i = 0; i < num; i++)
        {
            scanf("%d", &data[i]);
        }
        int l = 0, r;
        int sum = 0, max = 0;
        while (l < num)
        {
            sum = data[l];
            for ( r = (l + 1 + num) % num; r != l; r = (r + 1) % num)
            {
                sum += data[r];
                if (max < sum) {
                    max = sum;
                    //printf("l = %d, r = %d, max =  %d\n", l, r, max);
                }
            }
            //sum -= data[l];
            l++;
            
        }
        printf("%d\n", max);

        n--;
    }
    
    
    return 0;
}