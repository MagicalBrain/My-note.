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
	float size = 5.0f;	// Ĭ�ϵ�Ĵ�С
	float inc = 1.0f;	// ��Ĵ�С�ı仯��

	practice2_1();
	~practice2_1();

	// ��ÿ��Ӧ�ó���ĳ�ʼ�����񶼷���init
	virtual void init(GLFWwindow* window) override;

	virtual void display(GLFWwindow* window, double currentTime) override;

	virtual int test() override;

	string readFile(string filePath);

	GLuint createShaderProgram();

private:

};




