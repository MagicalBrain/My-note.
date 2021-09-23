/* ----- C++11 标准 创建线程的例子 ----- */
#include <iostream>
#include <thread>

#ifdef __linux__
#include <unistd.h>
	#define sleep0(time) (sleep(time / 1000))
#elif _WIN32
#include <windows.h>
	#define sleep0(time) (Sleep(time))
#endif

void threadproc01() {
	while (true)
	{
		//this_thread::sleep_for(chrono::seconds(0.5));
		sleep0(500);
		std::cout << "I am a New Thred01!" << std::endl;
	}
}

void threadproc02(int a, int b) {
	while (true)
	{
		//this_thread::sleep_for(chrono::seconds(0.5));
		sleep0(500);
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