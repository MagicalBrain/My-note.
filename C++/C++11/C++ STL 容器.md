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
6. string

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

### 关联容器的操作

不管是有序还是无序的关联容器，都支持普通的容器操作。
不支持顺序容器中与位置相关的操作。

## 练习

### 11.1节 练习

### 练习11.1:描述map和vector的不同。

map里的元素类型有两种，且有一种元素的值是通过关键字来获取的；

vector里的元素只能有一种，且可通过下标来访问元素的值。

### 练习11.2:分别给出最适合使用list， vector， deque， map以及set的例子。

list：适合经常频繁删除元素的场合

vector：适用于处理的元素全都是一种，且元素操作不复杂的场合

deque：适合排序？

map：不用说肯定是通过一种元素获取另外一种对应元素的值

set：适合查询同一种元素中的某一个是否存在的场景。

### 练习11.3:编写你自己的单词计数程序。

### 练习11.4:扩展你的程序，忽略大小写和标点。例如，＂example. ＂、＂example，＂和＂Example＂应该递增相同的计数器。

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
