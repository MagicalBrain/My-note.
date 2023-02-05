#! /bin/bash

# -e 打开反斜杠，这样才能设置进制
echo -e "\11\22"
echo -e "\011\022"
echo -e "\x11\x22"

# -n 将echo默认在末尾生成的换号符去掉
echo -e "\x11\x22" > test.txt
echo -e -n "\x11\x22" > test.txt
