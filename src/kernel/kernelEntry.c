#include "../lib/terminal/terminal.h"

void _startKernel(void)
{
    initTerminal();
    printStr("Test Print\n New Line Test");
}