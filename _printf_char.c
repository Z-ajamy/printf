#include "main.h"

/**
 * _printf_char - Prints a single character.
 * @list: The argument list containing the character.
 *
 * Return: Always returns 1 (one character printed).
 */
int _printf_char(va_list *list, char *ptr, int *k)
{
	ptr[*k] = (va_arg(*list, int));
	*k = *k +1;
	if (*k == 1024)
	{
		_putchar(ptr, k);
		*k = 0;
	}
	return (1);
}
