# ROS2-topic命令

管理并查看当前ros2中运行的topic（会话？）

详细信息：

```bash
ros2 topic -h
usage: ros2 topic [-h] [--include-hidden-topics]
                  Call `ros2 topic <command> -h` for more detailed usage. ...

Various topic related sub-commands

optional arguments:
  -h, --help            show this help message and exit
  --include-hidden-topics
                        Consider hidden topics as well

Commands:
  bw     Display bandwidth used by topic
  delay  Display delay of topic from timestamp in header
  echo   Output messages from a topic
  find   Output a list of available topics of a given type
  hz     Print the average publishing rate to screen
  info   Print information about a topic
  list   Output a list of available topics
  pub    Publish a message to a topic
  type   Print a topic's type

  Call `ros2 topic <command> -h` for more detailed usage.
```

## topic info

查看topic的相关信息

```bash
ros2 topic info [topic_name]
```

## topic list

列出所有的topic

```bash
ros2 topic list
```

## topic pub

直接发布topic指令

## topic type

## topic bw

## topic delay

## topic echo

## topic find

## topic hz

