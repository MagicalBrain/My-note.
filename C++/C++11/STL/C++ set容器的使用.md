# C++ set容器的使用

set是一种关联容器，是关键字的简单集合。

主要作用：查询一个关键字是否存在。

## 一个简单的使用例子

在单词计数程序中，使用set来保存我们要忽略的常见的单词:

```cpp
//统计输入中每个单词出现的次数
map<string, size_st> word count; // string到sizet的空map
set<string> exclude = {"The", "But", "And", "Or", "An", "A",
"the", "but", "and", "or", "an", "a"}; string word;
while (cin >> word)
    //只统计不在exclude中的单词
    if (exclude.find(word) == exclude.end())
        ++word_count[word]; //获取并递增word的计数器
```

注意：
上面例子里的find和end的返回值都是迭代器

## set类型的定义

同顺序容器，set也是一类模板。
我们必须在定义的时候指明关键字的类型。例如上面的程序中：
```cpp
set<string> exclude;
```

关键字是string类型

## set类型的初始化

```cpp
//列表初始化
set<string> exclude= ("the", "but", "and", "or", "an", "a", "The", "But", "And", "or", "An", "A"};
```

## multiset类型的初始化

multiset一个关键字可以有多个元素对应，例如：

```cpp
//定义一个有20个元素的vector,保存0到9每个整数的两个拷贝
vector<int> ivec;
for (vector<int>::size_type i = 0; i != 10; ++i) {
    ivec.push_back(i);
    ivec.push_back(i); //每个数重复保存一次
}
// iset包含来自ivec的不重复的元素; miset包含所有20个元素
set<int> iset(ivec.cbegin() , ivec.cend());
multiset<int> miset(ivec.cbegin(), ivec.cend()); 
cout << ivec.size() << endl; //打印出20
cout << iset.size() << endl; //打印出10
cout << miset.size() << endl; //打印出20
```
