# Git分支模型

## 分支模型是什么？

一般来讲，一个项目正在持续交付的时候难免会遇到一些问题或者产品经理客户又提出了什么新的需求需要满足。

这时为了保证开发工作有条理地向前推进进度，我们需要用到git的分支模型。
（git本身支持版本迭代和回滚但这还不够方便。）

## 分支模型解决了哪些问题？

1、fix bugs的时候要修改代码，但代码还没有修改好的时候客户怎么能有代码用？

2、用户提出了新的需求，我们代码实现未完成的时候客户怎么能有代码用？

3、修好代码，实现了新的需求，怎么将新的代码合并到原来的代码里去？

## 分支模型有哪些常见的？

1. Git Flow
2. Github Flow
3. TBD based Development（Google和Facebook都在用）

## Git Flow

### 主分支

+ `master`
+ `develop`

### 支持分支

+ `feature`
+ `release`
+ `hotfix`
  
### 用法

#### 创建新功能

通常一个新功能会在`develop`分支上创建一个新的`feature`分支
新功能实现好后会merge回develop分支，然后再develop分支上构建、测试、部署

有问题则直接在develop分支上修复

没有问题则合并到master分支

#### 发布release

在master分支的基础上新建一个release分支，需要哪些功能就从feature分支上合并过来

### 总结

这个模型挺麻烦的

## Github Flow

### 主分支

master

相当于把上面的Git Flow里的master和develop合并了

### 支持分支

feature

### 用法

### 总结

简化了分支管理转而使用PR方式来进行代码合并

## TBD based Development

## 参考连接

https://zhuanlan.zhihu.com/p/377812978
