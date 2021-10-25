# Docker如何安装ros

```bash
docker run --name hmi \
--mount type=bind,source=/Users/aa/ee,target=/root/ros_workspaces \
-itd -p 6080:80 -p 7777:7777 -p 9111:9111 -p 1314:1314 -p 1222:1222 \
library/melodic
```

```bash
docker run --name hmi \
--mount type=bind source=/Users/aa/ee target=/root/ros_workspaces \
-itd -p 6080:80 -p 7777:7777 -p 9111:9111 -p 1314:1314 -p 1222:1222 \
library/melodic
```
