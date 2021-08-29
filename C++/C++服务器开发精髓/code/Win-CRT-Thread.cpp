#include <iostream>

#include <process.h>

unsigned WINAPI threadfunc(void* args) {
	while (true)
	{
		std::cout << "I am a New Thread!" << std::endl;
	}
	return 0;
}

int main() {
	unsigned int threadid;
	_beginthreadex(0, 0, threadfunc, 0, 0, &threadid);

	while (true)
	{
	}
	return 0;
}
