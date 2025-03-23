#include"main.h"

int _print_Uint(va_list *list, int *m, char *ptr)
{
    int a;
	unsigned int num;

	num = va_arg(*list, unsigned int);

	a = print_Unum_rec(num, m, ptr);
	if (a == 0)
	{
		return 0;
	}

	return (1);
}


int print_Unum_rec(unsigned int num, int *m, char *ptr)
{
	int a = 1;
	if (num / 10)
	{
		a = print_Unum_rec(num / 10, m, ptr);
	}
	if (a == 0)
	{
		return 0;
	}
	ptr[*m] = ('0' + num % 10);
	*m = *m +1;
	if (*m == 1023)
	{
		return 0;
	}
	return 1;
}
