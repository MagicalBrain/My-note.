# Dockcross

## 安装

直接从github上clone下来：

```bash
git clone https://github.com/dockcross/dockcross.git
```

只不过我fork到gitee，那就可以直接从gitee上clone下来

```bash
git clone git@gitee.com:CPLASF000000/dockcross.git
```

## 使用方法

以Arm64为例，它这里提供了几个镜像：

我选的是`dockcross/linux-arm64-lts`

```bash
cd dockcross
sudo docker run --rm dockcross/linux-arm64-lts > ./docker-linux-arm64-lts
chmod +x ./docker-linux-arm64-lts
./docker-linux-arm64-lts bash -c '$CC test/C/hello.c -o hello_arm'
```

运行命令进入命令行：

```bash
./docker-linux-arm64-lts bash
# 如果有权限问题就
sudo ./docker-linux-arm64-lts bash
```

实测这个编译出来的文件可以直接复制到nano上运行

## 注意

linux-64 镜像如果放到x86的PC上，里面的可执行文件、动态库文件都是无法用的
arm64的镜像放到x86上再源码编译，编译出来的貌似还是x86的
