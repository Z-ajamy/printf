#include "main.h"

/**
 * _format_caces - Handles specific format specifiers.
 * @f: The format specifier character.
 * @list: The argument list containing values to be printed.
 * @ptr: Pointer to the buffer where formatted output is stored.
 * @k: Pointer to the index of the buffer.
 *
 * Description:
 * This function processes a given format specifier and calls the corresponding
 * helper function to format and store the output into the buffer.
 * It supports the following format specifiers:
 * - %c : Prints a single character.
 * - %s : Prints a string.
 * - %% : Prints the percentage symbol.
 * - %d, %i : Prints an integer.
 * - %b : Prints an unsigned integer in binary.
 * - %u : Prints an unsigned decimal integer.
 * - %o : Prints an unsigned octal integer.
 * - %x : Prints an unsigned hexadecimal integer (lowercase).
 * - %X : Prints an unsigned hexadecimal integer (uppercase).
 * - %S : Prints a string with non-printable characters in \x format.
 * - %p : Prints a pointer address.
 *
 * Return: The number of characters printed.
 */
int _format_caces(char f, va_list *list, char *ptr, int *k)
{
	int n = 0; /* Variable to keep track of the number of characters printed */

	/* Handle percentage symbol */
	if (f == '%')
	{
		Buffer_editor(ptr, k, '%');
		n++;
	}
	/* Handle character format specifier */
	if (f == 'c')
	{
		n = _printf_char(list, ptr, k);
	}
	/* Handle string format specifier */
	if (f == 's')
	{
		n = _printf_str(list, ptr, k);
	}
	/* Handle integer format specifiers */
	if (f == 'd' || f == 'i')
	{
		n = _printf_int(list, ptr, k);
	}
	/* Handle binary format specifier */
	if (f == 'b')
	{
		n = _print_binary(list, ptr, k);
	}
	/* Handle unsigned integer format specifier */
	if (f == 'u')
	{
		n = _print_Uint(list, ptr, k);
	}
	/* Handle octal format specifier */
	if (f == 'o')
	{
		n = _printf_oct(list, ptr, k);
	}
	/* Handle lowercase hexadecimal format specifier */
	if (f == 'x')
	{
		n = _printf_hex(list, ptr, k);
	}
	/* Handle uppercase hexadecimal format specifier */
	if (f == 'X')
	{
		n = _printf_HEX(list, ptr, k);
	}
	/* Handle custom string format specifier */
	if (f == 'S')
	{
		n = printf_custom_S(list, ptr, k);
	}
	/* Handle pointer format specifier */
	if (f == 'p')
	{
		n = _printf_pointer(list, ptr, k);
	}

	/* Return the total number of characters printed */
	return (n);
}
