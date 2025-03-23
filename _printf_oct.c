#include "main.h"

int _printf_oct(va_list *list)
{
    int n = 0;
    unsigned int num = va_arg(*list, unsigned int);

    _printf_oct_rec(&n, num);
    return n;
}

void _printf_oct_rec(int *n, unsigned int num)
{
    if (num / 8)
    {
        _printf_oct_rec(n, num/8);
    }
    _putchar('0' + num %8);
    *n = *n + 1;
}
