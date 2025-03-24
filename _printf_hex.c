#include "main.h"

void _printf_hex_rec(int *n, unsigned int num, char *ptr, int *k)
{
	int a;

	if (num / 16)
	{
		_printf_hex_rec(n, num / 16, ptr, k);
	}

	a = num % 16;

	if (a >= 0 && a <= 9)
	{
		Buffer_editor(ptr, k, ('0' + a));
	}
	else
	{
		Buffer_editor(ptr, k, ('a' + (a - 10)));
	}

	*n = *n + 1;
}

int _printf_hex(va_list *list, char *ptr, int *k)
{
	unsigned int num;
	int n = 0;

	num = va_arg(*list, unsigned int);

	_printf_hex_rec(&n, num, ptr, k);
	return (n);
}
