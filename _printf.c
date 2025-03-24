#include "main.h"
/*
 * File: _printf.c
 * Auth: Abd Al-rahman Al-jamy
 *
 * Description:
 * This file contains the implementation of the `_printf` function,
 * a simplified version of the standard `printf` function.
 * It processes a format string and variadic arguments, handling
 * various format specifiers and buffering the output before
 * printing it to standard output.
 */

 #include "main.h"

 /**
  * _printf - Custom printf function to format and print data.
  * @str: The format string containing characters and format specifiers.
  *
  * Description:
  * This function takes a format string and a variable number of arguments,
  * processes them, and prints the formatted output. It supports various
  * format specifiers using helper functions.
  *
  * Return: The number of characters printed (excluding null byte),
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
		return -1;	

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
		else  /* Handle format specifiers */
		{
			/* Edge case: '%' at the end of string without a specifier */
			if (!str[i + 1]) /* Handle cases where '%' is at the end */
			{
				n = -1;
				break;
			}
			/* Process format specifier and update character count */
			n += _format_caces(str[++i], &list, ptr, &k);
		}
		i++;
	}

	/* Print the final formatted buffer output */
	_putchar(ptr, &k);


	/* Free allocated memory */
	free(ptr);

	/* End processing of variadic arguments */
	va_end(list);

	return (n); /* Return the total number of printed characters */
}
