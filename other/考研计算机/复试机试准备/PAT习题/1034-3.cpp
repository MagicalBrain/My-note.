/*
* 1034题 网上大佬代码 版本3 代码存档
*/
#include <iostream>
#include <cmath>
using namespace std;

struct fenshu{
	long long down, up;		
};

int gcd(long long a, long long b){
	if(b==0)	return a;
	else return gcd(b, a%b);
} 

fenshu huajian(fenshu a){
	if(a.down < 0){
		a.up = -a.up;
		a.down = -a.down;
	}
	if(a.up == 0)
		a.down = 1;
	else{
		int d = gcd(abs(a.up), abs(a.down));
		a.up /= d;
		a.down /= d;
	}
	return a;
}

fenshu jia(fenshu a, fenshu b){
	fenshu result;
	result.down = a.down * b.down;//通分
	result.up = a.up*b.down + b.up*a.down;
	return huajian(result); 
}

fenshu jian(fenshu a, fenshu b){
	fenshu result;
	result.down = a.down * b.down;//通分
	result.up = a.up*b.down - b.up*a.down;
	return huajian(result); 
}

fenshu cheng(fenshu a, fenshu b){
	fenshu result;
	result.down = a.down * b.down;//通分
	result.up = a.up * b.up;
	return huajian(result); 
}

fenshu chu(fenshu a, fenshu b){
	//就是与b的倒数相乘
	fenshu result;
	result.down = a.down * b.up;//通分
	result.up = a.up * b.down;
	return huajian(result); 
} 

void show(fenshu a){
	a = huajian(a);
	if(a.up < 0)	printf("(");
	if(a.down == 1)	printf("%lld", a.up);//分数为整数 
	else if(abs(a.up) > abs(a.down))	printf("%lld %lld/%lld", a.up/a.down, abs(a.up%a.down), a.down);
	else	printf("%lld/%lld", a.up, a.down);
	if(a.up < 0)	printf(")");
}

int main(){
	fenshu a, b, r1, r2, r3;
	scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
	//加减乘运算 
	r1 = jia(a, b); r2 = jian(a, b); r3 = cheng(a, b);
	show(a); printf(" + "); show(b); printf(" = "); show(r1); printf("\n");
	show(a); printf(" - "); show(b); printf(" = "); show(r2); printf("\n");
	show(a); printf(" * "); show(b); printf(" = "); show(r3); printf("\n");
	//除运算
	show(a); printf(" / "); show(b); printf(" = ");
	if(b.up == 0)
		printf("Inf");
	else
		show(chu(a, b));
	return 0;
}

