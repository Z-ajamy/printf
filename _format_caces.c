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
	int i;
	int n = 0;

	char_case cases[] = {
		{'c', _printf_char},{'s', _printf_str},
		{'d', _printf_int},{'i', _printf_int},
		{'b', _print_binary},{'u', _print_Uint},
		{'o', _printf_oct},{'x', _printf_hex},
		{'X', _printf_HEX},{'S', printf_custom_S},
		{'p', _printf_pointer},
		{'\0', NULL}
	};

	while (cases[i].c)
	{
		if (cases[i].c == f)
		{
			return((cases[i].ptr)(list, ptr, k));
		}
		i++;
	}

	if (f == '%')
	{
		Buffer_editor(ptr, k, '%');
		n++;
	}
	else
	{
		Buffer_editor(ptr, k, '%');
		Buffer_editor(ptr, k, f);
		n += 2;
	}
	return (n);
}
