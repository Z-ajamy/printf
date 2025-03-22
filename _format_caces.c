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

	return (n);
}
