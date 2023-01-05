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
