#!/bin/bash

# 这是一个给目录里的文件分类的bash脚本

for i in {1..7..1}
do
	mkdir 0$i
	mv *$i.* 0$i
done
