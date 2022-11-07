# Git如何上传大文件到Github

目前貌似只支持Github，Gitee如果要上传大文件，需要额外收费。

**注意**：
github大文件的免费容量只有1GB，所以如果超过了的话，还是早日歇了吧。

注意：
为了确保成功，以下步骤注意顺序不要乱，尤其是上传`.gitattribute`和文件的顺序不能乱。

### 新建仓库并初始化

```bash
mkdir mycode && cd mycode
git init
```

## 安装git lfs

```bash
git lfs install
```

## lfs追踪大文件

```bash
git lfs track "*.pptx"  # 设置你要上传的大文件的文件类型
git add .gitattribute
git commit -m "upload .gitattribute"
```

## 链接远程仓库并上传.gitattribute

```bash
git remote add origin url
git push origin master  # 先把之前commit的.gitattribute上传
```

## 添加要上传的大文件

```bash
git add *.pptx
git commit -m "upload *pptx"
git push origin master
```

## 克隆lfs仓库

```bash
git lfs clone [url:http or ssh]
```

尽管这样可以大大提升在Windows上的性能，但是依然很慢。
