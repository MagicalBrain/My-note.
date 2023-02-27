# package 功能包

## 功能包的作用

## 创建功能包

使用ros2 pkg create命令创建功能包

```bash
ros2 pkg create --build-type ament-cmake [your package name]
```

关于pkg命令可以查看[笔记](./../commands/ROS2-pkg命令.md)

## 编译功能包

```bash
colcon build --packages-select [your package name]
```


