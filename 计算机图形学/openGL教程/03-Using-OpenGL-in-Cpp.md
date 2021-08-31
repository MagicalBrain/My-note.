# 03-Using-OpenGL-in-Cpp

@import "安装glew库.md"

注意：
glew的初始化要在有效的`OpenGL`渲染上下文之后，在这里也就是：

```cpp
/* Make the window's context current */
glfwMakeContextCurrent(window);

// 检查glew库是否安装成功
// 初始化glew
if (glewInit() != GLEW_OK)
    std::cout << "Error: glew initialize failed!" << std::endl;
```

也就是`glewInit()`要放在`glfwMakeContextCurrent(window)`之后。
