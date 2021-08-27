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
   1. 只检索最外部的轮廓
   2. 分析：简单粗暴只适合比较简单的物体轮廓提取
2. cv::RETR_LIST
   1. 检索所有轮廓并保存到表中
   2. 分析：可以方便地获取所有提取的轮廓，但是却无法获知轮廓之间的关系
3. cv::RETR_CCOMP
   1. 检索所有轮廓并组织成两层结构：
      1. 顶层时最外部的轮廓
      2. 第二层边界时内部孔洞的轮廓
   2. 分析：可以简单、快速地获取最外部的轮廓和内部的轮廓。
4. cv::RETR_TREE
   1. 检索所有轮廓并建立起树状结构。从根节点到叶子节点，是最外部的轮廓到内部的轮廓。
   2. 分析：可以获取所有轮廓之间的包含关系，但是遍历轮廓较麻烦（树的遍历效率较低）

**method**：
设定轮廓表达的方式，有三种方法可选
1. cv::CHAIN_APPROX_NONE
   1. 将轮廓编码中的所有点转换为点。这一操作会产生大量的点，不会减少轮廓提取后返回的点的数量。
2. cv::CHAIN_APPROX_SIMPLE
   1. 压缩水平、垂直、斜的部分为一个点。将会大大减少返回的点（例如：矩形只保留四个角点）
3. cv::CHAIN_APPROX_TC89L1 OR cv::CHAIN_APPROX_TC89KCOS
   1. 使用**Teh-Chin链**逼近算法，用于减少返回的点的数量

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
