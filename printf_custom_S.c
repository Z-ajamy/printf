#include "main.h"

/**
 * printf_custom_S - Prints a string, replacing non-printable characters.
 * @list: Argument list containing the string to print.
 * @p: Pointer to the buffer where the formatted output is stored.
 * @k: Pointer to an integer tracking the buffer index.
 *
 * Description: This function prints a string, but replaces non-printable
 * ASCII characters (values < 32 or ≥ 127) with their hexadecimal
 * representation prefixed by "\x".
 *
 * Return: The total number of characters added to the buffer.
 */
int printf_custom_S(va_list *list, char *p, int *k)
{
	char *ptr = NULL;
	int n = 0, x = 0, temp = 0;

	ptr = va_arg(*list, char *);
	if (ptr == NULL)
		ptr = "(null)";

	while (ptr[n])
	{
		if ((ptr[n] < 32 && ptr[n] > 0) || ptr[n] >= 127)
		{
			Buffer_editor(p, k, '\\');
			Buffer_editor(p, k, 'x');
			x += 2;

			if (!((int)ptr[n] / 16)) /* Ensures two-digit hex format */
			{
				Buffer_editor(p, k, '0');
				x++;
			}

			_printf_HEX_rec(&x, (unsigned int)ptr[n], p, k);
			temp++;
		}
		else
		{
			Buffer_editor(p, k, ptr[n]);
		}
		n++;
	}
	return (n + x - temp);
}
