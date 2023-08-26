#ifndef __PORT_H
#define __PORT_H 1

typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;

static inline void write8(uint16_t port, uint8_t val)
{
    asm volatile("outb %0, %1" :: "a"(val), "Nd"(port) : "memory");
}
static inline void write16(uint16_t port, uint16_t val)
{
    asm volatile("outw %0, %1" :: "a"(val), "Nd"(port) : "memory");
}

static inline uint8_t read8(uint16_t port)
{
    uint8_t o;
    asm volatile("inb %1, %0" : "=a"(o) : "Nd"(port) : "memory");
    return o;
}
static inline uint16_t read16(uint16_t port)
{
    uint16_t o;
    asm volatile("inw %1, %0" : "=a"(o) : "Nd"(port) : "memory");
    return o;
}

#endif