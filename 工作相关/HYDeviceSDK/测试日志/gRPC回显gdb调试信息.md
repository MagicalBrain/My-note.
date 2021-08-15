# gRPC回显gdb调试信息

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

运行到这里HYDeviceManager就会闪退
