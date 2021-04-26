/*
* 1012题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, n;
    int a1 = 0, a2 = 0, a3 = 0,  a5 = 0;
    int flag = 1;
    float a4 = 0.0;
    
    int len[5] = {0};
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        if (num % 5 == 0 && num % 2 == 0) {
            a1 += num;
            len[0]++;
        }
        if (num % 5 == 1) {
            if (flag)
                a2 += num;
            else 
                a2 -= num;  
            flag = !flag;
            len[1]++;
        }
        if (num % 5 == 2) {
            a3++;
            len[2]++;
        }
        if (num % 5 == 3) {
            a4 += num;
            len[3]++;
        }
        if (num % 5 == 4) {
            if (num > a5)
                a5 = num;
            len[4]++;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        if (len[i] == 0)
            printf("%c", 'N');
        else if (i == 0)
            printf("%d",a1);
        else if (i == 1)
            printf("%d",a2);
        else if (i == 2)
            printf("%d",a3);
        else if (i == 3)
            printf("%0.1f",a4 / len[3]);
        else if (i == 4)
            printf("%d",a5);
        
        if (i != 4)
            printf(" ");
        else 
            printf("\n");
    }
    
    return 0;
}