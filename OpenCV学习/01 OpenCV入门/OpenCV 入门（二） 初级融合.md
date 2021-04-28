# OpenCV 入门（二） 初级融合

标签（空格分隔）： OpenCV

---

```c++
#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat img1 = imread("image.jpg",CV_LOAD_IMAGE_COLOR);
	Mat img2 = imread("img.jpg",CV_LOAD_IMAGE_COLOR);

	Mat imgROI = img1(Rect(20,20,img2.cols,img2.rows));

	//初级融合
	img2.copyTo(imgROI);
	imshow("ROI",imgROI);
	imshow("dst",img1);
    
    /*以下代码段有问题尚未解决
	Mat mask = Mat::zeros(img1.size(),CV_8UC1);
	circle(mask,Point(mask.cols/2,mask.rows/2),100,Scalar(100),-1,8);

	Mat dst = img2.clone();
	add(img1,img2,dst,mask);
	imshow("dst",dst);
	*/
	
	waitKey(0);
	return 0;
}
```




