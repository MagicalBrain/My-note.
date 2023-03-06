# ROS2-param命令

## ros2 param list

列出所有param参数

## ros2 param get

获取param的值

## ros2 param describe

获取param的描述信息

## ros2 param set

设置param的值

## ros2 param dump

将param导出到YAML文件

## ros2 param delete

## param命令详解

```bash
ros2 param -h
usage: ros2 param [-h]
                  Call `ros2 param <command> -h` for more detailed usage. ...

Various param related sub-commands

optional arguments:
  -h, --help            show this help message and exit

Commands:
  delete    Delete parameter
  describe  Show descriptive information about declared parameters
  dump      Dump the parameters of a node to a yaml file
  get       Get parameter
  list      Output a list of available parameters
  set       Set parameter

  Call `ros2 param <command> -h` for more detailed usage.
```

## ros2 param list 详解

列出所有param参数

## ros2 param get 详解

获取param的值

## ros2 param describe 详解

获取param的描述信息

## ros2 param set 详解

设置param的值

```bash
ros2 param set -h
usage: ros2 param set [-h] [--spin-time SPIN_TIME] [--include-hidden-nodes]
                      node_name parameter_name value

Set parameter

positional arguments:
  node_name             Name of the ROS node
  parameter_name        Name of the parameter
  value                 Value of the parameter

optional arguments:
  -h, --help            show this help message and exit
  --spin-time SPIN_TIME
                        Spin time in seconds to wait for discovery (only
                        applies when not using an already running daemon)
  --include-hidden-nodes
                        Consider hidden nodes as well
```

## ros2 param dump 详解

将param导出到YAML文件

```bash
ros2 param dump -h
usage: ros2 param dump [-h] [--spin-time SPIN_TIME] [--include-hidden-nodes]
                       [--output-dir OUTPUT_DIR] [--print]
                       node_name

Dump the parameters of a node to a yaml file

positional arguments:
  node_name             Name of the ROS node

optional arguments:
  -h, --help            show this help message and exit
  --spin-time SPIN_TIME
                        Spin time in seconds to wait for discovery (only
                        applies when not using an already running daemon)
  --include-hidden-nodes
                        Consider hidden nodes as well
  --output-dir OUTPUT_DIR
                        The absolute path were to save the generated file
  --print               Print generated file in terminal rather than saving a
                        file.
                        ros2 param dump -h
usage: ros2 param dump [-h] [--spin-time SPIN_TIME] [--include-hidden-nodes]
                       [--output-dir OUTPUT_DIR] [--print]
                       node_name

Dump the parameters of a node to a yaml file

positional arguments:
  node_name             Name of the ROS node

optional arguments:
  -h, --help            show this help message and exit
  --spin-time SPIN_TIME
                        Spin time in seconds to wait for discovery (only
                        applies when not using an already running daemon)
  --include-hidden-nodes
                        Consider hidden nodes as well
  --output-dir OUTPUT_DIR
                        The absolute path were to save the generated file
  --print               Print generated file in terminal rather than saving a
                        file.
```

## ros2 param delete 详解
