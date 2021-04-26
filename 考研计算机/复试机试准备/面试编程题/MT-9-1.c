/*
* 4.1题1/4 [编程题]糕点问题 代码存档
* 【面试 编程题】1/4 美团
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, m, a, b;
    
    int max, min;
    int Yes = 0;
    int No = 0;
    while (scanf("%d%d%d%d", &n, &m, &a, &b) != EOF) {
        Yes = 0;
        No = 0;
        if (a < b) {
            max = b, min = a;
        }
        else {
            max = a, min = b;
        }

        int *cake = (int*) malloc(m * sizeof(int));
        for (int i = 0; i < m; i++)
            scanf("%d", &cake[i]);
        
        for (int i = 0; i < m; i++)
        {
            if (cake[i] < min || cake[i] > max) {
                printf("NO\n");
                No = 1;
                break;
            }
            if (cake[i] == min)
                Yes++;
            if (cake[i] == max)
                Yes++;
        }
        if (No == 0) {
            if (Yes >= 2)
                printf("YES\n");
            else if (Yes == 1 && n - m >= 1)
                printf("YES\n");
            else if (n - m >= 2)
                printf("YES\n");
            else 
                printf("NO\n");
        }
    }
    return 0;
}