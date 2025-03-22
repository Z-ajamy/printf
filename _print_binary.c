#include "main.h"

int _print_binary(va_list *list)
{
    int num_rec = 0;
    unsigned long num = va_arg(*list, unsigned long);

    if (num == 0)
    {
        _putchar('0');
        return 1;
    }
        

    binary_rec(&num_rec, num);
    return num_rec;
}


void binary_rec(int *num_rec, unsigned long num)
{

    if (num / 2)
    {
        binary_rec(num_rec, num / 2);
    }

    _putchar('0'+num%2);
    *num_rec = *num_rec + 1;

}
