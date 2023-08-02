#include "../lib/terminal/terminal.h"
#include "../lib/cstdlib/stdio/stdio.h"

void _startKernel(void)
{
    initTerminal();
    int num = 32;
    const char* str = " next str and check out this cool number ";

    for (int i = 0; i < VGA_HEIGHT; i++)
        printf("first str%s%d%c%c\n", str, num, ' ', 'c');
    printf("scrolled line\n");
}