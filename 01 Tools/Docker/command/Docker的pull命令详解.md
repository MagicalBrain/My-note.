# Docker的pull命令详解

## 拉取制定架构的镜像

```bash
docker pull --platform linux/arm64 openjdk
```

## 拉取 one-api 镜像（指定 amd64 架构）
docker pull --platform linux/amd64 justsong/one-api

## help 详细

```bash
docker pull --help
Usage:  docker pull [OPTIONS] NAME[:TAG|@DIGEST]

Download an image from a registry

Aliases:
  docker image pull, docker pull

Options:
  -a, --all-tags                Download all tagged images in the repository
      --disable-content-trust   Skip image verification (default true)
      --platform string         Set platform if server is multi-platform
                                capable
  -q, --quiet                   Suppress verbose output
```
