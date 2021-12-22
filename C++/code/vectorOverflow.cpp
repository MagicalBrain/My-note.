/*
* vector溢出的情况
*/
#include <iostream>
#include <vector>

std::vector<int> data{10, 11};

int main() {
	std::cout << data[3] << std::endl;
    data[3] = 1;
    std::cout << data[4] << std::endl;
	return 0;
}
