# Docker使用上遇到的问题总结

这里主要记录的都是Docker使用上的问题

## 运行docker命令时遇到报错：

```bash
$ docker ps

----

Got permission denied while trying to connect to the Docker daemon socket at unix:///var/run/docker.sock: Get "http://%2Fvar%2Frun%2Fdocker.sock/v1.24/containers/json": dial unix /var/run/docker.sock: connect: permission denied
```

解决办法使用root权限执行

```bash
sudo docker ps
```

