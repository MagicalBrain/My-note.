/*
* callback 4-1
* 使用函数指针是最简单的实现回调函数的方式
*/
#include <iostream>

void setPRG() {
	std::cout << "set PRG of movement." << std::endl;
}

bool send(void(*func)()) {
	std::cout << "send location" << std::endl;
	setPRG();
	return true;
}

int main() {
	send(setPRG);
	return 0;
}
