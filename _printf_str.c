#include"main.h"

int _printf_str (va_list *list)
{
    char *ptr = NULL;
    int n = 0;

    ptr = va_arg(*list, char *);
    if (ptr == NULL)
    {
        char *str = "(null)";
        while (str[n])
        {
            _putchar(str[n]);
            n++;
        }
        return n;
    }
    
    while (ptr[n])
    {
        _putchar(ptr[n]);
        n++;
    }
    return n;
}
