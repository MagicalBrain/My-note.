#include "friend.h"

//1.���ǳ�Ա��������Ϊ��Ԫ����
class Person
{
public:
	Person(int = 0, string = "����");
	friend void show(Person *pper);//��show����Ϊ��Ԫ����

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

////2.��������ĳ�Ա��������Ϊ��Ԫ����
////person�еĳ�Ա�������Է���MobilePhone�е�˽�г�Ա����
//class MobilePhone;//��ǰ����
////����Person��
//class Person
//{
//public:
//	Person(int = 0, string = "����");
//	void show(MobilePhone *mp);
//private:
//	int age;
//	string name;
//};
////����MobilePhone��
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
//	cout << mp->year << "��  " << mp->memory << "G " << mp->name << endl;
//}
//int main()
//{
//	Person *pp = new Person(234, "yar");
//	MobilePhone *mp = new MobilePhone;
//	pp->show(mp);
//	system("pause");
//	return 0;
//}