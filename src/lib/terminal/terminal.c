#include "terminal.h"
#include "../port/port.h"
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

void scroll(uint8_t lines)
{
    for (uint8_t y = lines; y < VGA_HEIGHT; y++)
    {
        for (uint8_t x = 0; x < VGA_WIDTH; x++)
            terminalBuffer[(y - lines) * VGA_WIDTH + x] = terminalBuffer[y * VGA_WIDTH + x];
    }

    for (uint8_t y = VGA_HEIGHT - lines; y < VGA_HEIGHT; y++)
    {
        for (uint8_t x = 0; x < VGA_WIDTH; x++)
            terminalBuffer[y * VGA_WIDTH + x] = mergeChar(' ', mergeColour(VGA_COLOUR_BLACK, VGA_COLOUR_BLACK));
    }
    
    currentY -= lines;
    currentY = (currentY < 0) ? 0 : currentY;
    currentX = 0;
}

void updateCursor()
{
    uint16_t pos = currentY * VGA_WIDTH + currentX;

	write8(0x3D4, 0x0F);
	write8(0x3D5, (uint8_t) (pos & 0xFF));
	write8(0x3D4, 0x0E);
	write8(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
}

void setColour(uint8_t newColour)
{
    currentColour = newColour;
}
uint8_t getCurrentColour()
{
    return currentColour;
}

void printChar(uint16_t c, bool cursor)
{
    terminalBuffer[currentY * VGA_WIDTH + currentX] = c;
    if (currentX != VGA_WIDTH)
        currentX++;
    else
    {
        currentX = 0;
        currentY++;
    }
    if (currentY == VGA_HEIGHT)
        scroll(1);
    if (cursor)
        updateCursor();
}

void printStr(const char* str)
{
    for (size_t i = 0; i < strlen(str); i++)
    {
        if (str[i] == '\n')
        {
            currentX = 0;
            currentY++;
        }
        else
            printChar(mergeChar(str[i], currentColour), false);
    }
    updateCursor();
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

    write8(0x3D4, 0x0A);
	write8(0x3D5, (read8(0x3D5) & 0xC0) | 0);
 
	write8(0x3D4, 0x0B);
	write8(0x3D5, (read8(0x3D5) & 0xE0) | 15);
}
