#include "main.h"

int _printf_hex(va_list *list)
{
    unsigned int num;
    int n =0;

    num = va_arg(*list, unsigned int);

    _printf_hex_rec(&n, num);
    return n;
}

void _printf_hex_rec(int *n, unsigned int num)
{
    int a;
    if (num / 16)
    {
        _printf_hex_rec(n,num / 16);
    }
    a= num%16;
    if (a >= 0 && a<= 9)
    {
        _putchar('0' + a);
        *n = *n +1;
    }
    else
    {
        _putchar('a' + (a - 10));
        *n = *n +1;
    }
}
