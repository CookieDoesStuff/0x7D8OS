#include "gdt.h"

void loadGDT(gdtDescriptor* gdt)
{
    asm volatile("lgdt %0" : : "m"(*gdt));
}

void initGDT(void)
{
    // null segment
    gdt[0].limit_low = 0;
    gdt[0].base_low = 0;
    gdt[0].base_mid = 0;
    gdt[0].access_byte = 0;
    gdt[0].limit_high_flags = 0;
    gdt[0].base_high = 0;

    // code segment
    gdt[1].limit_low = 0xFFFF;
    gdt[1].base_low = 0;
    gdt[1].base_mid = 0;
    gdt[1].access_byte = 0x9A; // 1 00 1 0 A = Present, Ring 0, Code, Executable
    gdt[1].limit_high_flags = 0xCF; // 1 1 00 1 1 = 4KB granularity, 32-bit code
    gdt[1].base_high = 0;

    // data segment
    gdt[2].limit_low = 0xFFFF;
    gdt[2].base_low = 0;
    gdt[2].base_mid = 0;
    gdt[2].access_byte = 0x92; // 1 00 1 0 0 = Present, Ring 0, Data, Writable
    gdt[2].limit_high_flags = 0xCF; // 1 1 00 1 1 = 4KB granularity, 32-bit code
    gdt[2].base_high = 0;

    gdtDescriptor gdtr;
    gdtr.limit = sizeof(gdt) - 1;
    gdtr.base = (uint32_t)gdt;

    loadGDT(&gdtr);
}