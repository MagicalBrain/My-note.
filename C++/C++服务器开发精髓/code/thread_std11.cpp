/* ----- C++11 标准 创建线程的例子 ----- */
#include <iostream>
#include <thread>

void threadproc01() {
	while (true)
	{
		Sleep(1000);
		std::cout << "I am a New Thred01!" << std::endl;
	}
}

void threadproc02(int a, int b) {
	while (true)
	{
		Sleep(1000);
		std::cout << "I am a New Thred02!" << std::endl;
	}
}

int main() {
	// 创建线程1
	std::thread t1(threadproc01);
	// 创建线程2
	std::thread t2(threadproc02, 1, 2);

	while (true)
	{
	}
	return 0;
}