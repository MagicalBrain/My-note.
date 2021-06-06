#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
// 定义向量的长度
#define __VEC_LENGTH__ 10000000

// 线程数量
int thread_count = 4;
// 第一个向量
double arr1[__VEC_LENGTH__];
// 第二个向量
double arr2[__VEC_LENGTH__];
// 计算加法的结果
double result[__VEC_LENGTH__];
// 每个线程执行的函数
void *sum_vec(void *rank);

int main()
{
    long thread;
    pthread_t *thread_handles;
    int i;
    srand(time(NULL));
    thread_handles =(pthread_t *)malloc(thread_count * sizeof(pthread_t));
    for(i = 0; i < __VEC_LENGTH__; ++i)//随机初始化函数
    {
        arr1[i] = rand() / 9999;
        arr2[i] = rand() / 9999;
    }

    struct timeval tv1, tv2;
    gettimeofday(&tv1, NULL);
    // 绑定线程，开始分叉
    for (thread = 0; thread < thread_count; ++thread)
    // 将线程hello，和给hello的参数绑定到线程上
        pthread_create(&thread_handles[thread], NULL,
        sum_vec, (void *)thread);

    // 结束线程
    for (thread = 0; thread < thread_count; ++thread)
        pthread_join(thread_handles[thread], NULL);
    gettimeofday(&tv2, NULL);
    // 输出高维加法执行时间
    printf("Spliting the date to 4 pieces takes %ld us\n",
        (tv2.tv_sec - tv1.tv_sec) * 1000000 + tv2.tv_usec - tv1.tv_usec);

    printf("The first three elements of result is %lf %lf %lf\n",
        result[0], result[1], result[2]);
    free(thread_handles);    
    return 0;
}

void *sum_vec(void *rank)
{
    long my_rank = (long)rank;

    // 每个线程都计算 __VEC_LENGTH__ / thread_count 个元素相加
    int i;
    int my_work = __VEC_LENGTH__ / thread_count;
    int my_first = my_rank * my_work;
    int my_last = (my_rank + 1) * my_work;

    for (i = my_first; i < my_last; ++i)
    {
        result[i] = arr1[i] + arr2[i];
    }
    return NULL;
}
