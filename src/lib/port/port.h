#ifndef __PORT_H
#define __PORT_H 1

typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;

typedef uint8_t port8;
typedef uint16_t port16;

void write8(port8, uint8_t);
void write16(port16, uint16_t);

uint8_t read8(port8);
uint16_t read16(port16);

#endif