## 安装glew库

### 下载glew

[下载地址](http://glew.sourceforge.net/)

点击下载binary就好

### 设置静态调用glew

在 项目属性 -> C++ -> 预处理器 -> 附加宏

添加：
```bash
GLEW_STATIC
```

注意：
设置完成后要先重新生成解决方案，设置方可起作用。

### 检查glew是否安装成功

在程序里添加一句：

```cpp
glewInit();
```
