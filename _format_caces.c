#include "main.h"

/**
 * _format_caces - Handles specific format specifiers.
 * @f: The format specifier character.
 * @list: The argument list containing values to be printed.
 *
 * Return: The number of characters printed.
 */
int _format_caces(char f, va_list *list)
{
	int n = 0;

	if (f == '%')
	{
		_putchar('%');
		n++;
	}
	if (f == 'c')
	{
		n = _printf_char(list);
	}
	if (f == 's')
	{
		n = _printf_str(list);
	}
    if (f == 'd' || f == 'i')
    {
        n = _printf_int(list);
    }
    if (f == 'b')
    {
        n = _print_binary(list);
    }
	if (f == 'u')
	{
		n = _print_Uint(list);
	}
	if (f == 'o')
	{
		n = _printf_oct(list);
	}
	if (f == 'x')
	{
		n = _printf_hex(list);
	}
    if (f == 'X')
	{
		n = _printf_HEX(list);
	}

	return (n);
}
