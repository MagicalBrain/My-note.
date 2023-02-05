# 使用python实现控制鼠标

## 控制鼠标

```python
from  pynput.mouse import Button, Controller
import time

mouse = Controller()
print(mouse.position)
time.sleep(3)
print('The current pointer position is {0}'.format(mouse.position))


#set pointer positon
mouse.position = (277, 645)
print('now we have moved it to {0}'.format(mouse.position))

#鼠标移动（x,y）个距离
mouse.move(5, -5)
print(mouse.position)

mouse.press(Button.left)
mouse.release(Button.left)

#Double click
mouse.click(Button.left, 1)

#scroll two  steps down
mouse.scroll(0, 500)
```

## 监听鼠标事件

```python

```