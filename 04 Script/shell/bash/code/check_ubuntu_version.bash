#!/usr/bin/bash

# version=$(lsb_release -d | awk -F"\t" '{print $2}')
version=$( lsb_release -d | awk -F"\t" '{print $2}' | grep -Eo "[0-9]+\.[0-9]+")

echo "Ubuntu版本：$version"

if [[ "$version" == "20.04" ]]; then
	# sudo make install
    echo "20.04 Yes!"
fi
