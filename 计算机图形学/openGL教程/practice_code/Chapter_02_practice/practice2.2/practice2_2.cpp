#pragma once
#include "../include/practice2_2.h"


practice2_2::practice2_2()
{
}

practice2_2::~practice2_2()
{
}

string practice2_2::readFile(string filePath) {
	cout << filePath << endl;
	string content;
	ifstream fileStream(filePath, ios::in);
	string line = "";
	while (!fileStream.eof()) {
		getline(fileStream, line);
		content.append(line + "\n");
	}
	fileStream.close();
	cout << content << endl;
	return content;
}


/*
* 创建着色器程序
*/
GLuint practice2_2::createShaderProgram() {
	GLint vertCompiled;
	GLint fragCompiled;
	GLint linked;

	/*
	* 通过 vertShaderStr, fshaderSource 两个字符串
	* 将glsl代码从文件里读取出来
	*/
	stringstream target;
	boost::filesystem::path path = boost::filesystem::initial_path();
	cout << path.string() << endl;

	// 使用反斜杠
	target << path.string() << "/shader/vertShaderP2_2.glsl";
	string vertShaderPath = target.str();
	cout << vertShaderPath << endl;
	string vertShaderStr = readFile(vertShaderPath);
	target.str("");

	// 使用两个斜杠 都是可以的
	target << path.string() << "\\shader\\fragShaderP2_2.glsl";
	string fragShaderPath = target.str();
	cout << fragShaderPath << endl;
	string fragShaderStr = readFile(fragShaderPath);

	const char* vertShaderSrc = vertShaderStr.c_str();
	const char* fragShaderSrc = fragShaderStr.c_str();

	// 创建空的顶点着色器对象
	// 并将该着色器对象的ID通过GLuint返回
	GLuint vShader = glCreateShader(GL_VERTEX_SHADER);

	// 创建空的片段着色器对象
	// 并将该着色器对象的ID通过GLuint返回
	GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);

	// 创建一个程序对象
	// vfprogram 存储该程序的 ID
	GLuint vfprogram = glCreateProgram();

	// 将GLSL代码从字符串载入空的着色器对象里
	glShaderSource(vShader, 1, &vertShaderSrc, NULL);
	glShaderSource(fShader, 1, &fragShaderSrc, NULL);
	/*
	* glShaderSource() 有四个参数：
	* 1. 存放着色器的着色器对象
	* 2. 存储着色器源代码的字符串个数
	* 3. 包含源代码的字符串指针
	* 4.
	*/

	// 编译着色器源代码
	glCompileShader(vShader);
	glCompileShader(fShader);
	

	// 将 着色器 载入到程序对象
	glAttachShader(vfprogram, vShader);
	glAttachShader(vfprogram, fShader);

	// 链接请求GLSL编译器
	glLinkProgram(vfprogram);
	

	// 返回程序对象的ID——vfprogram
	return vfprogram;
}

// 将每个应用程序的初始化任务都放在init
void practice2_2::init(GLFWwindow* window)
{
	// 调用 createShaderProgram() 里创建的程序对象
	// 并返回ID 为全局变量 renderingProgram
	renderingProgram = createShaderProgram();

	// 将数据存入 顶点数组对象 (Vertex array object, VAO)
	glGenVertexArrays(numVAOs, vao);
	glBindVertexArray(vao[0]);
}

void practice2_2::display(GLFWwindow* window, double currentTime)
{
	/*
	* 将 程序对象绑定的着色器对象载入到OpenGL管线中，即GPU里
	* 并没有运行着色器程序。
	*/
	glUseProgram(renderingProgram);

	// 设置点的大小，默认点的大小是30个像素
	//glPointSize(30.0f);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	// 启动OpenGL管线处理
	//glDrawArrays(GL_POINTS, 0, 1);
}

/*
* 着色器， 画一个点
*/
int practice2_2::test()
{
	// 初始化GLFW库
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}

	// 设置机器必须与OpenGL 版本 4.3 兼容
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// 实例化GLFW window
	GLFWwindow* window = glfwCreateWindow(600, 600, "Chapter 2 - program 4", NULL, NULL);
	/*
	* 宽和高作为它的前两个参数；第三个参数表示这个窗口的名称（标题）
	* 另外两个设为NULL的参数是用来设置全屏显示和资源共享的
	*/

	/*
	* 通知GLFW将我们窗口的上下文设置为当前线程的主上下文了。
	*/
	glfwMakeContextCurrent(window);

	// 初始化GLEW库
	if (glewInit() != GLEW_OK) {
		exit(EXIT_FAILURE);
	}
	glfwSwapInterval(1);

	init(window);

	while (!glfwWindowShouldClose(window)) {
		// 调用display函数显示渲染的物体
		display(window, glfwGetTime());

		// 和上面的 glfwSwapInterval() 配合
		// 用来开启垂直同步的
		glfwSwapBuffers(window);

		// 处理窗口相关事件
		glfwPollEvents();
	}

	// 销毁窗口
	glfwDestroyWindow(window);
	// 终止运行
	glfwTerminate();
	//exit(EXIT_SUCCESS);
	return 0;
}
