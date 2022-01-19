#include <iostream>
#include <cstring>

using namespace std;

char* getString1() {
    char c1[1024] = "getString1";
    return c1;
}

string getString2() {
    char c1[1024] = "getString2";
    string re;
    re.assign(c1, strlen(c1));
    return re;
}

int main() {
    char c1[1024] = "hello, world!";
    string str1, str2, str3, str4;
    
    str1 = c1;

    str2.assign(c1, strlen(c1));

    //str3 = getString1();
    // 会导致程序崩溃

    //str3 = str3.assign(getString1(),strlen(getString1()));
    // 依然会导致程序崩溃

    str3 = getString2();

    cout << "str is: " << c1
        << " strlen of str is: " << strlen(c1) << endl;

    cout << "str1 is: " << str1
        << " len of str1 is: " << str1.length() << endl;
    cout << "str2 is: " << str2 
        << " len of str2 is: " << str2.length() << endl;
    cout << "str3 is: " << str3
        << " len of str3 is: " << str3.length() << endl;
    return 0;
}