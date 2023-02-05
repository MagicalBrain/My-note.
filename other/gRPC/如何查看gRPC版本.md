# 如何查看gRPC版本

可以通过查看源码根目录下的Makefile文件中的

```
CORE_VERSION = 7.0.0-dev

CPP_VERSION=1.18.0-dev

CSHARR_VERSION=1.18.0-dev
```

三个字段查看

注意：
HYDeviceSDK装的时gRPC 1.38，这三个字段为:

```bash
CORE_VERSION = 16.0.0
CPP_VERSION = 1.38.0
CSHARP_VERSION = 2.38.0
```