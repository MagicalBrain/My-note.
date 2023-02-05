# 微信机器人聊天

标签（空格分隔）： Python 微信机器人

---

## 安装wxpy

安装wxpy非常简单，如果你拥有pip，请直接按照Github中的方法安装：

从 PYPI 官方源下载安装 (在国内可能比较慢或不稳定):

pip3 install -U wxpy

从豆瓣 PYPI 镜像源下载安装 (推荐国内用户选用):

pip install -U wxpy -i "https://pypi.doubanio.com/simple/"

登录微信

wxpy 使用起来非常简单，我们只需要创建一个bot 对象，程序运行后，会弹出二维码，扫描二维码后显示登陆成功。为了能自动保存信息，不需要每次扫码，只需要设置cache_path=True. 同时在项目文件夹下，多了一个wxpy.pkl文件。

```python
from wxpy import *

#在初始化时便会执行登陆操作，需要手机扫描登陆。

bot = Bot()

#自动保存登录信息，就不需要每次扫二维码

bot = Bot(cache_path=True)
```
以下为代码输出


## 给别人发送信息

给自己发送“我爱你“

```python

# 在Web微信中把自己加为好友

bot.self.add()

bot.self.accept()

# 发送消息给自己

bot.self.send(" 520，我爱你!")
```

## 指定聊天对象，大胆聊天表白吧

在这么特殊的一天，你可以使用聊天机器人指定某个人进行聊天，大胆说出自己平常不敢说的话。即使他/她给你回复了，你不好意思回复他。机器人可以帮你自动回复。如何实在不好意思和她聊天，也可以忽略，不用自动回复。

比如，找到微信昵称或者备注为”冯彬“的好友，然后对他说，“亲，在干嘛呢”。并且自动回复 “嗯，收到你的消息了”。

```python

#指定聊天对象，并发送你想说的话

#还可以发送图片，视频，文件或者动图等。可以试一下

my_friend = bot.friends().search('冯彬')[0]

#found = ensure_one(my_friend) //确保找到的是唯一，避免重复

my_friend.send("亲，在干嘛呢")

#如何指定聊天回复你了，聊天机器人自动回复设置好的消息。

@bot.register(my_friend)

def reply_my_friend(msg):

    return '{} ，收到你的消息了'.format(msg.text, msg.type)

```

## 指定聊天对象，聊天机器人拒绝回复他的消息
```python
ignore_friend = bot.friends().search('冯彬')[0]

@bot.register(ignore_friend)

def ignore(msg):

    return
```

## 参考
http://wxpy.readthedocs.io/zh/latest/index.html

## 安装下载信息
```
Stored in directory: C:\Users\37487\AppData\Local\pip\Cache\wheels\11\a7\31\277fb9d25f7bed35d2775774489121cefd401307fa83356fe2
  Running setup.py bdist_wheel for future ... done
  Stored in directory: C:\Users\37487\AppData\Local\pip\Cache\wheels\4d\3f\bf\83c3f96bc34fec191e991f932849e27dcc028e949c67d1d837
  Running setup.py bdist_wheel for pyqrcode ... done
  Stored in directory: C:\Users\37487\AppData\Local\pip\Cache\wheels\de\84\89\5a1acb90a1c686a8f4cd295b4472a2c06310ecd58d94833318
  Running setup.py bdist_wheel for pypng ... done
  Stored in directory: C:\Users\37487\AppData\Local\pip\Cache\wheels\e2\a4\37\259acf34b6972d4f24a8cc9f807762abf5f387035716d89cb5
Successfully built wxpy future pyqrcode pypng
Installing collected packages: pyqrcode, urllib3, idna, certifi, requests, pypng, itchat, future, wxpy
  Found existing installation: idna 2.6
    Uninstalling idna-2.6:
      Successfully uninstalled idna-2.6
  Found existing installation: requests 2.14.2
    Uninstalling requests-2.14.2:
      Successfully uninstalled requests-2.14.2
Successfully installed certifi-2018.11.29 future-0.17.1 idna-2.8 itchat-1.2.32 pypng-0.0.18 pyqrcode-1.2.1 requests-2.21.0 urllib3-1.24.1 wxpy-0.3.9.8
```

## 示例代码
```python
from wxpy import *

#在初始化时便会执行登陆操作，需要手机扫描登陆。

#bot = Bot()

#自动保存登录信息，就不需要每次扫二维码

bot = Bot(cache_path=True)



# 发送消息给自己

friends = bot.friends().search('燕彦')[0]

print(friends)

friends.send('你好呀！！')

@bot.register(friends)

def reply_my_friend(msg):
    #print(msg)
    return '我是黄瑞霖'.format(msg.text, msg.type)


embed()
'''
myself = bot.self
bot.file_helper.send('Hello from wxpy!')

myself.add()
myself.accept()

myself.send(" 520，我爱你!")
'''



```