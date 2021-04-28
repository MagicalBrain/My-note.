# OpenCV 实例（一） 随机加椒盐噪音

标签（空格分隔）： OpenCV

---

与像素操作的部分有关
```c++
#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void salt(Mat image,int n)
{
	int i, j;
	for (int k = 0; k < n; k++)
	{
		//rand是随机数生成器
		i = rand() % image.cols;
		j = rand() % image.rows;

		if (image.type()==CV_8UC1)
		{
			image.at<uchar>(j, i) = 255;
		}
		else if (image.type()==CV_8UC3)
		{
			image.at<Vec2b>(j,i)[0] = 255;
			image.at<Vec2b>(j, i)[1] = 255;
			image.at<Vec2b>(j, i)[2] = 255;
		}
	}
}

//减色函数
void colourReduce(Mat image, int div=64)
{
	int n1 = image.rows;
	int n2 = image.cols*image.channels();

	for (int j = 0; j < n1; j++)
	{
		uchar*data = image.ptr<uchar>(j);
		for (int i = 0; i < n2; i++)
		{
			data[i]=data[i]/div*div+div/2;
		}
		
	}
}

int main(void)
{
	Mat Image(240,320,CV_8U,Scalar(100));
	Image = imread("image.jpg",CV_LOAD_IMAGE_COLOR);
	namedWindow("My image");
	imshow("My image",Image);

	salt(Image,30000);
	//调用函数以增加噪音
	colourReduce(Image);
	//调用减色函数

	Mat image(240,320,CV_8UC3,Scalar(0,0,255));
	namedWindow("My red image");
	imshow("My red image",image);

	//Image.convertTo(image,CV_16U,1/1.0,0.0);
	imshow("My image", Image);

	waitKey(0);
	return 0;
}
```




