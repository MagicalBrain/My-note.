# ssh的常见问题及解决

## client_loop: send disconnect: Broken pipe

这个通常就是网络问题

端口未开放
DNS缓存被污染


## client_loop: send disconnect: Connection reset by peer

这个问题可能有多种原因造成。

04/19/2022:
我是在幻13上运行HYInspect客户端有线连接gpu；
同时通过有线ssh远程连接gpu

而后我ssh远程连接gpu改走WiFi发现就没有这个问题了。
