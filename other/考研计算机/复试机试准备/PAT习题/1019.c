/*
* 1019题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//比较函数
int compare(const void *A, const void *B) {
    int a = *(int*)A;
    int b = *(int*)B;

    return b - a;
}

void reverse(int in[], int max) {
    for (int i = 0, j = max - 1; i < j; i++, j--)
    {
        int t = in[i];
        in[i] = in[j];
        in[j] = t;
    }
}

//int转数组
void num2array(int num, int re[], int max) {
    int i = max - 1;
    while (num > 0)
    {
        re[i] = num % 10;
        num /= 10;
        i--;
    }
}

//数组转int
int array2num(int in[], int max) {
    int re = 0;
    int t = 1;
    for (int i = max - 1; i >= 0; i--)
    {
        re += in[i] * t;
        t *= 10;
    }
    
    return re;
}

int main() {
    int array[4] = {0};
    int num, re = 0;
    scanf("%d", &num);

    while (re != 6174)
    {
        num2array(num, array, 4);
        if (array[0] == array[1] &&
        array[1] == array[2] &&
        array[2] == array[3])
        {
            printf("%.4d - %.4d = %.4d\n", num, num, 0);
            break;    
        }
        qsort(array, 4, sizeof(int), compare);

        int a = array2num(array, 4);

        reverse(array, 4);

        int b = array2num(array, 4);
        re = a - b;
        num = re;
        printf("%.4d - %.4d = %.4d\n", a, b, num);
    }

    return 0;
}