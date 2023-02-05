#! /bin/bash

# 检查系统中是否存在 HRL环境变量

if [ -v HOME ]
then
    echo "env exists!"
    echo $HOME
else
    echo "env doesn't exists"
fi
