# C++ vector容器的使用

## vector的定义

## 如何定义一个空的vector

```cpp
std::vector<double> pose;
```

## vector的初始化

## vector元素的访问

### 添加元素

### 遍历元素

### 访问最后一个元素

有如下几种方法：

```cpp
//方法一： 
return vec.at(vec.size()-1);
 
//方法二： 
return vec.back();
//
方法三： 
return vec.end()-1;  //注意：end指向末尾元素的下一个元素。
 
//方法四： 
return vec.rbegin();
```

## vector的判空

有两种方法

1. `vector::size() == 0`
2. `vector::emtpty() == true`

这两种方法的区别是？

算法复杂度不一样

推荐使用`empty()`，因为算法复杂度为$O(1)$，而`size() == 0`，算法复杂度为$O(n)$.

因此，对于STL容器，只要有`empty()`，就应该使用它
