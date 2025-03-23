#include"main.h"

int _print_Uint(va_list *list)
{
    int n = 0;
	int num_rec = 0;
	unsigned int num;

	num = va_arg(*list, unsigned int);

	print_Unum_rec(&num_rec, num);
	n += num_rec + 1;

	return (n);
}



void print_Unum_rec(int *num_rec, unsigned int num)
{
	if (num / 10)
	{
		(*num_rec)++;
		print_num_rec(num_rec, num / 10);
	}

	_putchar('0' + num % 10);
}
