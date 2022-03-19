# 使用std::future优化for循环

## 参考链接

https://blog.csdn.net/gaussrieman123/article/details/81779329

## 单个for循环

### 申请内存空间

```cpp
void testfuc(int num){
    int a = 0;
    for (int i = 0; i != num; i++) {
        int *b = new int[10]();
        delete [] b;
	}
}
```

## 两个for循环

```cpp
bool SurfaceFitting::aquireCurvePoints(cv::Mat_<double>& src,
	std::vector<std::vector<cv::Point2i>>& pixelPoints, int num)
{
	std::cout << "Start aquiring curve points" << std::endl;
	int rows = src.rows;
	int cols = src.cols;
	float delta = float(this->rect_.width) * this->obROIRatio_ / num;
	for (int v = 1; v < num; v++)
	{
		std::vector<cv::Point2i> pixelCurvePoints;
		int k = v < (num + 1) / 2 ? v : v - num;//线的序数变delta倍数
		float m = tan(acos(delta * k / this->radius_));//斜率倒数
		//int j_0 = int(core.y - delta * k);
		//int i_0 = int(core.x + abs(k) * delta / this->radius_ * k * delta);//减少i循环次数
		for (int i = 0; i < this->rect_.br().y; i++)
		{
			int j = int(this->centerPoint_.y + (float(i) - this->centerPoint_.x) / m);
			if (j < this->rect_.br().x && j > this->rect_.y)
			{
				if (src(i, j) < this->zmax_ && src(i, j) > this->zmin_)
				{
					cv::Point2i point(i, j);
					pixelCurvePoints.emplace_back(point);
				}
			}
		}

		pixelPoints.emplace_back(pixelCurvePoints);//#TODO push_back
	}

	std::cout << "			pixelPoints[1]:" << pixelPoints[1].size() << std::endl;

	std::vector<cv::Point2i> pixelCurvePoints2;

	for (int i = this->rect_.y; i < this->rect_.br().y; i++)//#TODO i取值可以受ROI限制
	{
		int j = int(this->centerPoint_.y);// 倾斜角为90度
		if (src(i, j) < this->zmax_ && src(i, j) > this->zmin_)
		{
			cv::Point2i point(i, j);
			pixelCurvePoints2.emplace_back(point);
		}
	}
	pixelPoints.emplace_back(pixelCurvePoints2);

	std::cout << "Aquire curve points finished" << std::endl;

	return true;
}
```
