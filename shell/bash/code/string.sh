#! /bin/bash

echo "please input your option:(y/n)"

read -r option

echo "$option"

# String
if [[ -z "$option" ]]; then
  echo "String is empty"
elif [[ -n "$option" ]]; then
  echo "String is not empty"
else
  echo "This never happens"
fi

if [[ "$option" == "y" ]];
then
    echo "your option is y!"
else
    echo "your option is not y!"
fi

if [ "$option" == "y" ]
then
    echo "your option is y!"
else
    echo "your option is not y!"
fi

if [[ "$option" == "y" ]]
then
    echo "your option is y!"
else
    echo "your option is not y!"
fi
