#ifndef _IO_H
#define _IO_H 1

typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;

static inline void outb(uint16_t port, uint8_t val)
{
    asm volatile("outb %0, %1" : : "a"(val), "Nd"(port) );
}
static inline uint8_t inb(uint16_t port)
{
    uint8_t o;
    asm volatile("inb %1, %0" : "=a"(o) : "Nd"(port) );
    return o;
}

#endif