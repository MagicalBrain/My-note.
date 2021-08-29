# OpenGL 程序模板

```c++
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include <amp_graphics.h>


void LineDDA(int x1, int y1, int x2, int y2, int color)
{
	int dm = 0;
	if (abs(x2 - x1) >= abs(y2 - y1))
		dm = abs(x2 - x1);
	else
		dm = abs(y2 - y1);

	float dx = (float)(x2 - x1) / dm;
	float dy = (float)(y2 - y1) / dm;
	float x = x1 + 0.5;
	float y = y1 + 0.5;

	for (int i = 0; i < dm; i++)
	{
		glVertex2i((int)x, (int)y);
		x += dx;
		y += dy;
	}
}


void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0); //窗口颜色(红:[0.0~1.0]R, 绿:[0.0~1.0]G，蓝:[0.0~1.0]B, 透明度:[0.0~1.0]A)
									  /*使用正投影将世界坐标系二位矩形区域的内容映射到屏幕上，区域的x坐标值从0.0到200.0，y坐标值从0.0到150.0*/
	glShadeModel(GLU_FLAT);
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
}

void lineSegment(void)
{
	glClear(GL_COLOR_BUFFER_BIT);//GL_COLOR_BUFFER_BIT是一个OpenGL符号常量，用来指定它的颜色缓存（刷新缓存）中的位值，该缓存将使用 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?glClearColor函数中指定的值来设定。
	glColor3f(1.0f, 1.0f, 0.0f);//设置线段颜色为红色

								/*定义了一个从整数笛卡尔端点坐标（180，15）到(10, 145)的二维直线段*/
	glBegin(GL_POLYGON);
	
	//glVertex2i(180, 15);
	//glVertex2i(10, 145);
	//LineDDA(180, 15, 10, 145, 255);
	glVertex2f(50.0, 50.0);
	glVertex2f(250.0, 50.0);
	glVertex2f(250.0, 250.0);
	glEnd();

	glFlush(); //执行所有的OpenGL程序
}


int main(int argc, char *argv[])
{
	glutInit(&argc, argv);//初始化GULT
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);//设置显示模式
	glutInitWindowPosition(100, 100);//设置左上角窗口显示位置
	glutInitWindowSize(300, 300);//设置窗口显示的宽与高
	glutCreateWindow("An Example OpenGL Program！");//创建一个窗口
	init();//执行初始化程序

	glutReshapeFunc(reshape);
	glutDisplayFunc(lineSegment);//把图形显示在窗口
	glutMainLoop();//显示所有并进入等待状态
	return 0;
}
```




