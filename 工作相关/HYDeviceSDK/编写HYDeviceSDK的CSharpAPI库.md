# 编写HYDeviceSDK的C#API库

实现一个HYWebSocketCSharp类

## 构造函数与析构函数

析构函数为空，没什么好说的，因为释放内存的操作有专门一个release函数（应该）。

构造函数：
1. set access logger channel 设置访问日志记录器的channel
2. 设置访问错误日志的记录器的channel
3. 初始化ASIO（估计是初始化一个异步操作的库）
4. 
