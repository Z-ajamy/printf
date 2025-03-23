#include"main.h"

int _print_Uint(va_list *list, char *ptr, int *k)
{
    int n = 0;
	unsigned int num;

	num = va_arg(*list, unsigned int);

	print_Unum_rec(&n, num, ptr, k);
	return (n);
}



void print_Unum_rec(int *num_rec, unsigned int num, char *ptr, int *k)
{
	if (num / 10)
	{
		print_num_rec(num_rec, num / 10, ptr, k);
	}

	ptr[*k] = ('0' + num % 10);
	*k = *k +1;
	if (*k == 1024)
	{
		_putchar(ptr, k);
		*k = 0;
	}
	(*num_rec)++;
}
