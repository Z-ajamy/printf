#include "main.h"

/**
 * _printf_str - Prints a string.
 * @list: The argument list containing the string.
 *
 * Description: If the string is NULL, it prints "(null)" instead.
 *
 * Return: The number of characters printed.
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
		p[*k] = (ptr[n]);
		*k = *k +1;
		if (*k == 1024)
		{
			_putchar(p, k);
			*k = 0;
		}
		n++;
	}

	return (n);
}
