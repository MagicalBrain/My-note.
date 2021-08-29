# OpenCV 入门（四） 操作像素

标签（空格分隔）： OpenCV

---

## 像素的类型
图像本质上就是一个矩阵，矩阵每个元素表示一个像素,一个像素有三个通道，一般是8位，特殊情况（医学影像）下会用到16位

还可以使用其他类型：
CV_32U  32位无符号
CV_32S  32位有符号
CV_32F  32位浮点
可以储存处理过程中的中间结果

## 加噪音
```c++
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
```

## 减色函数
```c++
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
```
以上是使用了除法作为减色算法，其他的还有：

### 取模
```c++
data[i]=data[i]-data[i] % div +div/2;
```

### 使用输入输出参数
上面的函数只是在原来的图像上进行处理，这称之为**就地处理**
有时定义函数需要允许用户选择是否采用就地处理的方法
我们把函数改写为：
```c++
void colourReduce(const Mat &image,Mat &image0, int div = 64)
{
	int n1 = image.rows;
	int n2 = image.cols*image.channels();

	image0.create(image.rows, image.cols,image.type());
	//注意这一步不能忘，忘记分配空间的话，程序不会报错，但会崩溃

	for (int j = 0; j < n1; j++)
	{
		const uchar*data_in = image.ptr<uchar>(j);
		uchar* data_out = image0.ptr<uchar>(j);
		//注意这里用了两个指针
		for (int i = 0; i < n2; i++)
		{
			//data[i] = data[i] / div*div + div / 2;
			data_out[i] = data_in[i] -data_in[i] % div + div / 2;
			//
		}

	}
}
```

## 获取像素值个数
### 每行的
```c++
int nc1 = img1.cols*img1.channels();
//输出每一行像素值：3000
//像素个数为1000
//但由于是彩色图片，三通道的，故像素值个数为3000
```

同理，可输出每列的
```c++
int nc2 = img1.rows*img1.channels();
```

**ptr方法：**
就是上面的减色函数里用的
```c++
uchar*data = image.ptr<uchar>(j);
//data是一个指向uchar类型的行指针
//把第j行的地址存进data
```

## 对连续图像的高效扫描
### 判断图像是不是连续的
```c++
    if (img1.step == img1.cols*img1.elemSize())
		cout << "是连续图像\n";
	else
		cout << "不是连续图像\n";
```

**还可以用isContinuous()方法**
```c++
    if (img1.isContinuous())
		cout << "是连续图像\n";
	else
		cout << "不是连续图像\n";
```

### 当做是很长的一维数组进行处理
如果是连续图像的话，我们就可以把它当做一个图像长乘以宽的一维数组来进行处理

上面的减色函数可以进一步优化为
```c++
void colourReduce(const Mat &image,Mat &image0, int div = 64)
{
	int n1 = image.rows;
	int n2 = image.cols*image.channels();

	if (image.isContinuous())
	{
		n2 = n1*n2;
		n1 = 1;
	}

	image0.create(image.rows, image.cols,image.type());

    int j = 0;
	const uchar*data_in = image.ptr<uchar>(j);
	uchar* data_out = image0.ptr<uchar>(j);
	for (int i = 0; i < n2; i++)
	//只用一重循环即可
	{
		data_out[i] = data_in[i] -data_in[i] % div + div / 2;
	}
}

```

