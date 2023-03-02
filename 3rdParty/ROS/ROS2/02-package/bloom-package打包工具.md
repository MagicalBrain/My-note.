# bloom-package打包工具

## 安装

```bash
sudo apt install python3-bloom
sudo apt install dpkg-dev debhelper dh-python
```

## 使用方法详解

```bash
bloom-generate -h
usage: bloom-generate [-h] [debian | rosdebian | rosrpm | rpm] ...

Calls a generator on a local package, e.g. bloom-generate debian

optional arguments:
  -h, --help            show this help message and exit

generate commands:
  Call `bloom-generate [debian | rosdebian | rosrpm | rpm] -h` for help on a
  each generate command.

  [debian | rosdebian | rosrpm | rpm]
```
