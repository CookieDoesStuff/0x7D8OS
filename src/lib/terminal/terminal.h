#ifndef __TERMINAL_H
#define __TERMINAL_H 1

#include <stdbool.h>

typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;

enum textColour
{
    VGA_COLOUR_BLACK = 0,
	VGA_COLOUR_BLUE = 1,
	VGA_COLOUR_GREEN = 2,
	VGA_COLOUR_CYAN = 3,
	VGA_COLOUR_RED = 4,
	VGA_COLOUR_MAGENTA = 5,
	VGA_COLOUR_BROWN = 6,
	VGA_COLOUR_LIGHT_GREY = 7,
	VGA_COLOUR_DARK_GREY = 8,
	VGA_COLOUR_LIGHT_BLUE = 9,
	VGA_COLOUR_LIGHT_GREEN = 10,
	VGA_COLOUR_LIGHT_CYAN = 11,
	VGA_COLOUR_LIGHT_RED = 12,
	VGA_COLOUR_LIGHT_MAGENTA = 13,
	VGA_COLOUR_LIGHT_BROWN = 14,
	VGA_COLOUR_WHITE = 15
};

static const uint8_t VGA_WIDTH = 80;
static const uint8_t VGA_HEIGHT = 25;

uint8_t mergeColour(enum textColour, enum textColour);
uint16_t mergeChar(unsigned char, uint8_t);

void scroll(uint8_t);
void updateCursor();

void setColour(uint8_t);
uint8_t getCurrentColour();

void printChar(uint16_t, bool);
void printStr(const char*);

void initTerminal(void);

#endif