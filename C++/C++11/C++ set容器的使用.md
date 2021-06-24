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

## map类型的定义

同顺序容器，set也是一类模板。
我们必须在定义的时候指明关键字的类型。例如上面的程序中：
```cpp
set<string> exclude;
```

关键字是string类型
