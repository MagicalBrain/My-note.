# macOS启动容器失败

## 1 在docker desktop里手动创建镜像报错

```bash
(HTTP code 400) unexpected - failed to create task for container: failed to create shim task: OCI runtime create failed: runc create failed: unable to start container process: error during container init: exec: "zsh": executable file not found in $PATH: unknown
```

出错原因：
macOS终端默认的shell是zsh，而docker容器里没有安装zsh所以启动失败了

解决方案：

```bash
# 使用以下命令重新创建容器即可
docker run -it --name contain_name -d image_name /bin/bash
```

## 2 使用如下docker run命令创建容器报错

```bash
docker run -it --name cpp-hrl -d cpp-hrl -p 5678:22 /bin/bash
```

报错：

```bash
ARNING: The requested image's platform (linux/amd64) does not match the detected host platform (linux/arm64/v8) and no specific platform was requested
9cce0b1b3b28fe4bc4e6f5945f2970c01a649eb657325d1b6d42fa1e4f775d40
docker: Error response from daemon: failed to create task for container: failed to create shim task: OCI runtime create failed: runc create failed: unable to start container process: error during container init: exec: "-p": executable file not found in $PATH: unknown

Run 'docker run --help' for more information
```

其实就是 option 顺序错了，改成下面这样就行了：

```bash
docker run -it --name cpp-hrl -p 5678:22 -d cpp-hrl /bin/bash
```
