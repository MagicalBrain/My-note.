#! /bin/bash

flag=100
echo "flag is $flag"

while [ $flag -gt 0 ];
do
    echo "sleeping"
    usleep 100
    ((flag=$flag-1))
done
