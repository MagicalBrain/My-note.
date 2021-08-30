#include "friend.h"

//1.将非成员函数声明为友元函数
class Person
{
public:
	Person(int = 0, string = "张三");
	friend void show(Person *pper);//将show声明为友元函数

private:
	int age;
	string name;
};

Person::Person(int a, string s) :age(a), name(s)
{
	cout << a << " " << s << endl;
}

void show(Person *pper)
{
	cout << "age=" << pper->age << endl;
	cout << "name=" << pper->name << endl;
}

int main()
{
	;
	Person *pp = new Person(234, "yar");
	show(pp);
	system("pause");
	return 0;
}

////2.将其他类的成员函数声明为友元函数
////person中的成员函数可以访问MobilePhone中的私有成员变量
//class MobilePhone;//提前声明
////声明Person类
//class Person
//{
//public:
//	Person(int = 0, string = "张三");
//	void show(MobilePhone *mp);
//private:
//	int age;
//	string name;
//};
////声明MobilePhone类
//class MobilePhone
//{
//public:
//	MobilePhone();
//	friend void Person::show(MobilePhone *mp);
//private:
//	int year;
//	int memory;
//	string name;
//};
//MobilePhone::MobilePhone()
//{
//	year = 1;
//	memory = 4;
//	name = "iphone 6s";
//}
//Person::Person(int a, string s) :age(a), name(s)
//{
//	cout << a << " " << s << endl;
//}
//void Person::show(MobilePhone *mp)
//{
//	cout << mp->year << "年  " << mp->memory << "G " << mp->name << endl;
//}
//int main()
//{
//	Person *pp = new Person(234, "yar");
//	MobilePhone *mp = new MobilePhone;
//	pp->show(mp);
//	system("pause");
//	return 0;
//}