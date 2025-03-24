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
			if (   str[i + 1] == 'c' || str[i + 1] == 's' || str[i + 1] == '%'
				|| str[i + 1] == 'i' || str[i + 1] == 'd' || str[i + 1] == 'b'
				|| str[i + 1] == 'u' || str[i + 1] == 'o' || str[i + 1] == 'x'
				|| str[i + 1] == 'X' || str[i + 1] == 'S' || str[i + 1] == 'p')
			{
				n += _format_caces(str[++i], &list, ptr, &k);
			}
			else /* Print '%' as a normal character if no valid specifier */
			{
				Buffer_editor(ptr, &k, ('%'));
				n++;
			}
		}
		i++;
	}

	_putchar(ptr, &k);

	free(ptr);
	va_end(list);
	return (n);
}
