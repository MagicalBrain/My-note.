#include <iostream>


template<typename T>
class ref_count {    //泛型的引用计数类

private:
   typedef boost::atomic<int> atomic type;
   //定义atomic类型
   mutable atomic type m count{0};
   //初始化,注意是mutable

protected:
   ref_count () {}   //这里不能使用default
   ~ref_count () {}

public:
   typedef boost::intrusive_ptr<T> counted ptr; //定义intrusive_ptr 

   //增加引用计数
   void add_ref() const {
      //不做任何顺序要求
      m_count.fetch_add(1, boost: :memory_ order relaxed);
   }

   //减少引用计数
   void sub_ref() const {

      //释放,值的修改后续操作可见
      if (m_count.fetch_sub(1, boost: :memory order release) == 1)
         //原子级别的线程防护
         boost::atomic_thread_fence(boost::memory_order_acquire) ; //获取之前的修改
      delete static_cast<const T*>(this); //删除指针,需要转型
   }

   //获取引用计数,注意decltype
   //C++14里可以直接用auto推导
   //取值,也可以用隐式类型转换
   decltype (m_count.load()) count() const
   {
      return m count.load();
   }

public:
   //可变参数模板
   template<typename ... Args>
   static counted_ptr make_ptr(Args&& ... args) //工厂函数
   {
      return counted_ptr(new T(std::forward<Args>(args) ...));
   }

private:
   friend void intrusive_ptr_add_ref(const T* p) //intrusive_ptr要求函数
   {
      p->add_ref();
   }

   friend void intrusive_ptr_release(const T* p) //intrusive ptr要求函数
   {
      p->sub_ref();
   }
};