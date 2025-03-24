#include "main.h"

/**
 * _printf_str - Prints a string from the argument list.
 * @list: Argument list containing the string to print.
 * @p: Pointer to the buffer where characters will be stored.
 * @k: Pointer to the buffer index.
 *
 * Description: Extracts a string from the argument list
 * and prints it character by character. If the string is NULL,
 * it prints "(null)" instead.
 *
 * Return: The total number of characters printed.
 */
int _printf_str(va_list *list, char *p, int *k)
{
	char *ptr = NULL;
	int n = 0;

	ptr = va_arg(*list, char *);
	if (ptr == NULL)
		ptr = "(null)";

	while (ptr[n])
	{
		Buffer_editor(p, k, (ptr[n]));
		n++;
	}

	return (n);
}
