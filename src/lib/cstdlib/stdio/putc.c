#include "stdio.h"
#include "../../terminal/terminal.h"

void putc(int c)
{
    printChar(mergeChar(c, getCurrentColour()), false);
}