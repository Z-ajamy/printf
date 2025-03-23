#include "main.h"

/**
 * _printf_hex_rec - Recursively prints the hexadecimal representation of a number
 * @n: Pointer to an integer that keeps track of the number of printed digits
 * @num: The unsigned integer to be converted and printed in hexadecimal
 *
 * Description: This function recursively divides the number by 16
 * to extract hexadecimal digits in the correct order.
 */
void _printf_hex_rec(int *n, unsigned int num)
{
	int a;

	if (num / 16)
	{
		_printf_hex_rec(n, num / 16);
	}

	a = num % 16;

	if (a >= 0 && a <= 9)
	{
		_putchar('0' + a);
	}
	else
	{
		_putchar('a' + (a - 10));
	}

	*n = *n + 1;
}

/**
 * _printf_hex - Converts an unsigned integer to hexadecimal and prints it
 * @list: Argument list containing the number to convert
 *
 * Description: Extracts an unsigned integer from the argument list and
 * prints its lowercase hexadecimal representation using recursion.
 *
 * Return: The total number of characters printed.
 */
int _printf_hex(va_list *list)
{
	unsigned int num;
	int n = 0;

	num = va_arg(*list, unsigned int);

	_printf_hex_rec(&n, num);
	return (n);
}
