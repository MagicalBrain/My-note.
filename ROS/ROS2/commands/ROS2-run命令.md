# ROS2-run命令

想要运行ROS2中某个节点，我们可以使用ros2 run命令进行操作，例如我们要运行海龟仿真节点和键盘控制节点：

```bash
ros2 run turtlesim turtlesim_node
ros2 run turtlesim turtle_teleop_key
```

~~注意：这两个命令须在不同的终端里运行，且turtlesim_node须在GUI桌面下的终端运行~~

## run详解

详细信息：

```bash
ros2 run -h
usage: ros2 run [-h] [--prefix PREFIX] package_name executable_name ...

Run a package specific executable

positional arguments:
  package_name     Name of the ROS package
  executable_name  Name of the executable
  argv             Pass arbitrary arguments to the executable

optional arguments:
  -h, --help       show this help message and exit
  --prefix PREFIX  Prefix command, which should go before the executable.
                   Command must be wrapped in quotes if it contains spaces
                   (e.g. --prefix 'gdb -ex run --args').
```

**必须要有的参数**
1. package_name
2. executable_name
3. argv

**可选参数**
1. -h，--help：
2. --prefix FREFIX

