#include "main.h"

/**
 * _printf_char - Prints a single character.
 * @list: The argument list containing the character.
 *
 * Return: Always returns 1 (one character printed).
 */
int _printf_char(va_list *list, int *m, char *ptr)
{
	ptr[*m] = (va_arg(*list, int));
	*m = *m + 1;
	if (*m == 1023)
	{
		return 0;
	}
	return (1);
}
