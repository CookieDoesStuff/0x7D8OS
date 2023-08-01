#ifndef __STRING_H
#define __STRING_H 1

#define NULL 0

typedef long unsigned int size_t;

void* memcpy(void*, const void*, size_t);
void* memchr(const void*, int, size_t);
int memcmp(const void*, const void*, size_t);
size_t strlen(const char*);

#endif