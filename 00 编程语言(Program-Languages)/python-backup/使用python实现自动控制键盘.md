# 使用python实现自动控制键盘

## 参考链接

https://www.cnblogs.com/botoo/p/8302531.html

## 自动控制键盘

```python
from pynput.keyboard import Key, Controller
import time

keyboard = Controller() # 注意要实例化一个Controller对象，括号别漏了

time.sleep(3)

#Press and release space 按下并松开空格
keyboard.press(Key.space)
keyboard.release(Key.space)

#Type a lower case A ;this will work even if no key on the physical keyboard  is labelled 'A' 
#打一个‘a’，这种方法甚至可以在键盘上的A键坏了的时候使用
keyboard.press('a')
keyboard.release('a')

#Type two  upper case As 打两个大写的A
keyboard.press('A')
keyboard.release('A')
# or
# 按住 shift 的同时 敲 a
with keyboard .pressed(Key.shift):
    keyboard.press('a')
    keyboard.release('a')

#type 'hello world '  using the shortcut type  method 敲一个字符串出来
keyboard.type('hello world')
```

## 监听键盘敲击某个键

```python
from pynput import keyboard

def on_press(key):
    try:
        print('alphanumeric key  {0} pressed'.format(key.char))
    except AttributeError:
        print('special key {0} pressed'.format(key))

def on_release(key):
    print('{0} released'.format(key))
    if key == keyboard.Key.esc:
        return False

while True:
    with keyboard.Listener(
        on_press = on_press,
        on_release = on_release) as listener:
        listener.join()
```