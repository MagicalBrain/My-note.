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

## 使用module的好处是什么？

如果你直接依赖别人的项目，那么使用module来依赖，别人项目更新的时候不会影响到你这个项目；
如果你想用到别人项目的更新，直接更新`git submodule update`就可以了.

灵活依赖只是好处之一，关键还可以给你的项目节省空间。
