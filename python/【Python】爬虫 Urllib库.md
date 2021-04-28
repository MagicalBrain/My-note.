# Python 爬虫 Urllib库

标签（空格分隔）： Python 爬虫

---

## 基本操作

### 读取网页代码
```python3
import urllib.request
#导入模块

file = urllib.request.urlopen("http://www.baidu.com")
#把要访问的URL地址存到file变量

data = file.read()
#将网页源代码存到data

dataline = file.readline()
#将网页第一行代码存到dataline

print(data)
#输出数据
```
1、```file.read()```
读取全部内容，并赋值给一个字符串变量
2、```file.readlines()```
读取全部内容，赋值给一个列表变量
3、```file.readline()```
读取一行内容

### 保存网页内容
法一：
```python3
fhandle = open(r"C:\Users\Administrator\Desktop\爬虫\爬虫1.html","wb")

print(fhandle.write(data))

fhandle.close()
```

法二：
```python
filename = urllib.request.urlretrieve("http://edu.51cto.com",filename=r"C:\Users\Administrator\Desktop\爬虫\爬虫2.html")

urllib.request.urlcleanup()
#记得一定要有，清缓存
```

### 访问基本信息
```python3
file.info()
```

### 爬取状态吗
```python3
file.getcode()
```

### 获取当前的URL
```python
file.geturl()
```

编码：
```python
str = urllib.request.quote("http://www.baidu.com")
print(str)
```

结果：
http%3A//www.baidu.com

解码：
```python
str = urllib.request.unquote("http%3A//www.baidu.com")
print(str)
```

结果：
http://www.baidu.com

