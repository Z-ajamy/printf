#include "main.h"

/**
 * _printf_oct_rec - Recursively prints the octal representation of a number
 * @n: Pointer to an integer that keeps track of the number of printed digits
 * @num: The unsigned integer to be converted and printed in octal
 *
 * Description: This function recursively divides the number by 8
 * to extract octal digits in the correct order.
 */
int _printf_oct_rec(unsigned int num, int *m, char *ptr)
{
	int a = 1;
	if (num / 8)
	{
		a = _printf_oct_rec(num / 8, m, ptr);
	}
	if (a == 0)
	{
		return 0;
	}
	ptr[*m] = ('0' + num % 8);
	*m = *m +1;
	if (*m == 1023)
	{
		return 0;
	}
	return 1;
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
int _printf_oct(va_list *list, int *m, char *ptr)
{
	int a;
	unsigned int num = va_arg(*list, unsigned int);

	a = _printf_oct_rec(num, m, ptr);
	if (a == 0)
	{
		return 0;
	}
	return (1);
}
