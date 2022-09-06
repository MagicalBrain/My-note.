# Linux解压缩zip文件

## 压缩成zip文件

```bash
zip -r Myzip.zip filename
```

## 解压成zip文件

```bash
# 默认解压到一个和压缩包同名的文件夹里
unzip Myzip.zip 
```

```bash
unzip Myzip.zip -d [target_path]
```

解压到你想要的路径下（target_path）
