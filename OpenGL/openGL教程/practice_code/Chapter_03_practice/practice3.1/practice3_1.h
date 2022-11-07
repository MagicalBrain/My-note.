#pragma once

#include <boost/filesystem.hpp>

#include <glm.hpp>
//#include <math.h>

#include "test4OpenGL.h"

class practice3_1 : public test4OpenGL
{
public:
	//const int numVAOs = 1;
	GLuint renderingProgram;
	GLuint vao[numVAOs];

	float x = 0.0;
	float inc = 0.01;

public:
	practice3_1();
	~practice3_1();

	// 将每个应用程序的初始化任务都放在init
	virtual void init(GLFWwindow* window) override;

	virtual void display(GLFWwindow* window, double currentTime) override;

	virtual int test() override;

	string readFile(string filePath);

	GLuint createShaderProgram();

	//buildRotate();

private:

};
