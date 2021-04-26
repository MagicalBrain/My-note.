# 【PAT Basic】1020 月饼 (25 分)

## 题目描述

月饼是中国人在中秋佳节时吃的一种传统食品，不同地区有许多不同风味的月饼。现给定所有种类月饼的库存量、总售价、以及市场的最大需求量，请你计算可以获得的最大收益是多少。

注意：销售时允许取出一部分库存。样例给出的情形是这样的：假如我们有 3 种月饼，其库存量分别为 18、15、10 万吨，总售价分别为 75、72、45 亿元。如果市场的最大需求量只有 20 万吨，那么我们最大收益策略应该是卖出全部 15 万吨第 2 种月饼、以及 5 万吨第 3 种月饼，获得 72 + 45/2 = 94.5（亿元）。

输入格式：

每个输入包含一个测试用例。每个测试用例先给出一个==不超过 1000 的正整数 N== 表示月饼的种类数、以及==不超过 500（以万吨为单位）的正整数 D==表示市场最大需求量。随后一行给出 N 个正数表示每种月饼的库存量（以万吨为单位）；最后一行给出 N 个正数表示每种月饼的总售价（以亿元为单位）。数字间以空格分隔。

输出格式：

对每组测试用例，在一行中输出最大收益，以亿元为单位并精确到小数点后 2 位。

输入样例：

3 20
18 15 10
75 72 45

输出样例：

94.50

## 基本思路

## 代码

```c++
/*
* 1020题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct yb {
    double item;
    double value;
    double danjia;
}yb;

int compare(const void *A, const void *B) {
    yb a = *(yb*)A;
    yb b = *(yb*)B;
    if (b.danjia - a.danjia > 0.0)
        return 1;
    else if (b.danjia - a.danjia == 0.0)
        return 0;
    else 
        return -1;
    //return a.danjia - b.danjia;
}

int main() {
    int type, need;
    double sum = 0.0;
    yb *y;
    scanf("%d%d", &type, &need);
    
    y = (yb*) malloc(type * sizeof(yb));

    for (int i = 0; i < type; i++)
        scanf("%lf", &y[i].item);
    
    for (int i = 0; i < type; i++)
    {
        scanf("%lf", &y[i].value);
        y[i].danjia = y[i].value / y[i].item;
    }

    qsort(y, type, sizeof(yb), compare);

    int cnt = 0;
    for (int i = 0; i < type; i++)
    {
        cnt += y[i].item;
        if (cnt > need) {
            if (i != 0)
                sum += (double)(need - (cnt - y[i].item) ) * y[i].danjia;
            else 
                sum += (double)(need) * y[i].danjia;
            break;
        }
        else if (cnt == need) {
            sum += y[i].value;
            break;
        }
        else 
            sum += y[i].value;
        //测试的时候可能会用到这行代码
        //printf("%d %lf %lf\n",i ,y[i].item, y[i].danjia);
    }   
    printf("%.2lf\n",sum);
    return 0;
}
```

### 柳神代码

```c++
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct mooncake{
    float mount, price, unit;
};
int cmp(mooncake a, mooncake b) {
    return a.unit > b.unit;
}
int main() {
    int n, need;
    cin >> n >> need;
    vector<mooncake> a(n);
    for (int i = 0; i < n; i++) scanf("%f", &a[i].mount);
    for (int i = 0; i < n; i++) scanf("%f", &a[i].price);
    for (int i = 0; i < n; i++) a[i].unit = a[i].price / a[i].mount;
    sort(a.begin(), a.end(), cmp);
    float result = 0.0;
    for (int i = 0; i < n; i++) {
        if (a[i].mount <= need) {
            result = result + a[i].price;
        } else {
            result = result + a[i].unit * need;
            break;
        }
        need = need - a[i].mount;
    }
    printf("%.2f",result);
    return 0;
}
```

[柳婼代码原文链接](https://blog.csdn.net/liuchuo/article/details/51994567?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522161510699816780271526987%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fblog.%2522%257D&request_id=161510699816780271526987&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~blog~first_rank_v1~rank_blog_v1-2-51994567.pc_v1_rank_blog_v1&utm_term=PAT+1020)

## 总结
