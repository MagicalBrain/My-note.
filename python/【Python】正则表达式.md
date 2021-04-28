# Python 正则表达式

当你需要在字符串中快速找到某种类型的子串，那么正则表达式就是你最好的选择。

Python 自1.5版本起增加了re 模块，它提供 Perl 风格的正则表达式模式。
re 模块使 Python 语言拥有全部的正则表达式功能。

[参考链接](https://www.runoob.com/python/python-reg-expressions.html)

## re.match()模块

```python
# -*- coding: UTF-8 -*- 

import re

print(re.match('www', 'www.runoob.com').span())  # 在起始位置匹配
print(re.match('com', 'www.runoob.com'))         # 不在起始位置匹配
```

返回结果：
```
(0, 3)
None
```

**注意：**
1. 如果re.match()方法没有找到的话是不能使用span()方法获取找到的字符串，因为此时返回的对象是None。而找到字符串后，如果不使用span()是无法获取找到的字符串，re.match()返回的是一个对象？
2. 如果正在处理的字符串从头开始找能够找到我们要的子串，则re.match()方法能够满足我们的需求；否则不行，即如果字符串从起始位置开始就不匹配，则无法找到。


  