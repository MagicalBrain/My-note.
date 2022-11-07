#pragma once

#include <boost/filesystem.hpp>

#include "test4OpenGL.h"

class practice2_1 : public test4OpenGL
{
public:
	//const int numVAOs = 1;
	GLuint renderingProgram;
	GLuint vao[numVAOs];

public:
	float size = 5.0f;	// 默认点的大小
	float inc = 1.0f;	// 点的大小的变化量

	practice2_1();
	~practice2_1();

	// 将每个应用程序的初始化任务都放在init
	virtual void init(GLFWwindow* window) override;

	virtual void display(GLFWwindow* window, double currentTime) override;

	virtual int test() override;

	string readFile(string filePath);

	GLuint createShaderProgram();

private:

};




