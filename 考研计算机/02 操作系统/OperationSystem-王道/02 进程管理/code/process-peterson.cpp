/*
* 利用线程来模拟进程的调度
* 模拟peterson进程调度算法
*/
#include <iostream>
#include <thread>
//#include <chrono>

#ifdef __linux__
#include <unistd.h>
	#define sleep0(time) (sleep(time / 1000))
#elif _WIN32
#include <windows.h>
	#define sleep0(time) (Sleep(time))
#endif

const int thread_num = 2;

int turn = 0;

// flag[i] 即第i个进程的标志
bool flag[thread_num];

// 进程1
void threadproc01() {
	while (true)
	{
		flag[0] = true;
		turn = 0;

		while (flag[0] && (turn == 0))
		{
			//this_thread::sleep_for(chrono::seconds(0.5));
			sleep0(1000);
			std::cout << "I am a New Thred01!" << std::endl;
		}

		// 临界区
		flag[0] = false;
	}
}

// 进程2
void threadproc02() {
	while (true)
	{
		flag[1] = true;
		turn = 1;

		while (flag[1] && (turn == 1))
		{
			//this_thread::sleep_for(chrono::seconds(0.5));
			sleep0(1000);
			std::cout << "I am a New Thred02!" << std::endl;
		}

		// 临界区
		flag[1] = false;
	}
}

int main() {
	// 创建线程1
	std::thread t1(threadproc01);
	// 创建线程2
	std::thread t2(threadproc02);

	while (true)
	{
		std::cout << flag[1] << 1 << std::endl;
		flag[0] = true;
		turn = 0;
		sleep0(5000);
		std::cout << flag[0] << 0 << std::endl;
		flag[1] = true;
		turn = 1;
	}
	return 0;
}