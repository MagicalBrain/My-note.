#include <iostream>
#include <stdio.h>

int main(void)
{
    int c;
    while ( (c = getc(stdin)) != EOF )
    {
        if (putc(c, stdout) == EOF)
            std::cout << "output error" << std::endl;
    }
    
    if (ferror(stdin))
        std::cout << "input error" << std::endl;
    
    return 0;
}
