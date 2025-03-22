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
            n++;
        }
        else
        {
            if (!str[i + 1])
            {
                return -1;
            }
            if (str[i + 1] == 'c' || str[i+1] == 's' || str[i+1] == '%')
            {
                n += _format_caces(str[++i], &list);
            }
            else
            {
                _putchar('%');
                n++;
            }
        }
        
        i++;
    }

    va_end(list);
    return (n);
} 
