# nvidia cuda的卸载

## windows

## wsl2

## Linux

### ubuntu18

### ubuntu20

### ubuntu22

#### cuda-11.7 卸载

```bash
# To uninstall the CUDA Toolkit, run cuda-uninstaller in /usr/local/cuda-11.7/bin
cd /usr/local/cuda-11.7/bin
sudo ./cuda-uninstaller
```

## 其他版本的cuda卸载

可以参照：

```bash
cd /usr/local/cuda-xx.x/bin/
sudo ./cuda-uninstaller
sudo rm -rf /usr/local/cuda-xx.x
```

运行结束后检查`/usr/local/`目录下是否还有cuda相关文件的残留
