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

	Buffer_editor(ptr, k, ('0' + num % 10));

	(*num_rec)++;
}
