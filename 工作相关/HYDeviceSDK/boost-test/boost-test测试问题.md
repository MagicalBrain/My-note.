# boost-test-测试问题

```bash
fatal error: in "Test_Connect_websocket_01": critical check sensor->connected() == true has failed
```

一般遇到这种问题，十有八九是被判别的对象没有初始化，只是被分配了内存空间，没有值，也不为空，无论与谁比较都是false。

遇到要调试的情形需要查看HYDeviceManager详细的日志，还需输入命令：

```bash
.\HYDeviceManager.exe -l 1
```
