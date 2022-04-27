# C++ vector容器的使用

## vector的定义

定义一个空的vector，且元素类型为double

```cpp
std::vector<double> pose;
```

## vector的初始化

### 初始化一个指定长度、指定类型的vector

## vector元素的访问

**注意**：
在对vector元素的访问的时候，我们都假定vector是非空的，一定是有元素的。

### 访问第一个元素

以下所有代码都是基于自定义的类的[^MyClass]

```cpp
        /// <summary>
		/// 访问第一个元素
		/// </summary>
		/// <param name="e"></param>
		void TheFirst(int& e) {
			e = this->data.front();
			// 或者
			// e = *(this->data.begin());
		}
```

### 访问最后一个元素

```cpp
		/// <summary>
		/// 访问最后一个元素并通过形参返回
		/// </summary>
		/// <param name="e"></param>
		void TheBack(int& e) {
			e = *(this->data.end() - 1);
			// 或者
			// e = this->data.back();
		}
```

### 访问指定位置的元素

```cpp
		/// <summary>
		/// 获取指定位置的元素，并通过形参返回
		/// </summary>
		/// <param name="pos"></param>
		/// <param name="e"></param>
		void getElement(int pos, int &e) {
			e = this->data.at(pos);
			// 或者
			// e = this->data[pos]
			// 但是这样效率高一丢丢，但是却没有越界检查，不够安全
		}
```



### 添加元素

#### 在vector最前面添加元素

暂时没有思路

```cpp

```

#### 在vector后面添加元素

直接`push_back()`搞定

```cpp
		/// <summary>
		/// 在vector最后面添加元素
		/// </summary>
		/// <param name="e"></param>
		void pushVector(int e) {
			this->data.push_back(e);
		}
```

#### 在指定位置添加元素

```cpp

```

### 删除元素


#### 在vector最前面删除元素

```cpp
		/// <summary>
		/// 删除vector里第一个元素并通过形参返回
		/// </summary>
		/// <param name="e">被删除的元素的值</param>
		void deleteFirst(int &e) {
			try
			{
				e = *data.begin();
				this->data.erase(data.begin());
			}
			catch (const std::exception& err)
			{
				std::cout << err.what() << std::endl;
			}
		}
```

#### 在vector后面删除元素

```cpp
		/// <summary>
		/// 删除vector最后一个元素，并通过形参返回
		/// </summary>
		/// <param name="e"></param>
		/// <details>
		/// 需要注意的是，删除元素只改变size，并不改变容量 capacity
		/// </details>
		void popVector(int &e) {
			e = this->data.back();
			this->data.pop_back();
		}
```

#### 在指定位置删除元素

主要是利用`erase`api

```cpp

```



#### 删除指定位置区间的元素

主要是利用`erase`api

```cpp

```


### 遍历元素

```cpp
		/// <summary>
		/// 遍历所有元素并打印
		/// </summary>
		/// <returns></returns>
		bool traverseVector() {
			if (getSize() < 1)
				return false;

			for (auto i : data) {
				std::cout << i << " ";
			}
			std::cout << std::endl;

			return true;
		}
```


### 访问其中一个元素的多种方法比较

```cpp
// 假设有个名为vec的vector，里面有元素若干
std::vector<int> vec;

// 访问第i个元素
// 方法一:
vec[i];

// 方法二:
vec.at(i);
```

**两种方法的区别**
1. 没有越界判断，但性能高
2. 有越界判断

```cpp
// 方法三：
vec.data();     // 该方法返回指向vec第一个元素的指针，类似数组名
```

### 访问最后一个元素多种方法比较

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

### 访问vector中多个元素

```cpp
//
vec.size();
```

## vector的判空

有两种方法

1. `vector::size() == 0`
2. `vector::emtpty() == true`

这两种方法的区别是？

算法复杂度不一样

推荐使用`empty()`，因为算法复杂度为$O(1)$，而`size() == 0`，算法复杂度为$O(n)$.

因此，对于STL容器，只要有`empty()`，就应该使用它

## 类的定义

```cpp
    /// <summary>
	/// 这个类主要是用来学习vector的用法，元素类型为int
	/// </summary>
	class MyVector
	{
	public:
		MyVector();
		~MyVector();

        private:
		std::vector<int> data;

	};
```

## 参考链接

http://c.biancheng.net/view/6846.html

[^MyClass]: 代码参考 类的定义