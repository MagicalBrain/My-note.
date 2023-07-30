# 在vscode中配置cpp开发环境

主要是四个文件

## c_cpp_properties.json

主要是配置cpp的环境变量，头文件路径……

配置路径的时候使用环境变量`${env:Name}`

```json
{
  "configurations": [
      {
          "name": "Linux",
          "includePath": [
              "${workspaceFolder}/**",
              "${env:HOME}/ros2_ws/install/robot_localization/include/**",
              "${env:HOME}/ros2_ws/install/openslam_gmapping/include/**",
              "/opt/ros/${env:ROS_DISTRO}/include/**",
              "${env:HOME}/cuda_ros2_ws/src/ros2_cuda_learning/ament_cmake_packages/cuda_ament_cmake/include/**",
              "${env:HOME}/cuda_ros2_ws/src/ros2_cuda_learning/Sensor/pwc-angstrong/include/**",
              "${env:HOME}/cuda_ros2_ws/src/ros2_cuda_learning/Sensor/pwc-realsense/include/**",
              "include/**",
              "/usr/include/**"
          ],
          "defines": [],
          "compilerPath": "/usr/bin/gcc",
          "cStandard": "c99",
          "cppStandard": "c++14",
          "intelliSenseMode": "clang-x64"
      }
  ],
  "version": 4
}
```

https://code.visualstudio.com/docs/cpp/c-cpp-properties-schema-reference

## tasks.json

主要是配置编译器的

## launch.json

主要是配置debug的

## setting.json

主要是配置缩进，字符编码等

## 参考链接

https://code.visualstudio.com/docs/languages/cpp
https://code.visualstudio.com/docs/cpp/customize-default-settings-cpp
https://code.visualstudio.com/docs/cpp/c-cpp-properties-schema-reference
