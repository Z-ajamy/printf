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
	int i = 0, n = 0, k = 0;
	char *ptr;
	va_list list;

	if (!str)
		return (-1);
	ptr = (char *)malloc(sizeof(char) * 1024);
	if (!ptr)
		return -1;	

	va_start(list, str);

	while (str[i])
	{
		if (str[i] != '%') /* Print normal characters */
		{
			Buffer_editor(ptr, &k, (str[i]));
			n++;
		}
		else /* Handle format specifiers */
		{
			if (!str[i + 1]) /* Handle cases where '%' is at the end */
			{
				n = -1;
				break;
			}
				n += _format_caces(str[++i], &list, ptr, &k);
		}
		i++;
	}

	_putchar(ptr, &k);

	free(ptr);
	va_end(list);
	return (n);
}
