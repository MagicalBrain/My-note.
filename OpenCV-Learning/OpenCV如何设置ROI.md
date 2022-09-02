# OpenCV如何设置ROI

设置ROI有两种情况，第一种是我们清楚地知道ROI的坐标，第二种是不知道ROI具体坐标。

第一种情况比较简单，这里不谈，主要谈的是第二种情况。

对于第二种情况，我们可以：
1. 用鼠标选择一个矩形区域（鼠标点两个点）


## 鼠标框选

可以使用官方的API

```cpp
Rect cv::selectROI	(	const String & 	windowName,
InputArray 	img,
bool 	showCrosshair = true,
bool 	fromCenter = false 
)		
```

使用例子：

```cpp
int test4selectROI(string bmp_path)
{
    Mat input = imread(bmp_path);
    Rect re = Rect(0, 0, 0, 0);
    re = selectROI(input, false, false);
    cout << re << endl;

    //Mat tmp0(re.width, re.height, CV_8U);
    //Mat tmp0;
    //Mat &tmp = tmp0;
    Mat output = input(Rect(re.x, re.y, re.width, re.height));
    imshow("ROI", output);
    waitKey();
    return 0;
}
```

也可以自己写，但是容易出问题，比如画出来的框容易出问题却不影响最终的区域划分

## openCV获取ROI的原理

图像感兴趣区域（ROI）提取主要使用掩模来进行。掩模是二值图像，感兴趣区域的掩模值设置为255，非感兴趣区域的掩模值为0
获取掩模的方法主要有两种

1. 使用opencv中Mat函数方法,调用Mat(Rect).setTo方法设置掩模
2. 在全为0的原始掩模中画一个封闭区域，使用漫水填充算法填充封闭区域，将封闭区域的值都设置为255，实现掩模的提取

还可以使用轮廓来进行：
将边界转换为轮廓，使用`cv::drawContours(mask, contours, -1, cv::Scalar::all(255),CV_FILLED);`
函数提取感兴趣区域(ROI)。

## 其它形状的ROI

https://cxybb.com/article/youandme520/107844296

任意几何形状感兴趣区域的提取主要使用方法二和方法三。提取的关键是画出几何形状的边界或获得轮廓。

### 椭圆

## 设置多个ROI

可直接使用官方的API`selectROIS`

```cpp
void cv::selectROIs	(	
    const String            &windowName,
    InputArray 	            img,
    std::vector< Rect >     &boundingBoxes,
    bool 	                showCrosshair = true,
    bool 	                fromCenter = false 
)	
```

`#include <opencv2/highgui.hpp>`

Selects ROIs on the given image. Function creates a window and allows user to select a ROIs using mouse. Controls: use space or enter to finish current selection and start a new one, use esc to terminate multiple ROI selection process.

按下空格键或者回车键完成一次ROI的选取，由于这是选取多个ROI的，所以，选取次数够了以后，按下esc键退出。

Parameters
windowName	name of the window where selection process will be shown.
img	image to select a ROI.

boundingBoxes	selected ROIs.

showCrosshair	if true crosshair of selection rectangle will be shown.

fromCenter	if true center of selection will match initial mouse position. In opposite case a corner of selection rectangle will correspont to the initial mouse position.

Note
The function sets it's own mouse callback for specified window using cv::setMouseCallback(windowName, ...). After finish of work an empty callback will be set for the used window.
