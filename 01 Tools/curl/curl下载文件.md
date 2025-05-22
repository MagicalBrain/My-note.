# curl下载文件

http://yun.ihnnk.com:8084/v1/api/log/download?path=/data/hncloud/log/20250520/att_win_cplasf_20250520_101623957.zip

```bash
curl -L -# -o att_win_cplasf_20250520_101623957.zip "http://yun.ihnnk.com:8084/v1/api/log/download?path=/data/hncloud/log/20250520/att_win_cplasf_20250520_101623957.zip"
```

参数说明：
- `-L`: 跟随重定向。如果服务器返回重定向响应，curl会自动跟随重定向到新的URL
- `-#`: 显示下载进度条
- `-o`: 指定输出文件名。这里将文件保存为 att_win_cplasf_20250520_101623957.zip
- 最后的URL用引号包围，因为URL中包含特殊字符（如?和=）
