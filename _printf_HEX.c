#include "main.h"

/**
 * _printf_HEX_rec - Recursively prints the uppercase hexadecimal representation of a number
 * @n: Pointer to an integer that keeps track of the number of printed digits
 * @num: The unsigned integer to be converted and printed in uppercase hexadecimal
 *
 * Description: This function recursively divides the number by 16
 * to extract hexadecimal digits in the correct order.
 */
int _printf_HEX_rec(unsigned int num, int *m, char *ptr)
{
	int a, b;

	if (num / 16)
	{
		b = _printf_HEX_rec(num / 16, m , ptr);
	}
	if (b == 0)
	{
		return 0;
	}

	a = num % 16;

	if (a >= 0 && a <= 9)
	{
		ptr[*m] = ('0' + a);
		*m = *m +1;
	}
	else
	{
		ptr[*m] = ('A' + (a - 10));
		*m = *m +1;
	}

	if (*m == 1023)
	{
		return 0;
	}
	return 1;
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
int _printf_HEX(va_list *list, int *m, char *ptr)
{
	unsigned int num;
	int a;

	num = va_arg(*list, unsigned int);

	a = _printf_HEX_rec(num, m, ptr);
	if (a == 0)
	{
		return 0;
	}
	return (1);
}
