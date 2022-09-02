# OpenCV特征检测和特征匹配方法汇总

[参考链接](https://www.cnblogs.com/skyfsm/p/7401523.html)

## 1. SIFT

SURF算法是SIFT算法的加速版， 而SIFT（尺度不变特征转换， ScaleInvariant Feature Transform） 是另一种著名的尺度不变特征检测法。我们知道，SURF相对于SIFT而言，特征点检测的速度有着极大的提升，所以在一些实时视频流物体匹配上有着很强的应用。而SIFT因为其巨大的特征计算量而使得特征点提取的过程异常花费时间，所以在一些注重速度的场合难有应用场景。但是SIFT相对于SURF的优点就是，由于SIFT基于浮点内核计算特征点，因此通常认为， SIFT算法检测的特征在空间和尺度上定位更加精确，所以在要求匹配极度精准且不考虑匹配速度的场合可以考虑使用SIFT算法。

SIFT特征检测的代码我们仅需要对上面的SURF代码作出一丁点修改即可。



## 2. SURF

特征检测的视觉不变性是一个非常重要的概念。 但是要解决尺度不变性问题，难度相当大。 为解决这一问题，计算机视觉界引入了尺度不变特征的概念。 它的理念是， 不仅在任何尺度下拍摄的物体都能检测到一致的关键点，而且每个被检测的特征点都对应一个尺度因子。 理想情况下，对于两幅图像中不同尺度的的同一个物体点， 计算得到的两个尺度因子之间的比率应该等于图像尺度的比率。近几年， 人们提出了多种尺度不变特征，本节介绍其中的一种：SURF特征。 SURF全称为“加速稳健特征”（Speeded Up Robust Feature），我们将会看到，它们不仅是尺度不变特征，而且是具有较高计算效率的特征。

我们首先进行常规的特征提取和特征点匹配，看看效果如何。

```cpp
#pragma once
#include <iostream>

#include "opencv2/imgcodecs.hpp"
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include <opencv2/xfeatures2d/nonfree.hpp>

using namespace cv;
using namespace std;


int demo4SURF()
{
    Mat image01 = imread("2.png", 1);    //右图
    Mat image02 = imread("1.png", 1);    //左图
    namedWindow("p2", 0);
    namedWindow("p1", 0);
    imshow("p2", image01);
    imshow("p1", image02);

    //灰度图转换  
    Mat image1, image2;
    cvtColor(image01, image1, COLOR_RGB2GRAY);
    cvtColor(image02, image2, COLOR_RGB2GRAY);


    //提取特征点    
    //xfeatures2d::SurfFeatureDetector surfDetector(800);  // 海塞矩阵阈值，在这里调整精度，值越大点越少，越精准 
    Ptr<xfeatures2d::SURF> surfDetector = xfeatures2d::SURF::create(800);
    vector<KeyPoint> keyPoint1, keyPoint2;
    surfDetector->detect(image1, keyPoint1);
    surfDetector->detect(image2, keyPoint2);

    //特征点描述，为下边的特征点匹配做准备    
    //SurfDescriptorExtractor SurfDescriptor;
    Ptr<xfeatures2d::SurfDescriptorExtractor> SurfDescriptor = xfeatures2d::SurfDescriptorExtractor::create();
    Mat imageDesc1, imageDesc2;
    SurfDescriptor->compute(image1, keyPoint1, imageDesc1);
    SurfDescriptor->compute(image2, keyPoint2, imageDesc2);

    //获得匹配特征点，并提取最优配对     
    FlannBasedMatcher matcher;
    vector<DMatch> matchePoints;

    matcher.match(imageDesc1, imageDesc2, matchePoints, Mat());
    cout << "total match points: " << matchePoints.size() << endl;


    Mat img_match;
    drawMatches(image01, keyPoint1, image02, keyPoint2, matchePoints, img_match);
    namedWindow("match", 0);
    imshow("match", img_match);
    imwrite("match.jpg", img_match);

    waitKey();
    return 0;
}
```

由上面的特征点匹配的效果来看，匹配的效果还是相当糟糕的，如果我们拿着这样子的匹配结果去实现图像拼接或者物体追踪，效果肯定是极差的。所以我们需要进一步筛选匹配点，来获取优秀的匹配点，这就是所谓的“去粗取精”。这里我们采用了Lowe’s算法来进一步获取优秀匹配点。

为了排除因为图像遮挡和背景混乱而产生的无匹配关系的关键点，SIFT的作者Lowe提出了比较最近邻距离与次近邻距离的SIFT匹配方式：取一幅图像中的一个SIFT关键点，并找出其与另一幅图像中欧式距离最近的前两个关键点，在这两个关键点中，如果最近的距离除以次近的距离得到的比率ratio少于某个阈值T，则接受这一对匹配点。因为对于错误匹配，由于特征空间的高维性，相似的距离可能有大量其他的错误匹配，从而它的ratio值比较高。显然降低这个比例阈值T，SIFT匹配点数目会减少，但更加稳定，反之亦然。

Lowe推荐ratio的阈值为0.8，但作者对大量任意存在尺度、旋转和亮度变化的两幅图片进行匹配，结果表明ratio取值在0. 4~0. 6 之间最佳，小于0. 4的很少有匹配点，大于0. 6的则存在大量错误匹配点，所以建议ratio的取值原则如下:

ratio=0. 4：对于准确度要求高的匹配；

ratio=0. 6：对于匹配点数目要求比较多的匹配；

ratio=0. 5：一般情况下。

```cpp
#include "highgui/highgui.hpp"    
#include "opencv2/nonfree/nonfree.hpp"    
#include "opencv2/legacy/legacy.hpp"   
#include <iostream>  

using namespace cv;
using namespace std;


int demo4SURF_Better()
{

    Mat image01 = imread("02.png", 1);    //右图
    Mat image02 = imread("01.png", 1);    //左图
    namedWindow("p2", 0);
    namedWindow("p1", 0);
    imshow("p2", image01);
    imshow("p1", image02);

    //灰度图转换  
    Mat image1, image2;
    cvtColor(image01, image1, COLOR_RGB2GRAY);
    cvtColor(image02, image2, COLOR_RGB2GRAY);


    //提取特征点    
    //xfeatures2d::SurfFeatureDetector surfDetector(800);  // 海塞矩阵阈值，在这里调整精度，值越大点越少，越精准 
    Ptr<xfeatures2d::SURF> surfDetector = xfeatures2d::SURF::create(2000);
    vector<KeyPoint> keyPoint1, keyPoint2;
    surfDetector->detect(image1, keyPoint1);
    surfDetector->detect(image2, keyPoint2);

    //特征点描述，为下边的特征点匹配做准备    
    //SurfDescriptorExtractor SurfDescriptor;
    Ptr<xfeatures2d::SurfDescriptorExtractor> SurfDescriptor = xfeatures2d::SurfDescriptorExtractor::create();
    Mat imageDesc1, imageDesc2;
    SurfDescriptor->compute(image1, keyPoint1, imageDesc1);
    SurfDescriptor->compute(image2, keyPoint2, imageDesc2);

    //获得匹配特征点，并提取最优配对     
    FlannBasedMatcher matcher;
    vector<vector<DMatch> > matchePoints;
    vector<DMatch> GoodMatchePoints;

    vector<Mat> train_desc(1, imageDesc1);
    matcher.add(train_desc);
    matcher.train();

    matcher.knnMatch(imageDesc2, matchePoints, 2);
    cout << "total match points: " << matchePoints.size() << endl;

    // Lowe's algorithm,获取优秀匹配点
    for (int i = 0; i < matchePoints.size(); i++)
    {
        if (matchePoints[i][0].distance < 0.6 * matchePoints[i][1].distance)
        {
            GoodMatchePoints.push_back(matchePoints[i][0]);
        }
    }

    Mat first_match;
    drawMatches(image02, keyPoint2, image01, keyPoint1, GoodMatchePoints, first_match);
    imshow("first_match ", first_match);
    waitKey();

    return 0;
}
```

## 3. ORB

ORB是ORiented Brief的简称，是brief算法的改进版。ORB算法比SIFT算法快100倍，比SURF算法快10倍。在计算机视觉领域有种说法，ORB算法的综合性能在各种测评里较其他特征提取算法是最好的。

ORB算法是brief算法的改进，那么我们先说一下brief算法有什么去缺点。

BRIEF的优点在于其速度，其缺点是：

1. 不具备旋转不变性
2. 对噪声敏感
3. 不具备尺度不变性

而ORB算法就是试图解决上述缺点中1和2提出的一种新概念。值得注意的是，==ORB没有解决尺度不变性==。

```cpp
#include "highgui/highgui.hpp"    
#include "opencv2/nonfree/nonfree.hpp"    
#include "opencv2/legacy/legacy.hpp"   
#include <iostream>  

using namespace cv;
using namespace std;


int main()
{

    Mat image01 = imread("g2.jpg", 1);
    Mat image02 = imread("g4.jpg", 1);
    imshow("p2", image01);
    imshow("p1", image02);

    //灰度图转换  
    Mat image1, image2;
    cvtColor(image01, image1, CV_RGB2GRAY);
    cvtColor(image02, image2, CV_RGB2GRAY);


    //提取特征点    
    OrbFeatureDetector OrbDetector(1000);  // 在这里调整精度，值越小点越少，越精准 
    vector<KeyPoint> keyPoint1, keyPoint2;
    OrbDetector.detect(image1, keyPoint1);
    OrbDetector.detect(image2, keyPoint2);

    //特征点描述，为下边的特征点匹配做准备    
    OrbDescriptorExtractor OrbDescriptor;
    Mat imageDesc1, imageDesc2;
    OrbDescriptor.compute(image1, keyPoint1, imageDesc1);
    OrbDescriptor.compute(image2, keyPoint2, imageDesc2);

    flann::Index flannIndex(imageDesc1, flann::LshIndexParams(12, 20, 2), cvflann::FLANN_DIST_HAMMING);

    vector<DMatch> GoodMatchePoints;

    Mat macthIndex(imageDesc2.rows, 2, CV_32SC1), matchDistance(imageDesc2.rows, 2, CV_32FC1);
    flannIndex.knnSearch(imageDesc2, macthIndex, matchDistance, 2, flann::SearchParams());

    // Lowe's algorithm,获取优秀匹配点
    for (int i = 0; i < matchDistance.rows; i++)
    {
        if (matchDistance.at<float>(i,0) < 0.6 * matchDistance.at<float>(i, 1))
        {
            DMatch dmatches(i, macthIndex.at<int>(i, 0), matchDistance.at<float>(i, 0));
            GoodMatchePoints.push_back(dmatches);
        }
    }

    Mat first_match;
    drawMatches(image02, keyPoint2, image01, keyPoint1, GoodMatchePoints, first_match);
    imshow("first_match ", first_match);
    imwrite("first_match.jpg", first_match);
    waitKey();
    return 0;
}
```

上面不是opencv4.4.0版本的，下面才是

```cpp
	Mat tem = imread("D:\\opencv_c++\\opencv_tutorial\\data\\images\\a.png");
	flip(tem, tem, 0);
	resize(tem, tem, Size(), 1.5, 1.5);
	Mat test = imread("D:\\opencv_c++\\opencv_tutorial\\data\\images\\abc.png");
	//创建OBR对象指针，使用auto智能指针来自动判断返回值类型
	auto orb = ORB::create(100, 1.6, 8, 31, 0, 2, ORB::HARRIS_SCORE, 31, 20);	
	//通过ORB算法检测两幅图像中的特征点，并计算各自的二值描述子
	vector<KeyPoint> keyPoints_tem, keyPoints_test;
	Mat descriptors_tem, descriptors_test;
	orb->detectAndCompute(tem, Mat(), keyPoints_tem, descriptors_tem, false);
	orb->detectAndCompute(test, Mat(), keyPoints_test, descriptors_test, false);
	//特征匹配是通过使用合适的相似度度量比较特征描述子来执行的。
	//定义特征描述子匹配器
	Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create(DescriptorMatcher::MatcherType::BRUTEFORCE);
	//参数MatcherType：匹配器类型，这里使用MatcherType::BRUTEFORCE（暴力匹配算法）

	vector<DMatch> matches;
	//通过描述子匹配器，对两幅图像的描述子进行匹配，也就是将两幅图像中的对应特征点进行匹配；输出的是一个DMatch结构体向量，其每一个DMatch结构体包含一组对应特征点的信息。
	matcher->match(descriptors_tem, descriptors_test, matches, Mat());

	float maxdist = 0;
	for (int i = 0; i < matches.size(); i++)
	{
		//寻找匹配特征点对中匹配质量最差的点对，也就是匹配距离最远的点对，获取该最大距离值
		maxdist = max(maxdist, matches[i].distance);	
	}

	vector<DMatch> good_matches;
	for (int j = 0; j < matches.size(); j++)
	{
		//如果匹配特征点对中，某个点对的匹配距离小于某个阈值（可以是最大距离值乘以一个小于1的系数），则可以认为是高度匹配的特征点对
		if (matches[j].distance < 0.18 * maxdist)		
		{
			good_matches.push_back(matches[j]);
		}
	}

	//将两幅图像之间的高度匹配的对应特征点使用连线绘制出来，输出一幅将两幅图像拼接起来再进行连线的图像
	//Scalar::all(-1)是选择随机颜色
	Mat result;
	drawMatches(tem, keyPoints_tem, test, keyPoints_test, good_matches, result, Scalar::all(-1), Scalar::all(-1));
	imshow("result", result);
```
