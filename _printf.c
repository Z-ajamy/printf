#include"main.h"

int _printf(const char* str, ...)
{
    int i = 0, n = 0, k;
    va_list list;

    if (!str)
    {
        va_end(list);
        return -1;
    }
    
    va_start(list, str);

    while (str[i])
    {
        k = n;
        if (str[i] != '%')
        {
            _putchar(str[i]);
        }
        else
        {
            if (str[i + 1])
            {
                n += (-2 + _format_caces(str[i + 1], &list));
                if (n != k)
                {
                    i++;
                }
            }
            if(!str[i] || n==k)
            {
                if (k == n && str[i])
                {
                    if (str[i + 1])
                    {
                        _putchar('%');
                        if (str[i] != '%')
                        {
                            _putchar(str[i]);
                        }
                    }
                    else
                        i--;
                }
                
                if (i == 0)
                {
                    i--;
                    break;
                }
            }
        }
        i++;
    }

    va_end(list);
    return (i + n);
} 
