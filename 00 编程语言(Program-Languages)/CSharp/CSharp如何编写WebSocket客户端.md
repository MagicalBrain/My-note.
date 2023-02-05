# CSharp如何编写WebSocket客户端


1、
https://blog.csdn.net/D_lunar/article/details/120054686

```CSharp
using System.Net.WebSockets;
private ClientWebSocket webSocket = new ClientWebSocket();
private static String SocketPath = "ws://xxx.x.x.x:8085";
[HttpPost]
public async Task<IHttpActionResult> ReportInfo(){
     try
       {
          if (webSocket.State != WebSocketState.Open)
           {
             //连接服务器,如果远程服务器未开启，这句话会报错：无法连接到远程服务器
             await webSocket.ConnectAsync(new Uri(SocketPath), CancellationToken.None);                                                                                                    
            }
            //上报对象转为json字符串;
            string SendJson = JsonConvert.SerializeObject(ReportInfos); 
            //发送的数据
            var sendBytes = Encoding.UTF8.GetBytes("WebApiJson:" + SendJson);
            var bsend = new ArraySegment<byte>(sendBytes);
            //发送信息
            await webSocket.SendAsync(bsend, WebSocketMessageType.Text, true, CancellationToken.None);
            //关闭连接
             if (webSocket.State == WebSocketState.Open)
             {
                  await webSocket.CloseAsync(WebSocketCloseStatus.NormalClosure, "1", CancellationToken.None);//关闭连接
             }
        }
      catch (Exception ex)
        {
          messageinfo.code = 2;
          messageinfo.msg = ex.Message;
        }
      finally
        {
          webSocket.Dispose();
        }
}
```

用不了

2、https://blog.csdn.net/Qin066/article/details/84971890

```csharp
readonly ClientWebSocket _webSocket = new ClientWebSocket();
        readonly CancellationToken _cancellation = new CancellationToken();

        public async void WebSocket() {
            try {
                //建立连接
                var url = "ws://121.40.165.18:8800";

                await _webSocket.ConnectAsync(new Uri(url), _cancellation);

                var bsend = new byte[1024];

                await _webSocket.SendAsync(new ArraySegment<byte>(bsend), WebSocketMessageType.Binary, true, _cancellation); //发送数据

                while (true) {
                    var result = new byte[1024];

                    await _webSocket.ReceiveAsync(new ArraySegment<byte>(result), new CancellationToken());//接受数据

                    var lastbyte = ByteCut(result, 0x00);

                    var str = Encoding.UTF8.GetString(lastbyte, 0, lastbyte.Length);

                }

            } catch (Exception ex) {
                Console.WriteLine(ex.Message);
            }
        }
```

