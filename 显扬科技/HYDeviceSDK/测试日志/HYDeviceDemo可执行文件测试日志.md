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