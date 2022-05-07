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

## 切换WSL 1与WSL 2

安装的Linux发行版默认是wsl 1的，切换成wsl 2则需要输入以下命令：

```bash
wsl --set-version [Linux name] 2
```

该命令也可以用于将WSL 2降级为WSL 1

## 其它WSL常用命令

https://docs.microsoft.com/zh-cn/windows/wsl/basic-commands

## 关闭WSL

### 关闭指定版本的WSL虚拟机

```bash
wsl --terminate [version-name]
```

### 关闭所有的WSL虚拟机

```bash
wsl --shutdown
```

立即停止所有wsl虚拟机

有时候内存占用过大，例如`Vmmem`
