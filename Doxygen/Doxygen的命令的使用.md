# Doxygen的命令的使用

## 控制代码注释

### brief

```cpp
/// @brief 创建并初始化一个伯朗特机器人对象
```

### detail

```cpp
/// @brief     远程发送要运动的点位loc (mm) 寄存器地址800给borunte
/// @details   以绝对坐标直线运动方式运动
```

### param


### return

```cpp
/// @brief 	获取borunte机器人当前世界坐标
/// @details   默认是法兰盘中心坐标 borunte工具端标定在机器人控制器内
/// @param loc 
/// @param type 
/// @return 
virtual int pose(std::vector<double>& loc, int type = hy::ROBOT_POSE_TCP) override;
```

## 控制文档生成

### mainpage

## 参考链接

https://blog.csdn.net/archielau/article/details/9203075
