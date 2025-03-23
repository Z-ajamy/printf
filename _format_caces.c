#include "main.h"

/**
 * _format_caces - Handles specific format specifiers.
 * @f: The format specifier character.
 * @list: The argument list containing values to be printed.
 *
 * Return: The number of characters printed.
 */
int _format_caces(char f, va_list *list, int *m, char *ptr)
{
	int n = 1;

	if (f == '%')
	{
		ptr[*m] = '%';
		*m = *m + 1;
		if (*m == 1023)
		{
			n = 0;
		}
	}
	if (f == 'c')
	{
		n = _printf_char(list, m, ptr);
	}
	if (f == 's')
	{
		n = _printf_str(list, m, ptr);
	}
    if (f == 'd' || f == 'i')
    {
        n = _printf_int(list, m, ptr);
    }
    if (f == 'b')
    {
        n = _print_binary(list, m, ptr);
    }
	if (f == 'u')
	{
		n = _print_Uint(list, m, ptr);
	}
	if (f == 'o')
	{
		n = _printf_oct(list, m, ptr);
	}
	if (f == 'x')
	{
		n = _printf_hex(list, m, ptr);
	}
    if (f == 'X')
	{
		n = _printf_HEX(list, m, ptr);
	}

	return (n);
}
