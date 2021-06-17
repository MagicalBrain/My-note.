#include <iostream>
#include <string>
#include <functional>

using namespace std;

std::function<void(int a)> fun1;
std::function<void(string str)> fun2;
std::function<string(int a, int b)> fun3;

void norm1(int a) {
    cout << "普通函数" << endl;
}

static void norm2(string str) {
    cout << "普通静态函数" << endl;
    cout << str << endl;
}

auto lambda = [](int a, int b) -> string{
    int c = a + b;
    return "boy";
};

int main() {
    fun1 = norm1;
    fun1(3);

    fun2 = norm2;
    fun2("hello");

    fun3 = lambda;
    cout << fun3(2, 3) << endl;
    return 0;
}