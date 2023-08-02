#include "string/string.h"
#include "itoa.h"

void reverse(char* str)
{
    size_t len = strlen(str);
    for (size_t i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void itoa(int num, char* buffer, uint8_t base)
{
    int8_t sign = (num < 0) ? -1 : 1;
    num = (sign < 0) ? num * -1 : num; 

    int i = 0;
    while (num != 0)
    {
        int rem = num % base;
        buffer[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }
    if (sign < 0)
        buffer[i++] = '-';
    
    reverse(buffer);
}
