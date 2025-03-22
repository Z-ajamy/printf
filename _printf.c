#include"main.h"

int _printf(const char* str, ...)
{
    int i = 0, n = 0;
    va_list list;

    va_start(list, str);

    while (str[i])
    {
        if (str[i] != '%')
        {
            _putchar(str[i]);
        }
        else
        {
           n += (-2 + _format_caces(str[++i], &list));
        }
        i++;
    }

    va_end(list);
    return (i + n);
} 
