# boost-文件系统学习使用

## 核心类path

头文件：`#include <boost/filesystem.hpp>`

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

## 遍历目录

```cpp
#include <iostream>

#include <boost/filesystem.hpp>

// 这是一个遍历当前目录下所有文件的函数
// 目录里的子目录会被跳过
int test4ls() {
	std::string str;
	std::cout << "please input the path of directory: " << std::endl;
	std::cin >> str;
	std::cin.get();

	//boost::filesystem::path path = boost::filesystem::initial_path<boost::filesystem::path>();
	boost::filesystem::path path(str);
	boost::filesystem::directory_iterator pos(path);

	std::cout << path.string() << std::endl;

	boost::filesystem::directory_iterator end;
	for (; pos != end; pos++)
	{
		// 如果是目录就跳过
		if (boost::filesystem::is_directory(*pos))
			continue;

		std::cout << *pos << std::endl;
		std::cout << pos->path().string() << std::endl;
	}

	return 0;
}

```
