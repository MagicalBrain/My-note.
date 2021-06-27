# C++ map容器的使用

map是一种关联容器，是`关键字-值`对的集合

map的作用主要是根据关键字来获取对应的值。

## 一个简单的使用例子

一个经典的使用关联数组的例子是单词计数程序:

```cpp
//统计每个单词在输入中出现的次数
map<string, size t> word count; // string到sizet的空map string word;
while (cin >> word)
++word count [word];
//提取word的计数器并将其加1
for (const auto &w : word_count) //对map中的每个元素
//打印结果
cout < w.first   occurs
K w. second
<< ((w.second > 1) ? " times" : " time") << endl;
```

## map类型的定义

同顺序容器，map也是一类模板。
我们必须在定义的时候指明关键字和值的类型。例如上面的程序中：
```cpp
map<string, size_t> word_count;
```

关键字是string类型，值是size_t类型

## map类型的初始化

```cpp
//初始化三个元素; authors将姓映射为名
map<string, string> authors = { 
    {"Joyce", "James"},
    {"Austen", "Jane",
    {"Dickens", "Charles"} 
};
```

## 添加元素

使用insert方法添加元素。
记住：insert所操作的元素类型必须是pair。

如果想要插入的数据没有现成的pair对象，可在insert的参数列表中创建一个pair。

```cpp
 //向word count插入word的4种方法
word count.insert ((word, 1});
word count.insert (make_pair(word, 1));
word count.insert(pair<string, size t> (word, 1));
word count.insert (map<string, size t>::value_type (word, 1));
```

## 删除元素

```cpp

```
