#include "main.h"

/**
 * _printf_char - Prints a single character.
 * @list: The argument list containing the character.
 *
 * Return: Always returns 1 (one character printed).
 */
int _printf_char(va_list *list)
{
	_putchar(va_arg(*list, int));
	return (1);
}
