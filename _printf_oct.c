#include "main.h"

/**
 * _printf_oct_rec - Recursively prints the octal representation of a number
 * @n: Pointer to an integer that keeps track of the number of printed digits
 * @num: The unsigned integer to be converted and printed in octal
 *
 * Description: This function recursively divides the number by 8
 * to extract octal digits in the correct order.
 */
void _printf_oct_rec(int *n, unsigned int num)
{
	if (num / 8)
	{
		_printf_oct_rec(n, num / 8);
	}

	_putchar('0' + num % 8);
	*n = *n + 1;
}

/**
 * _printf_oct - Converts an unsigned integer to octal and prints it
 * @list: Argument list containing the number to convert
 *
 * Description: Extracts an unsigned integer from the argument list and
 * prints its octal representation using recursion.
 *
 * Return: The total number of characters printed.
 */
int _printf_oct(va_list *list)
{
	int n = 0;
	unsigned int num = va_arg(*list, unsigned int);

	_printf_oct_rec(&n, num);
	return (n);
}
