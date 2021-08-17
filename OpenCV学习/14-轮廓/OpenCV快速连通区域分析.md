# OpenCV快速连通区域分析

输入要求是一张二值（黑白）图像，输出是一张像素标记图

## cv::connectedComponents()

```cpp
int cv::::connectedComponents(
    cv::InputArray image,      //input 8-bits single-channel(binary)
    cv::OutputArray labels,     //output label map
    int connectivity = 8,   //4 or 8-connected components
    int ltype = CV_32S  //Output label type (CV_32S or CV_16U)
);
```

仅仅是简单生成了标记图

## cv::connectedComponentsWithStats()

```cpp
int cv::connectedComponentsWithStats(
    cv::InputArray image,      //input 8-bits single-channel(binary)
    cv::OutputArray labels,     //output label map
    cv::OutputArray stats,   //Nx5 matrix (CV_32S) of statistics
    cv::OutputArray centroids,  //Nx2 CV_64F matrix of centroids
    int connectivity = 8,   //4 or 8-connected components
    int ltype = CV_32S  //Output label type (CV_32S or CV_16U)
);
```

除了生成标记图外，还返回了一些连通区域的重要信息。
