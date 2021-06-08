# pcl库的安装

## win10

## Linux系统

https://blog.csdn.net/mystyle_/article/details/109827365

以Ubuntu 18.04为例

```
cmake -DCMAKE_BUILD_TYPE=None -DCMAKE_INSTALL_PREFIX=/usr \ -DBUILD_GPU=ON-DBUILD_apps=ON -DBUILD_examples=ON \ -DCMAKE_INSTALL_PREFIX=/usr ..
```