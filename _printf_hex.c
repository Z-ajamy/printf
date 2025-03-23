#include "main.h"

/**
 * _printf_hex_rec - Recursively prints the hexadecimal representation of a number
 * @n: Pointer to an integer that keeps track of the number of printed digits
 * @num: The unsigned integer to be converted and printed in hexadecimal
 *
 * Description: This function recursively divides the number by 16
 * to extract hexadecimal digits in the correct order.
 */
int _printf_hex_rec(unsigned int num, int *m, char *ptr)
{
	int a, b;

	if (num / 16)
	{
		b = _printf_hex_rec(num / 16, m, ptr);
	}
	if (b == 0)
	{
		_putchar(ptr, *m);
		*m = 0;
	}

	a = num % 16;

	if (a >= 0 && a <= 9)
	{
		ptr[*m] = ('0' + a);
		*m = *m +1;
	}
	else
	{
		ptr[*m] = ('a' + (a - 10));
		*m = *m +1;
	}

	if (*m == 1023)
	{
		_putchar(ptr, *m);
		*m = 0;
	}
	return 1;
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
int _printf_hex(va_list *list, int *m, char *ptr)
{
	unsigned int num;
	int a;
	num = va_arg(*list, unsigned int);

	a = _printf_hex_rec(num, m, ptr);
	if (a == 0)
	{
		_putchar(ptr, *m);
		*m = 0;
	}
	return (1);
}
