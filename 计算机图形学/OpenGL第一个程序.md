# OpenGL 第一个程序


```C++
#include "windows.h"
#include<gl/glut.h>

void init(void){
   glClearColor(0.0,0.0,0.0,0.0);//设置背景色
   glShadeModel(GL_FLAT);
}


void display(void){
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0,1.0,0.0);//设置前景色
   glBegin(GL_POLYGON); 
      glVertex2f(50.0,50.0); 
      glVertex2f(250.0,50.0); 
      glVertex2f(250.0,250.0); 
   glEnd();
   glFlush();
}

void reshape(int w,int h){
   glViewport(0,0,(GLsizei)w,(GLsizei)h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0.0,(GLdouble)w,0.0,(GLdouble)h);
}

int main(int argc, char* argv[])
{
	/*窗口管理*/
	glutInit(&argc,argv);//初始化GLUT并处理命令行参数，应在调用其它函数前调用
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);//指定使用单缓存RGBA颜色模式
	glutInitWindowSize(300,300);//指定窗口左上角在屏幕上的位置
	glutInitWindowPosition(100,100);//指定窗口的大小，单位为像素
	glutCreateWindow("OpenGL初始化");//该函数返回一个标识符，唯一的标识新建的窗口
	init();
    
	/*回调函数*/
	glutReshapeFunc(reshape);//指定窗口大小发生改变时应采取的措施
	glutDisplayFunc(display);//显示回调函数。每当GLUT认为需要重新显示窗口内容时，都将执行该函数注册的回调函数，因此，应将为重新绘制场景需要调用的函数都放到显示回调函数中

	glutMainLoop();//运行该函数，将创建的所有窗口和被渲染到该窗口中的内容显示出来。程序开始处理事件，注册的显示回调函数被触发。进入该循环后便不会退出。
	
	  return 0;
}
```




