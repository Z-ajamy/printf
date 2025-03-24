#include "main.h"

/**
 * _printf - Custom implementation of printf function.
 * @str: The format string containing characters and format specifiers.
 *
 * Description:
 * This function takes a format string and additional arguments,
 * processes format specifiers, and prints the formatted output accordingly.
 *
 * Return: The total number of characters printed (excluding null byte),
 * or -1 if an error occurs.
 */
int _printf(const char *str, ...)
{
	int i = 0, n = 0, k = 0; /* Iterators and character counters */
	char *ptr; /* Buffer for storing the formatted output */
	va_list list; /* List to process variadic function arguments */

	/* Check if the format string is NULL */
	if (!str)
		return (-1);

	/* Allocate memory dynamically for the buffer */
	ptr = (char *)malloc(sizeof(char) * 1024);
	if (!ptr)
		return (-1);

	/* Initialize the variadic argument list */
	va_start(list, str);

	/* Loop through the format string */
	while (str[i])
	{
		/* If character is not '%' print normally */
		if (str[i] != '%')
		{
			Buffer_editor(ptr, &k, (str[i])); /* Store character in buffer */
			n++; /* Increase the count of printed characters */
		}
		else /* Handle format specifiers */
		{
			/* Edge case: '%' at the end of string without a specifier */
			if (!str[i + 1])
			{
				n = -1;
				break;
			}
			/* Process format specifier and update character count */
			n += _format_caces(str[++i], &list, ptr, &k);
		}
		i++; /* Move to the next character */
	}

	/* Print the final formatted buffer output */
	_putchar(ptr, &k);

	/* Free allocated memory */
	free(ptr);

	/* End processing of variadic arguments */
	va_end(list);

	return (n); /* Return the total number of printed characters */
}
