# 作为编译脚本的范本

sudo rm -r build
echo "start build!"
mkdir build && cd build
cmake .. 
make -j$(nproc)

echo "make is finished, do you want to install it?(y/n)"
read y
if [[ "$y" == "y" ]]; then
	sudo make install
fi