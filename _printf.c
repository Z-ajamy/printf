#include"main.h"

int _printf(const char* str, ...)
{
    int i = 0, n = 0;
    va_list list;

    if (!str)
    {
        va_end(list);
        return -1;
    }
    
    va_start(list, str);

    while (str[i])
    {
        if (str[i] != '%')
        {
            _putchar(str[i]);
        }
        else
        {
            if (str[i + 1])
            {
                n += (-2 + _format_caces(str[++i], &list));
            }
            else
            {
                break;
            }
        }
        i++;
    }

    va_end(list);
    return (i + n);
} 
