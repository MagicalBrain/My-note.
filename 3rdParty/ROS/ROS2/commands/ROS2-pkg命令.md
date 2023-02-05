# ROS2-pkg命令

```bash
ros2 pkg -h
usage: ros2 pkg [-h] Call `ros2 pkg <command> -h` for more detailed usage. ...

Various package related sub-commands

optional arguments:
  -h, --help            show this help message and exit

Commands:
  create       Create a new ROS2 package
  executables  Output a list of package specific executables
  list         Output a list of available packages
  prefix       Output the prefix path of a package
  xml          Output the XML of the package manifest or a specific tag

  Call `ros2 pkg <command> -h` for more detailed usage.
```

## pkg create

```bash
ros2 pkg create -h
usage: ros2 pkg create [-h] [--package-format {2,3}]
                       [--description DESCRIPTION] [--license LICENSE]
                       [--destination-directory DESTINATION_DIRECTORY]
                       [--build-type {cmake,ament_cmake,ament_python}]
                       [--dependencies DEPENDENCIES [DEPENDENCIES ...]]
                       [--maintainer-email MAINTAINER_EMAIL]
                       [--maintainer-name MAINTAINER_NAME]
                       [--node-name NODE_NAME] [--library-name LIBRARY_NAME]
                       package_name

Create a new ROS2 package

positional arguments:
  package_name          The package name

optional arguments:
  -h, --help            show this help message and exit
  --package-format {2,3}, --package_format {2,3}
                        The package.xml format.
  --description DESCRIPTION
                        The description given in the package.xml
  --license LICENSE     The license attached to this package
  --destination-directory DESTINATION_DIRECTORY
                        Directory where to create the package directory
  --build-type {cmake,ament_cmake,ament_python}
                        The build type to process the package with
  --dependencies DEPENDENCIES [DEPENDENCIES ...]
                        list of dependencies
  --maintainer-email MAINTAINER_EMAIL
                        email address of the maintainer of this package
  --maintainer-name MAINTAINER_NAME
                        name of the maintainer of this package
  --node-name NODE_NAME
                        name of the empty executable
  --library-name LIBRARY_NAME
                        name of the empty library
```

### 创建一个功能包

```bash
ros2 pkg create --build-type <build-type> <package_name>
```

* `--build-type`参数后面跟的是 编译类型
  * ament_cmake
  * ament_python
* 

例如：

```bash
# 这里cd到工作空间的目录
cd ~/dev_ws/src
# 创建一个C++功能包
ros2 pkg create --build-type ament_cmake learning_pkg_c               # C++
# 创建一个python功能包
ros2 pkg create --build-type ament_python learning_pkg_python         # Python
```

## pkg executables

## pkg list

## pkg prefix

## pkg xml
