#include <iostream>
#include <string>

#include <typeinfo>

using namespace std;

int main() {
    int x;
    char c;
    double v3 = 1;
    float v4 = 1.1;
    bool v5 = false; 
    string str;
    cout << typeid(x).name() << endl;
    cout << typeid(c).name() << endl;
    cout << typeid(v3).name() << endl;
    cout << typeid(v4).name() << endl;
    cout << typeid(v5).name() << endl;
    cout << typeid(str).name() << endl;
    return 0;
}
