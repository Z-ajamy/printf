#include "main.h"

/**
 * _printf_hex_ptr - Recursively converts an unsigned long
 * integer to lowercase hexadecimal
 *                   and stores the result in a buffer.
 * @n: Pointer to an integer that keeps track of the
 * number of characters printed.
 * @num: The unsigned long integer to be converted and stored as hexadecimal.
 * @ptr: Pointer to the buffer where the formatted output is stored.
 * @k: Pointer to the index of the buffer.
 *
 * Description: This function recursively divides the number by 16
 *              to extract hexadecimal digits in the correct order.
 */
void _printf_hex_ptr(int *n, unsigned long int num, char *ptr, int *k)
{
	int a;

	if (num / 16)
	{
		_printf_hex_ptr(n, num / 16, ptr, k);
	}

	a = num % 16;

	if (a >= 0 && a <= 9)
	{
		Buffer_editor(ptr, k, ('0' + a));
	}
	else
	{
		Buffer_editor(ptr, k, ('a' + (a - 10)));
	}

	*n = *n + 1;
}

/**
 * _printf_pointer - Prints the address of a pointer in hexadecimal format.
 * @list: Argument list containing the pointer to be printed.
 * @ptr: Pointer to the buffer where the formatted output is stored.
 * @k: Pointer to the index of the buffer.
 *
 * Description: Extracts a pointer from the argument list and prints its
 *              address in lowercase hexadecimal format, prefixed with "0x".
 *              If the pointer is NULL, it prints "(nil)" instead.
 *
 * Return: The total number of characters printed.
 */
int _printf_pointer(va_list *list, char *ptr, int *k)
{
	unsigned long int num;
	int n = 0;

	num = va_arg(*list, unsigned long int);
	if (num == 0)
	{
		char *str = "(nil)";

		_printf_strings(&n, str, ptr, k);
		return (n);
	}

	Buffer_editor(ptr, k, ('0'));
	Buffer_editor(ptr, k, ('x'));
	n += 2;
	_printf_hex_ptr(&n, num, ptr, k);

	return (n);
}

/**
 * _printf_strings - Prints a string to the buffer.
 * @n: Pointer to an integer that keeps track of the number
 * of characters printed.
 * @str: Pointer to the string to be printed.
 * @ptr: Pointer to the buffer where the formatted output is stored.
 * @k: Pointer to the index of the buffer.
 *
 * Description: Iterates over the characters of the string and stores them in
 *              the buffer. If the string is NULL, the function does nothing.
 */
void _printf_strings(int *n, char *str, char *ptr, int *k)
{
	int i = 0;

	if (str == NULL)
	{
		return;
	}

	while (str[i])
	{
		Buffer_editor(ptr, k, str[i]);
		*n = *n + 1;
		i++;
	}
}
