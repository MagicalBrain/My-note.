# cv_bridge

cv_bridge是用来进行将ros消息和opcv mat类型之间互相转换的

## ros消息转cv::Mat



## cv::Mat 转 ros消息

## sensor_msgs::image_encodings 详解

sensor_msgs::image_encodings对应的opencv编码：

|sensor_msgs' encoding|opencv's encoding|
|--|--|
|||
if (encoding == enc::BGR8) {return CV_8UC3;}
  if (encoding == enc::MONO8) {return CV_8UC1;}
  if (encoding == enc::RGB8) {return CV_8UC3;}
  if (encoding == enc::MONO16) {return CV_16UC1;}
  if (encoding == enc::BGR16) {return CV_16UC3;}
  if (encoding == enc::RGB16) {return CV_16UC3;}
  if (encoding == enc::BGRA8) {return CV_8UC4;}
  if (encoding == enc::RGBA8) {return CV_8UC4;}
  if (encoding == enc::BGRA16) {return CV_16UC4;}
  if (encoding == enc::RGBA16) {return CV_16UC4;}

  // For bayer, return one-channel
  if (encoding == enc::BAYER_RGGB8) {return CV_8UC1;}
  if (encoding == enc::BAYER_BGGR8) {return CV_8UC1;}
  if (encoding == enc::BAYER_GBRG8) {return CV_8UC1;}
  if (encoding == enc::BAYER_GRBG8) {return CV_8UC1;}
  if (encoding == enc::BAYER_RGGB16) {return CV_16UC1;}
  if (encoding == enc::BAYER_BGGR16) {return CV_16UC1;}
  if (encoding == enc::BAYER_GBRG16) {return CV_16UC1;}
  if (encoding == enc::BAYER_GRBG16) {return CV_16UC1;}

  // Miscellaneous
  if (encoding == enc::YUV422) {return CV_8UC2;}
  if (encoding == enc::YUV422_YUY2) {return CV_8UC2;}

通过查看下面这段代码可以知道对应的opencv编码：

```cpp
int getCvType(const std::string & encoding)
{
  // Check for the most common encodings first
  if (encoding == enc::BGR8) {return CV_8UC3;}
  if (encoding == enc::MONO8) {return CV_8UC1;}
  if (encoding == enc::RGB8) {return CV_8UC3;}
  if (encoding == enc::MONO16) {return CV_16UC1;}
  if (encoding == enc::BGR16) {return CV_16UC3;}
  if (encoding == enc::RGB16) {return CV_16UC3;}
  if (encoding == enc::BGRA8) {return CV_8UC4;}
  if (encoding == enc::RGBA8) {return CV_8UC4;}
  if (encoding == enc::BGRA16) {return CV_16UC4;}
  if (encoding == enc::RGBA16) {return CV_16UC4;}

  // For bayer, return one-channel
  if (encoding == enc::BAYER_RGGB8) {return CV_8UC1;}
  if (encoding == enc::BAYER_BGGR8) {return CV_8UC1;}
  if (encoding == enc::BAYER_GBRG8) {return CV_8UC1;}
  if (encoding == enc::BAYER_GRBG8) {return CV_8UC1;}
  if (encoding == enc::BAYER_RGGB16) {return CV_16UC1;}
  if (encoding == enc::BAYER_BGGR16) {return CV_16UC1;}
  if (encoding == enc::BAYER_GBRG16) {return CV_16UC1;}
  if (encoding == enc::BAYER_GRBG16) {return CV_16UC1;}

  // Miscellaneous
  if (encoding == enc::YUV422) {return CV_8UC2;}
  if (encoding == enc::YUV422_YUY2) {return CV_8UC2;}

  // Check all the generic content encodings
  std::cmatch m;

  if (std::regex_match(encoding.c_str(), m,
    std::regex("(8U|8S|16U|16S|32S|32F|64F)C([0-9]+)")))
  {
    return CV_MAKETYPE(depthStrToInt(m[1].str()), atoi(m[2].str().c_str()));
  }

  if (std::regex_match(encoding.c_str(), m,
    std::regex("(8U|8S|16U|16S|32S|32F|64F)")))
  {
    return CV_MAKETYPE(depthStrToInt(m[1].str()), 1);
  }

  throw Exception("Unrecognized image encoding [" + encoding + "]");
}
```

### 对应的realsense格式

可见对于realsense的`Z16`格式，应该是：`sensor_msgs::image_encodings::MONO16`

## 参考资料

[github源码地址](git@github.com:ros-perception/vision_opencv.git)
