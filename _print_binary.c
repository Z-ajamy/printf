#include "main.h"

/**
 * binary_rec - Recursively prints the binary representation of a number
 * @num_rec: Pointer to an integer that counts the number of printed digits
 * @num: The unsigned integer to be converted and printed in binary
 *
 * Description: This function recursively divides the number by 2
 * to extract binary digits in the correct order.
 */
int binary_rec(unsigned int num, int *m, char *ptr)
{
	int a = 1;
	if (num / 2)
	{
		a = binary_rec(num / 2, m, ptr);
	}
	if (a == 0)
	{
		return 0;
	}
	ptr[*m] = ('0' + num % 2);
	*m = *m +1;
	if (*m == 1023)
	{
		return 0;
	}
	return 1;
}

/**
 * _print_binary - Converts an unsigned integer to binary and prints it
 * @list: Argument list containing the number to convert
 *
 * Description: Extracts an unsigned integer from the argument list and
 * prints its binary representation using recursion.
 *
 * Return: The total number of characters printed.
 */
int _print_binary(va_list *list, int *m, char *ptr)
{
	int a;
	unsigned int num = va_arg(*list, unsigned int);
	if (num == 0)
	{
		ptr[*m] = ('0');
		*m = *m +1;
		if (*m == 1023)
		{
			return (0);
		}
		return (1);
	}
	a = binary_rec(num, m, ptr);
	if (a == 0)
	{
		return 0;
	}
	return (1);
}
