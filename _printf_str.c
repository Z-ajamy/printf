#include"main.h"

int _printf_str (va_list *list)
{
    char *ptr;
    int n = 0;
    ptr = va_arg(*list, char *);
    while (ptr[n])
    {
        _putchar(ptr[n]);
        n++;
    }
    return n;
}
