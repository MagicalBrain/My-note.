#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

/*
* 编写一个编译Shader的函数
* 这是一个static函数，因为不想让它的代码在编译的时候被混入到其它地方
*/
static int ComplieShader(unsigned int type, const std::string &source) {
    //unsigned int id = glCreateShader(GL_VERTEX_SHADER);
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str(); 
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    // TODO: Error handing
    int re;
    glGetShaderiv(id, GL_COMPILE_STATUS, &re);
    if (re == GL_FALSE) {
        int len;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &len);
        //char* message = (char*) alloca(len * sizeof(char));
        char* message = (char*) _malloca(len * sizeof(char));
        glGetShaderInfoLog(id, len, &len, message); 

        std::cout << "Failed to comile "
            << (type == GL_VERTEX_SHADER ? "vertex" : "fragment")
            << std::endl;
        std::cout << message << std::endl;

        glDeleteShader(id);
        return 0;
    }

    return id;
}

/*
* 编写一个创建Shader的函数
* 这是一个static函数，因为不想让它的代码在编译的时候被混入到其它地方
*/
static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader) {
    unsigned int program = glCreateProgram();
    unsigned int vs = ComplieShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = ComplieShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);

    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1024, 760, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    // 检查glew库是否安装成功
    // 初始化glew
    if (glewInit() != GLEW_OK)
        std::cout << "Error: glew initialize failed!" << std::endl;

    // 输出OpenGL版本号
    std::cout << glGetString(GL_VERSION) << std::endl;

    float position[6] = {
        -0.5f, -0.5f,
         0.0f, 0.5f,
         0.5f, -0.5f
    };

    // 定义一个Buffer
    unsigned int buffer;
    glGenBuffers(1, &buffer);
    // 绑定buffer
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), position, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    std::string vertexShader =
        "#version 330 core\n"
        "\n"
        "layout(location = 0) in vec4 position;\n"
        "\n"
        "void main()\n"
        "{\n"
        "   gl_Position = position;\n"
        "}\n"
        ;

    std::string fragmentShader =
        "#version 330 core\n"
        "\n"
        "layout(location = 0) out vec4 color;\n"
        "\n"
        "void main()\n"
        "{\n"
        "   color = vec4(1.0, 0.0, 0.0, 1.0);\n"
        "}\n"
        ;

    unsigned int shader = CreateShader(vertexShader, fragmentShader);
    glUseProgram(shader);

    //glBindBuffer(GL_ARRAY_BUFFER, 0);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        // 清楚当前屏幕上画的东西
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /*
        * 一下是legacy OpenGL的写法，现在不用了
        // ToDo 注意真正要写的代码在这
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.5f, -0.5f);
        glEnd();
        */

        // 画三角形
        glDrawArrays(GL_TRIANGLES, 0, 3);


        // 交换buffer
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glDeleteProgram(shader);

    glfwTerminate();
    return 0;
}
