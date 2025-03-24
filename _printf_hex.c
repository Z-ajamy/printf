#include "main.h"

/**
 * _printf_hex_rec - Recursively converts and prints an unsigned integer
 *                   in lowercase hexadecimal format.
 * @n: Pointer to an integer tracking the number of characters printed.
 * @num: The unsigned integer to be converted and printed.
 * @ptr: Pointer to the buffer where formatted output is stored.
 * @k: Pointer to the index of the buffer.
 *
 * Description: This function recursively divides the number by 16
 *              to extract hexadecimal digits in the correct order.
 */
void _printf_hex_rec(int *n, unsigned int num, char *ptr, int *k)
{
	int a;

	if (num / 16)
	{
		_printf_hex_rec(n, num / 16, ptr, k);
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
 * _printf_hex - Converts an unsigned integer to lowercase hexadecimal
 *               and prints it.
 * @list: Argument list containing the number to convert.
 * @ptr: Pointer to the buffer where formatted output is stored.
 * @k: Pointer to the index of the buffer.
 *
 * Description: Extracts an unsigned integer from the argument list and
 *              prints its lowercase hexadecimal representation using recursion.
 *
 * Return: The total number of characters printed.
 */
int _printf_hex(va_list *list, char *ptr, int *k)
{
	unsigned int num;
	int n = 0;

	num = va_arg(*list, unsigned int);

	_printf_hex_rec(&n, num, ptr, k);
	return (n);
}
