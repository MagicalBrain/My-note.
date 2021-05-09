/*
 * 【leetcode】NextGreaterNumber类题代码 存档
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* nextGreaterElement(int *nums, int numsSize)
{
    int *re = (int*) malloc(numsSize * sizeof(int));    //用来返回的动态数组
    int *stack = (int*) malloc(numsSize * sizeof(int));    //单调栈
    int top = 0;

    for (int i = numsSize - 1; i >= 0; i--)
    {
        while (
            top != 0
            && stack[top - 1] <= nums[i])
        {
            top--;      //矮个子单调栈出栈
        }
        if (top == 0)
        {
            re[i] = -1;
        }
        else
        {
            re[i] = stack[top - 1];
        }
        stack[top++] = nums[i];
    }

    return re;
}

int* nextWarmerDay(int *nums, int numsSize)
{
    int *re = (int*) malloc(numsSize * sizeof(int));
    int *stack = (int*) malloc(numsSize * sizeof(int));
    int top = 0;

    for (int i = numsSize - 1; i >= 0; i--)
    {
        while (top != 0
            && stack[top - 1] >= nums[i])
        {
            top--;
        }
        if (top == 0)
        {
            re[i] = -1;
        }
        else
        {
            re[i] = stack[top - 1];
        }
        stack[top++] = nums[i];
    }
    
    return re;
}

int* nextGreaterElement_2(int *nums, int numsSize)      //进阶版，503
{
    int *re = (int*) malloc(numsSize * sizeof(int));    //用来返回的动态数组
    int *stack = (int*) malloc(2 * numsSize * sizeof(int));    //单调栈
    int top = 0;

    for (int i = 2 * numsSize - 1; i >= 0; i--)
    {
        while (
            top != 0
            && stack[top - 1] <= nums[i % numsSize])
        {
            top--;      //矮个子单调栈出栈
        }
        if (top == 0)
        {
            re[i % numsSize] = -1;
        }
        else
        {
            re[i % numsSize] = stack[top - 1];
        }
        stack[top++] = nums[i % numsSize];
        //stack[top++] = nums[i];
    }

    return re;
}

int main()
{
    int num;
    int *data;

    puts("请输入个数：");
    scanf("%d", &num);
    data = (int*) malloc(num * sizeof(int));

    puts("请输入各个元素");
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &data[i]);
    }
    
    int *re;
    //re = nextGreaterElement(data, num);
    re = nextWarmerDay(data, num);
    re = nextGreaterElement_2(data, num);

    for (int i = 0; i < num; i++)
    {
        printf("%d ", re[i]);
    }
    printf("\n");
    
    return 0;
}