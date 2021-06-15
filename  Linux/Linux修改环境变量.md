# Linux修改环境变量

## 设置文件/etc/bash.bashrc

```
sudo vim /etc/bash.bashrc
```

## sudo vim ~/.bashrc

## 动态库.so路径

```
vim /etc/ld.so.conf
```

添加目录后，运行
```
ldconfig 
```

## 通过环境变量LD_LIBRARY_PATH指定动态库搜索路径。 

```
export LD_LIBRARY_PATH=”LD_LIBRARY_PATH:/opt/”
```

### 在编译目标代码时指定该程序的动态库搜索路径。
