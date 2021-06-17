# OpenCV 入门（三） 使用兴趣区域ROI

标签（空格分隔）： OpenCV

---

## 使用Rect方法

img1是目标图像，img2是要插入的图像
省去了导入图片的步骤
```c++
Mat imgROI = img1(Rect(img1.cols - img2.cols, img1.rows - img2.rows, 
img2.cols, img2.rows));
//Mat imgROI(img1,Rect(img1.cols-img2.cols,img1.rows-img2.rows,img2.cols,img2.rows));
//这个语句效果同上
//先在目标图像划定要插入的区域，即ROI区域

img2.copyTo(imgROI);
//插入图片
//这一步千万不要忘了

imshow("img1", img1);
```
即可

**目标图像原图**
![image_1chc9nkh41jilcq47ja6t7150v16.png-1491kB][1]


**要插入的图片**
![image_1chc9l5g41nrr1ii4191sek1ok09.png-82.4kB][2]


**插入后**
![image_1chc9ojmgcqs1gvom8v1uprt2b1j.png-1458.6kB][3]


## 法二：使用Range结构来划分
```c++
Mat imgROI = img1(Range(img1.rows - img2.rows,img1.rows),
Range(img1.cols - img2.cols,img1.cols));
```


  [1]: http://static.zybuluo.com/Arbalest-Laevatain/nx8qva9ssknkhu7v5apyaaae/image_1chc9nkh41jilcq47ja6t7150v16.png
  [2]: http://static.zybuluo.com/Arbalest-Laevatain/vqp8i7epnqzmwonatr7pojy9/image_1chc9l5g41nrr1ii4191sek1ok09.png
  [3]: http://static.zybuluo.com/Arbalest-Laevatain/2rq5drcu6jiga1fwv6gb39u1/image_1chc9ojmgcqs1gvom8v1uprt2b1j.png