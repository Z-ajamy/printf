#include "main.h"

/**
 * _format_caces - Handles specific format specifiers.
 * @f: The format specifier character.
 * @list: The argument list containing values to be printed.
 *
 * Return: The number of characters printed.
 */
int _format_caces(char f, va_list *list, char *ptr, int *k)
{
	int n = 0;

	if (f == '%')
	{
		ptr[*k] = ('%');
		*k = *k +1;
		if (*k == 1024)
		{
			_putchar(ptr, k);
			*k = 0;
		};
		n++;
	}
	if (f == 'c')
	{
		n = _printf_char(list, ptr, k);
	}
	if (f == 's')
	{
		n = _printf_str(list, ptr, k);
	}
    if (f == 'd' || f == 'i')
    {
        n = _printf_int(list, ptr, k);
    }
    if (f == 'b')
    {
        n = _print_binary(list, ptr, k);
    }
	if (f == 'u')
	{
		n = _print_Uint(list, ptr, k);
	}
	if (f == 'o')
	{
		n = _printf_oct(list, ptr, k);
	}
	if (f == 'x')
	{
		n = _printf_hex(list, ptr, k);
	}
    if (f == 'X')
	{
		n = _printf_HEX(list, ptr, k);
	}

	return (n);
}
