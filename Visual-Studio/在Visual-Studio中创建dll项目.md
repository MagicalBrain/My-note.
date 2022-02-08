# 在Visual-Studio中创建dll项目

## 新建dll项目

在DLL项目里的头文件（最好弄一个头文件包含所有头文件，这样比较方便）加上宏：

```cpp

```

## 如果不想用默认提供的pch那套预编译头怎么办？

很简单，在项目的属性里，C/C++ -> 预编译头 选择不使用 预编译头 即可

![](asset/不使用预编译头.png)

## 如何调用dll

### 如果DLL在同一个vs解决方案中

* 添加头文件
属性`C++` == 常规 ==》 附加包含目录

```bash
$(SolutionDir)MyDLL
```

* 添加lib
链接器 -> 常规 -> 附加库目录

```bash
$(SolutionDir)$(Platform)\$(Configuration)
```

链接器 输入里别忘了添加对应的lib
