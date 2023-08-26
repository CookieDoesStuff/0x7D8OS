#ifndef __PORT_H
#define __PORT_H 1

typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;

typedef uint8_t port8;
typedef uint16_t port16;

static inline void write8(port8 port, uint8_t val)
{
    asm volatile("outb %0, %1" :: "a"(val), "Nd"(port) );
}

static inline void write16(port16 port, uint16_t val)
{
    asm volatile("outw %0, %1" :: "a"(val), "Nd"(port):"memory");
}

static inline uint8_t read8(port8 port)
{
    uint8_t o;
    asm volatile("inb %1, %0" : "=a"(o) : "Nd"(port) );
    return o;
}

static inline uint16_t read16(port16 port)
{
    uint8_t o;
    asm volatile("inw %1, %0" : "=a"(o) : "Nd"(port) );
    return o;
}

#endif