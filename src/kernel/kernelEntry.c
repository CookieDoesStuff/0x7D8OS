#include "../lib/terminal/terminal.h"
#include "../lib/cstdlib/stdio/stdio.h"

void _startKernel(void)
{
    initTerminal();
    int num = 32;
    const char* str = " next str and check out this cool number ";

    printf("first str%s%d%c%c\n", str, num, ' ', 'c');
}
