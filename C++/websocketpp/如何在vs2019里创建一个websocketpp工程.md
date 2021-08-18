# 如何在vs2019里创建一个websocketpp工程

Hi StasToken,
I've been through the same nightmare. Even though the steps, once you know them, seem easy and logical, getting to them is not easy, at least it wasn't for me because there are many concepts involved and most of them were new for me. I needed to create a Websocket server to add functionality to a legacy C++ MFC app.

我也经历过同样的噩梦。即使你第一次看见这些步骤，觉得很容易和有逻辑，但要做到它们并不容易，至少对我来说是这样，因为其中涉及到许多概念，其中大部分对我来说是新的。我需要创建一个Websocket服务器来为遗留的c++ MFC应用程序添加功能。

First, you need to install boost and openSSL:
Boost from https://www.boost.org/users/history/version_1_76_0.html
openSSL from https://github.com/openssl/openssl.
And of course you need to git clone the websocketpp somewhere (let's assume you have it in F:\websocketpp).

首先你需要安装boost和openSSL：
Boost from https://www.boost.org/users/history/version_1_76_0.html
openSSL from https://github.com/openssl/openssl.
当然，你还需要使用git将websocketpp克隆到本地的某个地方，假设你将websocket克隆到 F:\websocketpp

Once that is done, you should go through the following steps:
这些一旦完成，你应该进行接下来的步骤：

Create an empty VS2019 solution. I created mine in the "examples" folder of the websocketpp main folder (git clone).
Manually add a new empty project named "EchoServer".

创建一个空的VS2019解决方案。我是在(git克隆的)websocketpp主文件夹的“examples”文件夹中创建的。然后手动添加一个名为“EchoServer”的新空项目。

Add to the "Source Files" filter in that project the files "echo_handler.hpp" and "echo_server.cpp" which are in folder "examples/echo_server".

将echo_handler.hpp和echo_server.cpp添加到该项目的“源文件”过滤器中，这两个文件位于“examples/echo_server”文件夹中。

Assuming your main websocketpp folder is F:\websocketpp, then right-click on the project EchoServer in the Solution Explorer and select "Properties".

假设你的主websocketpp文件夹是F:\websocketpp，然后右键单击解决方案资源管理器中的EchoServer项目，选择“属性”。

Under Configuration Properties->General, make sure that "C++ Language Standard" is set to ISO C++17 Standard. It should also work with the default C++ 14, but just in case.

在“Configuration Properties -> General”中，确保“c++ Language Standard”设置为“ISO c++ 17 Standard”。它也应该适用于默认的c++ 14，但只是以防万一。

Under C/C++->General->Additional Include Directories, manually add (for "All Configurations" and "All Platforms"):
-F:\websocketpp (where subfolder websocketpp contains the websocketpp headers)
-your boost root folder (for instance C:\boost\boost_1_76_0)

在C/C++->General->Additional Include Directories里，手动添加 
1. F:\websocketpp  (其中的子文件夹websocketpp包含 websocketpp的头文件)
2. 你的boost安装的根目录（例如 C:\boost\boost_1_76_0）

Under C/C++->Code Generation, ensure the Runtime Library is multi-threaded (DLL or static depending on what you built for boost)

在C/C++->Code Generation，确保运行库是多线程的（DLL或静态，这取决于为boost构建的内容）

Under Linker->General->Additional Library Directories, manually add:
-your boost lib folder (for instance C:\boost\boost_1_76_0\stage_lib)
-your openSSL lib folder (that depends on how and where you've arranged your openSSL. There could be separate folders for debug, release, x86 and x64 versions).

在链接器->常规->附加库目录，手动添加：
1. 你的boost的lib文件夹（例如 C:\boost\boost_1_76_0\stage_lib）
2. 你的openSSL的lib文件夹（这取决于你是如何安排你的openSSL的。可以有单独的文件夹用于调试、发布、x86和x64版本）

Under Linker->Input->Additional Dependencies, manually add:
libcrypto.lib;libssl.lib;libcrypto64MTd.lib;libssl64MTd.lib; (for 64-bit debug), or
libcrypto.lib;libssl.lib;libcrypto64MT.lib;libssl64MT.lib; (for 64-bit release), or
libcrypto.lib;libssl.lib;libcrypto32MTd.lib;libssl32MTd.lib; (for 32-bit debug), or
libcrypto.lib;libssl.lib;libcrypto32MT.lib;libssl32MT.lib; (for 32-bit release), etc.

在 链接器->输入->附加依赖，手动添加：
libcrypto.lib;libssl.lib;libcrypto64MTd.lib;libssl64MTd.lib; (对应64位 debug), or
libcrypto.lib;libssl.lib;libcrypto64MT.lib;libssl64MT.lib; (for 64-bit release), or
libcrypto.lib;libssl.lib;libcrypto32MTd.lib;libssl32MTd.lib; (for 32-bit debug), or
libcrypto.lib;libssl.lib;libcrypto32MT.lib;libssl32MT.lib; (for 32-bit release), etc.

After all that is done, you should be able to build the EchoServer project with VS2019 as usual and run it normally. I use the Chrome extension WebSocket King Client, although probably any other websocket client will work.

完成所有这些之后，您应该能够像往常一样使用VS2019构建EchoServer项目并正常运行它。我使用Chrome扩展WebSocket国王客户端，尽管可能任何其他WebSocket客户端都可以工作。

Repeat steps 1 to 9 for those examples in the "examples" folder that you would like to build, to have a project for each one.
I am right now trying to find out why the TLS projects(echo_server_both and echo_server_tls) always send an error "handle_transport_init received error: sslv3 alert certificate unknown". I have used the .pem files that come with the library, and also generated my own ones with openssl, but still no success (testing with Chrome additions WebSocket King Client and Simple WebSocket Client, both generate the same error). If you know or find how to solve this, I will appreciate.

对于您想要构建的“examples”文件夹中的示例，重复步骤1到9，为每个示例创建一个项目。
我现在试图找出为什么TLS项目(echo_server_both和echo_server_tls)总是发送一个错误“handle_transport_init received error: sslv3 alert certificate unknown”。我使用了库自带的.pem文件，也用openssl生成了我自己的文件，但仍然没有成功(测试Chrome插件WebSocket国王客户端和简单的WebSocket客户端，都产生了相同的错误)。如果你知道或找到如何解决这个问题，我会很感激。

Update: Found the problem in the last paragraph: the library will not accept a self-signed certificate (the ones you can create directly in your own PC using OpenSSL or the Windows utilities). There is no way around it. You must have a valid, authority-validated and endorsed certificate. You can get such certificate from https://zerossl.com/. The site has detailed instructions on how to request, obtain and install a certificate.

更新:在最后一段中发现了问题:库不接受自签名证书(可以使用OpenSSL或Windows实用程序在自己的PC中直接创建的证书)。没有别的办法。您必须有一个有效的、经过授权验证和认可的证书。你可以从https://zerossl.com/上获得这样的证书。该网站有关于如何请求、获取和安装证书的详细说明。

## 对于官方的tuition里遇到的问题

server：
将以下代码注释即可：
```cpp
//#define ASIO_STANDALONE
```
