# Python Tricks

## 1.  Reversing a string in Python

反转一个字符串

```python
a =  "codementor"
print "Reverse is",a[::-1]
```

输出结果:
```
Reverse is rotnemedoc
```

## 2. Transposing a Matrix

矩阵转置

```python
mat = [[1, 2, 3], [4, 5, 6]]
zip(*mat)
```
result:
```
[(1, 4), (2, 5), (3, 6)]
```
## 3.Store all three values of the list in 3 new variables

将list类型中三个值存储到新的三个变量中

```python
>>> a = [1, 2, 3]
>>> x, y, z = a 
>>> x
1
>>> y
2
>>> z
3
```
## 4. Create a single string from all the elements in list above.

把给出的list中所有的字符串合并创建一个字符串

```python
a = ["Code", "mentor", "Python", "Developer"]
>>> print " ".join(a)
Code mentor Python Developer
```

## 5. 将两个list的元素成对输出

List 1 = ['a', 'b', 'c', 'd']
List 2 = ['p', 'q', 'r', 's']
Write a Python code to print
ap
bq
cr
ds
```python
>>> for x, y in zip(list1,list2):
...    print x, y
...
a p
b q
c r
d s
```
## 6.用一行代码交换两个变量的值

Swap two numbers with one line of code.
```python
>>> a=7
>>> b=5
>>> b, a =a, b
>>> a
5
>>> b
7
```

## 7.不使用循环语句打印重复的字符串

Print "codecodecodecode mentormentormentormentormentor" without using loops
```python
>>> print "code"*4+' '+"mentor"*5
codecodecodecode mentormentormentormentormentor
```
## 8.不使用循环将一个矩阵转换为一个向量

a = [[1, 2], [3, 4], [5, 6]]
Convert it to a single list without using any loops.
Output:- [1, 2, 3, 4, 5, 6]

```python
>>> import itertools 
>>> list(itertools.chain.from_iterable(a))
[1, 2, 3, 4, 5, 6]
```

## 9.判断两个单词是否相同

Checking if two words are anagrams
```python
def is_anagram(word1, word2):
    """Checks whether the words are anagrams.
    word1: string
    word2: string
    returns: boolean
    """
```
Complete the above method to find if two words are anagrams.
```python
from collections import Counter
def is_anagram(str1, str2):
     return Counter(str1) == Counter(str2)
>>> is_anagram('abcd','dbca')
True
>>> is_anagram('abcd','dbaa')
False
```

##10.使用一行代码将几个数字转成向量输出

Taking a string input.
For example "1 2 3 4" and return [1, 2, 3, 4]
Remember list being returned has integers in it.
Don't use more than one line of code.
```python
>>> result = map(lambda x:int(x) ,raw_input().split())
1 2 3 4
>>> result
[1, 2, 3, 4]
```
