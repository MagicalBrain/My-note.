/*
 * 【leetcode】单调栈模板代码 存档
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//利用单调栈找最大值
int max_queue(int *nums, int numsSize,int windowsSize) {
    int *max = (int*) malloc(numsSize * sizeof(int));
    int st_max = 0, ed_max = 0;
    int st = 0, ed = 0;

    if (windowsSize == 0)
        windowsSize = numsSize;

    while (ed < numsSize) {
        while (st_max < ed_max && nums[ed] > max[ed_max - 1])
            ed_max--;
        max[ed_max++] = nums[ed];
        while (st_max < ed_max && nums[ed] > max[st_max])
            st_max++;
        if (ed - st > windowsSize - 1)
            st++;
        ed++;
    }
    
    return max[st_max];
}

//利用单调栈找最小值
int min_queue(int *nums, int numsSize,int windowsSize) {
    int *min = (int*) malloc(numsSize * sizeof(int));
    int st_min = 0, ed_min = 0;
    int st = 0, ed = 0;

    if (windowsSize == 0)
        windowsSize = numsSize;

    while (ed < numsSize) {
        while (st_min < ed_min && nums[ed] < min[ed_min - 1])
            ed_min--;
        min[ed_min++] = nums[ed];
        while (st_min < ed_min && nums[ed] < min[st_min])
            st_min++;
        if (ed - st > windowsSize - 1)
            st++;
        ed++;
    }
    
    return min[st_min];
}

int main()
{
    int size;
    int *data;
    int windowsSize;

    puts("请输入数组长度：");
    scanf("%d", &size);

    puts("请输入数组各个元素的值：");
    data = (int*) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &data[i]);
    }

    puts("请输入区间大小：");
    scanf("%d", &windowsSize);

    printf("最大值为：%d\n", max_queue(data, size, windowsSize));
    printf("最小值为：%d\n", min_queue(data, size, windowsSize));
    
    return 0;
}