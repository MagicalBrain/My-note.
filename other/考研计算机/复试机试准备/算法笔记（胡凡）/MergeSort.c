/*
* 归并排序 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b) {
    if (a < b) 
        return a;
    else
        return b;
}

/* ----- 归并排序的实现 ----- */

//const int maxn = 100;

void merge(int *A, int L1, int R1, int L2, int R2) {
    int i = L1, j = L2;
    int maxn = L1 + R2 + 1;
    int *temp, index = 0;
    temp = (int*) malloc(maxn * sizeof(int));

    while (i <= R1 && j <= R2) {
        if (A[i] <= A[j])
            temp[index++] = A[i++];
        else 
            temp[index++] = A[j++];
    }

    while (i <= R1) temp[index++] = A[i++];
    while (j <= R2) temp[index++] = A[j++];
    for (int i = 0; i < index; i++)
    {
        A[L1 + i] = temp[i];
    }
    
}

//递归版本

//非递归版本
/* 非递归版本，归并排序 arr【0...n-1】 */
void mergeSort(int *arr, int n) 
{ 
   int curr_size;  // 当前子数组的大小，子数组大小： 1 到 n/2 
   int left_start;  // 左子数组的开始下标
  
   // 自底向上归并.  首先归并大小为1的数组形成大小为2的有序子数组, 
   // 接着归并大小为2的数组，形成大小为4的有序子数组 
   for (curr_size = 1; curr_size <= n - 1; curr_size *= 2) 
   { 
       // 根据子数组大小调整左子数组起始下标 
       for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size) 
       { 
           // min函数是为了防止下标越界
           // 找出左子数组结尾下标
           int mid = min(left_start + curr_size - 1, n-1); 
           // 找出右子数组结尾下标
           int right_end = min(left_start + 2*curr_size - 1, n-1); 
  
           // 归并子数组 arr【left_start...mid】 & arr【mid+1...right_end】 ，和递归的相同
           merge(arr, left_start, mid, mid + 1, right_end); 
       }
       //输出一趟排序的结果 
   } 
}

int main() {
    int n;
    int *data;
    scanf("%d", &n);
    data = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
    }

    mergeSort(data,n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
    return 0;
}