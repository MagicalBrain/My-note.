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
