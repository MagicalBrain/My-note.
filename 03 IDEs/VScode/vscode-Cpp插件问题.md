<!--
 * @Author: hrl_jxzx_pc_u22 374870361@qq.com
 * @Date: 2023-08-09 08:51:24
 * @LastEditors: hrl_jxzx_pc_u22 374870361@qq.com
 * @LastEditTime: 2023-10-13 11:03:29
 * @FilePath: /Notes/MyNotes/03 IDEs/VScode/vscode-Cpp插件问题.md
 * @Description: 
-->
# vscode-Cpp插件问题

## 无法使用go to definition等功能

在Ubuntu 20中使用微软官方的Cpp插件套装，安装后无法使用go to definition等功能

解决办法：
重启vscode
重启电脑

## outline显示不完整

在Ubuntu 20中使用微软官方的Cpp插件套装，开发ros2相关项目，然后cpp文件对应的outlie显示不完整

解决办法：
1. 删除`colcon build`生成的build相关文件夹
2. 重命名cpp文件后再删除build相关文件夹直到outline信息出现
