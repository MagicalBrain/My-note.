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
* ������ɫ������
*/
GLuint practice2_2::createShaderProgram() {
	GLint vertCompiled;
	GLint fragCompiled;
	GLint linked;

	/*
	* ͨ�� vertShaderStr, fshaderSource �����ַ���
	* ��glsl������ļ����ȡ����
	*/
	stringstream target;
	boost::filesystem::path path = boost::filesystem::initial_path();
	cout << path.string() << endl;

	// ʹ�÷�б��
	target << path.string() << "/shader/vertShaderP2_2.glsl";
	string vertShaderPath = target.str();
	cout << vertShaderPath << endl;
	string vertShaderStr = readFile(vertShaderPath);
	target.str("");

	// ʹ������б�� ���ǿ��Ե�
	target << path.string() << "\\shader\\fragShaderP2_2.glsl";
	string fragShaderPath = target.str();
	cout << fragShaderPath << endl;
	string fragShaderStr = readFile(fragShaderPath);

	const char* vertShaderSrc = vertShaderStr.c_str();
	const char* fragShaderSrc = fragShaderStr.c_str();

	// �����յĶ�����ɫ������
	// ��������ɫ�������IDͨ��GLuint����
	GLuint vShader = glCreateShader(GL_VERTEX_SHADER);

	// �����յ�Ƭ����ɫ������
	// ��������ɫ�������IDͨ��GLuint����
	GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);

	// ����һ���������
	// vfprogram �洢�ó���� ID
	GLuint vfprogram = glCreateProgram();

	// ��GLSL������ַ�������յ���ɫ��������
	glShaderSource(vShader, 1, &vertShaderSrc, NULL);
	glShaderSource(fShader, 1, &fragShaderSrc, NULL);
	/*
	* glShaderSource() ���ĸ�������
	* 1. �����ɫ������ɫ������
	* 2. �洢��ɫ��Դ������ַ�������
	* 3. ����Դ������ַ���ָ��
	* 4.
	*/

	// ������ɫ��Դ����
	glCompileShader(vShader);
	glCompileShader(fShader);
	

	// �� ��ɫ�� ���뵽�������
	glAttachShader(vfprogram, vShader);
	glAttachShader(vfprogram, fShader);

	// ��������GLSL������
	glLinkProgram(vfprogram);
	

	// ���س�������ID����vfprogram
	return vfprogram;
}

// ��ÿ��Ӧ�ó���ĳ�ʼ�����񶼷���init
void practice2_2::init(GLFWwindow* window)
{
	// ���� createShaderProgram() �ﴴ���ĳ������
	// ������ID Ϊȫ�ֱ��� renderingProgram
	renderingProgram = createShaderProgram();

	// �����ݴ��� ����������� (Vertex array object, VAO)
	glGenVertexArrays(numVAOs, vao);
	glBindVertexArray(vao[0]);
}

void practice2_2::display(GLFWwindow* window, double currentTime)
{
	/*
	* �� �������󶨵���ɫ���������뵽OpenGL�����У���GPU��
	* ��û��������ɫ������
	*/
	glUseProgram(renderingProgram);

	// ���õ�Ĵ�С��Ĭ�ϵ�Ĵ�С��30������
	//glPointSize(30.0f);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	// ����OpenGL���ߴ���
	//glDrawArrays(GL_POINTS, 0, 1);
}

/*
* ��ɫ���� ��һ����
*/
int practice2_2::test()
{
	// ��ʼ��GLFW��
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}

	// ���û���������OpenGL �汾 4.3 ����
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// ʵ����GLFW window
	GLFWwindow* window = glfwCreateWindow(600, 600, "Chapter 2 - program 4", NULL, NULL);
	/*
	* ��͸���Ϊ����ǰ����������������������ʾ������ڵ����ƣ����⣩
	* ����������ΪNULL�Ĳ�������������ȫ����ʾ����Դ�����
	*/

	/*
	* ֪ͨGLFW�����Ǵ��ڵ�����������Ϊ��ǰ�̵߳����������ˡ�
	*/
	glfwMakeContextCurrent(window);

	// ��ʼ��GLEW��
	if (glewInit() != GLEW_OK) {
		exit(EXIT_FAILURE);
	}
	glfwSwapInterval(1);

	init(window);

	while (!glfwWindowShouldClose(window)) {
		// ����display������ʾ��Ⱦ������
		display(window, glfwGetTime());

		// ������� glfwSwapInterval() ���
		// ����������ֱͬ����
		glfwSwapBuffers(window);

		// ����������¼�
		glfwPollEvents();
	}

	// ���ٴ���
	glfwDestroyWindow(window);
	// ��ֹ����
	glfwTerminate();
	//exit(EXIT_SUCCESS);
	return 0;
}
