#include <iostream>
#include <string>
#include <functional>

using namespace std;

std::function<void(int a)> fun1;
std::function<void(string str)> fun2;
std::function<string(int a, int b)> fun3;

void norm1(int a) {
    cout << "普通函数" << endl;
    cout << a << endl;
}

static void norm2(string str) {
    cout << "普通静态函数" << endl;
    cout << str << endl;
}

auto lambda = [](int a, int b) -> string{
    int c = a + b;
    return "boy";
};

void func2func2(std::function<void(int a)> func) {
    fun1(507);
    //fun1(a);
    return ;
}

int main() {
    fun1 = norm1;
    fun1(3);

    fun2 = norm2;
    fun2("hello");

    fun3 = lambda;
    cout << fun3(2, 3) << endl;

    func2func2(fun1);
    return 0;
}