# OpenCV 入门（六） 简单的图像运算

标签（空格分隔）： OpenCV

---

## 相加

**注意：处理前，要先把两张图的大小调整成一样的**

### add() 函数
```c++
Mat image1;  //定义第一个图像
Mat image2;  //定义第二个图像

Mat result;
//定义相加后存出结果的图像
add(image1,result0,result);
```

### addWeighted() 函数
```c++
Mat image1;  //定义第一个图像
Mat image2;  //定义第二个图像

Mat result;
//定义相加后存出结果的图像
addWeighted(image1,0.99,result0,0.6,1,result);
```

相当于：
$$result[i] = image1[i] * 0.99 + resdult0[i] * 0.6 + 1$$

## 位运算
### ```&```

### ```|```

### ```^```

### ```~```

## min、max、abs
### min

### max

### abs

## 比较
```<``` 等等 不等号
返回的是一个8位的二值图像
## 矩阵运算

### 乘法
```c++
Mat result(image1.rows,image1.cols,CV_64FC1,100);

result =  image1.mul(result0);
//两个图大小要一致
```

### 求逆

### 变位

### 行列式

### 求范数

### 叉乘

### 点乘
#### dot函数的定义
```c++
double Mat::dot(InputArray _mat) const
{
    CV_INSTRUMENT_REGION()

    Mat mat = _mat.getMat();
    int cn = channels();
    DotProdFunc func = getDotProdFunc(depth());
    CV_Assert( mat.type() == type() && mat.size == size && func != 0 );

    if( isContinuous() && mat.isContinuous() )
    {
        size_t len = total()*cn;
        if( len == (size_t)(int)len )
            return func(data, mat.data, (int)len);
    }

    const Mat* arrays[] = {this, &mat, 0};
    uchar* ptrs[2];
    NAryMatIterator it(arrays, ptrs);
    int len = (int)(it.size*cn);
    double r = 0;

    for( size_t i = 0; i < it.nplanes; i++, ++it )
        r += func( ptrs[0], ptrs[1], len );

    return r;
}

}
```

#### 调用dot函数的注意事项
1、两图片大小要一致

#### 实例
```c++
#include <opencv2\opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat image1;  //定义一个新图像
	image1 = imread("me.jpg", CV_32FC1);  //读取输入的图像
	cout << "The image is " << image1.cols << " x " << image1.rows << endl;
	//输出该图像的大小
	namedWindow("我");
	imshow("我", image1);
	/*窗口是以名字来表识的，所以定义用 namedWindow 定义一个名字，
	然后可用 imshow 通过名字来打开窗口*/
	
	cout << "This image has " << image1.channels() << " channels"<<endl;

	Mat image2;  //定义一个新图像
	image2 = imread("artist.jpg", CV_32FC1);  //读取输入的图像
	cout << image2.size() << endl;
	//输出该图像的大小
	namedWindow("风格");
	imshow("风格", image2);
	/*窗口是以名字来表识的，所以定义用 namedWindow 定义一个名字，
	然后可用 imshow 通过名字来打开窗口*/

	cout << "This image has " << image2.channels() << " channels" << endl;
	cout << image1.type() << endl << image2.type() << endl;

	Mat result0;
	resize(image2,result0, Size(image1.cols,image1.rows));
	cout << image1.size() << endl;
	cout << result0.size() << endl;
	//输出该图像的大小
	
	cout << image1.type() << endl << result0.type() << endl;

	double result =  image1.dot(result0);

	cout << result << endl;
	
	waitKey(0);
	return 0;
}
```