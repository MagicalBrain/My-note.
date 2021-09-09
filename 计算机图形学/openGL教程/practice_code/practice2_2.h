#pragma once

#include <boost/filesystem.hpp>

#include "test4OpenGL.h"

class practice2_2 : public test4OpenGL
{
public:
	//const int numVAOs = 1;
	GLuint renderingProgram;
	GLuint vao[numVAOs];

public:
	practice2_2();
	~practice2_2();

	// ��ÿ��Ӧ�ó���ĳ�ʼ�����񶼷���init
	virtual void init(GLFWwindow* window) override;

	virtual void display(GLFWwindow* window, double currentTime) override;

	virtual int test() override;

	string readFile(string filePath);

	GLuint createShaderProgram();

private:

};
