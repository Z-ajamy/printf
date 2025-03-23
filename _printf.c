#include "main.h"

/**
 * _printf - Custom implementation of printf function.
 * @str: The format string containing directives.
 *
 * Description: Prints formatted output based on the provided format string.
 * Supports %c (character), %s (string), and %% (percentage symbol).
 *
 * Return: The number of characters printed.
 */
int _printf(const char *str, ...)
{
	int i = 0, n = 0, err = 0, m = 1;
	char *ptr;
	va_list list;

	ptr = (char *)malloc(sizeof(char) * 1024);
	if (!ptr)
		return -1;
	
	if (!str)
	{
		return (-1);
	}

	va_start(list, str);

	while (str[i] && n < 1023)
	{
		if (str[i] != '%')
		{
			ptr[n] = str[i];
			n++;
		}
		else
		{
			if (!str[i + 1])
			{
				err = -1;
			}
			if (   str[i + 1] == 'c' || str[i + 1] == 's' || str[i + 1] == '%'
				|| str[i + 1] == 'i' || str[i + 1] == 'd' || str[i + 1] == 'b'
				|| str[i + 1] == 'u' || str[i + 1] == 'o' || str[i + 1] == 'x'
				|| str[i + 1] == 'X')
			{
				m = _format_caces(str[++i], &list, &n, ptr);
				if (m == 0)
				{
					_putchar(ptr, m);
					m = 0;
				}
			}
			else if(err == 0)
			{
				ptr[n] = '%';
				n++;
			}
		}
		i++;
	}
	ptr[n] = '\0';
	_putchar(ptr, n);
	free(ptr);
	va_end(list);
	if (err != 0)
	{
		n = err;
	}
	return (n);
}
