# boost的类的摘要

参考自我的goodnotes——《boost库完全开发指南》

[toc]

# 时间与日期

## timer

用于计时的轻巧的库

### progress_timer

自动计时的小工具，派生于timer，构造对象时自动开始计时，析构对象时自动停止，使用方便。

## progress_display

可在控制台上现实程序的进度。

缺陷：
无法把进度显示和程序本身的输出分离。

## date_time

用于显示日期。

需要编译才可以使用

不能处理1400年以前的日期，不能用来研究那之前的历史。

# 内存管理

## smart_ptr

提供了6种智能指针：
scoped_ptr
scoped_array
shared_ptr
shared_array
weak_ptr
intrusive_ptr

它们都是轻量级的对象，都是异常安全的（exception safe）
对于所指向的类型T只有一个小小的要求：
析构函数不能抛出异常。
