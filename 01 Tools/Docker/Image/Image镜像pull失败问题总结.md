# Image镜像pull失败问题总结

```bash
docker pull debian
# 报错
Using default tag: latest
Error response from daemon: Get "https://registry-1.docker.io/v2/": context deadline exceeded
```

## 尝试配置镜像源

参考[笔记](./Docker配置镜像源.md)
