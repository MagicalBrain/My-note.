# OpenCV 入门（一） 图像中画图加文字

标签（空格分隔）： OpenCV 

---


```c++
#include <opencv2\opencv.hpp>
#include <iostream>  
using namespace cv;
using namespace std;

int main(void)
{
	Mat image;  //定义一个新图像
	cout << "The image is " << image.rows << " x " << image.cols << endl;
	//输出该图像的大小
	image = imread("img.jpg", CV_LOAD_IMAGE_COLOR);  //读取输入的图像
	namedWindow("我的第一张图");

	circle(image,
		Point(50, 50),
		20,
		255,
		3);

	putText(image,
		"Galaxy.",
		Point(40, 200),
		FONT_HERSHEY_PLAIN,
		2.0,
		255,
		2);
	if (!image.empty())
	imshow("我的第一张图", image);
	else
	{
		cout << "图片为空" << endl;
	}
	/*窗口是以名字来表识的，所以定义用 namedWindow 定义一个名字，
	然后可用 imshow 通过名字来打开窗口*/

	cout << "This image has " << image.channels() << " channels" << endl;

	waitKey(0);

	return 0;
}
```
**注意：**绘图语句必须要放在输出语句imshow前面

## 代码二
两者几乎一模一样，只是上面的更加健壮

```c++
#include <opencv2\opencv.hpp>
#include <iostream>  
using namespace cv;
using namespace std;

int main(void)
{
	Mat image;  //定义一个新图像
	cout << "The image is " << image.rows << " x " << image.cols << endl;
	//输出该图像的大小
	image = imread("img.jpg",CV_LOAD_IMAGE_COLOR);  //读取输入的图像
	namedWindow("我的第一张图");

	circle(image,
		Point(50, 50),
		20,
		255,
		3);

	putText(image,
		"Galaxy.",
		Point(40, 200),
		FONT_HERSHEY_PLAIN,
		2.0,
		255,
		2);

	imshow("我的第一张图", image);
	/*窗口是以名字来表识的，所以定义用 namedWindow 定义一个名字，
	然后可用 imshow 通过名字来打开窗口*/
	
	cout << "This image has " << image.channels() << " channels"<<endl;
	
	waitKey(0);
	
	return 0;
}
```

输出：

![image_1cjaib0cm1h8qi0p1no1oj5bdu9.png-84.2kB][1]


  [1]: http://static.zybuluo.com/Arbalest-Laevatain/ou02kvqdudk8eaexqeip1aab/image_1cjaib0cm1h8qi0p1no1oj5bdu9.png