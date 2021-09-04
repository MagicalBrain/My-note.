#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

struct ShaderProgramSource {
    std::string VertexSource;
    std::string FragmentSource;
};

static ShaderProgramSource ParseShader(const std::string& filepath) {
    std::ifstream stream(filepath);

    enum ShaderType
    {
        NONE = -1,
        VERTEX = 0,
        FRAGMENT = 1
    };

    std::string line;
    std::stringstream ss[2];
    ShaderType type = ShaderType::NONE;

    while (getline(stream, line))
    {
        if (line.find("#shader") != std::string::npos) {
            if (line.find("vertex") != std::string::npos)
                type = ShaderType::VERTEX;
            else if (line.find("fragment") != std::string::npos)
                type = ShaderType::FRAGMENT;
        }
        else {
            ss[(int)type] << line << "\n";
        }
    }
    return { ss[0].str(), ss[1].str() };
}

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

    /* Create a windowed mode window and its OpenGL context 
    * 使用glfw创建一个Windows模式的窗口，并将OpenGL的上下文放入其中
    */
    window = glfwCreateWindow(1024, 760, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current 
    * 使用glfw初始化一个窗口的上下文
    */
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
    
    
    // 创建一个vertex shader（顶点着色器）
    ShaderProgramSource source = ParseShader("./Basic.shader");
    std::cout << "Vertex: " << std::endl;
    std::cout << source.VertexSource << std::endl;
    std::cout << "Fragment: " << std::endl;
    std::cout << source.FragmentSource << std::endl;

    unsigned int shader = CreateShader(source.VertexSource, source.FragmentSource);
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
