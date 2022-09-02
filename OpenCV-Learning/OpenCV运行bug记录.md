# OpenCV运行bug记录

## cv::imshow 不显示

```cpp
#include <opencv2/opencv.hpp>

using namespace std;
//using namespace cv;

int main(int argc, char * argv[]) try
{
    cv::namedWindow("Realsense Stream");

    cv::imread(ir, "./test.png");
    cv::imshow("Realsense Stream", ir);

    return EXIT_SUCCESS;
}
```

原因以及解决办法：
加上`cv::waitKey()`：

```cpp
#include <opencv2/opencv.hpp>

using namespace std;
//using namespace cv;

int main(int argc, char * argv[]) try
{
    cv::namedWindow("Realsense Stream");

    cv::imread(ir, "./test.png");
    cv::imshow("Realsense Stream", ir);
    cv::waitKey(0);
    
    return EXIT_SUCCESS;
}
```
