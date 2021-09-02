# boost-文件系统学习使用

## 核心类path

### path定义

```cpp

```

# 用法

## 获取路径

### 获取当前文件所在的路径

```cpp
boost::filesystem::path path;
path = boost::filesystem::initial_path<boost::filesystem::path>();
```

### 获取当前路径的父目录

```cpp
boost::filesystem::path path;
cout << path.parent_path().string() << endl;
```
