# Mat数据结构

标签（空格分隔）： OpenCV

---
## 创建图像
### 初始化图像
```c++
Mat image(240,320,CV_8U,100);
//定义image的图像的同时，把它初始化为一个宽为240，长为320的图像
```

#### Scalar数据结构
用于在调用函数时传递像素值（就是可以调颜色）

```c++
Mat image(240,320,CV_8U,100,Scalar(0,0,255));
//创建了一个红色图像
//
```
**注意：**
RGB通道的次序是**BGR**

```c++
Scalar(100);
//初始化为灰度图像
```

## creat方法
```c++
Mat image1;
image1.creat(200,200,CV_8U);
//重新把一个图像放进image1
```

## 复制图像的方法
### copyTo方法
```c++
image1.copyTo(image2);
```
**这其实是一个深复制的方法**

### clone方法
```c++
image2 = image1.clone();
```

### covertTo方法
```c++
image1.converTo();
```



