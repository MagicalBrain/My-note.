# Git如何拉取指定文件夹

## 稀疏检出

**注意**
这种方式必须新建一个本地仓库才能实现。

有时候，公司的代码库十分的臃肿，会把几个项目的代码放在同一个库中，而且公司的主力IDE时visual studio，用过的人都知道，这家伙体积大、占内存多不说，一旦解决方案里的项目一多，那么在跳转代码的时候就会非常慢，而且生成的`.vs`文件夹体积巨大，如果代码有几十M，那么`.vs`文件夹往往会有几个G那么大，太烦了。

为此我常常新建解决方案，然后只把自己需要的项目添加其中，但是这样的话，从git上合并分支就很麻烦，因为，一旦`git merge`就会把其它我不需要的项目给合并过来。十分烦人。

为此我又想了一个办法，那就是每一次`git pull`我只要我要的项目所在文件夹`pull`下来

具体操作如下：

* 设置 `core.sparsecheckout = true`

```bash
git config core.sparsecheckout true
```

* 新建文件 `.git/info/sparse-checkout`

添加你要的文件夹：

```bash
Debug/
```

忽略你不想要的文件夹：

```bash
!/Debug/
```

最后直接`git pull origin master`就可以只`pull`需要的文件夹了。
