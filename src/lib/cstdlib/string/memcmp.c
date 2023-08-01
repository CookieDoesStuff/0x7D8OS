#include "string.h"

int memcmp(const void* cmp1, const void* cmp2, size_t n)
{
    if (n != 0)
    {
        const unsigned char* a = (unsigned char*)cmp1;
        const unsigned char* b = (unsigned char*)cmp2;
        for (size_t i = 0; i < n; i++)
        {
            if (a[i] < b[i])
                return -1;
            else if (b[i] < a[i])
                return 1;
        }
    }
    
    return 0;
}