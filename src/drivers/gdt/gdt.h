#ifndef __GDT_H
#define __GDT_H 1

typedef unsigned char uint8_t;
typedef unsigned int uint32_t;

typedef struct __attribute__((packed))
{
    uint32_t base;
    uint32_t limit;
    uint8_t accessByte;
    uint8_t flags
}gdtEntry;



#endif