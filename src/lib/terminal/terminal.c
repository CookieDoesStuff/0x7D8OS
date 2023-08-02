#include "terminal.h"
#include "../io/io.h"
#include "../cstdlib/string/string.h"

uint8_t currentX, currentY, currentColour;
uint16_t* terminalBuffer;

uint8_t mergeColour(enum textColour fg, enum textColour bg)
{
    return fg | bg << 4;
}

uint16_t mergeChar(unsigned char uc, uint8_t colour)
{
	return (uint16_t)uc | (uint16_t)colour << 8;
}

void setColour(uint8_t newColour)
{
    currentColour = newColour;
}

void printChar(uint16_t c)
{
    terminalBuffer[currentY * VGA_WIDTH + currentX] = c;
    if (currentX != VGA_WIDTH)
        currentX++;
    else
    {
        currentX = 0;
        currentY++;
    }
    //move cursor
    uint16_t pos = currentY * VGA_WIDTH + currentX;

	outb(0x3D4, 0x0F);
	outb(0x3D5, (uint8_t) (pos & 0xFF));
	outb(0x3D4, 0x0E);
	outb(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
}

void putc(int c)
{
    if (c == '\n')
    {
        currentX = 0;
        currentY++;
    }
    else 
        printChar(mergeChar(c, currentColour));
}

void printStr(const char* str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '\n')
        {
            currentX = 0;
            currentY++;
        }
        else
        {
            printChar(mergeChar(str[i], currentColour));
        }
    }
}

void initTerminal(void)
{
	currentX = 0;
	currentY = 0;
    currentColour = mergeColour(VGA_COLOUR_WHITE, VGA_COLOUR_BLACK);
	terminalBuffer = (uint16_t*) 0xB8000;
	for (size_t y = 0; y < VGA_HEIGHT; y++) 
    {
		for (size_t x = 0; x < VGA_WIDTH; x++) 
			terminalBuffer[y * VGA_WIDTH + x] = mergeChar(' ', VGA_COLOUR_BLACK);
	}
}
 