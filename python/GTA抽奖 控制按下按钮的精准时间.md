# GTA抽奖 控制按下按钮的精准时间

```python
from pynput import keyboard
from pynput.keyboard import Controller
import time

key0 = Controller()

def on_press(key):
    try:
        print('alphanumeric key  {0} pressed'.format(key.char))
    except AttributeError:
        print('special key {0} pressed'.format(key))

def on_release(key):
    print('{0} released'.format(key))
    if key == keyboard.Key.enter:
        return False

with key0.pressed(keyboard.Key.alt):
    key0.press(keyboard.Key.tab)
    key0.release(keyboard.Key.tab)

with keyboard.Listener(
        on_press=on_press,
        on_release=on_release) as listener:
        listener.join()

time.sleep(4)
key0.press('s')
key0.release('s')
print("输入结束")

```