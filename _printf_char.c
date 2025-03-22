#include"main.h"

int _printf_char(va_list *list)
{
    int n = 0;
    _putchar(va_arg(*list, int));
    n += 1;
    return n;
}
