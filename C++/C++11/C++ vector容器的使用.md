# C++ vector容器的使用

## vector的定义

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
