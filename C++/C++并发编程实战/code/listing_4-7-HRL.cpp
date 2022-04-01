/*
* 通过 std::async 向任务函数传递参数
*/

#include <iostream>
#include <string>
#include <future>
#include <mutex>

std::mutex lock_print;

// 定义了一个类
struct X
{
    void pIntAndString(int a, std::string const& s) {
        std::lock_guard<std::mutex> guard(lock_print);
        std::cout << s << " " << a << std::endl;
    }

    std::string pString(std::string const& s) {
        std::lock_guard<std::mutex> guard(lock_print);
        std::cout << s << std::endl;
        return s;
    }
};

struct Y
{
    double operator()(double d) {
        std::lock_guard<std::mutex> guard(lock_print);
        std::cout << d / 2.0 << std::endl;
        return d;
    }
};

class move_only
{
public:
    move_only() {
        std::lock_guard<std::mutex> guard(lock_print);
        std::cout << "move_only() constructor has been called!\n";
    }

    move_only(move_only&&) noexcept 
    {
        std::lock_guard<std::mutex> guard(lock_print);
        std::cout << "move_only(move_only&&) constructor has been called!\n";
    }
    
    move_only(move_only const&) = delete;
    
    move_only& operator=(move_only&& m) noexcept
    {
        std::lock_guard<std::mutex> guard(lock_print);
        std::cout << "move_only operator=(move_only&& m) has been called!\n";
        return m;
    }
    
    move_only& operator=(move_only const&) = delete;
    
    void operator()() {
        std::lock_guard<std::mutex> guard(lock_print);
        std::cout << "move_only operator()() has been called!\n";
    }
};

X getXx(X& x) {
    return x;
}

int main() {
    // 实例化类对象
    X x;

    // 注意学习这里是如何通过 std::async 调用类成员函数的
    // (函数指针， 类对象指针， 参数1， 参数2)
    auto f1 = std::async(&X::pIntAndString, &x, 42, "hello");
    auto f2 = std::async(&X::pString, x, "goodbye");

    // 书上源码是：std::async(baz,std::ref(x));
    // 这里是译者修改为auto f6 的
    //auto f6=std::async(baz,std::ref(x));
    // 我重新调了一下顺序为 f5
    auto f3 = std::async(getXx, std::ref(x));

    // 实例化Y类的对象y
    Y y;

    auto f4 = std::async(Y(), 3.141);
    // 注意这种用法
    auto f5 = std::async(std::ref(y), 2.718);

    auto f6 = std::async(move_only());

    f1.get();
    f2.get();
    f3.get();
    f4.get();
    f5.get();
    f6.get();

    return 0;
}
