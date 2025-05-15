# Docker的commit命令详解

这个命令主要用来提交 容器对镜像的修改的？

用于将容器的当前状态保存为一个新的 Docker 镜像

```bash
docker commit -h
Flag shorthand -h has been deprecated, please use --help

Usage:  docker commit [OPTIONS] CONTAINER [REPOSITORY[:TAG]]

Create a new image from a container's changes

Options:
  -a, --author string    Author (e.g., "John Hannibal Smith
                         <hannibal@a-team.com>")
  -c, --change list      Apply Dockerfile instruction to the created image
  -m, --message string   Commit message
  -p, --pause            Pause container during commit (default true)
```

----

如果要查看 docker commit 的提交记录就只能通过 docker history 命令了

## 参考

https://www.runoob.com/docker/docker-commit-command.html
