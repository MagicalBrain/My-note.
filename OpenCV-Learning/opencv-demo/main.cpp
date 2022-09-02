#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	Mat src_image = imread("../test.png");

	imshow("", src_image);
	waitKey(0);

	return 0;
}
