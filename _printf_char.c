#include "main.h"

/**
 * _printf_char - Prints a character from the argument list.
 * @list: The argument list containing the character to be printed.
 * @ptr: Pointer to the buffer where the character will be stored.
 * @k: Pointer to the index of the buffer.
 *
 * Description:
 * This function extracts a character from the variable argument list and
 * stores it in the buffer using the Buffer_editor function. It returns 1
 * since only one character is printed.
 *
 * Return: The number of characters printed (always 1).
 */
int _printf_char(va_list *list, char *ptr, int *k)
{
	Buffer_editor(ptr, k, (va_arg(*list, int)));
	return (1);
}
