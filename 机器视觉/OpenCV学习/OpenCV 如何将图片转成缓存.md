# OpenCV 如何将图片转成缓存

## cv::imencode 方法

```cpp
#include <opencv2/imgcodecs.hpp>
```

Encodes an image into a memory buffer.

The function imencode compresses the image and stores it in the memory buffer that is resized to fit the result. See cv::imwrite for the list of supported formats and flags description.

Parameters
* ext	
File extension that defines the output format.
输出格式的文件扩展名，例如“.png、.jpg”之类的
**注意**是带“.”的

* img	
Image to be written.
被写入的图像

* buf	
Output buffer resized to fit the compressed image.
输出的缓存

* params	
Format-specific parameters. See cv::imwrite and cv::ImwriteFlags.
格式指定参数，参考`cv::imwrite`和`cv::ImwriteFlags`

