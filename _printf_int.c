#include "main.h"

/**
 * print_num_rec - Recursively prints digits of an integer
 * @num_rec: Pointer to an integer that keeps track of printed digits
 * @num: The number to be printed
 *
 * Description: This function recursively divides the number by 10
 * and prints its digits one by one, ensuring correct order.
 */
void print_num_rec(int *num_rec, int num, char *ptr, int *k)
{
	if (num / 10)
	{
		print_num_rec(num_rec, num / 10, ptr, k);
	}

	ptr[*k] = ('0' + num % 10);
	*k = *k +1;
	if (*k == 1024)
	{
		_putchar(ptr, k);
		*k = 0;
	}
	(*num_rec)++;
}

/**
 * _printf_int - Prints an integer
 * @list: Argument list containing the integer to print
 *
 * Description: Extracts an integer from the argument list, handles negative
 * values by printing a '-' sign, and correctly prints INT_MIN.
 *
 * Return: The total number of characters printed.
 */
int _printf_int(va_list *list, char *ptr, int *k)
{
	int n = 0;
	char big = 0;
	int num;

	num = va_arg(*list, int);

	if (num < 0)
	{
		ptr[*k] = ('-');
		*k = *k +1;
		if (*k == 1024)
		{
			_putchar(ptr, k);
			*k = 0;
		}
		n++;
		if (num < -2147483647) /* Handles INT_MIN case */
		{
			big = 1;
			num = num / 10;
		}
		num *= -1;
	}

	print_num_rec(&n, num, ptr, k);

	if (big)
	{
		ptr[*k] = ('0' + 8);
		*k = *k +1;
		if (*k == 1024)
		{
			_putchar(ptr, k);
			*k = 0;
		} /* Adds back the last digit of INT_MIN */
		n++;
	}
	return (n);
}
