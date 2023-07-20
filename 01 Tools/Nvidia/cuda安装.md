# nvidia cuda的安装

## windows

## WSL2

[我自己的WSL2安装cuda笔记](../../02%20OperationSystem%E6%93%8D%E4%BD%9C%E7%B3%BB%E7%BB%9F/Linux/WSL/WSL%E5%A6%82%E4%BD%95%E5%AE%89%E8%A3%85Cuda.md)

## Linux

### ubuntu18

### ubuntu20

### ubuntu22

cuda在Ubuntu22上能装的最低版本是11.7：

```bash
wget https://developer.download.nvidia.com/compute/cuda/11.7.1/local_installers/cuda_11.7.1_515.65.01_linux.run
sudo sh cuda_11.7.1_515.65.01_linux.run
```

*这两个命令就在官网的下载界面可以找到*

```bash
===========
= Summary =
===========

Driver:   Not Selected
Toolkit:  Installed in /usr/local/cuda-11.7/

Please make sure that
 -   PATH includes /usr/local/cuda-11.7/bin
 -   LD_LIBRARY_PATH includes /usr/local/cuda-11.7/lib64, or, add /usr/local/cuda-11.7/lib64 to /etc/ld.so.conf and run ldconfig as root

To uninstall the CUDA Toolkit, run cuda-uninstaller in /usr/local/cuda-11.7/bin
***WARNING: Incomplete installation! This installation did not install the CUDA Driver. A driver of version at least 515.00 is required for CUDA 11.7 functionality to work.
To install the driver using this installer, run the following command, replacing <CudaInstaller> with the name of this run file:
    sudo <CudaInstaller>.run --silent --driver

Logfile is /var/log/cuda-installer.log
```

配置环境变量：

```bash
vim ~/.bashrc
# 在文件里加入
# nvidia cuda env
export CUDA_HOME=/usr/local/cuda
export PATH=$PATH:$CUDA_HOME/bin
export LD_LIBRARY_PATH=/usr/local/cuda/lib64${LD_LIBRARY_PATH:+:${LD_LIBRARY_PATH}}
```

https://blog.csdn.net/zxdd2018/article/details/127705627
