# curl发送Post请求

假设api：

http://10.10.56.30:19080/sleep/webuser/user/register

发送数据：

```json
{
  "captchaId": "string",
  "captchaText": "string",
  "from": "string",
  "password": "hrl001",
  "userName": "hrl001"
}
```

## curl发送POST请求的方法

### 1. 基本POST请求

```bash
curl -X POST \
  -H "Content-Type: application/json" \
  -d '{
    "captchaId": "string",
    "captchaText": "string",
    "from": "string",
    "password": "hrl001",
    "userName": "hrl001"
  }' \
  http://10.10.56.30:19080/sleep/webuser/user/register
```

### 2. 使用JSON文件发送数据

首先创建数据文件 `data.json`：

```json
{
  "captchaId": "string",
  "captchaText": "string",
  "from": "string",
  "password": "hrl001",
  "userName": "hrl001"
}
```

然后使用文件发送：

```bash
curl -X POST \
  -H "Content-Type: application/json" \
  -d @data.json \
  http://10.10.56.30:19080/sleep/webuser/user/register
```

### 3. 添加更多headers的完整示例

```bash
curl -X POST \
  -H "Content-Type: application/json" \
  -H "Accept: application/json" \
  -H "User-Agent: curl/7.68.0" \
  -d '{
    "captchaId": "string",
    "captchaText": "string",
    "from": "string",
    "password": "hrl001",
    "userName": "hrl001"
  }' \
  http://10.10.56.30:19080/sleep/webuser/user/register
```

### 4. 保存响应到文件

```bash
curl -X POST \
  -H "Content-Type: application/json" \
  -d '{
    "captchaId": "string",
    "captchaText": "string",
    "from": "string",
    "password": "hrl001",
    "userName": "hrl001"
  }' \
  -o response.json \
  http://10.10.56.30:19080/sleep/webuser/user/register
```

### 5. 显示详细信息（调试用）

```bash
curl -X POST \
  -H "Content-Type: application/json" \
  -d '{
    "captchaId": "string",
    "captchaText": "string",
    "from": "string",
    "password": "hrl001",
    "userName": "hrl001"
  }' \
  -v \
  http://10.10.56.30:19080/sleep/webuser/user/register
```

## 参数说明

- `-X POST`: 指定HTTP方法为POST
- `-H "Content-Type: application/json"`: 设置请求头，指定发送的是JSON数据
- `-d`: 指定要发送的数据
- `@data.json`: 从文件读取数据（注意@符号）
- `-o response.json`: 将响应保存到文件
- `-v`: 显示详细信息，包括请求和响应头
