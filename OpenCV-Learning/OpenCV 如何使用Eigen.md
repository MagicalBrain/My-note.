# OpenCV 如何使用Eigen

```cpp
#include <iostream>
#include <string>
#include <vector>
#include "opencv.hpp"
#include "Dense"

int main()
{
	//把要读取的图片存在向量中~~~
	const std::vector<std::string> image_name{ "selfie.jpg" };
	//读取图片
        cv::Mat mat_src = cv::imread(image_name[0]);
	if (!mat_src.data) {
		std::fprintf(stderr, "read image fail:%s\n", image_name[0].c_str());
		return -1;
	}
        //把三个通道分离~~~
	std::vector<cv::Mat>mat_split;
	cv::split(mat_src, mat_split);//将图像的通道分离存储在向量中

	//用Eigen库处理OpenCV矩阵
	Eigen::Map<Eigen::Matrix<unsigned char, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor>>
		//channel1
		map_B(mat_split[0].data, mat_split[0].rows, mat_split[0].cols),
		//channel2
		map_G(mat_split[1].data, mat_split[1].rows, mat_split[1].cols),
		//channel3
		map_R(mat_split[2].data, mat_split[2].rows, mat_split[2].cols);
	//Eigen的transpose方法将三个通道转置
	Eigen::Matrix<unsigned char, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor>
		trans_B = map_B.transpose(),
		trans_G = map_G.transpose(),
		trans_R = map_R.transpose();
	//转置完了再根据得到的Eigen矩阵创建CV矩阵
	cv::Mat
		mat_dst_B(trans_B.rows(), trans_B.cols(), CV_8UC1, trans_B.data()),
		mat_dst_G(trans_G.rows(), trans_G.cols(), CV_8UC1, trans_G.data()),
		mat_dst_R(trans_R.rows(), trans_R.cols(), CV_8UC1, trans_R.data());
	//这个向量用来存储三个通道的矩阵
	std::vector<cv::Mat> mat_merge;
	//推进向量里面~~~
	mat_merge.push_back(std::move(mat_dst_B));
	mat_merge.push_back(std::move(mat_dst_G));
	mat_merge.push_back(std::move(mat_dst_R));
	//用merge方法把三个元素作为三个通道画个图~~~
	cv::Mat mat_dst;
	cv::merge(mat_merge, mat_dst);
	cv::imwrite("Eigen.jpg", mat_dst);
	return 0;
}
```
