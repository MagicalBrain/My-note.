# OpenGL实现魔方

## 实现思路

### 1、如何画方块

## 遇到问题的解决办法

### 1、多个旋转轴复合旋转的解决办法

每旋转一次，存储当前的状态，而后刷新坐标系，进行下一次旋转


```c++
void Draw_Cube(GLfloat x1, GLfloat x2, GLfloat y1, GLfloat y2, GLfloat z1, GLfloat z2)
{	//桌子由立方体组成，已知六个参数即可构造八个顶点
	int i, j;
	GLfloat vertex[8][3] = {
		//八个顶点，从v1-v8
		x1,y1,z2,
		x2,y1,z2,
		x1,y2,z2,
		x2,y2,z2,
		x1,y1,z1,
		x2,y1,z1,
		x1,y2,z1,
		x2,y2,z1
	};
	GLint surface[6][4] = {
		//v1对应0,以此类推
		0,1,3,2,
		4,5,7,6,
		2,3,7,6,
		0,1,5,4,
		0,2,6,4,
		1,3,7,5
	};

	glBegin(GL_QUADS);//指定绘制方式
					  //将每个立方体分成六个面绘制
	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 4; j++)
			glVertex3fv(vertex[surface[i][j]]);
	}
		
	glEnd();
}
```

### 2、如何给方块的每一个面着色

在绘制方块的函数Draw_Cube中最后绘制的for循环那里加一个swirch语句来控制你每个面想要的颜色

```c++
for (i = 0; i < 6; i++)
	{
		glColor3f(1.0, 1.0, 1.0);
		switch (i)
		{
		case 0:
			glColor3f(1.0, 1.0, 0.0);
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		default:
			break;
		}
		for (j = 0; j < 4; j++)
			glVertex3fv(vertex[surface[i][j]]);
	}
```

这里最好是里面的颜色统一成一个颜色，比如灰色。

### 但是要怎么确定每个块朝向里面那些面是哪几个面？

只能想一个编码了：

类似二维的分割编码，我们可以想一个三维的，有四个面来分割：
分别是up,down,left,right四个面，可以想象一下

修改块的数据结构为：

```c
//每个块的旋转变量
typedef struct cube
{
	int rox, roy, roz;
	int x, y, z;
	int up,down,left,right;
}cube;
```

#### 块与那四个面的相对位置的判别条件？

##### up面

在up上面：

```c
roz>=1
```

在up下面：
```c
roz<1
```

其他三个面，以此类推

### 3、如何旋转

### 4、坐标系、旋转轴的问题如何解决？

## 魔方的数据结构

## 参考代码

```c++
// main.cpp : 定义控制台应用程序的入口点。
#include "glut.h"
 
float fTranslate;//平移因子
float fRotate;//旋转因子
float fScale=1.0f;//缩放因子
 
void Draw_Cube(GLfloat x1, GLfloat x2, GLfloat y1,GLfloat y2,GLfloat z1,GLfloat z2)
{	//桌子由立方体组成，已知六个参数即可构造八个顶点
	int i, j;
	GLfloat vertex[8][3] = {
		//八个顶点，从v1-v8
		x1,y1,z2,
		x2,y1,z2,
		x1,y2,z2,
		x2,y2,z2,
		x1,y1,z1,
		x2,y1,z1,
		x1,y2,z1,
		x2,y2,z1
	};
	GLint surface[6][4] = {
		//v1对应0,以此类推
		0,1,3,2,
		4,5,7,6,
		2,3,7,6,
		0,1,5,4,
		0,2,6,4,
		1,3,7,5
	};
 
	glBegin(GL_QUADS);//指定绘制方式
	//将每个立方体分成六个面绘制
	for (i = 0; i < 6; i++)
		for (j = 0; j < 4; j++)
			glVertex3fv(vertex[surface[i][j]]);
	glEnd();
}
void Draw_Table()
{
	//将桌子拆分成5个立方体绘制
	Draw_Cube(0.0, 1.0, 0.0, 0.8, 0.6, 0.8);//桌面
	Draw_Cube(0.1, 0.3, 0.1, 0.3, 0.0, 0.6);//四条腿
	Draw_Cube(0.7, 0.9, 0.1, 0.3, 0.0, 0.6);
	Draw_Cube(0.1, 0.3, 0.5, 0.7, 0.0, 0.6);
	Draw_Cube(0.7, 0.9, 0.5, 0.7, 0.0, 0.6);
}
 
void reshape(int width, int height)
{
	//当窗口尺寸改变时改变尺寸
	if (height==0)										// Prevent A Divide By Zero By
	{
		height=1;										// Making Height Equal One
	}
	glViewport(0,0,width,height);						// Reset The Current Viewport
 
	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix
 
	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
 
	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}
 
void idle()
{
	glutPostRedisplay();
}
 
void redraw()
{
	//display in wireframe mode
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glClear(GL_COLOR_BUFFER_BIT);//清除窗口
	glLoadIdentity();						// Reset The Current Modelview Matrix
	//模型变换——移动	
	glPushMatrix();//glpushmatrix与glpopmatrix配合使用可以消除上一次变换对本次变换的影响
	glTranslatef(-2.5f, 0.0f,-6.0f);//放在左边
	glTranslatef(0.0f, fTranslate, 0.0f);
	Draw_Table();					
	glPopMatrix();
	//模型变换——旋转
	glPushMatrix();
	glTranslatef(0.0f, 0.0f,-6.0f);//放在中间
	glRotatef(fRotate, 0, 1.0f, 0);			// Rotate around Y axis
	Draw_Table();						// Draw triangle
	glPopMatrix();
	//模型变换——缩放
	glPushMatrix();
	glTranslatef(2.0f, 0.0f, -6.0f);
	glScalef(fScale, fScale,fScale);
	Draw_Table();
	glPopMatrix();
	//更新因子
	fTranslate += 0.005f;
	fRotate += 0.5f;
	fScale -= 0.005f;
 
	if(fTranslate > 0.5f)
		fTranslate = 0.0f;
	if (fScale < 0.5f)//缩小到一定程度之后变回原来大小
		fScale = 1.0f;
	glutSwapBuffers();
}
 
int main (int argc,  char *argv[])
{
	glutInit(&argc, argv);//对glut函数库进行初始化
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);//指定glutCreateWindow函数将要创建的窗口显示模式 RGB 双缓冲
	glutInitWindowSize(640,480);//窗口大小                                         
	glutCreateWindow("Exercise2");//打开设置好的窗口，进入glutMainLoop之前这个窗口不会显示
 
	glutDisplayFunc(redraw);//指定当前窗口需要重绘时调用的函数
	glutReshapeFunc(reshape);//注册窗口大小改变时回调函数
	glutIdleFunc(idle);	//可以执行连续动画				
 
	glutMainLoop();//进入glut事件处理循环，永远不会返回
 
	return 0;
}

```






