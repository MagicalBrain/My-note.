# C/C++里的宏指令

## pragma once

这是一个防止本文件编译多次的命令。

## ifndef

```cpp
#ifndef NAME
//todo
#endif
```

如果宏`NAME`没有定义就会执行`#ifndef`里的语句

**注意**：别忘了和```#endif```成对使用
