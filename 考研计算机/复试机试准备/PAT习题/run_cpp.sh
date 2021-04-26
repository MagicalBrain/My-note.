#! /bin/bash
## author:HRL
## For running my C++ propram.

echo '请输入要debug的源代码文件名：'
read filename
echo '开始编译！'
time g++ -fsanitize=address -g $filename.cpp -o $filename.out
echo '运行可执行文件！'
./$filename.out
