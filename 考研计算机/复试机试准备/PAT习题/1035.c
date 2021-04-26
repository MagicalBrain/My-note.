/*
* 1035题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int com4num(const void *A, const void *B) {
    int a = *(int*) A;
    int b = *(int*) B;
    return a - b;
}

void printf_array(int *in, int len) {
    for (int i = 0; i < len; i++)
    {
        if (i == 0)
            printf("%d", in[i]);
        else 
            printf(" %d", in[i]);
    }
    printf("\n");
}

//比较数组函数
int compare(int *in1, int *in2, int len) {
    for (int i = 0; i < len; i++)
    {
        if (in1[i] != in2[i])
            return 0;
    }
    return 1;
}

//插入排序
void Insertion_sort(int *in, int *com, int len) {
    int end = 0;
    //整个排序循环，从左往右遍历需要被插入到前面的数
    for (int i = 1; i < len; i++)
    {
        int tmp = in[i];
        int j = i - 1;
        //在前面的有序序列中，从左到右遍历一个适合该元素插入的位置
        while (j >= 0 && in[j] > tmp)
        {
            in[j + 1] = in[j];
            j--;
        }
        //插入需要被插入的元素
        in[j + 1] = tmp;

        //停下排序，并输出
        if (end) {
            printf_array(in, len);
            break;
        }
        //比较这一趟排序所得序列是否与输入一致，一致则准备进行下一次后停下
        if (compare(in, com, len)) {
            printf("Insertion Sort\n");
            end = 1;
        }
    }
    
}

//归并排序
//注意不能使用递归来做，因为这样无法获得每一趟排序的结果

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

int min(int a, int b) {
    if (a < b) 
        return a;
    else
        return b;
}

void MergeSort(int *arr, int *in2, int n) 
{ 
    int end = 0;
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
       if (end == 1) {
           printf_array(arr, n);
           break;
       }
       if ( compare(arr, in2, n) ) {
           printf("Merge Sort\n");
           end = 1;
       }
       //printf_array(arr, n);
   } 
}

int main() {
    int *in1, *in2, *tmp;
    int n;
    scanf("%d", &n);
    in1 = (int*) malloc( n * sizeof(int));
    tmp = (int*) malloc( n * sizeof(int));
    in2 = (int*) malloc( n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &in1[i]);
        tmp[i] = in1[i];
    }
    for (int i = 0; i < n; i++)
        scanf("%d", &in2[i]);

    //测试插入排序
    Insertion_sort(in1, in2, n);

    for (int i = 0; i < n; i++)
        in1[i] = tmp[i];
    

    //测试归并排序
    MergeSort(in1, in2, n);
    //printf_array(in1, n);
    
    return 0;
}