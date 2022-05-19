#include <Windows.h>
#include <iostream>

DWORD WINAPI ThreadProc(LPVOID lpParameters) {
	while (true)
	{
		// 睡眠 1 sec
		Sleep(1000);

		std::cout << "I am New Thread!" << std::endl;
	}
	return 0;
}

int main() {
	DWORD dwThreadID;
	HANDLE hThread = CreateThread(NULL, 0, ThreadProc, NULL, 0, &dwThreadID);

	if (hThread == NULL) {
		std::cout << "Fail to create Thread." << std::endl;
		return -1;
	}

	// 让主线程一直保持执行 不退出。
	while (true)
	{
	}
	return 0;
}
