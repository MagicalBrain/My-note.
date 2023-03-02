# ROS2的安装、配置和源码获取

## 安装

## 源码获取

### 安装vcstool

```bash
sudo apt-get install python3-vcstool
```

### 获取源码

```bash
mkdir -p ~/ros2_eloquent/src
cd ~/ros2_eloquent
wget https://raw.githubusercontent.com/ros2/ros2/eloquent/ros2.repos
vcs import src < ros2.repos
```

vcs报错：

```bash
vcs import src < ros2.repos
.EEEEEE.EE.EEE.EEEEEEE.EEEEEEEEEEEEE.EEEEEEE.EEEEE.EEE.EEEEEE.EEEEEEEEEEEEE.E.EEEEE.EEEEEEEEEE.
=== src/ament/ament_cmake (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ament/ament_cmake.git/': gnutls_handshake() failed: Error in the pull function.
=== src/ament/ament_index (git) ===
Cloning into '.'...
=== src/ament/ament_lint (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ament/ament_lint.git/': gnutls_handshake() failed: Error in the pull function.
=== src/ament/ament_package (git) ===
Cloning into '.'...
=== src/ament/googletest (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ament/googletest.git/': gnutls_handshake() failed: Error in the pull function.
=== src/ament/uncrustify_vendor (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ament/uncrustify_vendor.git/': gnutls_handshake() failed: Error in the pull function.
=== src/eProsima/Fast-CDR (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/eProsima/Fast-CDR.git/': gnutls_handshake() failed: Error in the pull function.
=== src/eProsima/Fast-DDS (git) ===
Cloning into '.'...
=== src/eProsima/foonathan_memory_vendor (git) ===
Could not clone repository 'https://github.com/eProsima/foonathan_memory_vendor.git': Cloning into '.'...
fatal: unable to access 'https://github.com/eProsima/foonathan_memory_vendor.git/': Failed to connect to github.com port 443: Connection refused
=== src/eclipse-cyclonedds/cyclonedds (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/eclipse-cyclonedds/cyclonedds.git/': gnutls_handshake() failed: Error in the pull function.
=== src/osrf/osrf_pycommon (git) ===
Could not clone repository 'https://github.com/osrf/osrf_pycommon.git': Cloning into '.'...
fatal: unable to access 'https://github.com/osrf/osrf_pycommon.git/': Failed to connect to github.com port 443: Connection refused
=== src/osrf/osrf_testing_tools_cpp (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/osrf/osrf_testing_tools_cpp.git/': gnutls_handshake() failed: Error in the pull function.
=== src/ros-perception/laser_geometry (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros-perception/laser_geometry.git/': gnutls_handshake() failed: Error in the pull function.
=== src/ros-planning/navigation_msgs (git) ===
Cloning into '.'...
=== src/ros-tracing/ros2_tracing (git) ===
Cloning into '.'...
Note: switching to '0.2.12'.

You are in 'detached HEAD' state. You can look around, make experimental
changes and commit them, and you can discard any commits you make in this
state without impacting any branches by switching back to a branch.

If you want to create a new branch to retain commits you create, you may
do so (now or later) by using -c with the switch command. Example:

  git switch -c <new-branch-name>

Or undo this operation with:

  git switch -

Turn off this advice by setting config variable advice.detachedHead to false

HEAD is now at 5cd2298 0.2.12
=== src/ros-visualization/interactive_markers (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros-visualization/interactive_markers.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros-visualization/python_qt_binding (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros-visualization/python_qt_binding.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros-visualization/qt_gui_core (git) ===
Could not clone repository 'https://github.com/ros-visualization/qt_gui_core.git': Cloning into '.'...
fatal: unable to access 'https://github.com/ros-visualization/qt_gui_core.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros-visualization/rqt (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros-visualization/rqt.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros-visualization/rqt_action (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros-visualization/rqt_action.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros-visualization/rqt_console (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros-visualization/rqt_console.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros-visualization/rqt_graph (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros-visualization/rqt_graph.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros-visualization/rqt_msg (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros-visualization/rqt_msg.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros-visualization/rqt_plot (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros-visualization/rqt_plot.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros-visualization/rqt_publisher (git) ===
Cloning into '.'...
=== src/ros-visualization/rqt_py_console (git) ===
Could not clone repository 'https://github.com/ros-visualization/rqt_py_console.git': Cloning into '.'...
fatal: unable to access 'https://github.com/ros-visualization/rqt_py_console.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros-visualization/rqt_reconfigure (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros-visualization/rqt_reconfigure.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros-visualization/rqt_service_caller (git) ===
Could not clone repository 'https://github.com/ros-visualization/rqt_service_caller.git': Cloning into '.'...
fatal: unable to access 'https://github.com/ros-visualization/rqt_service_caller.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros-visualization/rqt_shell (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros-visualization/rqt_shell.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros-visualization/rqt_srv (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros-visualization/rqt_srv.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros-visualization/rqt_top (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros-visualization/rqt_top.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros-visualization/rqt_topic (git) ===
Cloning into '.'...
=== src/ros/class_loader (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros/class_loader.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros/kdl_parser (git) ===
Could not clone repository 'https://github.com/ros/kdl_parser.git': Cloning into '.'...
fatal: unable to access 'https://github.com/ros/kdl_parser.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros/pluginlib (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros/pluginlib.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros/resource_retriever (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros/resource_retriever.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros/robot_state_publisher (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros/robot_state_publisher.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros/ros_environment (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros/ros_environment.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros/ros_tutorials (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros/ros_tutorials.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros/urdfdom (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros/urdfdom.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros/urdfdom_headers (git) ===
Cloning into '.'...
=== src/ros2/ament_cmake_ros (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros2/ament_cmake_ros.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/common_interfaces (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros2/common_interfaces.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/console_bridge_vendor (git) ===
Could not clone repository 'https://github.com/ros2/console_bridge_vendor.git': Cloning into '.'...
fatal: unable to access 'https://github.com/ros2/console_bridge_vendor.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/demos (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros2/demos.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/eigen3_cmake_module (git) ===
Could not clone repository 'https://github.com/ros2/eigen3_cmake_module.git': Cloning into '.'...
fatal: unable to access 'https://github.com/ros2/eigen3_cmake_module.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/example_interfaces (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros2/example_interfaces.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/examples (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros2/examples.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/geometry2 (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros2/geometry2.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/launch (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros2/launch.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/launch_ros (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros2/launch_ros.git/': gnutls_handshake() failed: Error in the pull function.
=== src/ros2/libyaml_vendor (git) ===
Could not clone repository 'https://github.com/ros2/libyaml_vendor.git': Cloning into '.'...
fatal: unable to access 'https://github.com/ros2/libyaml_vendor.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/message_filters (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros2/message_filters.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/orocos_kinematics_dynamics (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros2/orocos_kinematics_dynamics.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/poco_vendor (git) ===
Cloning into '.'...
=== src/ros2/python_cmake_module (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros2/python_cmake_module.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/rcl (git) ===
Cloning into '.'...
=== src/ros2/rcl_interfaces (git) ===
Could not clone repository 'https://github.com/ros2/rcl_interfaces.git': Cloning into '.'...
fatal: unable to access 'https://github.com/ros2/rcl_interfaces.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/rcl_logging (git) ===
Could not clone repository 'https://github.com/ros2/rcl_logging.git': Cloning into '.'...
fatal: unable to access 'https://github.com/ros2/rcl_logging.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/rclcpp (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros2/rclcpp.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/rclpy (git) ===
Cloning into '.'...
=== src/ros2/rcpputils (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros2/rcpputils.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/rcutils (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros2/rcutils.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/realtime_support (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros2/realtime_support.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/rmw (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros2/rmw.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/rmw_connext (git) ===
Could not clone repository 'https://github.com/ros2/rmw_connext.git': Cloning into '.'...
fatal: unable to access 'https://github.com/ros2/rmw_connext.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/rmw_cyclonedds (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros2/rmw_cyclonedds.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/rmw_fastrtps (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros2/rmw_fastrtps.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/rmw_implementation (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros2/rmw_implementation.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/rmw_opensplice (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros2/rmw_opensplice.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/ros1_bridge (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros2/ros1_bridge.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/ros2cli (git) ===
Could not clone repository 'https://github.com/ros2/ros2cli.git': Cloning into '.'...
fatal: unable to access 'https://github.com/ros2/ros2cli.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/ros_testing (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros2/ros_testing.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/rosbag2 (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros2/rosbag2.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/rosidl (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros2/rosidl.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/rosidl_dds (git) ===
Cloning into '.'...
=== src/ros2/rosidl_defaults (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros2/rosidl_defaults.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/rosidl_python (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros2/rosidl_python.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/rosidl_runtime_py (git) ===
Cloning into '.'...
=== src/ros2/rosidl_typesupport (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros2/rosidl_typesupport.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/rosidl_typesupport_connext (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros2/rosidl_typesupport_connext.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/rosidl_typesupport_fastrtps (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros2/rosidl_typesupport_fastrtps.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/rosidl_typesupport_opensplice (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros2/rosidl_typesupport_opensplice.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/rviz (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros2/rviz.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/spdlog_vendor (git) ===
Could not clone repository 'https://github.com/ros2/spdlog_vendor.git': Cloning into '.'...
fatal: unable to access 'https://github.com/ros2/spdlog_vendor.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/sros2 (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros2/sros2.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/system_tests (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros2/system_tests.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/test_interface_files (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros2/test_interface_files.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/tinydir_vendor (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros2/tinydir_vendor.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/tinyxml2_vendor (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros2/tinyxml2_vendor.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/tinyxml_vendor (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros2/tinyxml_vendor.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/tlsf (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros2/tlsf.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/unique_identifier_msgs (git) ===
Cloning into '.'...
=== src/ros2/urdf (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros2/urdf.git/': Failed to connect to github.com port 443: Connection refused
=== src/ros2/yaml_cpp_vendor (git) ===
Could not determine ref type of version: fatal: unable to access 'https://github.com/ros2/yaml_cpp_vendor.git/': Failed to connect to github.com port 443: Connection refused
```

看样子是网络问题，修改ros2.repos:

```
repositories:
  ament/ament_cmake:
    type: git
    url: https://github.com/ament/ament_cmake.git
    version: eloquent
  ament/ament_index:
    type: git
    url: https://github.com/ament/ament_index.git
    version: eloquent
  ament/ament_lint:
    type: git
    url: https://github.com/ament/ament_lint.git
    version: eloquent
  ament/ament_package:
    type: git
    url: https://github.com/ament/ament_package.git
    version: eloquent
  ament/googletest:
    type: git
    url: https://github.com/ament/googletest.git
    version: ros2
  ament/uncrustify_vendor:
    type: git
    url: https://github.com/ament/uncrustify_vendor.git
    version: eloquent
  eclipse-cyclonedds/cyclonedds:
    type: git
    url: https://github.com/eclipse-cyclonedds/cyclonedds.git
    version: releases/0.7.x 
  eProsima/Fast-CDR:
    type: git
    url: https://github.com/eProsima/Fast-CDR.git
    version: v1.0.11
  eProsima/Fast-DDS:
    type: git
    url: https://github.com/eProsima/Fast-DDS.git
    version: ros2-eloquent
  eProsima/foonathan_memory_vendor:
    type: git
    url: https://github.com/eProsima/foonathan_memory_vendor.git
    version: master
  osrf/osrf_pycommon:
    type: git
    url: https://github.com/osrf/osrf_pycommon.git
    version: eloquent
  osrf/osrf_testing_tools_cpp:
    type: git
    url: https://github.com/osrf/osrf_testing_tools_cpp.git
    version: eloquent
  ros-perception/laser_geometry:
    type: git
    url: https://github.com/ros-perception/laser_geometry.git
    version: eloquent
  ros-planning/navigation_msgs:
    type: git
    url: https://github.com/ros-planning/navigation_msgs.git
    version: eloquent
  ros-tracing/ros2_tracing:
    type: git
    url: https://gitlab.com/ros-tracing/ros2_tracing.git
    version: 0.2.12
  ros-visualization/interactive_markers:
    type: git
    url: https://github.com/ros-visualization/interactive_markers.git
    version: eloquent
  ros-visualization/python_qt_binding:
    type: git
    url: https://github.com/ros-visualization/python_qt_binding.git
    version: crystal-devel
  ros-visualization/qt_gui_core:
    type: git
    url: https://github.com/ros-visualization/qt_gui_core.git
    version: crystal-devel
  ros-visualization/rqt:
    type: git
    url: https://github.com/ros-visualization/rqt.git
    version: crystal-devel
  ros-visualization/rqt_action:
    type: git
    url: https://github.com/ros-visualization/rqt_action.git
    version: crystal-devel
  ros-visualization/rqt_console:
    type: git
    url: https://github.com/ros-visualization/rqt_console.git
    version: dashing-devel
  ros-visualization/rqt_graph:
    type: git
    url: https://github.com/ros-visualization/rqt_graph.git
    version: dashing-devel
  ros-visualization/rqt_msg:
    type: git
    url: https://github.com/ros-visualization/rqt_msg.git
    version: crystal-devel
  ros-visualization/rqt_plot:
    type: git
    url: https://github.com/ros-visualization/rqt_plot.git
    version: crystal-devel
  ros-visualization/rqt_publisher:
    type: git
    url: https://github.com/ros-visualization/rqt_publisher.git
    version: dashing-devel
  ros-visualization/rqt_py_console:
    type: git
    url: https://github.com/ros-visualization/rqt_py_console.git
    version: crystal-devel
  ros-visualization/rqt_reconfigure:
    type: git
    url: https://github.com/ros-visualization/rqt_reconfigure.git
    version: dashing
  ros-visualization/rqt_service_caller:
    type: git
    url: https://github.com/ros-visualization/rqt_service_caller.git
    version: crystal-devel
  ros-visualization/rqt_shell:
    type: git
    url: https://github.com/ros-visualization/rqt_shell.git
    version: crystal-devel
  ros-visualization/rqt_srv:
    type: git
    url: https://github.com/ros-visualization/rqt_srv.git
    version: crystal-devel
  ros-visualization/rqt_top:
    type: git
    url: https://github.com/ros-visualization/rqt_top.git
    version: crystal-devel
  ros-visualization/rqt_topic:
    type: git
    url: https://github.com/ros-visualization/rqt_topic.git
    version: dashing-devel
  ros/class_loader:
    type: git
    url: https://github.com/ros/class_loader.git
    version: eloquent
  ros/pluginlib:
    type: git
    url: https://github.com/ros/pluginlib.git
    version: eloquent
  ros/kdl_parser:
    type: git
    url: https://github.com/ros/kdl_parser.git
    version: eloquent
  ros/resource_retriever:
    type: git
    url: https://github.com/ros/resource_retriever.git
    version: eloquent
  ros/robot_state_publisher:
    type: git
    url: https://github.com/ros/robot_state_publisher.git
    version: eloquent
  ros/ros_environment:
    type: git
    url: https://github.com/ros/ros_environment.git
    version: eloquent
  ros/ros_tutorials:
    type: git
    url: https://github.com/ros/ros_tutorials.git
    version: eloquent-devel
  ros/urdfdom_headers:
    type: git
    url: https://github.com/ros/urdfdom_headers.git
    version: eloquent
  ros/urdfdom:
    type: git
    url: https://github.com/ros/urdfdom.git
    version: eloquent
  ros2/ament_cmake_ros:
    type: git
    url: https://github.com/ros2/ament_cmake_ros.git
    version: eloquent
  ros2/common_interfaces:
    type: git
    url: https://github.com/ros2/common_interfaces.git
    version: eloquent
  ros2/console_bridge_vendor:
    type: git
    url: https://github.com/ros2/console_bridge_vendor.git
    version: eloquent
  ros2/demos:
    type: git
    url: https://github.com/ros2/demos.git
    version: eloquent
  ros2/eigen3_cmake_module:
    type: git
    url: https://github.com/ros2/eigen3_cmake_module.git
    version: eloquent
  ros2/example_interfaces:
    type: git
    url: https://github.com/ros2/example_interfaces.git
    version: eloquent
  ros2/examples:
    type: git
    url: https://github.com/ros2/examples.git
    version: eloquent
  ros2/geometry2:
    type: git
    url: https://github.com/ros2/geometry2.git
    version: eloquent
  ros2/launch:
    type: git
    url: https://github.com/ros2/launch.git
    version: eloquent
  ros2/launch_ros:
    type: git
    url: https://github.com/ros2/launch_ros.git
    version: eloquent
  ros2/libyaml_vendor:
    type: git
    url: https://github.com/ros2/libyaml_vendor.git
    version: eloquent
  ros2/message_filters:
    type: git
    url: https://github.com/ros2/message_filters.git
    version: eloquent
  ros2/orocos_kinematics_dynamics:
    type: git
    url: https://github.com/ros2/orocos_kinematics_dynamics.git
    version: eloquent
  ros2/poco_vendor:
    type: git
    url: https://github.com/ros2/poco_vendor.git
    version: eloquent
  ros2/python_cmake_module:
    type: git
    url: https://github.com/ros2/python_cmake_module.git
    version: eloquent
  ros2/rcl:
    type: git
    url: https://github.com/ros2/rcl.git
    version: eloquent
  ros2/rcl_interfaces:
    type: git
    url: https://github.com/ros2/rcl_interfaces.git
    version: eloquent
  ros2/rcl_logging:
    type: git
    url: https://github.com/ros2/rcl_logging.git
    version: eloquent
  ros2/rclcpp:
    type: git
    url: https://github.com/ros2/rclcpp.git
    version: eloquent
  ros2/rclpy:
    type: git
    url: https://github.com/ros2/rclpy.git
    version: eloquent
  ros2/rcpputils:
    type: git
    url: https://github.com/ros2/rcpputils.git
    version: eloquent
  ros2/rcutils:
    type: git
    url: https://github.com/ros2/rcutils.git
    version: eloquent
  ros2/realtime_support:
    type: git
    url: https://github.com/ros2/realtime_support.git
    version: eloquent
  ros2/rmw:
    type: git
    url: https://github.com/ros2/rmw.git
    version: eloquent
  ros2/rmw_connext:
    type: git
    url: https://github.com/ros2/rmw_connext.git
    version: eloquent
  ros2/rmw_cyclonedds:
    type: git
    url: https://github.com/ros2/rmw_cyclonedds.git
    version: dashing-eloquent
  ros2/rmw_fastrtps:
    type: git
    url: https://github.com/ros2/rmw_fastrtps.git
    version: eloquent
  ros2/rmw_implementation:
    type: git
    url: https://github.com/ros2/rmw_implementation.git
    version: eloquent
  ros2/rmw_opensplice:
    type: git
    url: https://github.com/ros2/rmw_opensplice.git
    version: eloquent
  ros2/ros1_bridge:
    type: git
    url: https://github.com/ros2/ros1_bridge.git
    version: eloquent
  ros2/ros2cli:
    type: git
    url: https://github.com/ros2/ros2cli.git
    version: eloquent
  ros2/ros_testing:
    type: git
    url: https://github.com/ros2/ros_testing.git
    version: eloquent
  ros2/rosbag2:
    type: git
    url: https://github.com/ros2/rosbag2.git
    version: eloquent
  ros2/rosidl:
    type: git
    url: https://github.com/ros2/rosidl.git
    version: eloquent
  ros2/rosidl_dds:
    type: git
    url: https://github.com/ros2/rosidl_dds.git
    version: eloquent
  ros2/rosidl_defaults:
    type: git
    url: https://github.com/ros2/rosidl_defaults.git
    version: eloquent
  ros2/rosidl_python:
    type: git
    url: https://github.com/ros2/rosidl_python.git
    version: eloquent
  ros2/rosidl_runtime_py:
    type: git
    url: https://github.com/ros2/rosidl_runtime_py.git
    version: eloquent
  ros2/rosidl_typesupport:
    type: git
    url: https://github.com/ros2/rosidl_typesupport.git
    version: eloquent
  ros2/rosidl_typesupport_connext:
    type: git
    url: https://github.com/ros2/rosidl_typesupport_connext.git
    version: eloquent
  ros2/rosidl_typesupport_fastrtps:
    type: git
    url: https://github.com/ros2/rosidl_typesupport_fastrtps.git
    version: eloquent
  ros2/rosidl_typesupport_opensplice:
    type: git
    url: https://github.com/ros2/rosidl_typesupport_opensplice.git
    version: eloquent
  ros2/rviz:
    type: git
    url: https://github.com/ros2/rviz.git
    version: eloquent
  ros2/spdlog_vendor:
    type: git
    url: https://github.com/ros2/spdlog_vendor.git
    version: eloquent
  ros2/sros2:
    type: git
    url: https://github.com/ros2/sros2.git
    version: eloquent
  ros2/system_tests:
    type: git
    url: https://github.com/ros2/system_tests.git
    version: eloquent
  ros2/test_interface_files:
    type: git
    url: https://github.com/ros2/test_interface_files.git
    version: eloquent
  ros2/tinydir_vendor:
    type: git
    url: https://github.com/ros2/tinydir_vendor.git
    version: eloquent
  ros2/tinyxml2_vendor:
    type: git
    url: https://github.com/ros2/tinyxml2_vendor.git
    version: eloquent
  ros2/tinyxml_vendor:
    type: git
    url: https://github.com/ros2/tinyxml_vendor.git
    version: eloquent
  ros2/tlsf:
    type: git
    url: https://github.com/ros2/tlsf.git
    version: eloquent
  ros2/unique_identifier_msgs:
    type: git
    url: https://github.com/ros2/unique_identifier_msgs.git
    version: eloquent
  ros2/urdf:
    type: git
    url: https://github.com/ros2/urdf.git
    version: eloquent
  ros2/yaml_cpp_vendor:
    type: git
    url: https://github.com/ros2/yaml_cpp_vendor.git
    version: eloquent
```
