# ROS2-node命令

管理和查看ros2当前的节点

详细信息：

```bash
ros2 node -h

usage: ros2 node [-h]
                 Call `ros2 node <command> -h` for more detailed usage. ...

Various node related sub-commands

optional arguments:
  -h, --help            show this help message and exit

Commands:
  info  Output information about a node
  list  Output a list of available nodes

  Call `ros2 node <command> -h` for more detailed usage.
```

## node info

```bash
ros2 node info -h
usage: ros2 node info [-h] [--spin-time SPIN_TIME] [--include-hidden]
                      node_name

Output information about a node

positional arguments:
  node_name             Node name to request information

optional arguments:
  -h, --help            show this help message and exit
  --spin-time SPIN_TIME
                        Spin time in seconds to wait for discovery (only
                        applies when not using an already running daemon)
  --include-hidden      Display hidden topics, services, and actions as well
```

## node list

```bash
ros2 node list -h
usage: ros2 node list [-h] [--spin-time SPIN_TIME] [-a] [-c]

Output a list of available nodes

optional arguments:
  -h, --help            show this help message and exit
  --spin-time SPIN_TIME
                        Spin time in seconds to wait for discovery (only
                        applies when not using an already running daemon)
  -a, --all             Display all nodes even hidden ones
  -c, --count-nodes     Only display the number of nodes discovered
```
