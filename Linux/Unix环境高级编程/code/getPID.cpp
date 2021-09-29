#include <iostream>
#include <unistd.h>


int main(void)
{
    std::cout << "process ID is: " << (long) getpid() << std::endl;
    return 0;
}
