# 作为编译脚本的范本

sudo rm -r build
echo "start build my process"
mkdir build && cd build
cmake .. -DBUILD_LIB=TRUE
make -j$(nproc)

echo "make is finished, do you want to install it?(y/n)"
read y
if [[ "$y" == "y" ]]; then
	sudo make install
fi

