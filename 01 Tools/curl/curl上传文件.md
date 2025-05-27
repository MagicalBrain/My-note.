# curl上传文件

## 上传当前目录的文件

```bash
curl -X POST http://localhost:8080/upload \
> > -F "file=@testUpload.txt"
```

## 指定目录的文件

例如我想上传 `D:\hrl\MyProject\MyQtProjects\Qt-Projects\Qt-Examples-Demo\Feature\Qt-HotUpdate-Demos\Demo00\package-2.0.zip`

```bash
curl -X POST http://localhost:8080/upload \
-F "file=@D:/hrl/MyProject/MyQtProjects/Qt-Projects/Qt-Examples-Demo/Feature/Qt-HotUpdate-Demos/Demo00/package-2.0.zip"
```

## 其它上传用法

### 1. 基本选项说明

- `-X POST`: 指定HTTP方法为POST
- `-F`: 使用multipart/form-data格式上传
- `-H`: 添加HTTP头
- `-v`: 显示详细信息
- `-i`: 显示响应头
- `-o`: 将输出保存到文件
- `-O`: 使用远程文件名保存
- `-C -`: 断点续传
- `--progress-bar`: 显示进度条

### 2. 上传单个文件

```bash
# 基本用法
curl -X POST http://localhost:8080/upload -F "file=@test.txt"

# 指定文件名
curl -X POST http://localhost:8080/upload -F "file=@test.txt;filename=custom.txt"

# 指定Content-Type
curl -X POST http://localhost:8080/upload -F "file=@test.txt;type=text/plain"
```

### 3. 上传多个文件

```bash
# 上传多个文件
curl -X POST http://localhost:8080/upload \
-F "file1=@test1.txt" \
-F "file2=@test2.txt"

# 使用数组形式上传多个文件
curl -X POST http://localhost:8080/upload \
-F "files[]=@test1.txt" \
-F "files[]=@test2.txt"
```

### 4. 添加额外参数

```bash
# 添加请求头
curl -X POST http://localhost:8080/upload \
-H "Authorization: Bearer token123" \
-F "file=@test.txt"

# 添加其他表单字段
curl -X POST http://localhost:8080/upload \
-F "file=@test.txt" \
-F "description=这是一个测试文件" \
-F "type=document"
```

### 5. 显示详细信息

```bash
# 显示详细请求和响应信息
curl -v -X POST http://localhost:8080/upload \
-F "file=@test.txt"

# 显示进度条
curl --progress-bar -X POST http://localhost:8080/upload \
-F "file=@test.txt"
```

### 6. 断点续传

```bash
# 支持断点续传的上传
curl -C - -X POST http://localhost:8080/upload \
-F "file=@large_file.zip"
```

### 7. 使用代理

```bash
# 使用HTTP代理
curl -x http://proxy.example.com:8080 \
-X POST http://localhost:8080/upload \
-F "file=@test.txt"

# 使用SOCKS5代理
curl --socks5 proxy.example.com:1080 \
-X POST http://localhost:8080/upload \
-F "file=@test.txt"
```

### 8. 处理响应

```bash
# 将响应保存到文件
curl -X POST http://localhost:8080/upload \
-F "file=@test.txt" \
-o response.txt

# 显示响应头
curl -i -X POST http://localhost:8080/upload \
-F "file=@test.txt"
```

### 9. 安全相关

```bash
# 忽略SSL证书验证
curl -k -X POST https://localhost:8080/upload \
-F "file=@test.txt"

# 使用客户端证书
curl --cert client.crt --key client.key \
-X POST https://localhost:8080/upload \
-F "file=@test.txt"
```

### 10. 超时设置

```bash
# 设置连接超时和传输超时
curl --connect-timeout 10 --max-time 300 \
-X POST http://localhost:8080/upload \
-F "file=@test.txt"
```

注意事项：
1. Windows系统中路径使用正斜杠`/`而不是反斜杠`\`
2. 文件名中包含空格时需要用引号括起来
3. 上传大文件时建议使用`--progress-bar`显示进度
4. 使用`-v`参数可以帮助调试上传问题
5. 如果服务器有特殊要求，注意查看响应信息进行调整
