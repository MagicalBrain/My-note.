# Python的time模块

标签（空格分隔）： Python

---

在机器学习中，常常需要对模型训练过程进行计时，可以使用time模块

## time函数
```python
import time #导入模块

time0 = time.time()
'''
程序主体部分
'''

# 输出时间
print("The Time consume is:",time.time()-time)
```

示例：
输出延时五秒后的时间
```python
import time

time0 = time.time()
time.sleep(5) #延时五秒

print("The Time consume is:",time.time()-time0)
```

输出：
![image_1ch3hc78q1ic1cbu2dnvau8f9.png-5.7kB][1]


  [1]: http://static.zybuluo.com/Arbalest-Laevatain/vudg2hey6cf71a3htgtvt0j9/image_1ch3hc78q1ic1cbu2dnvau8f9.png