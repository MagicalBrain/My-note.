# OpenCV 进阶（一） 图像点击事件

标签（空格分隔）： OpenCV

---

## 回调函数
首先需要定义一个回调函数
### 鼠标事件处理函数
先看声明
```c++
void onMouse(int event,int x,int y,int flags,void * p);
//参数1：整数，触发鼠标事件的类型
//参数2和3：鼠标的坐标
//参数4：发生事件时，按下了鼠标那个键
//参数5：任意对象的指针，作为附加参数给函数
```

**函数定义：**
```c++
void onMouse(int event,int x,int y,int flags,void*p)
{
	Mat *im = reinterpret_cast<Mat*>(p);

	switch (event)
	{
	case CV_EVENT_LBUTTONDOWN:
		cout << "at (" << x << "," << y << ") value is:" << 
			static_cast<int>(im->at<uchar>(Point(x, y))) << endl;
		break;
	default:
		break;
	}
}
```
**注意：**
要在主程序中用setMouseCallback方法来间接调用（注册）onMouse函数
```c++
Mat imgROI= imread("img.jpg",CV_LOAD_IMAGE_COLOR);
imshow("ROI",imgROI);

//调用onMouse函数一定要放在imshow语句后面
setMouseCallback("ROI",onMouse,reinterpret_cast<void*>(&imgROI));
//参数1：显示图片的窗口名字
//参数2：鼠标事件函数名
//参数3有待进一步探究
```



