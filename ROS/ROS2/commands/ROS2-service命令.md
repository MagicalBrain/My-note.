# ROS2-service命令

实现服务调用？

详细信息：

```bash
ros2 service -h
usage: ros2 service [-h] [--include-hidden-services]
                    Call `ros2 service <command> -h` for more detailed usage.
                    ...

Various service related sub-commands

optional arguments:
  -h, --help            show this help message and exit
  --include-hidden-services
                        Consider hidden services as well

Commands:
  call  Call a service
  find  Output a list of available services of a given type
  list  Output a list of available services
  type  Output a service's type

  Call `ros2 service <command> -h` for more detailed usage.
```

## service call

服务调用

```bash
ros2 service call -h
usage: ros2 service call [-h] [-r N] service_name service_type [values]

Call a service

positional arguments:
  service_name    Name of the ROS service to call to (e.g. '/add_two_ints')
  service_type    Type of the ROS service (e.g. 'std_srvs/srv/Empty')
  values          Values to fill the service request with in YAML format (e.g.
                  "{a: 1, b: 2}"), otherwise the service request will be
                  published with default values

optional arguments:
  -h, --help      show this help message and exit
  -r N, --rate N  Repeat the call at a specific rate in Hz
```

## service find

寻找服务

```bash
ros2 service find -h
usage: ros2 service find [-h] [-c] [--include-hidden-services] service_type

Output a list of available services of a given type

positional arguments:
  service_type          Name of the ROS service type to filter for (e.g.
                        'rcl_interfaces/srv/ListParameters')

optional arguments:
  -h, --help            show this help message and exit
  -c, --count-services  Only display the number of services discovered
  --include-hidden-services
                        Consider hidden services as well
```

## service list

列出服务

```bash
usage: ros2 service list [-h] [--spin-time SPIN_TIME] [-t] [-c]

Output a list of available services

optional arguments:
  -h, --help            show this help message and exit
  --spin-time SPIN_TIME
                        Spin time in seconds to wait for discovery (only
                        applies when not using an already running daemon)
  -t, --show-types      Additionally show the service type
  -c, --count-services  Only display the number of services discovered
```

## service type

服务类型

```bash
ros2 service type -h
usage: ros2 service type [-h] service_name

# Output a service's type

positional arguments:
  service_name  Name of the ROS service to get type (e.g.'/talker/list_parameters')

optional arguments:
  -h, --help    show this help message and exit
```
