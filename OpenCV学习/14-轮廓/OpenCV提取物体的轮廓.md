# OpenCV提取物体的轮廓

## 使用findContours函数寻找轮廓

### findContours函数声明

```cpp
void cv::findContours(
    cv::InputArray image,
    cv::OutputArray contours,
    cv::OutputArray hierarchy,
    int mode,
    int method,
    cv::Point offset = cv::Point()
)

void cv::findContours(
    cv::InputArray image,
    cv::OutputArray contours,
    int mode,
    int method,
    cv::Point offset = cv::Point()
)
```

**image**：
为输入图像，必须为8位单通道图像，且应该已经被转换为二值图像。
`cv::findContours`处理后会修改输入图像。

**contours**：
是一个vector容器，其元素类型应为轮廓，即`std::vector<cv::Point>`。

**hierarchy**（可选 optional）：
如果给定该参数，将输出所有轮廓的树结构。

**mode**：
设定提取轮廓的方式，有4种可选
1. cv::RETR_EXTERNAL
2. cv::RETR_LIST
3. cv::RETR_CCOMP
4. cv::RETR_TREE

**method**：
设定轮廓表达的方式，有三种方法可选
1. cv::CHAIN_APPROX_NONE
2. cv::CHAIN_APPROX_SIMPLE
3. cv::CHAIN_APPROX_TC89L1 OR cv::CHAIN_APPROX_TC89KCOS

### findContours函数的简单用法

```cpp
findContours(output, countersTemp, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE); 
```

## 使用drawContours函数绘制轮廓

### drawContours函数声明

```cpp
void cv::drawContours(
    cv::InputArray image,
    cv::InputArray contours,
    int contourIdx, 
    const cv::Scalar & color,
    int thickness = 1,
    int lineType = 8,
    cv::OutputArray hierarchy = noArray(),
    int maxLevel = INT_MAX,
    cv::Point offset = cv::Point()
)
```

**image**：
待绘制轮廓的图像

**contours**：
要绘制的轮廓，其元素类型应为轮廓，即`std::vector<cv::Point>`。

**contourIdx**
用于设置是否绘制所有轮廓。
`contourIdx > 0`则对应的轮廓会被绘制，`contourIdx < 0`，则所有轮廓都会被绘制出来。

**hierarchy**（可选 optional）：
如果给定该参数，将输出所有轮廓的树结构。
