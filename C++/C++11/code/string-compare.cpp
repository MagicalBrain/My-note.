/*
* 试一下string容器是不是真的可以这么方便地比较
*/
#include <iostream>
#include <string>

using namespace std;
using std::string;

int main() {
    string str;
    cin >> str;
    if (str == "quit")
        cout << "程序退出！" << endl;
    return 0;
}
