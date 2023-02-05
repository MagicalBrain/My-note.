#!/bin/bash

# 检查当前是否处于root状态，否则提示“需要root权限”并退出

if [ "$UID" -eq 0 ]; then
    echo "Yes, has been root."
else
    echo "需要root权限"
    exit 1
fi
