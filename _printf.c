#include "main.h"

/**
 * _printf - Custom implementation of the printf function.
 * @str: The format string containing directives.
 *
 * Description:
 * This function prints formatted output based on the provided format string.
 * It supports the following format specifiers:
 * - %c : Prints a single character.
 * - %s : Prints a string.
 * - %% : Prints the percentage symbol.
 * - %i, %d : Prints an integer.
 * - %b : Prints an unsigned integer in binary.
 * - %u : Prints an unsigned decimal integer.
 * - %o : Prints an unsigned octal integer.
 * - %x, %X : Prints an unsigned hexadecimal integer (lowercase/uppercase).
 * - %S : Prints a string with non-printable characters in \x format.
 * - %p : Prints a pointer address.
 *
 * Return: The number of characters printed, or -1 on failure.
 */
int _printf(const char *str, ...)
{
	int i = 0, n = 0, k = 0; /* i for iteration, n for char count, k for buffer index */
	char *ptr; /* Pointer to dynamically allocated memory for buffer */
	va_list list; /* Variable argument list */

	/* Handle NULL format string */
	if (!str)
		return (-1);

	/* Allocate memory for the buffer (size 1024) */
	ptr = (char *)malloc(sizeof(char) * 1024);
	if (!ptr)
		return (-1);

	/* Initialize the variable argument list */
	va_start(list, str);

	/* Loop through each character in the format string */
	while (str[i])
	{
		/* If current character is not '%', print it normally */
		if (str[i] != '%')
		{
			Buffer_editor(ptr, &k, str[i]); /* Store character in buffer */
			n++; /* Increment character count */
		}
		else /* Handle format specifiers */
		{
			/* Check if '%' is at the end without a valid specifier */
			if (!str[i + 1])
			{
				n = -1; /* Invalid format string */
				break;
			}

			/* Check for supported format specifiers */
			if (str[i + 1] == 'c' || str[i + 1] == 's' || str[i + 1] == '%'
				|| str[i + 1] == 'i' || str[i + 1] == 'd' || str[i + 1] == 'b'
				|| str[i + 1] == 'u' || str[i + 1] == 'o' || str[i + 1] == 'x'
				|| str[i + 1] == 'X' || str[i + 1] == 'S' || str[i + 1] == 'p')
			{
				n += _format_caces(str[++i], &list, ptr, &k);
			}
			else /* If no valid specifier, treat '%' as a normal character */
			{
				Buffer_editor(ptr, &k, '%');
				n++;
			}
		}
		i++; /* Move to the next character */
	}

	/* Print the buffer contents */
	_putchar(ptr, &k);

	/* Free allocated memory and end variable argument list */
	free(ptr);
	va_end(list);

	/* Return the total number of characters printed */
	return (n);
}
