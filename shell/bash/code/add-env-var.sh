#! /bin/bash

# 添加环境变量
sudo echo "export MYSDK_ROOT=$HOME/MySDK" >> ~/.bashrc
sudo echo "export EIGEN_ROOT=/usr/include/eigen3" >> ~/.bashrc

# 立即生效
source ~/.bashrc
