# 如何查看Docker容器使用哪个版本的linux

## 1

```bash
lsb_release -a
```

### lsb_release not found 解决办法

```bash
apt-get update && apt-get install -y lsb-release && apt-get clean all
```

https://stackoverflow.com/questions/58395566/lsb-release-command-not-found-in-latest-ubuntu-docker-container
