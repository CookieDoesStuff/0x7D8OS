/*

*   printf(const char* restrict, ...)
*       A usual printf implementation. Although it only supports 12 digit integers
*
*       FORMATS:
*           %s: to add a string
*           %c: to add a char
*           %d or %i: to add an integer of base ten
*           %o: to add an integer of base eight
*/


#include <stdarg.h>
#include <stddef.h>
#include "../math/math.h"
#include "stdio.h"

int printf(const char* restrict format, ...)
{
    va_list params;
    va_start(params, format);

    int out = 0;
    for (size_t i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == '\0')
            {
                putc('%');
                break;
            }
            char buffer[12];
            switch(format[i])
            {
                case 's':
                    const char* str = va_arg(params, const char*);
                    puts(str);
                break;
                case 'c':
                    char c = va_arg(params, int);
                    putchar(c);
                break;
                case 'i':
                case 'd':
                    int d = va_arg(params, int);
                    itoa(d, buffer, 10);
                    puts(buffer);
                break;
                case 'o':
                    int o = va_arg(params, int);
                    itoa(o, buffer, 8);
                    puts(buffer);
                break;
                case 'f':
                    double f = va_arg(params, double);
                    putchar(f);
                break;
                case '%':
                    putchar('%');
                break;

                default:
                    putchar(format[i]);
                break;
            }

        }
        else
        {
            putchar(format[i]);
        }
    }

    va_end(params);

    return out;
}