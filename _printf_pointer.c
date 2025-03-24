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
    if (num == 8)
    {
        char *str = "(nil)";
        _printf_strings(&n, str, ptr, k);
        return n;
    }
    Buffer_editor(ptr, k, ('0'));
	Buffer_editor(ptr, k, ('x'));
    n += 2;
	_printf_hex_ptr(&n, num, ptr, k);
	return (n);
}

void _printf_strings(int *n,char *str, char *ptr, int *k)
{
    int i = 0;
    if (str == NULL)
    {
        return;
    }
    while (str[i])
    {
        Buffer_editor(ptr, k, str[i]);
        *n = *n + 1;
    }
}
