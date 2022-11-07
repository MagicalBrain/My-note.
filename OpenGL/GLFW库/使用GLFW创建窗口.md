# 使用GLFW创建窗口

这是一个简单的实例

```cpp
int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    return 0;
}
```

## 初始化GLFW库

```cpp
glfwInit();
```

## 设置窗口属性

### glfwDefaultWindowHints()	

```cpp
void glfwDefaultWindowHints	(	void 		)	
```

设置窗口默认的属性

### glfwWindowHint()

```cpp
void glfwWindowHint(	
    int 	hint,
    int 	value 
)	
```

用整型变量来设置窗口属性的函数

### glfwWindowString()

```cpp
void glfwWindowHintString	(	int 	hint,
const char * 	value 
)	
```
