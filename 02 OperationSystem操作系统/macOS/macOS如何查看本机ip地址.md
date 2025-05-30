# macOS如何查看本机ip地址

我来介绍在 macOS 中使用命令行查看 IP 地址的几种主要方法：

1. 使用 `ifconfig` 命令：
```bash
ifconfig | grep "inet "
```
这会显示所有网络接口的 IPv4 地址。其中：
- `en0` 通常是 Wi-Fi 接口
- `lo0` 是本地回环地址（localhost）
- `en1` 可能是有线网络接口

2. 使用 `ipconfig` 命令：
```bash
# 获取 Wi-Fi 接口的 IP 地址
ipconfig getifaddr en0

# 获取有线网络接口的 IP 地址
ipconfig getifaddr en1
```

3. 使用 `networksetup` 命令：
```bash
# 查看 Wi-Fi IP 地址
networksetup -getinfo Wi-Fi

# 列出所有网络服务
networksetup -listallnetworkservices
```

4. 使用 `netstat` 命令：
```bash
netstat -nr | grep default
```
这会显示默认网关信息。

最常用和推荐的方法是使用 `ifconfig` 或 `ipconfig getifaddr en0`，因为：
- `ifconfig` 可以一次性查看所有网络接口的信息
- `ipconfig getifaddr en0` 直接显示 Wi-Fi 的 IP 地址，输出简洁明了

注意：
- 如果您连接的是 Wi-Fi，通常使用 `en0`
- 如果您使用有线网络，可能需要查看 `en1` 或其他接口
- `127.0.0.1` 是本地回环地址，不是您的实际 IP 地址

