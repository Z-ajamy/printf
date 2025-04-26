#include "main.h"

/**
 * binary_rec - Recursively prints the binary representation of a number.
 * @num_rec: Pointer to an integer that counts the number of printed digits.
 * @num: The unsigned integer to be converted and printed in binary.
 * @ptr: Pointer to the buffer where the binary digits are stored.
 * @k: Pointer to the index of the buffer.
 *
 * Description:
 * This function recursively divides the number by 2 to extract binary digits
 * in the correct order and stores them in the buffer using Buffer_editor.
 */
void binary_rec(int *num_rec, unsigned int num, char *ptr, int *k)
{
	if (num / 2)
	{
		binary_rec(num_rec, num / 2, ptr, k);
	}

	Buffer_editor(ptr, k, ('0' + num % 2));
	*num_rec = *num_rec + 1;
}

/**
 * _print_binary - Converts an unsigned integer to binary and prints it.
 * @list: Argument list containing the number to convert.
 * @ptr: Pointer to the buffer where the binary digits are stored.
 * @k: Pointer to the index of the buffer.
 *
 * Description:
 * Extracts an unsigned integer from the argument list and prints its binary
 * representation using recursion. If the number
 * is zero, it directly stores '0'.
 *
 * Return: The total number of characters printed.
 */
int _print_binary(va_list *list, char *ptr, int *k)
{
	int num_rec = 0;
	unsigned int num = va_arg(*list, unsigned int);

	if (num == 0)
	{
		Buffer_editor(ptr, k, ('0'));
		return (1);
	}

	binary_rec(&num_rec, num, ptr, k);
	return (num_rec);
}
