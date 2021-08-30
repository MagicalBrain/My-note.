# Broadcast Tutorial

广播教程？

This tutorial will dig into some more nitty gritty details on how to build high
scalability, high performance websocket servers for broadcast like workflows.

本教程将深入了解一些关于如何构建高扩展性，高性能的websocket服务器用于广播，如工作流。

Will go into features like:
- minimizing work done in handlers
- using asio thread pool mode
- teaming multiple endpoints
- setting accept queue depth
- tuning compile time buffer sizes
- prepared messages
- flow control
- basic operating system level tuning, particularly increasing file descriptor limits.
- measuring performance with wsperf / autobahn
- tuning permessage-deflate compression settings

将叙述如下功能:
- 尽量减少处理器的工作
- 使用asio线程池模式
- 多个端点负载平衡
- 设置接受队列深度
- 调整编译时缓冲区大小
- 准备要发送的消息
- 流控制
- 基本操作系统级别调优，特别是增加文件描述符限制。
- 用wsperf / autobahn测量性能
- 调整permessage-deflate压缩设置
