#include "main.h"

/**
 * print_num_rec - Recursively prints an integer digit by digit
 * @num_rec: Pointer to an integer tracking the number of digits printed
 * @num: The integer to print
 * @ptr: Pointer to the buffer where characters are stored
 * @k: Pointer to the buffer index
 *
 * Description: This function recursively divides the number by 10
 * to extract and print each digit in the correct order.
 */
void print_num_rec(int *num_rec, int num, char *ptr, int *k)
{
	if (num / 10)
	{
		print_num_rec(num_rec, num / 10, ptr, k);
	}
	Buffer_editor(ptr, k, ('0' + num % 10));
	(*num_rec)++;
}

/**
 * _printf_int - Prints an integer using a buffer system
 * @list: Argument list containing the integer to print
 * @ptr: Pointer to the buffer where characters are stored
 * @k: Pointer to the buffer index
 *
 * Description: Extracts an integer from the argument list,
 * handles negative numbers, and prints the integer recursively.
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
		Buffer_editor(ptr, k, ('-'));
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
		Buffer_editor(ptr, k, ('0' + 8));
		n++;
	}

	return (n);
}
