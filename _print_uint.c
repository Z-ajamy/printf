#include "main.h"

/**
 * _print_Uint - Prints an unsigned integer.
 * @list: Argument list containing the number to print.
 * @ptr: Pointer to the buffer where the number is stored.
 * @k: Pointer to the index of the buffer.
 *
 * Description:
 * This function extracts an unsigned integer from the argument list
 * and prints it using recursion.
 *
 * Return: The total number of characters printed.
 */
int _print_Uint(va_list *list, char *ptr, int *k)
{
	int n = 0;
	unsigned int num;

	num = va_arg(*list, unsigned int);

	print_Unum_rec(&n, num, ptr, k);
	return (n);
}

/**
 * print_Unum_rec - Recursively prints an unsigned integer.
 * @num_rec: Pointer to an integer that counts the number of printed digits.
 * @num: The unsigned integer to be printed.
 * @ptr: Pointer to the buffer where the number is stored.
 * @k: Pointer to the index of the buffer.
 *
 * Description:
 * This function recursively divides the number by 10 to extract digits
 * in the correct order and stores them in the buffer using Buffer_editor.
 */
void print_Unum_rec(int *num_rec, unsigned int num, char *ptr, int *k)
{
	if (num / 10)
	{
		print_Unum_rec(num_rec, num / 10, ptr, k);
	}

	Buffer_editor(ptr, k, ('0' + num % 10));

	(*num_rec)++;
}
