# 使用 nlohmann 读取json

注意看`HYRobotPluginParam.hpp`文件及其实现`HYRobotPluginParam.cpp`文件

`#include <nlohmann/json.hpp>`

## 序列化json

```cpp
json j;
j.jump();
```

## 对于nlomann没有定义的类型如何读写json

参考链接：
https://cloud.tencent.com/developer/article/1907451
