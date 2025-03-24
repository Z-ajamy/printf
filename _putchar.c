#include "main.h"

/**
 * _putchar - Writes the contents of a buffer to standard output.
 * @ptr: Pointer to the buffer containing the characters to print.
 * @k: Pointer to an integer representing the number of characters to write.
 *
 * Description: This function writes the first *k characters from the buffer
 * pointed to by ptr to the standard output using the write system call.
 *
 * Return: The number of bytes written on success, or -1 on failure.
 */
int _putchar(char *ptr, int *k)
{
	return (write(1, ptr, *k));
}
