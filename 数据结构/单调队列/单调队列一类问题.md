# 【Leetcode】单调队列一类问题

## 基本思想

单调队列的基本思想是，维护一个双向队列（deque），遍历序列，仅当一个元素可能成为某个区间最值时才保留它。

形象地打个比方，上面的序列可以看成学校里各个年级XCPC选手，数字越大代表能力越强。每个选手只能在大学四年间参赛，毕业了就没有机会了。那么，每一年的王牌选手都在哪个年级呢？

一开始的时候，大三大四的学长都比较菜，大二的最强，而大一的等大二的毕业后还有机会上位，所以队列里有两个数。

![](https://pic3.zhimg.com/80/v2-eeda8e22e5931732675ab99754f93bce_720w.jpg)

解释：
1. 因为大学本科有四个年级，区间长度为4

可见这是维护了一个递减的单调栈，这样找最大值的时间复杂度仅为$O(1)$，因为只要访问队头元素即可。

## 代码模板

```c++
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
```

### 测试程序

```c++
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
```

## 适用问题的特点

1. 对找最大最小值的时间要求很高的，比如1438要找十几万个数的最大最小值。
2. 当使用滑动窗口法解决问题时，需要求区间内最大值最小值


---

**参考链接（也是图片主要来源）**：
https://zhuanlan.zhihu.com/p/346354943