#include "main.h"

/**
 * print_num_rec - Recursively prints digits of an integer
 * @num_rec: Pointer to an integer that keeps track of printed digits
 * @num: The number to be printed
 *
 * Description: This function recursively divides the number by 10
 * and prints its digits one by one, ensuring correct order.
 */
void print_num_rec(int *num_rec, int num)
{
	if (num / 10)
	{
		(*num_rec)++;
		print_num_rec(num_rec, num / 10);
	}

	_putchar('0' + num % 10);
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
int _printf_int(va_list *list)
{
	int n = 0;
	int num_rec = 0;
	char big = 0;
	int num;

	num = va_arg(*list, int);

	if (num < 0)
	{
		_putchar('-');
		n++;
		if (num < -2147483647) /* Handles INT_MIN case */
		{
			big = 1;
			num = num / 10;
		}
		num *= -1;
	}

	print_num_rec(&num_rec, num);
	n += num_rec + 1;

	if (big)
	{
		_putchar('0' + 8); /* Adds back the last digit of INT_MIN */
		n++;
	}

	return (n);
}
