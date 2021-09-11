# 1-安装openGL需要啥？

1. C++开发环境
2. OpenGL/GLSL
3. 窗口管理库
4. 扩展库
5. 数学库
6. 纹理管理

## C++开发环境：
略

## OpenGL/GLSL

OpenGL/GLSL是已经装好在显卡驱动里的，查一下支持哪个版本就行。

# 窗口管理库：
以前用glut，现在最流行的则是GLFW，内置了常见系统跨平台的支持。

# 扩展库：

**GLEW**

为啥要用glew库？

因为OpenGL只是一个标准/规范，具体的实现是由驱动开发商针对特定显卡实现的。由于OpenGL驱动版本众多，它大多数函数的位置都无法在编译时确定下来，需要在运行时查询。任务就落在了开发者身上，开发者需要在运行时获取函数地址并将其保存在一个函数指针中供以后使用。取得地址的方法因平台而异，在Windows上会是类似这样：

```cpp
// 定义函数原型
typedef void (*GL_GENBUFFERS) (GLsizei, GLuint*);
// 找到正确的函数并赋值给函数指针
GL_GENBUFFERS glGenBuffers  = (GL_GENBUFFERS)wglGetProcAddress("glGenBuffers");
// 现在函数可以被正常调用了
GLuint buffer;
glGenBuffers(1, &buffer);
```

你可以看到代码非常复杂，而且很繁琐，我们需要对每个可能使用的函数都要重复这个过程。幸运的是，有些库能简化此过程，其中GLEW是目前最新，也是最流行的库。

@import "./安装glew库.md"

# 数学库：

常见的有：Eigen和vmath
但是和OpenGL配合的最好的还是OpenGL Mathematics

# 纹理库

常见的有：
1. FreeImage
2. Devil
3. OpenGL Image GLI
4. Glraw
5. SOIL (Simple OpenGL Image Loader)

推荐使用SOIL2，这是SOIL的一个较新的分支版本

## 可选库

有一些更复杂的现成的OBJ加载器可供选择