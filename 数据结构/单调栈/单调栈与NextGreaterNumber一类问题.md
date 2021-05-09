# 【Leetcode】NextGreaterNumber一类问题与单调栈

## 单调栈的概念

栈的一种，其实就是在栈的基础上，添加逻辑保证每一次新元素进栈后，栈内的元素都是单调的。

单调栈的用途不是很广泛，专门处理下面这个NextGreatNumber类问题。

## NextGreaterNumber类问题原始描述

给你一个数组num，返回一个相同长度的数组re。

在数组num中，num[i]的右边如果有比他大的数，则将右边第一个比他的数存入re对应下标的位置，如果没有则存入-1。

例如：
输入：[2,1,2,4,3]
输出：[4, 2, 4, -1, -1]

## 代码模板

C++版：
```c++
vector<int> nextGreaterElement(vector<int>& nums)
{
    vector<int> ans(nums.size());//存放答案的数组
    stack<int> s;
    for(int i = nums.size() - 1; i >= 0; i--)
    {
        //倒着往栈里放
        while(!s.empty() && s.top() <= nums[i])     //判定个子高矮
        {
            s.pop();    //矮个起开,反正也被挡着了。。。
        }  
        ans[i] = s.empty() ? -1 : s.to();     //这个元素身后的第一个高个
        s.push(nums[i]);    //进队,接受之后的身高判定吧!
    }
    return ans;   
}
```

C语言版：
```c++
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
```

## NextGreaterNumber类问题的变体

### 下一个更暖和的气温

给你一个数组T =［73,74,75,71,69,72,76,73]，这个数组存放的是近几天的天气气温（这气温是铁板烧？不是的，这里用的华氏度）。你返回一个数组，计算:对于每一天，你还要至少等多少天才能等到一个更暖和的气温；如果等不到那一天，填0。

