#include <iostream>
#include <opencv2/opencv.hpp>
 
using namespace std;
using namespace cv;

int main()
{
    Mat srcImage = imread("IMG_2525.jpeg");
    imshow("Display Image window",srcImage);
    waitKey(0);
    return 0;
}
