#include "main.h"

void print_num_rec(int *num_rec, int num);

int _printf_int(va_list *list)
{
    int n = 0;
    int num_rec = 0;
    char big = 0;
    int num;

    num = va_arg(*list, int);

    if (num < 0)
    {
        _putchar('-');
        n++;
        if (num < -2147483647)
        {
            big = 1;
            num = num / 10;
        }
        num *= -1;
    }

    print_num_rec(&num_rec, num);
    n += num_rec + 1;
    if (big)
    {
        _putchar('0' + 8);
        n++;
    }
    
    return n;
}


void print_num_rec(int *num_rec, int num)
{
    if (num / 10)
    {
        (*num_rec)++;
        print_num_rec(num_rec, num / 10);
    }
    
        _putchar('0' + num % 10);
}
