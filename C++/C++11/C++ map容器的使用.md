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
