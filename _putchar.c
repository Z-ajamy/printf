#include "main.h"

/**
 * _putchar - Writes a single character to standard output.
 * @a: The character to print.
 *
 * Return: On success, returns 1. On failure, -1 is returned.
 */
int _putchar(char* ptr, int *k)
{
	return (write(1, ptr, *k));
}
