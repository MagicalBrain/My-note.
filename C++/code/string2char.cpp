#include <iostream>
#include <cstring>

using namespace std;

char* getString1() {
    char str[1024] = "getString1";
    char *p = str;
    return p;
}

char* getString2() {
    char str[1024] = "getString1";
    return str;
}

int main() {
    string str;
    char s1[1014] = "hello";
    char *p1 = s1;

    char *p2 = getString1();

    char *p3 = getString2();

    cout << "s1 is: " << s1 
        << " strlen of s1 is: " << strlen(s1) << endl;

    cout << "p1 is: " << p1 
        << " strlen of p1 is: " << strlen(p1) << endl;
    str = p1;
    cout << "str1 is: " << str
        << " len of str1 is: " << str.length() << endl;

    cout << "p2 is: " << p2
        << " strlen of p2 is: " << strlen(p2) << endl;
    str = p2;
    cout << "str2 is: " << str
        << " len of str2 is: " << str.length() << endl;
    
    cout << "p3 is: " << p3
        << " strlen of p3 is: " << strlen(p3) << endl;
    str = p3;
    cout << "str3 is: " << str
        << " len of str3 is: " << str.length() << endl;
    return 0;
}