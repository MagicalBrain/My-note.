#!/bin/zsh

echo "想要访问常用的文件夹？"

LeetCode=/mnt/c/编程练习/Leetcode_demo/Leetcode_demo
PTA_Basic=/mnt/c/编程练习/PAT_Basic/PTA_Basic
MyNotes=/mnt/c/MyNote/My-note
MagicalBrain=/mnt/c/MyGithub_config/MagicalBrain

echo "1 -> LeetCode"
echo "2 -> PAT_Basic"
echo "3 -> MyNotes"
echo "4 -> My Github config"

read id

case $id {
    (1)
    echo "访问 LeetCode"
    cd $LeetCode
    ;;
    (2)
    echo "访问 PAT_Basic"
    cd $PTA_Basic
    ;;
    (3)
    echo "访问 MyNotes"
    cd $MyNotes
    ;;
    (4)
    echo "访问 My Github config"
    cd $MagicalBrain
    ;;
}