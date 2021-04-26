/*
* 1034题 网上大佬代码 版本一 代码存档
*/
#include <iostream>
#include <cmath>
 
using namespace std;
struct number
{
	long long int k, fenz, fenm;
};
long long int a1, b1, a2, b2;
long long int maxgongyueshu(long long int x,long long int y)
{
	long long int z = y;
	while (x%y != 0)
	{
		z = x%y;
		x = y;
		y = z;
	}
	return z;
}
void huajian(long long int afenz,long long int afenm)
{
	if (afenm == 0)
	{
		cout << "Inf";
		return;
	}
	if (afenz == 0)
	{
		cout << 0;
		return;
	}
	number tmp;
	long long int maxyue;
	if (abs(afenz) > abs(afenm))
	{
		tmp.k = afenz / afenm;
		if (abs(afenz)%abs(afenm) == 0)
		{
			tmp.fenz = 0;
			tmp.fenm = 0;
		}
		else
		{
			tmp.fenz = abs(afenz) - abs(tmp.k)*abs(afenm);
			maxyue = maxgongyueshu(abs(tmp.fenz), abs(afenm));
			tmp.fenz = tmp.fenz / maxyue;
			tmp.fenm = abs(afenm) / maxyue;
		}
	}
	else if (abs(afenz) == abs(afenm))
	{
		tmp.k = afenz / afenm;
		tmp.fenz = 0;
		tmp.fenm = 0;
	}
	else
	{
		tmp.k = 0;
		maxyue = maxgongyueshu(abs(afenz), abs(afenm));
		tmp.fenz = afenz / maxyue;
		tmp.fenm = afenm / maxyue;
	}
 
	///输出
	if (tmp.k == 0)
	{
		if (tmp.fenz * tmp.fenm < 0)
			cout << "(-" << abs(tmp.fenz) << "/" << abs(tmp.fenm) << ")";
		else
			cout << tmp.fenz << "/" << tmp.fenm;
	}
	else
	{
		if (tmp.fenz == 0 && tmp.fenm == 0)
		{
			if (tmp.k>0)
				cout << tmp.k;
			else
				cout << "(" << tmp.k << ")";
		}
		else
		{
			if (tmp.k>0)
				cout << tmp.k<<" "<<tmp.fenz<<"/"<<tmp.fenm;
			else
				cout << "(" << tmp.k << " " << tmp.fenz << "/" << tmp.fenm<<")";
		}
	}
}
 
void add()
{
	long long int m,n;
	m = a1*b2 + a2*b1;
	n = b1*b2;
	huajian(a1, b1);
	cout << " + ";
	huajian(a2, b2);
	cout << " = ";
	huajian(m, n);
	cout << endl;
}
 
void mins()
{
	long long int m, n;
	m = a1*b2 - a2*b1;
	n = b1*b2;
	huajian(a1, b1);
	cout << " - ";
	huajian(a2, b2);
	cout << " = ";
	huajian(m, n);
	cout << endl;
}
 
void multi()
{
	long long int m, n;
	m = a1*a2;
	n = b1*b2;
	huajian(a1, b1);
	cout << " * ";
	huajian(a2, b2);
	cout << " = ";
	huajian(m, n);
	cout << endl;
}
void div()
{
	long long int m, n;
	m = a1*b2;
	n = b1*a2;
	huajian(a1, b1);
	cout << " / ";
	huajian(a2, b2);
	cout << " = ";
	huajian(m, n);
	cout << endl;
}
int main()
{
	scanf("%lld/%lld", &a1, &b1);
	scanf("%lld/%lld", &a2, &b2);
	add();
	mins();
	multi();
	div();
	return 0;
}