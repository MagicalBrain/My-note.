#include <iostream>
#include <cstring>

using namespace std;

int main() {
    string str = "hello, world!";
    char p1[1024];
    char p2[1024];
    //p1 = str.c_str();
    /*
    p1 = str.c_str();
    这个用法是错误的
    一定要使用strcpy()函数 等来操作方法c_str()返回的指针
    p1最后指向的内容是垃圾,因为str对象被析构,其内容被处理
    */
    strcpy(p1, str.c_str());

    //p2 = str.data();
    strcpy(p2, str.data());

    cout << "str is: " << str
        << " len of str is: " << str.length() << endl;

    cout << "p1 is: " << p1 
        << " strlen of p1 is: " << strlen(p1) << endl;
    cout << "p2 is: " << p2 
        << " strlen of p2 is: " << strlen(p2) << endl;
    return 0;
}