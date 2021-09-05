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

## 窗口管理库：
以前用glut，现在最流行的则是GLFW，内置了常见系统跨平台的支持。

## 扩展库：
GLEW

## 数学库：
常见的有：Eigen和vmath
但是和OpenGL配合的最好的还是OpenGL Mathematics

## 纹理库

常见的有：
1. FreeImage
2. Devil
3. OpenGL Image GLI
4. Glraw
5. SOIL (Simple OpenGL Image Loader)

推荐使用SOIL2，这是SOIL的一个较新的分支版本

## 可选库

有一些更复杂的现成的OBJ加载器可供选择