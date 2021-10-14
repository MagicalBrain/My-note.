[toc]

# 客户端应用实例

## 第一章：初始化和安装

设置基本类型、打开和关闭连接、发送和接收消息。

### Step 1 一个基本的循环程序

一个基本的循环程序，提示用户输入命令，然后对其进行处理。在本教程中，我们将修改这个程序，以便通过WebSocket连接从远程服务器执行任务和检索数据。

#### Build 

使用clang++来编译`step1.cpp`：

```bash
clang++ step1.cpp
```

#### 代码

**注意**：在git存储库中，本教程文件旁边有每个步骤的代码快照。

假设我们目前只写了这么几行代码：

```cpp
#include <iostream>
#include <string>

int main() {
    bool done = false;
    std::string input;

    while (!done) {
        std::cout << "Enter Command: ";
        std::getline(std::cin, input);

        if (input == "quit") {
            done = true;
        } else if (input == "help") {
            std::cout
                << "\nCommand List:\n"
                << "help: Display this help text\n"
                << "quit: Exit the program\n"
                << std::endl;
        } else {
            std::cout << "Unrecognized Command" << std::endl;
        }
    }

    return 0;
}
```

可见这仅仅是一个简单的循环程序。

### Step 2 添加WebSocket++包含文件（头文件）并设置终端类型

添加WebSocket++包含文件（头文件）并设置终端类型。

WebSocket++包括两种主要的对象类型。终端和连接。终端创建并启动新的连接，并维护这些连接的默认设置。终端还管理任何共享的网络资源。

连接存储每个WebSocket会话特定的信息。

**注意**：
一旦连接启动，终端和连接之间就没有链接了。终端将所有默认设置复制到新连接中。更改终端上的默认设置只会影响将来的连接（只会影响后面新建的连接）。
连接不会维护与其相关联终端的链接。终端不维护未完成连接的列表。如果您的应用程序需要遍历所有连接，那么它本身就需要维护它们的列表。

WebSocket++终端是通过结合终端所承担的角色（所起的作用）和终端配置来构建的。有两种不同类型的终端角色，分别用于WebSocket会话中的客户端和服务器角色。这是一个客户端教程，所以我们将使用客户端角色`websocketpp::client`，它由`<websocketpp/client.hpp>`头文件提供。

> ##### 术语:终端配置
> WebSocket++终端有一组可以在编译时通过`config`模板参数配置的设置。配置是一个包含类型和静态常量的结构体，用于生成具有特定属性的终端。根据使用的配置，终端将有不同的可用方法，并可能有额外的第三方依赖。

#### Build

添加WebSocket++给我们的程序添加了一些必须在构建系统中解决的依赖项。首先，WebSocket++和Boost库头文件必须在构建系统的include搜索路径中。这取决于你在哪里安装了WebSocket++头文件，以及你使用的是什么构建系统。

除了新的头文件，boost::asio还依赖于`boost_system`共享库。这需要添加(静态或动态)到链接器。有关链接到共享库的说明，请参阅构建环境文档。

使用clang++来编译`step2.cpp`：

```bash
clang++_step2.cpp -lboost_system
```

#### Code so far

现在的代码为：

```cpp
//添加了websocketpp的依赖 头文件
#include <websocketpp/config/asio_no_tls_client.hpp>
#include <websocketpp/client.hpp>

#include <iostream>
#include <string>

//定义了终端类型 client
typedef websocketpp::client<websocketpp::config::asio_client> client;

int main() {
    bool done = false;
    std::string input;

    while (!done) {
        std::cout << "Enter Command: ";
        std::getline(std::cin, input);

        if (input == "quit") {
            done = true;
        } else if (input == "help") {
            std::cout
                << "\nCommand List:\n"
                << "help: Display this help text\n"
                << "quit: Exit the program\n"
                << std::endl;
        } else {
            std::cout << "Unrecognized Command" << std::endl;
        }
    }

    return 0;
}
```

### Step 3 创建处理初始化和设置后台线程的终端包装器对象

创建处理初始化和设置后台线程的终端包装器对象。

为了在后台进行网络处理时处理用户输入，我们将为WebSocket++处理循环使用一个单独的线程。这使得主线程可以自由处理前台用户输入。为了为我们的线程和终端启用简单的RAII风格的资源管理，我们将使用包装器对象，在其构造函数中配置它们。

> ##### 术语：websocketpp::lib namespace websocketpp::lib 命名空间
> WebSocket++被设计成与c++ 11标准库一起使用。由于这在流行的构建系统中并不是普遍可用的，Boost库可以作为c++ 98构建环境中c++ 11标准库的补充。`websocketpp::lib`命名空间由库及其相关示例使用，以抽象两者之间的区别。`websocketpp::lib::shared_ptr`在c++ 11环境中将被计算为`std::shared_ptr`，否则将被计算为`boost::shared_ptr`。
>
> 本教程使用`websocketpp::lib`包装器，因为它不知道读者的构建环境是什么。对于您的应用程序，除非您对类似的可移植性感兴趣，否则可以直接使用这些类型的boost或std版本。

[TODO: link to more information about logging]

```cpp
//清除访问日志
m_endpoint.clear_access_channels(websocketpp::log::alevel::all);
//清除错误日志
m_endpoint.clear_error_channels(websocketpp::log::elevel::all);
```

接下来，我们初始化终端基础的传输系统，并将其设置为永久模式。在永久模式下，终端的处理循环在没有连接时不会自动退出。这很重要，因为我们希望这个终端在我们的应用程序运行时保持活动状态，并在我们需要时按需处理新WebSocket连接的请求。这两种方法都是asio传输所特有的。它们在使用非asio配置的终端中是不必要的，也不存在的。


```cpp
//初始化 基于asio的传输系统
m_endpoint.init_asio();
//以 永久模式 启动
m_endpoint.start_perpetual();
```

最后，我们启动一个线程来运行客户端终端的`run`方法。当终端运行时，它将处理连接任务(读取和传递传入消息、帧和发送传出消息等)。因为它是在永久模式下运行的，当没有活动的连接时，它将一直等待下一个新的连接。

```cpp
//启动一个线程来运行run方法
m_thread.reset(new websocketpp::lib::thread(&client::run, &m_endpoint));
```

#### Build

现在我们的客户端终端模板已经实际实例化了，将会出现更多的连接器依赖项。特别是，WebSocket客户端需要一个加密安全的随机数生成器。WebSocket++可以使用`boost_random`或c++ 11标准库`<random>`来实现这个目的。`<random>`因为这个例子也使用了线程，如果我们没有c++ 11 `std::thread`可用，我们将需要包含`boost_thread`。

##### Clang (C++98 & boost)

使用clang++来编译`step2.cpp`

```bash
clang++ step3.cpp -lboost_system -lboost_random -lboost_thread
```

##### Clang (C++11)

```bash
clang++ -std=c++0x -stdlib=libc++ step3.cpp -lboost_system -D_WEBSOCKETPP_CPP11_STL_
```

##### G++ (C++98 & Boost)

```bash
g++ step3.cpp -lboost_system -lboost_random -lboost_thread
```

##### G++ v4.6+ (C++11)

```bash
g++ -std=c++0x step3.cpp -lboost_system -D_WEBSOCKETPP_CPP11_STL_
```

#### Code so far

目前的代码
```cpp
#include <websocketpp/config/asio_no_tls_client.hpp>
#include <websocketpp/client.hpp>

#include <websocketpp/common/thread.hpp>
#include <websocketpp/common/memory.hpp>

#include <iostream>
#include <string>

typedef websocketpp::client<websocketpp::config::asio_client> client;

class websocket_endpoint {
public:
    websocket_endpoint () {
        m_endpoint.clear_access_channels(websocketpp::log::alevel::all);
        m_endpoint.clear_error_channels(websocketpp::log::elevel::all);

        m_endpoint.init_asio();
        m_endpoint.start_perpetual();

        m_thread.reset(new websocketpp::lib::thread(&client::run, &m_endpoint));
    }
private:
    client m_endpoint;
    websocketpp::lib::shared_ptr<websocketpp::lib::thread> m_thread;
};

int main() {
    bool done = false;
    std::string input;
    websocket_endpoint endpoint;

    while (!done) {
        std::cout << "Enter Command: ";
        std::getline(std::cin, input);

        if (input == "quit") {
            done = true;
        } else if (input == "help") {
            std::cout
                << "\nCommand List:\n"
                << "help: Display this help text\n"
                << "quit: Exit the program\n"
                << std::endl;
        } else {
            std::cout << "Unrecognized Command" << std::endl;
        }
    }

    return 0;
}
```

### Step 4 打开websocket连接

打开websocket连接

这个步骤向utility_client添加了两个新命令。令其有了打开新连接的能力和查看关于以前打开的连接的信息的能力。每个打开的连接都将被分配一个整数连接id，程序的用户可以使用该id与该连接进行交互。

#### New Connection Metadata Object 新建连接元数据对象

为了跟踪关于每个连接的信息，定义了一个`connection_metadata`对象。该对象存储数字连接id和一些将在处理连接时填充的字段。最初，这包括连接的状态(打开、打开、失败、关闭等)、连接到的原始URI、来自服务器的标识值，以及连接失败/关闭原因的描述。后续步骤将向此元数据对象添加更多信息。

#### Update `websocket_endpoint` 

更新了`websocket_endpoint`

`websocket_endpoint`对象获得了一些新的数据成员和方法。它现在跟踪连接ID和关联元数据之间的映射，以及要分发的下一个顺序ID号。`connect()`方法启动一个新的连接。`get_metadata`方法获取给定ID的元数据。

#### The connect method `connect()`方法

一个新的WebSocket连接是通过三个步骤启动的。首先，连接请求由`endpoint::get_connection(uri)`创建。接下来，配置连接请求。最后，通过`endpoint::connect()`将连接请求提交回终端，将其添加到要建立的新连接队列中。

> ##### Terminology `connection_ptr`
> WebSocket++使用一个引用计数的共享指针来跟踪与连接相关的资源。这个指针的类型是`endpoint::connection_ptr`。`connection_ptr`允许直接访问有关连接的信息，并允许更改连接设置。由于这种直接访问和它们在库中的内部资源管理角色，终端应用程序使用`connection_ptr`是不安全的，除非在下面详细说明的特定情况下。
> 
> **何时使用`connection_ptr`是安全的？**
> - 在`endpoint::get_connection(…)`之后和`endpoint::connect()`之前:
> `get_connection`返回一个`connection_ptr`。使用此指针配置新连接是安全的。一旦你提交连接到`connect`，你可能不再使用`connection_ptr`，应该立即丢弃它，以优化内存管理。
> - 在处理程序期间:
> WebSocket++允许你为在连接的生命周期内发生的特定事件注册钩子/回调/事件处理程序。在调用这些处理程序中的一个时，库保证对与当前运行的处理程序相关联的连接使用`connection_ptr`是安全的。

> ##### 术语 `connection_hdl`
> 由于`connection_ptr`的线程安全性有限，库还提供了一个更灵活的连接标识符`connection_hdl`。`connection_hdl`有类型`websocketpp::connection_hdl`，它在`<websocketpp/common/connection_hdl.hpp>`中定义。注意，与`connection_ptr`不同，它不依赖于终端的类型或配置。简单地存储或传输`connection_hdl`但不使用它们的代码可以只包含上面的头文件，并可以把它的hdl当作值。

----

@import "./websocketpp-client-sample.md"
