#include "main.h"

/**
 * _printf_str - Prints a string.
 * @list: The argument list containing the string.
 *
 * Description: If the string is NULL, it prints "(null)" instead.
 *
 * Return: The number of characters printed.
 */
int _printf_str(va_list *list, int *m, char *ptr)
{
	char *p = NULL;
	int n = 0;

	p = va_arg(*list, char *);
	if (p == NULL)
		p = "(null)";

	while (p[n])
	{
		ptr[*m] = (p[n]);
		*m = *m + 1;
		if (*m == 1023)
		{
			return 0;
		}
		
		n++;
	}

	return (1);
}
