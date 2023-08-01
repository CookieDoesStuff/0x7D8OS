#include "string.h"

size_t strlen(const char* str)
{
    size_t index = 0;
    while (str[index++]);
    return index - 1;
}