/*
* callback 4-2
* 在面向对象 多态里 实现回调函数
*/
#include <iostream>

class Interface{
  public:
    virtual void do_something() = 0;
    virtual ~Interface(){}
};

class Impl : public Interface {
  public:
  virtual ~Impl(){}
  virtual void do_something(){
     std::cout <<"Impl::dosomething" << std::endl;
  }
};

int main(){
  Interface *f = new Impl();
  f->do_something();
  return 0;
}
