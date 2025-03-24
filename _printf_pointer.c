#include "main.h"


void _printf_hex_ptr(int *n, unsigned long int num, char *ptr, int *k)
{
	int a;

	if (num / 16)
	{
		_printf_hex_ptr(n, num / 16, ptr, k);
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


int _printf_pointer(va_list *list, char *ptr, int *k)
{
    unsigned long int num;
	int n = 0;

	num = va_arg(*list, unsigned long int);
    Buffer_editor(ptr, k, ('0'));
	Buffer_editor(ptr, k, ('x'));
    n += 2;
	_printf_hex_ptr(&n, num, ptr, k);
	return (n);
}
