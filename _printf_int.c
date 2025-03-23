#include "main.h"

/**
 * print_num_rec - Recursively prints digits of an integer
 * @num_rec: Pointer to an integer that keeps track of printed digits
 * @num: The number to be printed
 *
 * Description: This function recursively divides the number by 10
 * and prints its digits one by one, ensuring correct order.
 */
int print_num_rec(int num, int *m, char *ptr)
{
	int a = 1;
	if (num / 10)
	{
		a = print_num_rec(num / 10, m, ptr);
	}
	if (a == 0)
	{
		return 0;
	}
	ptr[*m] = ('0' + num % 10);
	*m = *m +1;
	if (*m == 1023)
	{
		return 0;
	}
	return 1;
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
int _printf_int(va_list *list, int *m, char *ptr)
{
	int a;
	char big = 0;
	int num;

	num = va_arg(*list, int);

	if (num < 0)
	{
		ptr[*m] = ('-');
		*m = *m + 1;
		if (*m == 1023)
		{
			return 0;
		}
		
		if (num < -2147483647) /* Handles INT_MIN case */
		{
			big = 1;
			num = num / 10;
		}
		num *= -1;
	}

	a = print_num_rec(num, m, ptr);
	if (a == 0)
	{
		return 0;
	}
	
	if (big)
	{
		ptr[*m] = ('0' + 8); /* Adds back the last digit of INT_MIN */
		*m = *m + 1;
	}
	if (*m == 1023)
	{
		return 0;
	}
	return (1);
}
