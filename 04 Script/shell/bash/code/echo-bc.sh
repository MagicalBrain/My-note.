#! /bin/bash

echo "ibase=16;obase=2;FFEE" | bc  

echo "ibase=16;obase=16;FFFF" | bc 
echo "obase=16;1111" | bc 

echo "ibase=8;obase=2;67"  |  bc  

echo "obase=16;base=2;11001111"  |  bc  

# 同时转换2个数字
echo "obase=16;ibase=2;11001111;0101100111001111"  |  bc 
