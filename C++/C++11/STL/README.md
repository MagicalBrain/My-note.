# C++ STL 容器

## STL 容器有哪些？

主要分为顺序容器和关联容器。

### 顺序容器

顺序容器：
1. vector
2. deque
3. list
4. forward_list
5. array
6. string[^string]

**vector**：
可变大小数组。支持快速随机访问。在尾部之外的位置插入或删除元素可能很慢

**deque**
双端队列。支持快速随机访问。在头尾位置插入/删除速度很快

**list**
双向链表。只支持双向顺序访问。在1ist中任何位置进行插入/删除操作速度都很快

**forward_list**
单向链表。只支持单向顺序访问。在链表任何位置进行插入/删除操作速度都很快

**array**
固定大小数组。支持快速随机访问。不能添加或删除元素

**string**
与vector相似的容器，但专门用于保存字符。随机访问快。在尾部 插入/删除速度快

#### 练习9.1:对于下面的程序任务， vector， deque和1ist哪种容器最为适合？解释你的选择的理由。如果没有哪一种容器优于其他容器，也请解释理由。
（a）读取固定数量的单词，将它们按字典序插入到容器中。我们将在下一章中看到，关联容器更适合这个问题。
list

（b）读取未知数量的单词，总是将新单词插入到末尾。删除操作在头部进行。
vector

（c）从一个文件读取未知数量的整数。将这些数排序，然后将它们打印到标准输出。
list


### 关联容器

[^string]: 关于`std::string`是否是STL容器目前还有争议，因为它的开发完全是独立与其他STL的，但同时又具有类似的用法

关联容器有：
1. map
2. set
3. multimap
4. multiset
5. unordered_map
6. unordered_set
7. unordered_multimap
8. unordered_multiset

**map**

**set**

**multimap**

**multiset**

**unordered_map**

**unordered_set**

**unordered_multimap**

**unordered_multiset**

### 选择容器的基本原则

1. 除非你有很好的理由选择其他容器，否则应使用vector。
2. 如果你的程序有很多小的元素，且空间的额外开销很重要，则不要使用list或 forward_list。
3. 如果程序要求随机访问元素，应使用vector或deque
4. 如果程序要求在容器的中间插入或删除元素，应使用list或forwardlist.如果程序需要在头尾位置插入或删除元素，但不在中间位置进行插入或删除操 作，则使用deque。
5. 如果程序只有在读取输入时才需要在容器中间位置插入元素，随后需要随机访问元素，则
   1. 首先，确定是否真的需要在容器中间位置添加元素。当处理输入数据时，通常可以很容易地向vector追加数据，然后再调用标准库的sort函数（我们将在10.2.3节介绍sort （第343页））来重排容器中的元素，从而避免在中间位置添加元素
   2. 如果必须在中间位置插入元素，考虑在输入阶段使用list，一旦输入完成，将list中的内容拷贝到一个vector中。

## 顺序容器

## 关联容器

### 定义关联容器

### pair类型

不管是有序还是无序的关联容器，都支持普通的容器操作。
不支持顺序容器中与位置相关的操作。

在介绍关联容器的操作之前，我们需要先了解pair的标准库类型，它定义在`utility`库文件中。

一个pair保存两个数据成员，有点类似于容器。
pair是一个用来生产特定类型的模板。
当创建一个pair时，我们必须提供两个数据成员对应的类型名，可相同也可不相同。

```cpp
pair<string, string> anon;    //保存两个string
pair<string, string> word_count;    //保存一个string和一个size_t
pair<string, vector<int>> line;     //保存string和vector<int>
```

pair默认的构造函数支持值初始化。

pair的数据成员是public的，分别为`first`和`second`，可直接访问：

```cpp
cout << w.first << " occurs" << w.second << endl;
```

**pair上的操作**
```cpp
pair<Tl, T2> p;   //p是一个pair，两个类型分别为T1和T2的成员都进行了值初始化（参见3.3.1节，第88页）
pair<Tl, T2> p(vl, v2)  //p是一个成员类型为T1和T2的pair； first和second成员分别用v1和v2进行初始化
pair<T1, T2>p = {v1, v2};  //等价于p （v1，v2）
make_pair (v1, v2)   //返回一个用v1和v2初始化的pair， pair的类型从v1和v2的类型推断出来
p.first     //返回p的名为first的（公有）数据成员
p.second    //返回p的名为second的（公有）数据成员
p1 relop p2    
/*
* 关系运算符（<、>、<=、>=）按字典序定义：
* 例如，
* 当pl.first < p2.first或!(p2.first < p1.first) && p1.second < p2.second成立时， p1 < p2为true。
* 关系运算利用元素的<运算符来实现
*/
pl == p2
p1 != p2
/*
* 当first和second成员分别相等时，两个pair相等。相等性判断利用元素的==运算符实现
*/
```

**创建pair对象的函数**

`pair-create.cpp`

```cpp
pair<string, int> process(vector<string> &v) {
   //处理v
   if (!v.empty())
      return {v.back(), v.back().size()};    //列表初始化
   else
      return pair<string, int> ();     //隐式构造返回值
}
```

若v不为空，我们返回一个由v中最后一个string及其大小组成的pair，否则隐式构造一个空pair，并返回它。

我们还可以使用`make_pair`函数来生成pair对象，如将上面的if里的返回语句改为：
```cpp
if (!v.empty())
   return make_pair(v.back(), v.back().size());
```

### 关联容器的操作

## 关于容器使用所需要的头文件

一般来讲头文件名和容器名是一样的。

## 练习

### 11.1节 练习

#### 练习11.1:描述map和vector的不同。

map里的元素类型有两种，且有一种元素的值是通过关键字来获取的；

vector里的元素只能有一种，且可通过下标来访问元素的值。

#### 练习11.2:分别给出最适合使用list， vector， deque， map以及set的例子。

list：适合经常频繁删除元素的场合

vector：适用于处理的元素全都是一种，且元素操作不复杂的场合

deque：适合排序？

map：不用说肯定是通过一种元素获取另外一种对应元素的值

set：适合查询同一种元素中的某一个是否存在的场景。

#### 练习11.3:编写你自己的单词计数程序。

```cpp

```

#### 练习11.4:扩展你的程序，忽略大小写和标点。例如，＂example. ＂、＂example，＂和＂Example＂应该递增相同的计数器。

```cpp
/*
* 问题；如何忽略大小写？
* 解决方法：全转为小写即可
*/
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cctype>

using namespace std;
using std::string;
using std::map;
using std::set;

int main() {
    //统计输入中每个单词出现的次数
    map<string, int> word_count; // string到sizet的空map
    set<string> exclude = {"The", "But", "And", "Or", "An", "A",
        "the", "but", "and", "or", "an", "a"}; 
    string word;
    while (cin >> word)
    {
        for (auto &i : word)
            i = tolower(i);
        
        //只统计不在exclude中的单词
        if (exclude.find(word) == exclude.end())
            ++word_count[word]; //获取并递增word的计数器
    }
    for (auto i : word_count)
    {
        cout << i.first << " occurs " << i.second 
            << (i.second > 1 ? " times." : " time.") << endl;
    }
    
    return 0;
}
```

### 11.2.1节 练习

#### 练习11.5:解释map和set的区别。你如何选择使用哪个？

map的元素只是一对关键字和值，而set的元素是关键字且不重复。

如果要查询关键字对应的值是哪个用map，查询关键字是否存在用set。

#### 练习11.6:解释set和list的区别。你如何选择使用哪个？

set是一个集合，存储的关键字是不重复的，而list是双向链表。

如果查询关键字没有太多增加或删除操作应当使用set，否则使用list。

#### 练习11.7:定义一个map，关键字是家庭的姓，值是一个vector，保存家中孩子（们）的名。编写代码，实现添加新的家庭以及向已有家庭中添加新的孩子。

**map-KidsinFamilies.cpp**

```cpp
/*
* 问题：创建一个map，用于存储一个家庭的孩子的姓名。
* 关键字为姓，值是一个vector为该家庭所有孩子的名
* 实现方法：
*    添加新家庭的孩子的姓名；
*    向已有家庭添加孩子的姓名；
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
using std::vector;
using std::string;
using std::map;

void CreateNewFamiliesKids(map<string, vector<string> > &families, string first_name, vector<string> names) {
    families.insert( make_pair(first_name, names));
}

void PrintFamilies(map<string, vector<string> > families) {
    if (families.empty()) {
        cout << "families 为空！" << endl;
        return;
    }

    for (auto i : families) {
        cout << i.first << endl;
        for (auto j : i.second) {
            cout << j << " ";
        }
        cout << endl;
    }
}

void AddNewKids(map<string, vector<string> > &families, string first_name, string names) {
    
    if (!families.empty()) {
        //如果families不为空，则
        string t;
        for (auto i : families) {
            if (i.first == first_name) {
                t = i.first;
                break;
            }
        }
        if (t.size() > 0) {
            families[t].push_back(names);
            return;
        }
        
    } 
    //如果families为空，则直接添加
    vector<string> tmp;
    tmp.push_back(names);
    pair<string, vector<string> > p = make_pair(first_name, tmp);
    families.insert(p);
    //return false;
}

int main() {
    map<string, vector<string> > familis;
    vector<string> names;
    string first_name, name;

    cout << "创建map" << endl;
    cout << "请输入姓" << endl;
    cin >> first_name;
    cout << "请输入孩子的名字：" << endl;
    while (cin >> name)
    {
        names.push_back(name);
    }
    CreateNewFamiliesKids(familis, first_name, names);
    
    PrintFamilies(familis);

    cout << "请输入孩子的姓名：" << endl;
    cin >> first_name >> name;
    AddNewKids(familis, first_name, name);

    PrintFamilies(familis);
    return 0;
}
```

代码有问题，不想这么写了，要吐了。

#### 练习11.8:编写一个程序，在一个vector而不是一个set中保存不重复的单词。使用set优点是什么？

```cpp
/*
* 问题：创建一个vector，用于存储不重复的单词
*/
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;
using std::vector;
using std::string;
using std::set;

int main() {
    vector<string> words;
    set<string> words_set;

    string word;
    while (cin >> word)
    {
        words_set.insert(word);
        if (words.size() > 1) {
            bool flag_find = false;
            for (auto i : words)
                if (i == word)
                    flag_find = true;
            
            if (!flag_find)
                words.push_back(word);
        }
        else words.push_back(word);
    }

    for (auto i : words)
        cout << i << " ";
    cout << endl;
    
    //words_set.insert(words.cbegin(), words.cend());
    for (auto i : words_set)
        cout << i << " ";
    cout << endl;
    
    return 0;
}
```

我这里添加了一个set用作对照，发现set默认是把添加进去的word按字典序排序的。

可见使用set的好处除了方便除重之外还可以将word按字典序进行排序，用起来十分方便。

### 11.2.2节 练习

#### 练习11.9:定义一个map，将单词与一个行号的list关联， list中保存的是单词所出现的行号。

定义如下：
```cpp
map<string, list<int> > m;
```

问题是我只是写了个定义，真要写个保存单词所在行号的程序怕是有点困难。

#### 练习11.10:可以定义一个vector<int>::iterator到int的map吗？list<int>::iterator到int的map呢？对于两种情况，如果不能，解释为什么。

```cpp
map<vector<int>::iterator, int > vi;
map< list<int>::iterator, int > li;
```

语法上没有问题，但是实际上运行会出错。

有序容器要求关键字类型必须支持比较操作`<`，因此map<vector<int>::iterator, int> vec_int是可以的，因为vector的迭代器支持比较操作。而map<list<int>::iterator, int> lst_int；是不行的，因为list的元素不是连续存储的，其迭代器不支持比较操作。

作者：吃口水
链接：https://zhuanlan.zhihu.com/p/353169184

#### 练习11.11:不使用decltype重新定义bookstore.

```cpp

```

### 11.2.3节 练习

#### 练习11.12:编写程序，读入string和int的序列，将每个string和int存入一pair中， pair保存在一个vector中。

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;
using std::vector;
using std::string;

int main() {
    string str;
    int num;
    vector<pair<string, int> > v;

    while (cin >> str >> num)
        v.push_back(make_pair(str, num));
    
    for (auto i : v)
    {
        cout << i.first << " " << i.second << endl;
    }
    //cout << endl;  
    
    return 0;
}
```

#### 练习11.13:在上一题的程序中，至少有三种创建pair的方法。编写此程序的三个版本，分别采用不同的方法创建pair，解释你认为哪种形式最易于编写和理解，为什么？

11.12我用的方式：
```cpp
make_pair(str, num);
```

除了11.12的方式，还有两种：
2、
```cpp
pair<string, int> v(str, num);
```

3、
```cpp
pair<string, int> v{str, num};
```

#### 练习11.14:扩展你在11.2.1节练习（第378页）中编写的孩子姓到名的map，添加一个pair的vector，保存孩子的名和生日。

**map-KidsinFamilies.cpp**

```cpp

```

## 关于容器的使用容易出错的地方

貌似容器不能够在switch的分值case里面定义，这个不光是容器的问题，所有变量都会有这个问题。
给需要定义变量的分支加上括号就行了，例如：
```cpp
case 9:
        {
            // 控制相机取图，如果需要做手眼标定，可以使用int capture(std::vector<cv::Mat>& images)接口获取相机图片
            int checkcapture = sensor->capture(images);
            if(0 != checkcapture)
            {
                BOOST_LOG_TRIVIAL(error) << "sensor capture fail";
                return -1;
            }
            BOOST_LOG_TRIVIAL(info) << "sensor capture sucess";

            // 生成并获取彩色图和深度图
    
            if (0 != sensor->compute(color, depth))
            {
                BOOST_LOG_TRIVIAL(error) << "sensor compute fail";
                return -1;
            }
            BOOST_LOG_TRIVIAL(info) << boost::format("color image type: %1%, size %2%") % color.type() % color.size();
            BOOST_LOG_TRIVIAL(info) << boost::format("depth image type: %1%, size %2%") % depth.type() % depth.size();
            
            cv::imwrite("color.bmp", color);
            cv::imwrite("depth.tiff", depth);
            cv::imwrite("depth.png", depth);
	        cv::imwrite("depth.pfm", depth);

            std::cout << depth.rows << " " << depth.cols << std::endl;

            // 深度图可直接生成点云，以pcl为例：

            for (int i = 0; i < depth.rows; ++i)
            {
                for (int j = 0; j < depth.cols; ++j)
                {
                    pcl::PointXYZRGB point;
                    point.x = depth.at<cv::Vec3f>(i, j)[0];
                    point.y = depth.at<cv::Vec3f>(i, j)[1];
                    point.z = depth.at<cv::Vec3f>(i, j)[2];
                    if (point.z <= 0)
                        continue;

                    if (color.type() == CV_8UC3)
                    {
                        point.b = color.at<cv::Vec3b>(i, j)[0];
                        point.g = color.at<cv::Vec3b>(i, j)[1];
                        point.r = color.at<cv::Vec3b>(i, j)[2];
                    }
                    else
                    {
                        point.b = point.g = point.r = color.at<uint8_t>(i, j);
                    }

                    cloud.emplace_back(point);
                }
            }

            if (cloud.size() > 0)
            {
                BOOST_LOG_TRIVIAL(info) << boost::format("get point cloud sucess, total %1% points") % cloud.size();
                pcl::PCDWriter writer;
                writer.writeBinaryCompressed("cloud.pcd", cloud);
            }
            else
                BOOST_LOG_TRIVIAL(error) << "point cloud is empty";

            break;
        }
```
