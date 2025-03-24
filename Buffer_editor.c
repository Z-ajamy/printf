#include "main.h"

/**
 * Buffer_editor - Manages the buffer and writes characters into it.
 * @p: Pointer to the buffer where characters are stored.
 * @k: Pointer to the index of the buffer.
 * @c: The character to be stored in the buffer.
 *
 * Description:
 * This function places a character into the buffer at the current index and
 * increments the index. If the buffer reaches its limit (1024 characters),
 * it flushes the buffer using _putchar and resets the index to 0.
 */
void Buffer_editor(char *p, int *k, char c)
{
	p[*k] = c;
	*k = *k + 1;

	/* Flush the buffer if it reaches the limit */
	if (*k == 1024)
	{
		_putchar(p, k);
		*k = 0;
	}
}
