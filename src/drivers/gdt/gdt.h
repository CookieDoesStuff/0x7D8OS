#ifndef __GDT_H
#define __GDT_H 1

typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;

typedef struct __attribute__((packed)) 
{
    uint16_t limit_low;     // Lower 16 bits of the limit
    uint16_t base_low;      // Lower 16 bits of the base
    uint8_t base_mid;       // Middle 8 bits of the base
    uint8_t access_byte;    // Access flags and segment type
    uint8_t limit_high_flags;   // Upper 4 bits of the limit and flags
    uint8_t base_high;      // Upper 8 bits of the base
} gdtEntry;


typedef struct __attribute__((packed)) 
{
    uint16_t limit;         // Total size of the GDT
    uint32_t base;          // Base address of the GDT
} gdtDescriptor;


/*
* index 0 is the null segment
* index 1 is the code segment
* index 2 is the data segment
*/
gdtEntry gdt[3];

void loadGDT(gdtDescriptor* gdt);

void initGDT(void);

#endif