# WebSocket网络通信协议

WebSocket协议是用于解决HTTP通信的无状态、短连接（通常是）和服务端无法主动向客户端推送数据等问题而开发的新型协议，其通信基础也基于 TCP。

由于较旧的浏览器可能不支持WebSocket协议，所以使用WebSocket协议的通信双方在进行 TCP三次握手之后，还要额外地进行一次握手，这次参与握手的通信双方的报文格式是基于HTTP改造的。

报文格式如下：

```bash
GET /realtime HTTP/1.1\r\n
Host: 127.0.0.1:9989\r\n
Connection: Upgrade\r\n
Pragma: no-cache\r\n
Cache-Control: no-cache\r\r
User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64)\r\n
Upgrade: websocket\r\r
Origin: http://xyz.com\r\n
Sec-WebSocket-Version: 13\r\n
Accept-Encoding: gzip, deflate, br\r\n
ccept-Language: zh-CN, zh;q-0.9, en;q=0. 8\r\n
sec-webSocket-Key: IqcAWodjyPDJuhGgZwkpKg==\r\n
Sec-Websocket-Extensions: permessage-deflate; client max window bits\r\n \r\n
```
