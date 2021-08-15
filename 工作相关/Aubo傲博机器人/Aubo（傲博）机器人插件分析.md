# Aubo（傲博）机器人插件分析

首先需要注意的是Aubo是有自己的一套SDK的，开发的时候尽量使用Aubo的开发SDK。

## 文件目录

### include的头文件

```cpp
#pragma once
#include <common/HYPluginFactory.hpp>
#include <robot/HYRobotPlugin.hpp>
#include "rsdef.h"
```

C:\hy\hysdk\include\HYPlugin\common\HYPluginFactory.hpp
C:\hy\hysdk\include\HYPlugin\robot\HYRobotPlugin.hpp\
C:\hy\hysdk\3rdParty\Aubo\include\rsdef.h

## 代码实现

### initialize()

主要就是
1. 读取config.json里的设置
2. 初始化机器人控制状态（其他的机器人可能不需要这一点）
3. 修改`initialize_`标志位为true

```cpp
int AuboRobotPlugin::initialize()
```


