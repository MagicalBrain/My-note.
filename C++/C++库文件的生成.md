# C++库文件的生成

Windows和Linux的库文件对应关系分别为

|winidows|Linux|
|--|--|
|.obj|.o|
|.lib|.a|
|.dll|.so|

## 使用gcc编译

参考本库的```gcc_g++```部分的内容

## 使用cmake编译

### 生成静态库

```cmake
add_library(name.a STATIC file1.cpp file2.cpp)
```

**注意**：
生成的库文件为```libname.a```。

### 生成动态库

```cmake
add_library(name.so SHARED file1.cpp file2.cpp)
```

**注意**：
生成的库文件为```libname.so```。
