# Cmake常用指令

## set指令

语法： 
```
SET(VAR [VALUE] [CACHE TYPE DOCSTRING [FORCE]]) 
```

指令功能: 用来显式的定义变量 

例子: 
```
SET (SRC_LST main.c other.c) 
```
说明: 用变量代替值，例子中定义了一个宏SRC_LST代替后面的字符串。

举例：

1、
```
set(libs "${CMAKE_SOURCE_DIR}/src/main/jnilibs")
```

这个命令完成了这么一件事情：
定义了一个变量libs，并且变量的值为`${CMAKE_SOURCE_DIR}/src/main/jnilibs`，其中`CMAKE_SOURCE_DIR` 是一个cmake内置变量，指定了CMakeLists.txt所在的目录。

详细介绍可参考：http://www.cnblogs.com/xianghang123/p/3556425.html。


2、
```
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/src/main/jnilibs/${ANDROID_ABI})
```
这个命令用于给`CMAKE_LIBRARY_OUTPUT_DIRECTORY`宏赋值，该宏指定了cmake编译输出的东西应该放在什么地方。

这个例子中的地方是${PROJECT_SOURCE_DIR}/src/main/jnilibs/${ANDROID_ABI}

其中`PROJECT_SOURCE_DIR` 是cmake内置宏，指向构建工程的全路径。详细介绍可参考

## add_custom_target

