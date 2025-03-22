#include"main.h"

int _format_caces(char f, va_list *list)
    
{
    int n = 0;
    if (f == '%')
    {
        _putchar('%');
        n++;
    }
    if (f == 'c')
    {
        n  = _printf_char(list);
    }
    if (f == 's')
    {
        n = _printf_str(list);
    }
    
    if (n > 0)
    {
        return n;
    }
    
    return 2;
}
