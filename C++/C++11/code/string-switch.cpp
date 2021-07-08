/*
* 试一下string容器是不是真的不可以在switch里面定义
*/
#include <iostream>
#include <string>

using namespace std;
using std::string;

int main() {
    int c;

    cin >> c;
    switch (c)
    {
    case 1:
        string str;
        cin >> str;
        cout << str << endl;
        break;
    
    default:
        break;
    }
    return 0;
}