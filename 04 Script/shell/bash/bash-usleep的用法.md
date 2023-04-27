# bash-usleep的用法

sleep无法休眠比秒还小的时间单位，而毫秒又比较常用；
就只能用usleep来实现休眠毫秒了

## 自己实现的usleep

## 在使用sleep的时候使用小数

```bash
sleep 0.1
```

这不就是相当于`usleep 100`了吗
