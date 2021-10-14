# websocketpp简易教程（待验证）

## websocket_endpoint

提供 server 功能的 `websocketpp::server` 和提供 client 功能的 `websocketpp:client` 都继承自基类 `websocketpp::endpoint` , endpoint提供了一些通用的功能函数：

```cpp
void set_access_channels(log::level channels);//设置日志级别
void clear_access_channels(log::level channels)//屏蔽某个级别的日志

void set_open_handler(open_handler h)；//设置打开连接时的回调函数
void set_close_handler(close_handler h)；//设置关闭连接时的回调函数
void set_fail_handler(fail_handler h)；//设置连接失败时的回调函数
void set_message_handler(message_handler h)；//设置收到消息时的回调函数
```

## 服务器代码

```cpp
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

#include <functional>

typedef websocketpp::server<websocketpp::config::asio> server;

class utility_server {
public:
    utility_server() {
         // 设置log
        m_endpoint.set_error_channels(websocketpp::log::elevel::all);
        m_endpoint.set_access_channels(websocketpp::log::alevel::all ^ websocketpp::log::alevel::frame_payload);

        // 初始化Asio
        m_endpoint.init_asio();

        // 设置消息回调为echo_handler
        m_endpoint.set_message_handler(std::bind(
            &utility_server::echo_handler, this,
            std::placeholders::_1, std::placeholders::_2
        ));
    }

    void echo_handler(websocketpp::connection_hdl hdl, server::message_ptr msg) {
        // 发送消息
        m_endpoint.send(hdl, msg->get_payload(), msg->get_opcode());
    }

    void run() {
        // 监听端口 9002
        m_endpoint.listen(9002);

       
        m_endpoint.start_accept();

        // 开始Asio事件循环
        m_endpoint.run();
    }
private:
    server m_endpoint;
};

int main() {
    utility_server s;
    s.run();
    return 0;
}
```

运行后执行到 s.run() 当前线程会进入Asio的消息循环，可以调用s.top()退出

## 客户端代码

```cpp
#include <websocketpp/config/asio_no_tls_client.hpp>
#include <websocketpp/client.hpp>
#include <iostream>

typedef websocketpp::client<websocketpp::config::asio_client> client;

using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;

typedef websocketpp::config::asio_client::message_type::ptr message_ptr;

void on_open(client *c, websocketpp::connection_hdl hdl)
{
    std::string msg = "hello";
    c->send(hdl, msg, websocketpp::frame::opcode::text);
    c->get_alog().write(websocketpp::log::alevel::app, "Tx: " + msg);
}

void on_message(client *c, websocketpp::connection_hdl hdl, message_ptr msg)
{
    std::cout << "on_message called with hdl: " << hdl.lock().get()
              << " and message: " << msg->get_payload()
              << std::endl;
    websocketpp::lib::error_code ec;
    //c->send(hdl,msg->get_payload(),msg->get_opcode(),ec);
    if(ec)
    {
        std::cout << "Echo failed because " << ec.message() << std::endl;
    }
}

//定时器回调函数
void Timeout(client *c, websocketpp::connection_hdl &hdl, boost::asio::deadline_timer *pt, const boost::system::error_code &ec)
{
    if(ec)
    {
        std::cout << "timer is cancel " << std::endl;
        return;
    }
    static int count = 0;
    c->send(hdl, "hello", websocketpp::frame::opcode::text);
    count++;
    if(count > 5)//定时器触发五次后关闭连接
    {
        c->close(hdl, websocketpp::close::status::normal, "");
        return;
    }
    pt->expires_at(pt->expires_at() + boost::posix_time::seconds(5));
    pt->async_wait(bind(Timeout, c, hdl, pt, ::_1));

}

int main(int argc, char *argv[])
{
    client c;

    std::string uri = "ws://xx.xx.xx.xx:xxx";

    c.set_access_channels(websocketpp::log::alevel::all);
    c.clear_access_channels(websocketpp::log::alevel::frame_payload);
    c.clear_access_channels(websocketpp::log::alevel::frame_header);

    // 初始化 ASIO
    c.init_asio();

    // 注册消息回调

    c.set_message_handler(bind(&on_message, &c, ::_1, ::_2));
    c.set_open_handler(bind(&on_open, &c, _1));

    websocketpp::lib::error_code ec;
    client::connection_ptr con = c.get_connection(uri, ec);
    con->add_subprotocol("janus-protocol");
    if(ec)
    {
        std::cout << "could not create connection because: " << ec.message() << std::endl;
        return 0;
    }

    auto hdl = con->get_handle();
    c.connect(con);
    
    boost::asio::deadline_timer t(c.get_io_service(), boost::posix_time::seconds(5)); //设置一个5s超时的定时器
    t.async_wait(bind(&Timeout, &c, hdl, &t, ::_1));

    std::thread th([&c] { c.run(); });
   
    //休眠13s后取消定时器并关闭连接
    sleep(13);
    t.cancel();
    c.close(hdl, websocketpp::close::status::normal, "");
    
    th.join();
}
```

我们可以利用 Asio 的一些其它组件，如定时器等；初始化定时器传入 c.get_io_service() 在一个io循环中处理定时事件和其它事件
当客户端调用 close 关闭连接时，则自动退出c.run()开启的循环

## 重复关闭和打开连接

```cpp
#include <websocketpp/config/asio_no_tls_client.hpp>
#include <websocketpp/client.hpp>
#include <iostream>

typedef websocketpp::client<websocketpp::config::asio_client> client;

using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;

typedef websocketpp::config::asio_client::message_type::ptr message_ptr;
class connection
{
public:

  void on_open(websocketpp::connection_hdl hdl)
  {
      std::string msg = "hello";
      c.send(hdl, msg, websocketpp::frame::opcode::text);
      c.get_alog().write(websocketpp::log::alevel::app, "Tx: " + msg);
  }

  void on_message(websocketpp::connection_hdl hdl, message_ptr msg)
  {
      std::cout << "on_message called with hdl: " << hdl.lock().get()
                << " and message: " << msg->get_payload()
                << std::endl;
      websocketpp::lib::error_code ec;
      if(ec)
      {
          std::cout << "Echo failed because " << ec.message() << std::endl;
      }
  }

  int init()
  {
      uri = "ws://xx.xx.xx.xx:xx";

      c.set_access_channels(websocketpp::log::alevel::all);
      c.clear_access_channels(websocketpp::log::alevel::frame_payload);
      c.clear_access_channels(websocketpp::log::alevel::frame_header);

      c.init_asio();


      c.set_message_handler(websocketpp::lib::bind(&connection::on_message, this,::_1, ::_2));
      c.set_open_handler(websocketpp::lib::bind(&connection::on_open, this, _1));

      c.start_perpetual();
      thread_=websocketpp::lib::make_shared<websocketpp::lib::thread>(&client::run,&c);

  }

  void connect()
  {
      websocketpp::lib::error_code ec;
      client::connection_ptr con = c.get_connection(uri, ec);
      if(ec)
      {
          std::cout << "could not create connection because: " << ec.message() << std::endl;
          return ;
      }

      hdl_ = con->get_handle();
      c.connect(con);

  }
  void close()
  {
      c.close(hdl_, websocketpp::close::status::normal, "");
  }

  void terminate()
  {
      c.stop_perpetual();
      thread_->join();
  }
private:
  client c;
  websocketpp::lib::shared_ptr<websocketpp::lib::thread> thread_;
  websocketpp::connection_hdl hdl_;
  std::string uri;

};
```

需要重复打开关闭连接时，只调用一次init_asio()函数，然后调用start_perpetual()将endpoint设置为永久的，不会在连接断开时自动退出。需要结束循环，调用stop_perpetual()

## 参考链接

https://www.cnblogs.com/luckydml/p/11867319.html
