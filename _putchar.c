#include "main.h"

/**
 * _putchar - Writes a single character to standard output.
 * @a: The character to print.
 *
 * Return: On success, returns 1. On failure, -1 is returned.
 */
int _putchar(char *a, int n)
{
	int b = write(1, a, n);
	return (b);
}
