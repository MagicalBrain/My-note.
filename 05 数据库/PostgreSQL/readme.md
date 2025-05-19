# PostgreSQL

##  简介

都是关系型数据库，PostgreSQL和MySQL有啥区别

1. 并发
   1. MySQL基于多线程，Postgres基于多进程（子进程）并发能力弱一点
2. 内存占用
   1. 由一可知，多线程的内存占用会比多进程要少一点，MySQL内存占用少
3. 功能
   1. MySQL不支持堆，PostgreSQL不支持聚集索引
   2. PostgreSQL重在分析，MySQL重在性能

参考[逼乎文章](https://www.zhihu.com/search?q=postgresql%20vs%20mysql&search_source=Suggestion&utm_content=search_suggestion&type=content)

## 安装

### Docker

这里推荐使用Docker开箱即用

### Linux

### Windows
