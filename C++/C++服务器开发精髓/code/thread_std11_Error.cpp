/* ----- C++11 标准 创建线程 会崩溃 的例子 ----- */
#include <iostream>
#include <thread>

void threadproc() {
	while (true)
	{
		std::cout << "I am a New Thread!" << std::endl;
	}
}

void func() {
	std::thread t(threadproc);
}

int main() {
	func();

	while (true)
	{
	}
	return 0;
}
