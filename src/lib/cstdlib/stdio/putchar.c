#include "stdio.h"
#include "../../terminal/terminal.h"

void putchar(int c)
{
    putc((unsigned char)c);
}