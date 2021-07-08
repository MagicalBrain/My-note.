# boost-test-测试问题

```bash
fatal error: in "Test_Connect_websocket_01": critical check sensor->connected() == true has failed
```

一般遇到这种问题，十有八九是被判别的对象没有初始化，只是被分配了内存空间，没有值，也不为空，无论与谁比较都是false。
