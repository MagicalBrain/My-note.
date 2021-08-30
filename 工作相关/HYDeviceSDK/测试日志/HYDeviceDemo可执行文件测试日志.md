# HYDeviceDemo可执行文件测试日志

## 21-06-15

今天卸载了pcl 1.8，重新装了 pcl 1.11

成功生成了HYDeviceSDK库并安装，但运行的时候出现问题

GRPC协议部分：

```
[2021-06-15 14:48:56.906274] [0x00007f9ca2027180] [info]    connecting sensor at 192.168.3.82:8080
[2021-06-15 14:48:57.118142] [0x00007f9ca2027180] [info]    grpc version: 1.38.0
[2021-06-15 14:48:57.340184] [0x00007f9ca2027180] [info]    sensor distance set to 100 - 2500
[2021-06-15 14:48:57.351181] [0x00007f9ca2027180] [info]    sensor fov set to 0, 0, 1440, 1080
[2021-06-15 14:48:57.365430] [0x00007f9ca2027180] [info]    sensor current set to 100, 100, 100
[2021-06-15 14:48:57.386254] [0x00007f9ca2027180] [info]    sensor exposure set to 22000, period 40400
[2021-06-15 14:48:58.560097] [0x00007f9ca2027180] [info]    sensor capture sucess
[2021-06-15 14:49:01.736809] [0x00007f9ca2027180] [info]    color image type: 0, size [1405 x 1056]
[2021-06-15 14:49:01.736871] [0x00007f9ca2027180] [info]    depth image type: 21, size [1405 x 1056]
[2021-06-15 14:49:01.819733] [0x00007f9ca2027180] [error]   point cloud is empty
```

websocket协议部分：

```
[2021-06-15 15:02:41.981366] [0x00007fe0dd5ae180] [info]    connecting sensor at ws://192.168.3.82:8080
[2021-06-15 15:02:41.992375] [0x00007fe0dd5ae180] [info]    websocket version: 0.8.2
[2021-06-15 15:02:42.003091] [0x00007fe0dd5ae180] [info]    sensor distance set to 100 - 2500
[2021-06-15 15:02:42.013504] [0x00007fe0dd5ae180] [info]    sensor fov set to 0, 0, 1440, 1080
[2021-06-15 15:02:42.023926] [0x00007fe0dd5ae180] [info]    sensor current set to 100, 100, 100
terminate called after throwing an instance of 'std::invalid_argument'
  what():  stoi
Aborted (core dumped)
```

## 21-06-18

问题；
1. websocket协议都遇到了同样的问题——live函数报错，stoi无法将字符串转换为整型
2. playback函数所调用的回调函数的定义

### live设置实时曝光，stoi报错

这个错误只发生在websocket协议连接相机

```bash
terminate called after throwing an instance of 'std::invalid_argument'
  what():  stoi
Aborted (core dumped)
```

黄工更新了HYpick，避免了stoi的错误

### playback函数所调用的回调函数如何写才可以正常实时显示相机的画面

实时显示，又称之为“回显”。

```bash
Thread 1 "HYDeviceDemo" hit Breakpoint 1, main (argc=1, argv=0x7fffffffe3e8)
    at /home/hrl/test4HYDeviceSDK/HYDeviceDemo.cpp:188
188                 sensor->playback(callback);
(gdb) step
[New Thread 0x7fffecca6700 (LWP 12886)]
std::__shared_ptr_access<hy::HYSensorClient, (__gnu_cxx::_Lock_policy)2, false, false>::operator-> (
    this=0x7fffffffdf40) at /usr/include/c++/7/bits/shared_ptr_base.h:969
969             return _M_get();
(gdb) step
std::__shared_ptr_access<hy::HYSensorClient, (__gnu_cxx::_Lock_policy)2, false, false>::_M_get (this=0x7fffffffdf40)
    at /usr/include/c++/7/bits/shared_ptr_base.h:975
975           { return static_cast<const __shared_ptr<_Tp, _Lp>*>(this)->get(); }
(gdb) step
std::__shared_ptr<hy::HYSensorClient, (__gnu_cxx::_Lock_policy)2>::get (this=0x7fffffffdf40)
    at /usr/include/c++/7/bits/shared_ptr_base.h:1258
1258          { return _M_ptr; }
(gdb) step
std::__shared_ptr_access<hy::HYSensorClient, (__gnu_cxx::_Lock_policy)2, false, false>::operator-> (
    this=0x7fffffffdf40) at /usr/include/c++/7/bits/shared_ptr_base.h:970
970           }
(gdb) step
std::function<void (cv::Mat const&, int)>::function(std::function<void (cv::Mat const&, int)> const&) (
    this=0x7fffffffe1e0, __x=...) at /usr/include/c++/7/bits/std_function.h:673
673         : _Function_base()
(gdb) step
std::_Function_base::_Function_base (this=0x7fffffffe1e0) at /usr/include/c++/7/bits/std_function.h:271
271         _Function_base() : _M_manager(nullptr) { }
(gdb) step
std::function<void (cv::Mat const&, int)>::function(std::function<void (cv::Mat const&, int)> const&) (
    this=0x7fffffffe1e0, __x=...) at /usr/include/c++/7/bits/std_function.h:675
675           if (static_cast<bool>(__x))
(gdb) step
std::function<void (cv::Mat const&, int)>::operator bool() const (this=0x7fffffffe010)
    at /usr/include/c++/7/bits/std_function.h:583
583           { return !_M_empty(); }
(gdb) step
std::_Function_base::_M_empty (this=0x7fffffffe010) at /usr/include/c++/7/bits/std_function.h:279
279         bool _M_empty() const { return !_M_manager; }
(gdb) step
std::function<void (cv::Mat const&, int)>::function(std::function<void (cv::Mat const&, int)> const&) (
    this=0x7fffffffe1e0, __x=...) at /usr/include/c++/7/bits/std_function.h:677
677               __x._M_manager(_M_functor, __x._M_functor, __clone_functor);
(gdb) step
std::_Function_base::_Base_manager<void (*)(cv::Mat const&, int)>::_M_manager (__dest=..., __source=...,
    __op=std::__clone_functor) at /usr/include/c++/7/bits/std_function.h:212
212             _M_manager(_Any_data& __dest, const _Any_data& __source,
(gdb) step
215               switch (__op)
(gdb) step
227                   _M_clone(__dest, __source, _Local_storage());
(gdb) step
std::_Function_base::_Base_manager<void (*)(cv::Mat const&, int)>::_M_clone (__dest=..., __source=...)
    at /usr/include/c++/7/bits/std_function.h:183
183               ::new (__dest._M_access()) _Functor(__source._M_access<_Functor>());
(gdb) s
std::_Any_data::_M_access<void (*)(cv::Mat const&, int)> (this=0x7fffffffe010)
    at /usr/include/c++/7/bits/std_function.h:117
117           { return *static_cast<const _Tp*>(_M_access()); }
(gdb) s
std::_Any_data::_M_access (this=0x7fffffffe010) at /usr/include/c++/7/bits/std_function.h:107
107         const void* _M_access() const { return &_M_pod_data[0]; }
(gdb) s
std::_Any_data::_M_access (this=0x7fffffffe1e0) at /usr/include/c++/7/bits/std_function.h:106
106         void*       _M_access()       { return &_M_pod_data[0]; }
(gdb) s
operator new (__p=0x7fffffffe1e0) at /usr/include/c++/7/new:169
169     { return __p; }
(gdb) s
std::_Function_base::_Base_manager<void (*)(cv::Mat const&, int)>::_M_clone (__dest=..., __source=...)
    at /usr/include/c++/7/bits/std_function.h:184
184             }
(gdb) s
std::_Function_base::_Base_manager<void (*)(cv::Mat const&, int)>::_M_manager (__dest=..., __source=...,
    __op=std::__clone_functor) at /usr/include/c++/7/bits/std_function.h:228
228                   break;
(gdb) s
234               return false;
(gdb) s
235             }
(gdb) s
std::function<void (cv::Mat const&, int)>::function(std::function<void (cv::Mat const&, int)> const&) (
    this=0x7fffffffe1e0, __x=...) at /usr/include/c++/7/bits/std_function.h:678
678               _M_invoker = __x._M_invoker;
(gdb) s
679               _M_manager = __x._M_manager;
(gdb) s
681         }
(gdb) s
[New Thread 0x7fffdffff700 (LWP 12887)]
[Thread 0x7fffdffff700 (LWP 12887) exited]
std::function<void (cv::Mat const&, int)>::~function() (this=0x7fffffffe1e0, __in_chrg=<optimized out>)
    at /usr/include/c++/7/bits/std_function.h:389
389         class function<_Res(_ArgTypes...)>
```

```bash
Thread 1 "HYDeviceDemo" hit Breakpoint 1, main (argc=1, argv=0x7fffffffe3e8)
    at /home/hrl/test4HYDeviceSDK/HYDeviceDemo.cpp:188
188                 sensor->playback(callback);
(gdb) s
std::__shared_ptr_access<hy::HYSensorClient, (__gnu_cxx::_Lock_policy)2, false, false>::operator-> (
    this=0x7fffffffdf40) at /usr/include/c++/7/bits/shared_ptr_base.h:969
969             return _M_get();
(gdb) finish
Run till exit from #0  std::__shared_ptr_access<hy::HYSensorClient, (__gnu_cxx::_Lock_policy)2, false, false>::operator-> (this=0x7fffffffdf40) at /usr/include/c++/7/bits/shared_ptr_base.h:969
[New Thread 0x7fffecca6700 (LWP 12923)]
0x0000555555579ab1 in main (argc=1, argv=0x7fffffffe3e8) at /home/hrl/test4HYDeviceSDK/HYDeviceDemo.cpp:188
188                 sensor->playback(callback);
Value returned is $1 = (std::__shared_ptr_access<hy::HYSensorClient, (__gnu_cxx::_Lock_policy)2, false, false>::element_type *) 0x5555557c9ba0
(gdb) s
std::function<void (cv::Mat const&, int)>::function(std::function<void (cv::Mat const&, int)> const&) (
    this=0x7fffffffe1e0, __x=...) at /usr/include/c++/7/bits/std_function.h:673
673         : _Function_base()
(gdb) finish
Run till exit from #0  std::function<void (cv::Mat const&, int)>::function(std::function<void (cv::Mat const&, int)> const&) (this=0x7fffffffe1e0, __x=...) at /usr/include/c++/7/bits/std_function.h:673
0x0000555555579ad8 in main (argc=1, argv=0x7fffffffe3e8) at /home/hrl/test4HYDeviceSDK/HYDeviceDemo.cpp:188
188                 sensor->playback(callback);
(gdb) s
[New Thread 0x7fffdffff700 (LWP 12924)]
[Thread 0x7fffdffff700 (LWP 12924) exited]
std::function<void (cv::Mat const&, int)>::~function() (this=0x7fffffffe1e0, __in_chrg=<optimized out>)
    at /usr/include/c++/7/bits/std_function.h:389
389         class function<_Res(_ArgTypes...)>
```