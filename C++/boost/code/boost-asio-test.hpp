#include <iostream>
#include "boost-asio.hpp"


//添加引用计数能力
class demo : public ref_count<demo>
{
public:
   demo() = default;
   ~demo()= default;
   int x;
};

int test4asio () {
   auto p = demo::make_ptr();
   
   //创建智能指针
   p->x=10;
   assert (p->x== 10) ;
   assert (p->count() == 1);      //检查引用计数
}
