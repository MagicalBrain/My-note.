# Android 四大布局

标签（空格分隔）： Android

---
## 四大布局：
 LinearLayout、RelativeLayout、FrameLayout、

## 线性布局  LinearLayout

### 垂直排列：
```xml
<LinearLayout xmlns:android="……"
	默认布局方向是水平的
	android：orientation="vertical"  ->控制布局方向为垂直的
	android:orientation="horizontal"  ->控制布局方向为水平的
>
```

**注意：**
方向为horizontal时，内部空间决不能将狂宽度设为 match_parent，否则会将整个水平方向占满，
且android：layout_gravity="center_horizontal"是不起作用的，
android：layout_gravity是用来控制控件位置的，而android：gravity是控制文字在控件中的位置
因为此时只有在垂直方向的位置调整才有用
垂直方向同理

待补充

## 相对布局 RelativeLayout
为什么叫相对布局？
因为它是相对父布局或者是某个控件来控制位置的

相对于父布局：
```
android:layout_alignParentLeft="true" 相对于父布局是最左边
android:layout_alignParentRight="true" 相对于父布局是最右边

android:layout_alignParentTop="true" 	相对于父布局是最顶部
android:layout_alignParentToBottom="true" 	相对于父布局是最底部

android:layout_centerInParent="true" 相对于父布局是最中间的
```
相对于控件
```
android:layout_above="@+id/btn3"  相对于控件id=btn3是上面
android:layout_below="@+id/btn3"  相对于控件id=btn3是下面

android:layout_toLeftOf="@+id/btn3"	相对于控件id=btn3是左边
android:layout_toRightOf="@+id/btn3"	相对于控件id=btn3是右边

android:layout_alignLeft="@+id/btn3"	相对于控件id=btn3，左边边缘对齐
android:layout_alignRight="@+id/btn3"	相对于控件id=btn3，右边边缘对齐

android:layout_alignTop="@+id/btn3"	相对于控件id=btn3，顶部边缘对齐
android:layout_alignBottom="@+id/btn3"	相对于控件id=btn3，底部边缘对齐
```
## 帧布局 FrameLayout
没有方便的定位方式，所有的控件都会默认在布局的左上角，故应用场景少
可以用layout_weight来控制控件的位置

上面的布局中只有LinearLayout是可以用百分比布局来进行更方便的以任意比例分割布局

RelativeLayout和FrameLayout可以通过gradle包扩展来进行百分比布局

打开	app/build.gradle文件，在dependencies包中添加：
```
dependcies{
	compile fileTree(dir:'libs',include:['*.jar'])
	compile 'com.android.support:appcompat-v7:24.2.1'
	compile 'com.android.support:percent:24.2.1'
	testcompile 'junit:junit:4.12'
}
```
待补充

## 引入布局
待补充




