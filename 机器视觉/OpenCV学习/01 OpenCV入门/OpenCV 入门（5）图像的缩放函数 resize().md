# OpenCV 入门（五）图像的缩放函数 resize()

标签（空格分隔）： OpenCV

---

## 函数的声明
```c++
void resize(InputArray src, OutputArray dst, Size dsize, double fx=0, double fy=0,
int interpolation=INTER_LINEAR )

/*
参数含义：
InputArray src     -原图像
OutputArray dst    -输出图像
Size dsize         -目标图像的大小
double fx=0        -在x轴上的缩放比例
double fy=0        -在y轴上的缩放比例

int interpolation  -插值方式，有以下四种方式（参数）
INTER_NN      -最近邻插值
INTER_LINEAR  -双线性插值 (默认使用)
INTER_AREA    -使用象素关系重采样，当图像缩小时候，该方法可以避免波纹出现。当图像放大时，类似于 INTER_NN 方法。
INTER_CUBIC   -立方插值。
*/
```

**说明：dsize与fx和fy必须不能同时为零**

### 例子
```c++
#include <opencv2\opencv.hpp>
#include <opencv2\imgproc\imgproc.hpp>
 
using namespace cv;
 
int main()
{
	//读入图像
	Mat srcImage=imread("1.jpg");
	Mat temImage,dstImage1,dstImage2;
	temImage=srcImage;
 
	//显示原图
	imshow("原图",srcImage);
 
	//尺寸调整
	resize(temImage,dstImage1,Size(temImage.cols/2,temImage.rows/2),0,0,INTER_LINEAR);
	resize(temImage,dstImage2,Size(temImage.cols*2,temImage.rows*2),0,0,INTER_LINEAR);
 
	imshow("缩小",dstImage1);
	imshow("放大",dstImage2);
 
	waitKey();
	return 0;
 
}
```




