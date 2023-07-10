# Nvidia Driver

## 显卡驱动分类

显卡驱动分为：
1. GRD  游戏驱动
2. SD   ？

一般最好安装游戏驱动，暂时不知道为啥，搞开发应该都行才对。

## 驱动安装

## 驱动卸载

```bash
sudo apt-get --purge remove "*cublas*" "*cufft*" "*curand*" \
 "*cusolver*" "*cusparse*" "*npp*" "*nvjpeg*" "cuda*" "nsight*" 
```
