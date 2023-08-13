#include "port.h"

void write8(port8 port, uint8_t val)
{
    __asm__ volatile ("outb %0, %1" : : "a" (val), "Nd" port);
}
void write16(port16 port, uint16_t val)
{
    __asm__ volatile ("outw %0, %1" : : "a" (val), "Nd" port);
}

port8 read8(port8 port)
{
    uint8_t o;
    __asm__ volatile ("inb %1, %0" : "=a" (o) : "Nd" (port));
    return o;
}
port16 read16(port16 port)
{
    uint16_t o;
    __asm__ volatile ("inw %1, %0" : "=a" (o) : "Nd" (port));
    return o;
}