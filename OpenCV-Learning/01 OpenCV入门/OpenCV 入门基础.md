# OpenCV 入门基础

标签（空格分隔）： OpenCV

---

## 读入图像
```c++
#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;
//上面记得要导入头文件
//cv名称空间不导入也行，导入会方便一点，就像std空间一样

int main(void)
{
    //首先创建一个新的空图像
    Mat image;  //相当于整型变量要用之前先进行定义
    
    image = imread("我的图像.jpg");
    //读入输入图像到image，相当于给整型变量赋值
    
    /*也可以直接通过初始化来进行赋值：
    Mat image = imread("我的图像.jpg");
    */
    return 0;
}
```

### 判断导入图像错误的方法
使用empty方法，如果导入失败，该方法返回值为true

```c++
if (image.empty())
{
    //我想要输出的错误信息
    //发生错误后，我想要进行的操作
}
```

## 显示图像
```c++
//首先定义窗口，不定义也行
namedWindow（"我的窗口"）;

//显示图像
imshow("我的窗口",image);
```

## 导出图像
```c++
imwrite("imgh.jpg",img2);
```

## 图像基本操作
### 1、水平翻转
```C++
flip(image,result,1);
//参数1：表示操作对象是image图像
//参数2：表示把操作后的图像保存到result图像中
//参数3：
//正数-->水平
//0-->垂直
//负数-->水平和垂直
```

例子：
```c++
Mat img1 = imread("image.jpg",CV_LOAD_IMAGE_COLOR);
Mat imgROI; 
imshow("img1", img1);

flip(img1,imgROI,1);
imshow("ROI",imgROI);
```

## 查看图像大小
### img.size()
返回大小（宽X高）

### img.cols
返回列数（宽）

### img.rows
返回行数（高）

#### **原图**
![image_1ch9nm1fb1tf38rhp1kk0o5f1m.png-1491.2kB][1]


















#### **处理后（参数3为1）**
![image_1ch9nk8i11a75kut1quqk9caeb9.png-1490kB][2]
可以发现只是水平翻转


































#### **处理后（参数3为0）**
![image_1ch9nr9hhshp1v9h15n713ao1taj13.png-1495.8kB][3]
可以发现只是垂直翻转



























































#### **处理后（参数为负数）**
![image_1ch9o06161lcjoq714thfecvi920.png-1489.4kB][4]
可以发现水平方向和垂直方向都翻转了























































































  [1]: http://static.zybuluo.com/Arbalest-Laevatain/f1mipvmjqe55jc7rdup1u4lt/image_1ch9nm1fb1tf38rhp1kk0o5f1m.png
  [2]: http://static.zybuluo.com/Arbalest-Laevatain/980uutdnfkuibloyrnzqa74e/image_1ch9nk8i11a75kut1quqk9caeb9.png
  [3]: http://static.zybuluo.com/Arbalest-Laevatain/jgd20mgb9nqcwzg9m6moiq8g/image_1ch9nr9hhshp1v9h15n713ao1taj13.png
  [4]: http://static.zybuluo.com/Arbalest-Laevatain/hmfqhr97og71onsx7c4gvjzm/image_1ch9o06161lcjoq714thfecvi920.png