/*
* 通过 std::async 向任务函数传递参数
*/
#include <string>
#include <future>

// 定义了一个类
struct X
{
    void foo(int,std::string const&);
    std::string bar(std::string const&);
};

// 实例化类对象
X x;

// 注意学习这里是如何通过 std::async 调用类成员函数的
// (函数指针， 类对象指针， 参数1， 参数2)
auto f1=std::async(&X::foo,&x,42,"hello");
auto f2=std::async(&X::bar,x,"goodbye");

struct Y
{
    double operator()(double);
};

Y y;

auto f3=std::async(Y(),3.141);
// 
auto f4=std::async(std::ref(y),2.718);

X baz(X&);

// 书上源码是：std::async(baz,std::ref(x));
// 这里是译者修改为auto f6 的
//auto f6=std::async(baz,std::ref(x));
// 我重新调了一下为 f5
auto f5=std::async(baz,std::ref(x));

class move_only
{
public:
    move_only();
    move_only(move_only&&);
    move_only(move_only const&) = delete;
    move_only& operator=(move_only&&);
    move_only& operator=(move_only const&) = delete;
    void operator()();
};
auto f6=std::async(move_only());

int main() {
    
    return 0;
}
