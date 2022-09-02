# opencv中的阈值化（二值化）操作

阈值操作就相当于$1 \times 1$的卷积。

## 全局阈值化操作

### cv::threshold

opencv主要是通过`cv::threshold`来实现：

```cpp
#include <opencv2/imgproc.hpp>

double cv::threshold(	
    InputArray 	src,
    OutputArray 	dst,
    double 	thresh,
    double 	maxval,
    int 	type 
)	
```

src	input array (multiple-channel, 8-bit or 32-bit floating point).
dst	output array of the same size and type and the same number of channels as src.
thresh	threshold value.
maxval	maximum value to use with the THRESH_BINARY and THRESH_BINARY_INV thresholding types.
type	thresholding type (see ThresholdTypes).
Returns
the computed threshold value if Otsu's or Triangle methods used.

### cv::ThresholdTypes

|||
|--|--|
|THRESH_BINARY| dst(x,y)={maxval0if src(x,y)>threshotherwise|
THRESH_BINARY_INV 

dst(x,y)={0maxvalif src(x,y)>threshotherwise
THRESH_TRUNC 

dst(x,y)={thresholdsrc(x,y)if src(x,y)>threshotherwise
THRESH_TOZERO 

dst(x,y)={src(x,y)0if src(x,y)>threshotherwise
THRESH_TOZERO_INV 

dst(x,y)={0src(x,y)if src(x,y)>threshotherwise
THRESH_MASK 

THRESH_OTSU 

flag, use Otsu algorithm to choose the optimal threshold value

THRESH_TRIANGLE 

flag, use Triangle algorithm to choose the optimal threshold value

## 局部阈值化操作

局部阈值化其实也就是自适应阈值化

### cv::adaptiveThreshold

opencv主要是通过`cv::adaptiveThreshold`来实现：

```cpp
void cv::adaptiveThreshold	(	
    InputArray 	src,
    OutputArray 	dst,
    double 	maxValue,
    int 	adaptiveMethod,
    int 	thresholdType,
    int 	blockSize,
    double 	C 
)	
```


src	Source 8-bit single-channel image.
dst	Destination image of the same size and the same type as src.
maxValue	Non-zero value assigned to the pixels for which the condition is satisfied
adaptiveMethod	Adaptive thresholding algorithm to use, see AdaptiveThresholdTypes. The BORDER_REPLICATE | BORDER_ISOLATED is used to process boundaries.
thresholdType	Thresholding type that must be either THRESH_BINARY or THRESH_BINARY_INV, see ThresholdTypes.
blockSize	Size of a pixel neighborhood that is used to calculate a threshold value for the pixel: 3, 5, 7, and so on.
C	Constant subtracted from the mean or weighted mean (see the details below). Normally, it is positive but may be zero or negative as well.

### cv::adaptiveThresholdTypes

**ADAPTIVE_THRESH_MEAN_C**

the threshold value T(x,y) is a mean of the blockSize×blockSize neighborhood of (x,y) minus C

**ADAPTIVE_THRESH_GAUSSIAN_C**

the threshold value T(x,y) is a weighted sum (cross-correlation with a Gaussian window) of the blockSize×blockSize neighborhood of (x,y) minus C . The default sigma (standard deviation) is used for the specified blockSize . See getGaussianKernel
