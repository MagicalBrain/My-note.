# OpenCV使用Hough变换进行线检测

```cpp
void cv::HoughLines(	
    InputArray 	image,
    OutputArray 	lines,
    double 	rho,
    double 	theta,
    int 	threshold,
    double 	srn = 0,
    double 	stn = 0,
    double 	min_theta = 0,
    double 	max_theta = CV_PI 
)	
```

使用标准霍夫变换在二进制图像中寻找线段
Finds lines in a binary image using the standard Hough transform.

The function implements the standard or standard multi-scale Hough transform algorithm for line detection. See http://homepages.inf.ed.ac.uk/rbf/HIPR2/hough.htm for a good explanation of Hough transform.

此函数利用标准或多尺度的标准霍夫变换算法来进行线检测。

如果有需要，请查阅 这是一个关于霍夫变换的有趣的例子


**image**
8-bit, single-channel binary source image. The image may be modified by the function.
8位，单通道二进制图像

**lines**
Output vector of lines. Each line is represented by a 2 or 3 element vector (ρ,θ) or (ρ,θ,votes) . ρ is the distance from the coordinate origin (0,0) (top-left corner of the image). θ is the line rotation angle in radians ( 0∼vertical line,π/2∼horizontal line ). votes is the value of accumulator.
输出检测出来的线的vector数组
每条线可能会被一个2维或者3维的vector表示，即$(\rho, \theta)$, $(\rho, \theta, votes)$

$\rho$
是到原点（图像的左上角）的距离

$\theta$
弧度制的旋转角

**votes**
是累加器的值

**rho**	
Distance resolution of the accumulator in pixels.

像素累加器的距离分辨率？

**theta**	
Angle resolution of the accumulator in radians.
弧度累加器的角度分辨率？

**threshold**	
Accumulator threshold parameter. Only those lines are returned that get enough votes ( >threshold ).
累加器阈值，只有votes大于这个阈值的线才会被返回

**srn**	
For the multi-scale Hough transform, it is a divisor for the distance resolution rho . The coarse accumulator distance resolution is rho and the accurate accumulator resolution is rho/srn . If both srn=0 and stn=0 , the classical Hough transform is used. Otherwise, both these parameters should be positive.

用来设置是否使用标准霍夫变换的。
如果rho和srn都是0，那么使用的是标准霍夫变换；
如果想要使用多尺度的霍夫变换，那么rho和srn应该都是正数

**stn**	
For the multi-scale Hough transform, it is a divisor for the distance resolution theta.
对于多尺度霍夫变换，它是距离分辨率的除数（分子）。

**min_theta**
For standard and multi-scale Hough transform, minimum angle to check for lines. Must fall between 0 and max_theta.
对于标准和多尺度霍夫变换，线检测的最小角度。
其范围必须落在$[0, \theta_{max})$

**max_theta**
For standard and multi-scale Hough transform, maximum angle to check for lines. Must fall between min_theta and CV_PI.
对于标准和多尺度霍夫变换，线检测的最小角度。
其范围必须落在$[\theta_{max}, CV\_PI]$
