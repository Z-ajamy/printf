#include "main.h"

/**
 * _printf_HEX_rec - Recursively prints the uppercase hexadecimal representation of a number
 * @n: Pointer to an integer that keeps track of the number of printed digits
 * @num: The unsigned integer to be converted and printed in uppercase hexadecimal
 *
 * Description: This function recursively divides the number by 16
 * to extract hexadecimal digits in the correct order.
 */
void _printf_HEX_rec(int *n, unsigned int num, char *ptr, int *k)
{
	int a;

	if (num / 16)
	{
		_printf_HEX_rec(n, num / 16, ptr, k);
	}

	a = num % 16;

	if (a >= 0 && a <= 9)
	{
		ptr[*k] = ('0' + a);
				*k = *k +1;
				if (*k == 1024)
				{
					_putchar(ptr, k);
					*k = 0;
				}
	}
	else
	{
		ptr[*k] = ('A' + (a - 10));
				*k = *k +1;
				if (*k == 1024)
				{
					_putchar(ptr, k);
					*k = 0;
				}
	}

	*n = *n + 1;
}

/**
 * _printf_HEX - Converts an unsigned integer to uppercase hexadecimal and prints it
 * @list: Argument list containing the number to convert
 *
 * Description: Extracts an unsigned integer from the argument list and
 * prints its uppercase hexadecimal representation using recursion.
 *
 * Return: The total number of characters printed.
 */
int _printf_HEX(va_list *list, char *ptr, int *k)
{
	unsigned int num;
	int n = 0;

	num = va_arg(*list, unsigned int);

	_printf_HEX_rec(&n, num, ptr, k);
	return (n);
}
