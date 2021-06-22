# Doxygen的使用

doxygen的使用方法通过doxygen -h可以获取。

## 创建配置文件doxyfile的方式

```bash
doxygen -s -g doxyfile  #简化版的doxyfile，没有很多注释信息。
# 或
doxygen -g doxyfile
```

输入命令：
```bash
doxygen -g doxyfile
```

输出如下：
```bash
Configuration file `Doxyfile' created.

Now edit the configuration file and enter

  doxygen Doxyfile

to generate the documentation for your project
```

You let doxygen generate the documentation, based on the settings in the configuration file:
想要让doxygen生成文档，使用如下命令即可：

```bash
doxygen <config_file>
```

如果想要将旧版本的doxygen配置文件升级到新版本，使用如下命令即可：
```bash
doxygen -u <config_file>
```
