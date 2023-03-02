# ROS2-launch命令

```bash
ros2 launch -h
usage: ros2 launch [-h] [-d] [-p | -s] [-a]
                   package_name [launch_file_name]
                   [launch_arguments [launch_arguments ...]]

Run a launch file

positional arguments:
  package_name          Name of the ROS package which contains the launch file
  launch_file_name      Name of the launch file
  launch_arguments      Arguments to the launch file; '<name>:=<value>' (for
                        duplicates, last one wins)

optional arguments:
  -h, --help            show this help message and exit
  -d, --debug           Put the launch system in debug mode, provides more
                        verbose output.
  -p, --print, --print-description
                        Print the launch description to the console without
                        launching it.
  -s, --show-args, --show-arguments
                        Show arguments that may be given to the launch file.
  -a, --show-all-subprocesses-output
                        Show all launched subprocesses' output by overriding
                        their output configuration using the
                        OVERRIDE_LAUNCH_PROCESS_OUTPUT envvar.
```
