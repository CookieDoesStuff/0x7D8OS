#include "../lib/terminal/terminal.h"
#include "../lib/cstdlib/stdio/stdio.h"

void _startKernel(void)
{
    initTerminal();
    int num = 32;
    double pi = 3.14159;
    const char* str = "Hello, World!";

    printf("Integer: %o\n", num);

}