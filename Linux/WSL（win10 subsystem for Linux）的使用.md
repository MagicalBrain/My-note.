# WSL（win10 subsystem for Linux）的使用

## 查看已安装的WSL

```
wsl --list
```
查看当前的默认wsl版本

```
wsl -l -v
```

查看所有wsl版本

## 启动WSL

```
wsl
```
启动默认版本的wsl

### 启动指定版本的WSL

```
wsl -d Ubuntu-20.04
```

启动指定版本的wsl

## 关闭WSL

```
wsl --shutdown
```

立即停止所有wsl虚拟机
