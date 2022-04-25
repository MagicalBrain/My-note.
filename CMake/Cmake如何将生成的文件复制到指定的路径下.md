# Cmake如何将生成的文件复制到指定的路径下

## 指定路径

1、我们可以设置变量来直接保存一个

2、通过cmake的regex找一个

## 自定义指令

知道了路径，接下来就是写自定义指令了。

## 实例

将AuboRobotPlugin-HRL生成的dll复制到其上一级目录下的PluginTest/AuboRobot-HRL文件夹里

项目目录：
```
./
├── AuboRobotPlugin-HRL
│   ├── AxlesModel.json
│   ├── CMakeLists.txt
│   ├── README.md
│   ├── config.json
│   ├── coordinate.json
│   ├── include
│   │   └── AuboRobotPlugin.h
│   ├── io_task.json
│   └── src
│       └── AuboRobotPlugin.cpp
├── HRLPluginConsole
│   ├── CMakeLists.txt
│   ├── include
│   │   └── Path.h
│   └── src
│       ├── Path.cpp
│       └── Source.cpp
├── PluginTest
│   └── AuboRobotPlugin-HRL
├── README.md
```

使用正则表达式找`PROJECT_SOURCE_DIR`上一级的路径

```bash
${PROJECT_SOURCE_DIR} = ./AuboRobotPlugin-HRL
```

```bash
string(REGEX REPLACE "(.+)\\AuboRobotPlugin-HRL.*" "\\1" PROJECT_INIT_PATH ${PROJECT_SOURCE_DIR})
```

```bash
${PROJECT_INIT_PATH} = ./
```

自定义命令：

```bash
# 复制Dll
string(REGEX REPLACE "(.+)\\AuboRobotPlugin-HRL.*" "\\1" PROJECT_INIT_PATH ${PROJECT_SOURCE_DIR})
add_custom_command(
	TARGET
		${PROJECT_NAME}
	POST_BUILD
		COMMAND
			${CMAKE_COMMAND} -E copy $<TARGET_FILE_DIR:${PROJECT_NAME}> ${PROJECT_INIT_PATH}PluginTest/AuboRobotPlugin-HRL
	VERBATIM
)
```

当然复制命令除了copy还有copy_directory

----

完整的例子：
@import "./code/robotplugin-hrl/CMakeLists.txt"
