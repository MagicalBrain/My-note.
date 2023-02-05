/*
* 序列合并问题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int merge(int A[], int B[], int C[], int n, int m) {
    int i = 0, j = 0, index = 0;
    while (i < n && j < m) {
        if (A[i] <= B[j]) 
            C[index++] = A[i++];
        else 
            C[index++] = B[j++];
    }
    while (i < n) C[index++] = A[i++];
    while (j < m) C[index++] = B[j++];
    return index;
}

int main() {
    int A[4] = {2,4,6,8};
    int B[6] = {0, 1, 3, 5, 7, 9};
    int C[10] = {0};
    if (merge(A, B, C, 4, 6)) {
        for (int i = 0; i < 10; i++)
        {
            printf("%d ", C[i]);
        }
        printf("\n");
    }
    return 0;
}