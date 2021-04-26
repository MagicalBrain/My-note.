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