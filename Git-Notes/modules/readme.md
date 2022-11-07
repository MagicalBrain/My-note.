# Git模块的用法

github有些项目还需要依赖其它第三方项目，而又是以module的形式加进来。

这样我们克隆下来的时候，module所在的目录仍然是空的。

那怎么把这些第三方依赖clone下来呢？

## 克隆仓库的同时克隆module

```bash
git clone --recursive [repo address]
```

## 克隆仓库后updatemodule

```bash
git submodule init
git submodule update
```

或者直接一条命令：

```bash
git submodule update --init --recursive
```

## 克隆的时候遇到网络问题文件下不下来

修改`.gitmodule`文件.

文件内容假设是：

```bash
[submodule "3rdparty/Pangolin"]
	path = 3rdparty/Pangolin
	url = https://github.com/stevenlovegrove/Pangolin
[submodule "3rdparty/Sophus"]
	path = 3rdparty/Sophus
	url = https://github.com/strasdat/Sophus
[submodule "3rdparty/ceres-solver"]
	path = 3rdparty/ceres-solver
	url = https://github.com/ceres-solver/ceres-solver
[submodule "3rdparty/g2o"]
	path = 3rdparty/g2o
	url = https://github.com/RainerKuemmerle/g2o
[submodule "3rdparty/DBoW3"]
	path = 3rdparty/DBoW3
	url = https://github.com/rmsalinas/DBow3
[submodule "3rdparty/googletest"]
	path = 3rdparty/googletest
	url = https://github.com/google/googletest.git

```

在`https://github`前面加上`https://ghproxy.com/`即可。

```bash
[submodule "3rdparty/Pangolin"]
	path = 3rdparty/Pangolin
	url = https://ghproxy.com/https://github.com/stevenlovegrove/Pangolin
[submodule "3rdparty/Sophus"]
	path = 3rdparty/Sophus
	url = https://ghproxy.com/https://github.com/strasdat/Sophus
[submodule "3rdparty/ceres-solver"]
	path = 3rdparty/ceres-solver
	url = https://ghproxy.com/https://github.com/ceres-solver/ceres-solver
[submodule "3rdparty/g2o"]
	path = 3rdparty/g2o
	url = https://ghproxy.com/https://github.com/RainerKuemmerle/g2o
[submodule "3rdparty/DBoW3"]
	path = 3rdparty/DBoW3
	url = https://ghproxy.com/https://github.com/rmsalinas/DBow3
[submodule "3rdparty/googletest"]
	path = 3rdparty/googletest
	url = https://ghproxy.com/https://github.com/google/googletest.git

```

## 如何添加module

```bash
git submodule add [module urls]
```

例如：
```bash
# 添加本仓库作为submodule
git submodule add https://gitee.com/CPLASF000000/git-notes.git
```

## 如何删除module

```bash
git submodule deinit [module name]
git rm -r [module\'s dir]
```

例如：
```bash
git submodule deinit Git-Notes
git rm -r Git-Notes/
```

然后检查`.gitmodules`是否还有相关信息；
检查`.git/module/`下是否还有相关模块同名的目录

## 如何修改submodule的文件并提交修改

首先我们得知道，submodule在`git submodule update`之后是处于所谓的“游离态”的，这个时候如果对其进行修改即使commit成功了也无法push（push之后comit的内容会不见）
那怎么办呢，如果还没有修改，那么先checkout到工作分支（例如master）之后再进行修改；
如果已经在游离态下修改了，那就直接新建一个branch然后checkout到master进行合并，然后把刚才新建的分支删除就可以了。

```bash
git branch new_branch
git checkout master
git merge new_branch
git branch -d new_branch
```

当处于工作分支上时，submodule可以和单独项目一样push和pull等操作。

## 如何更新submodule

```bash
git submodule update --remote
```

将submodule的修改更新到本项目里。

## 如何处理submodule的冲突

等碰到这种情况的时候再记录。

## 使用module的好处是什么？

如果你直接依赖别人的项目，那么使用module来依赖，别人项目更新的时候不会影响到你这个项目；
你如果更新了module也不会影响到别人的项目。

如果你想用到别人项目的更新，直接更新`git submodule update`就可以了.

灵活依赖只是好处之一，关键还可以给你的项目节省依赖库所需的空间。
