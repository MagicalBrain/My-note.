# OpenCV用多边形来逼近轮廓

实质就是用多边形来拟合轮廓。

## 矩形拟合 

### cv::boundingRect()

使用`cv::boundingRect()`直接计算外包围矩形

```cpp
cv::Rect cv::boundingRect(
    cv::InputArray points
);
```

该函数只有一个参数，就是需要计算包围框的曲线，该函数返回一个`cv::Rect`类型的值。

计算包围框对任何点集都有用，无论这些点是否代表一条完整的曲线。

### cv::minAreaRect()

使用`cv::minAreaRect()`来获得最小矩形框

```cpp
cv::RotatedRect cv::minAreaRect(
    cv::InputArray points
);
```

官方文档给出了一个例子：

```cpp
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;

static void help()
{
    cout << "This program demonstrates finding the minimum enclosing box, triangle or circle of a set\n"
         << "of points using functions: minAreaRect() minEnclosingTriangle() minEnclosingCircle().\n"
         << "Random points are generated and then enclosed.\n\n"
         << "Press ESC, 'q' or 'Q' to exit and any other key to regenerate the set of points.\n\n";
}

int main( int /*argc*/, char** /*argv*/ )
{
    help();
    Mat img(500, 500, CV_8UC3, Scalar::all(0));
    RNG& rng = theRNG();
    for(;;)
    {
        int i, count = rng.uniform(1, 101);
        vector<Point> points;
        // Generate a random set of points
        for( i = 0; i < count; i++ )
        {
            Point pt;
            pt.x = rng.uniform(img.cols/4, img.cols*3/4);
            pt.y = rng.uniform(img.rows/4, img.rows*3/4);
            points.push_back(pt);
        }
        // Find the minimum area enclosing bounding box
        Point2f vtx[4];
        RotatedRect box = minAreaRect(points);
        box.points(vtx);
        // Find the minimum area enclosing triangle
        vector<Point2f> triangle;
        minEnclosingTriangle(points, triangle);
        // Find the minimum area enclosing circle
        Point2f center;
        float radius = 0;
        minEnclosingCircle(points, center, radius);
        img = Scalar::all(0);
        // Draw the points
        for( i = 0; i < count; i++ )
            circle( img, points[i], 3, Scalar(0, 0, 255), FILLED, LINE_AA );
        // Draw the bounding box
        for( i = 0; i < 4; i++ )
            line(img, vtx[i], vtx[(i+1)%4], Scalar(0, 255, 0), 1, LINE_AA);
        // Draw the triangle
        for( i = 0; i < 3; i++ )
            line(img, triangle[i], triangle[(i+1)%3], Scalar(255, 255, 0), 1, LINE_AA);
        // Draw the circle
        circle(img, center, cvRound(radius), Scalar(0, 255, 255), 1, LINE_AA);
        imshow( "Rectangle, triangle & circle", img );
        char key = (char)waitKey();
        if( key == 27 || key == 'q' || key == 'Q' ) // 'ESC'
            break;
    }
    return 0;
}
```

## 多边形拟合

## 圆形拟合
