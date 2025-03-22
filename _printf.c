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
	int i = 0, n = 0;
	va_list list;

	if (!str)
	{
		va_end(list);
		return (-1);
	}

	va_start(list, str);

	while (str[i])
	{
		if (str[i] != '%') /* Print normal characters */
		{
			_putchar(str[i]);
			n++;
		}
		else /* Handle format specifiers */
		{
			if (!str[i + 1]) /* Handle cases where '%' is at the end */
			{
				return (-1);
			}
			if (str[i + 1] == 'c' || str[i + 1] == 's' || str[i + 1] == '%' || str[i + 1] == 'i' || str[i + 1] == 'd'|| str[i + 1] == 'b')
			{
				n += _format_caces(str[++i], &list);
			}
			else /* Print '%' as a normal character if no valid specifier */
			{
				_putchar('%');
				n++;
			}
		}

		i++;
	}

	va_end(list);
	return (n);
}
