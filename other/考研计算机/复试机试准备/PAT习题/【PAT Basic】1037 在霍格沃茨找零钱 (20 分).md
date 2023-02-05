# 【PAT Basic】1037 在霍格沃茨找零钱 (20 分)

## 题目描述

如果你是哈利·波特迷，你会知道魔法世界有它自己的货币系统 —— 就如海格告诉哈利的：“十七个银西可(Sickle)兑一个加隆(Galleon)，二十九个纳特(Knut)兑一个西可，很容易。”现在，给定哈利应付的价钱 P 和他实付的钱 A，你的任务是写一个程序来计算他应该被找的零钱。

输入格式：
输入在 1 行中分别给出 P 和 A，格式为 Galleon.Sickle.Knut，其间用 1 个空格分隔。这里 Galleon 是 $[0, 10^7​​ ]$ 区间内的整数，Sickle 是$ [0, 17) $区间内的整数，Knut 是$ [0, 29) $区间内的整数。

输出格式：

在一行中用与输入同样的格式输出哈利应该被找的零钱。如果他没带够钱，那么输出的应该是负数。

输入样例 1：
10.16.27 14.1.28

输出样例 1：
3.2.1

输入样例 2：
14.1.28 10.16.27

输出样例 2：
-3.2.1

## 基本思路

## 代码

```c++
/*
* 1037题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int enough(
    int pg, int ps, int pk,     //价钱
    int ag, int as, int ak) 
{
    if (ag < pg)
        return 0;
    else if (ag == pg && as < ps)
        return 0;
    else if (ag == pg && as == ps && ak < pk)
        return 0;
    else 
        return 1;
}

int main() {
    int Sickle = 17, Knut = 29;     //兑换的比例
    int pg, ps, pk;     //价钱
    int ag, as, ak;     //实际给出的钱
    int rg = 0, rs = 0, rk = 0;     //需要找回的零钱

    scanf("%d%*c%d%*c%d", &pg, &ps, &pk);
    scanf("%d%*c%d%*c%d", &ag, &as, &ak);

    if (enough(pg, ps, pk, ag, as, ak) == 0) {
        if (pk < ak) {
            rk = pk + Knut - ak;
            ps -= 1;
        }
        else    rk = pk - ak;
    
        if (ps < as) {
            rs = ps + Sickle - as;
            pg -= 1;
        }
        else rs = ps - as;

        rg = pg - ag;
        printf("-");
    }
    else
    {
        if (ak < pk) {
            rk = ak + Knut - pk;
            as -= 1;
        }
        else    rk = ak - pk;
    
        if (as < ps) {
            rs = as + Sickle - ps;
            ag -= 1;
        }
        else rs = as - ps;

        rg = ag - pg;
    }
    
    printf("%d.%d.%d\n", rg, rs, rk);
    return 0;
}
```

## 总结

注意题目中，如果钱不够时输出的负数，这个负数的计算方法是和钱够时算零钱的方法反过来再加负号即可。
