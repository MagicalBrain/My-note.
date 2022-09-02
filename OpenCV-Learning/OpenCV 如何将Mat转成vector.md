# OpenCV 如何将cv::Mat转成std::vector

参考我的`OpenCV-Learning`库

## Mat转vector

```cpp
int Mat2Vector() {
	cv::Mat a = (cv::Mat_<double>(3, 3) << 0.0, -1.0, 0.0, -1.0, 5.0, -1.0, 0.0, -1.0, 0.0);

	cv::Mat b;
	a.convertTo(b, CV_64F);
	std::vector<double> re = b.reshape(1, 1);
	std::cout << "the size of re: " << re.size();
	for (auto i : re)
		std::cout << i << " ";
	std::cout << std::endl;
	return 0;
}
```

## vector转Mat

```cpp
int Vector2Mat() {
	std::vector<double> in = { 0.0, -1.0, 0.0, -1.0, 5.0, -1.0, 0.0, -1.0, 0.0 };
	cv::Mat re(3, 3, CV_8UC1, cv::Scalar(0));	//单通道;
	re = cv::Mat(in, true);
	
	for (int i = 0; i < re.cols; i++)
	{
		for (int j = 0; j < re.rows; j++)
			std::cout << re.at<double>(i,j) << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return 0;
}
```

## 参考链接
https://blog.csdn.net/u010168781/article/details/81663483
