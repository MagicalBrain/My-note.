# OpenCV使用Canny算法进行边缘检测

## 基本原理

Canny算法是在Laplace滤波器理论的基础上进行改进的。

在Canny算法中，先在$x$ 和$y$方向上求一阶导数，然后将它们组成四个方向的导数。
其中方向导数是局部最大值的点将成为边缘的候选点。

该算法采用了两个阈值，一个较大值和一个较小值。
最大阈值与最小阈值的比值建议在$2:1$ 到$3:1$之间。如果该比值越大则检测出的边缘越多，可能会有很多不需要的边缘被检测出来。

Canny的创新点：
将单个的边缘候选像素加入到轮廓中去。

## cv::Canny的声明

```cpp
void cv::Canny(
    cv::InputArray image,   //输入单通道图像
    cv::OutputArray edges,  //输出灰度图像
    double thresholds1,     //最小阈值
    double thresholds2,     //最大阈值
    int apertureSize = 3,   //Sobel aperture
                            //内部调用的Sobel导数算子所用的aperture的大小
    bool L2gradient = false //用于选择合适L2范数来计算方向梯度
)
```

**Sobel aperture**：
用于设置内部调用的Sobel导数算子所用的aperture的大小

**L2gradient**：
用于选择合适L2范数来计算方向梯度
如果是**true**，就使用公式：
$$|grad(x,y)|_{L_2} = \sqrt{(\frac{\mathrm{d} I}{\mathrm{d} x})^2 + (\frac{\mathrm{d} I}{\mathrm{d} y})^2}$$

如果是**false**，就使用公式：
$$|grad(x,y)|_{L_2} = |\frac{\mathrm{d} I}{\mathrm{d} x}| + |\frac{\mathrm{d} I}{\mathrm{d} y}|$$

## 简单的用法

```cpp
int cannyThreshold1 = 30;
int cannyThreshold2 = 150;
cv::Canny(image, image, cannyThreshold1, cannyThreshold2);
```

其中`image`是一个单通道的图像，如果Canny算法处理的图像不是单通道的将会触发异常。

需要注意的是，`cv::Canny`函数并不返回轮廓类型的对象，如果需要轮廓类型的对象则需要使用`cv::findContours`函数从`cv::Canny`的输出结果中获取轮廓，再用`cv::drawContours`函数将轮廓画出来。
