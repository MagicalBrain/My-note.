# OpenCV 入门（四） 快速扫描像素的操作

标签（空格分隔）： OpenCV

---

## 扫描基础
### 例子：减色函数的实现
```c++
void colourReduce(Mat image, int div=64)
{
	int n1 = image.rows;
	int n2 = image.cols*image.channels();

	if (image.isContinuous())
	{
		n2 *= n1;
		n1 = 1;
	}
    
    //以下为扫描图像的代码
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

## 方法一
```c++
Mat image;
//定义一个图像

int n1 = image.rows;
int n2 = image.cols*image.channels();

if (image.isContinuous())
{
    n2 *= n1;
	n1 = 1;
}

for (int j = 0; j < n1; j++)
{
    uchar*data = image.ptr<uchar>(j);
	for (int i = 0; i < n2; i++)
	{
		data[i]=data[i]/div*div+div/2;
	}
}	
```

## 方法二
```c++
if (image.isContinuous())
{
    image.reshape(1,1);
    //新的通道数、新的行数
}

int n1 = image.rows;
int n2 = image.cols*image.channels();

uchar*data = image.ptr<uchar>(j);
for (int i = 0; i < n2; i++)
	{
		data[i]=data[i]/div*div+div/2;
	}
```

**该方法适合用于在同一个循环中同时扫描多个比较小的图像**

## 方法三
**低层次指针法**

```c++

```

**效率最低，不推荐使用**

## 方法四 使用迭代器

来自于C++的STL容器中的迭代器，为了方便扫描图像，OpenCV把它重写了
```c++
//在初始位置启动迭代器
	MatIterator_<Vec3b> itbegin = image.begin<Vec3b>();
	
	//迭代器获得结束位置
	MatIterator_<Vec3b> itend = image.end<Vec3b>();

	//循环遍历所有像素
	for (;itbegin!=itend;++itbegin)
	{
		(*itbegin)[0] = (*itbegin)[0] / div*div + div / 2;
		(*itbegin)[1] = (*itbegin)[1] / div*div + div / 2;
		(*itbegin)[2] = (*itbegin)[2] / div*div + div / 2;
	}
```

### 以下代码同理
```c++
//在初始位置启动迭代器
	Mat_<Vec3b>::iterator itbegin = image.begin<Vec3b>();
	
	//迭代器获得结束位置
	Mat_<Vec3b>::iterator itend = image.end<Vec3b>();

	//循环遍历所有像素
	for (;itbegin!=itend;++itbegin)
	{
		(*itbegin)[0] = (*itbegin)[0] / div*div + div / 2;
		(*itbegin)[1] = (*itbegin)[1] / div*div + div / 2;
		(*itbegin)[2] = (*itbegin)[2] / div*div + div / 2;
	}
```

### 以上两种甚至可以混合使用
```c++
//在初始位置启动迭代器
	Mat_<Vec3b>::iterator itbegin = image.begin<Vec3b>();
	
	//迭代器获得结束位置
	MatIterator_<Vec3b> itend = image.end<Vec3b>();

	//循环遍历所有像素
	for (;itbegin!=itend;++itbegin)
	{
		(*itbegin)[0] = (*itbegin)[0] / div*div + div / 2;
		(*itbegin)[1] = (*itbegin)[1] / div*div + div / 2;
		(*itbegin)[2] = (*itbegin)[2] / div*div + div / 2;
	}
```

### 控制开始和结束的行数
```c++
image.begin<Vec3b>() - i*image.cols;
//即从第i+1行开始

image.end<Vec3b>() - i*image.cols;
//即从倒数i+1行结束
```

## 方法五 访问像素的函数 at
```c++
    int n1 = image.rows;
	int n2 = image.cols*image.channels();

	for (int j = 0; j < n1; j++)
	{
		for (int i = 0; i < n2; i++)
		{
			image.at<Vec3b>(j, i)[0] = image.at<Vec3b>(j, i)[0]/div*div + div / 2;
			image.at<Vec3b>(j, i)[1] = image.at<Vec3b>(j, i)[1] / div*div + div / 2;
			image.at<Vec3b>(j, i)[2] = image.at<Vec3b>(j, i)[2] / div*div + div / 2;
		}

	}
```

**代码存在问题，跑不起来**

**效率很低，应该只在随机访问像素的时候使用**

## 如何知道扫描过程有多快？
这是我们首先需要计时函数

### 计时函数 
#### getTickCount()
返回电脑开机到现在的时钟周期数

#### getTickFrequency()
返回以秒为单位的时间
```c++
const int64 start = getTickCount();
//调用函数
double duration = (getTickCount() - start) / getTickFrequency()；
```
