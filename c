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
#include "main.h"

/**
 * _format_caces - Handles specific format specifiers.
 * @f: The format specifier character.
 * @list: The argument list containing values to be printed.
 * @ptr: Pointer to the buffer where formatted output is stored.
 * @k: Pointer to the index of the buffer.
 *
 * Description:
 * This function processes a given format specifier and calls the corresponding
 * helper function to format and store the output into the buffer.
 * It supports the following format specifiers:
 * - %c : Prints a single character.
 * - %s : Prints a string.
 * - %% : Prints the percentage symbol.
 * - %d, %i : Prints an integer.
 * - %b : Prints an unsigned integer in binary.
 * - %u : Prints an unsigned decimal integer.
 * - %o : Prints an unsigned octal integer.
 * - %x : Prints an unsigned hexadecimal integer (lowercase).
 * - %X : Prints an unsigned hexadecimal integer (uppercase).
 * - %S : Prints a string with non-printable characters in \x format.
 * - %p : Prints a pointer address.
 *
 * Return: The number of characters printed.
 */
int _format_caces(char f, va_list *list, char *ptr, int *k)
{
	int n = 0; /* Variable to keep track of the number of characters printed */

	/* Handle percentage symbol */
	if (f == '%')
	{
		Buffer_editor(ptr, k, '%');
		n++;
	}
	/* Handle character format specifier */
	if (f == 'c')
	{
		n = _printf_char(list, ptr, k);
	}
	/* Handle string format specifier */
	if (f == 's')
	{
		n = _printf_str(list, ptr, k);
	}
	/* Handle integer format specifiers */
	if (f == 'd' || f == 'i')
	{
		n = _printf_int(list, ptr, k);
	}
	/* Handle binary format specifier */
	if (f == 'b')
	{
		n = _print_binary(list, ptr, k);
	}
	/* Handle unsigned integer format specifier */
	if (f == 'u')
	{
		n = _print_Uint(list, ptr, k);
	}
	/* Handle octal format specifier */
	if (f == 'o')
	{
		n = _printf_oct(list, ptr, k);
	}
	/* Handle lowercase hexadecimal format specifier */
	if (f == 'x')
	{
		n = _printf_hex(list, ptr, k);
	}
	/* Handle uppercase hexadecimal format specifier */
	if (f == 'X')
	{
		n = _printf_HEX(list, ptr, k);
	}
	/* Handle custom string format specifier */
	if (f == 'S')
	{
		n = printf_custom_S(list, ptr, k);
	}
	/* Handle pointer format specifier */
	if (f == 'p')
	{
		n = _printf_pointer(list, ptr, k);
	}

	/* Return the total number of characters printed */
	return (n);
}
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
 * representation using recursion. If the number is zero, it directly stores '0'.
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
#include "main.h"

/**
 * _printf - Custom implementation of the printf function.
 * @str: The format string containing directives.
 *
 * Description:
 * This function prints formatted output based on the provided format string.
 * It supports the following format specifiers:
 * - %c : Prints a single character.
 * - %s : Prints a string.
 * - %% : Prints the percentage symbol.
 * - %i, %d : Prints an integer.
 * - %b : Prints an unsigned integer in binary.
 * - %u : Prints an unsigned decimal integer.
 * - %o : Prints an unsigned octal integer.
 * - %x, %X : Prints an unsigned hexadecimal integer (lowercase/uppercase).
 * - %S : Prints a string with non-printable characters in \x format.
 * - %p : Prints a pointer address.
 *
 * Return: The number of characters printed, or -1 on failure.
 */
int _printf(const char *str, ...)
{
	int i = 0, n = 0, k = 0; /* i for iteration, n for char count, k for buffer index */
	char *ptr; /* Pointer to dynamically allocated memory for buffer */
	va_list list; /* Variable argument list */

	/* Handle NULL format string */
	if (!str)
		return (-1);

	/* Allocate memory for the buffer (size 1024) */
	ptr = (char *)malloc(sizeof(char) * 1024);
	if (!ptr)
		return (-1);

	/* Initialize the variable argument list */
	va_start(list, str);

	/* Loop through each character in the format string */
	while (str[i])
	{
		/* If current character is not '%', print it normally */
		if (str[i] != '%')
		{
			Buffer_editor(ptr, &k, str[i]); /* Store character in buffer */
			n++; /* Increment character count */
		}
		else /* Handle format specifiers */
		{
			/* Check if '%' is at the end without a valid specifier */
			if (!str[i + 1])
			{
				n = -1; /* Invalid format string */
				break;
			}

			/* Check for supported format specifiers */
			if (str[i + 1] == 'c' || str[i + 1] == 's' || str[i + 1] == '%'
				|| str[i + 1] == 'i' || str[i + 1] == 'd' || str[i + 1] == 'b'
				|| str[i + 1] == 'u' || str[i + 1] == 'o' || str[i + 1] == 'x'
				|| str[i + 1] == 'X' || str[i + 1] == 'S' || str[i + 1] == 'p')
			{
				n += _format_caces(str[++i], &list, ptr, &k);
			}
			else /* If no valid specifier, treat '%' as a normal character */
			{
				Buffer_editor(ptr, &k, '%');
				n++;
			}
		}
		i++; /* Move to the next character */
	}

	/* Print the buffer contents */
	_putchar(ptr, &k);

	/* Free allocated memory and end variable argument list */
	free(ptr);
	va_end(list);

	/* Return the total number of characters printed */
	return (n);
}
#include "main.h"

/**
 * _printf_HEX_rec - Recursively prints the uppercase hexadecimal representation of a number
 * @n: Pointer to an integer that keeps track of the number of printed digits
 * @num: The unsigned integer to be converted and printed in uppercase hexadecimal
 * @ptr: Pointer to the buffer where the output is stored
 * @k: Pointer to the index of the buffer
 *
 * Description: This function recursively divides the number by 16
 * to extract hexadecimal digits in the correct order and stores
 * them in the buffer for formatted output.
 */
void _printf_HEX_rec(int *n, unsigned int num, char *ptr, int *k)
{
	int a;

	if (num / 16)
	{
		_printf_HEX_rec(n, num / 16, ptr, k);
	}

	a = num % 16;

	if (a >= 0 && a <= 9)
	{
		Buffer_editor(ptr, k, ('0' + a));
	}
	else
	{
		Buffer_editor(ptr, k, ('A' + (a - 10)));
	}

	*n = *n + 1;
}

/**
 * _printf_HEX - Converts an unsigned integer to uppercase hexadecimal and prints it
 * @list: Argument list containing the number to convert
 * @ptr: Pointer to the buffer where the output is stored
 * @k: Pointer to the index of the buffer
 *
 * Description: Extracts an unsigned integer from the argument list and
 * prints its uppercase hexadecimal representation using recursion.
 *
 * Return: The total number of characters printed.
 */
int _printf_HEX(va_list *list, char *ptr, int *k)
{
	unsigned int num;
	int n = 0;

	num = va_arg(*list, unsigned int);

	_printf_HEX_rec(&n, num, ptr, k);
	return (n);
}
#include "main.h"

/**
 * _printf_char - Prints a character from the argument list.
 * @list: The argument list containing the character to be printed.
 * @ptr: Pointer to the buffer where the character will be stored.
 * @k: Pointer to the index of the buffer.
 *
 * Description:
 * This function extracts a character from the variable argument list and
 * stores it in the buffer using the Buffer_editor function. It returns 1
 * since only one character is printed.
 *
 * Return: The number of characters printed (always 1).
 */
int _printf_char(va_list *list, char *ptr, int *k)
{
	Buffer_editor(ptr, k, (va_arg(*list, int)));
	return (1);
}
#include "main.h"

/**
 * _printf_hex_rec - Recursively converts and prints an unsigned integer
 *                   in lowercase hexadecimal format.
 * @n: Pointer to an integer tracking the number of characters printed.
 * @num: The unsigned integer to be converted and printed.
 * @ptr: Pointer to the buffer where formatted output is stored.
 * @k: Pointer to the index of the buffer.
 *
 * Description: This function recursively divides the number by 16
 *              to extract hexadecimal digits in the correct order.
 */
void _printf_hex_rec(int *n, unsigned int num, char *ptr, int *k)
{
	int a;

	if (num / 16)
	{
		_printf_hex_rec(n, num / 16, ptr, k);
	}

	a = num % 16;

	if (a >= 0 && a <= 9)
	{
		Buffer_editor(ptr, k, ('0' + a));
	}
	else
	{
		Buffer_editor(ptr, k, ('a' + (a - 10)));
	}

	*n = *n + 1;
}

/**
 * _printf_hex - Converts an unsigned integer to lowercase hexadecimal
 *               and prints it.
 * @list: Argument list containing the number to convert.
 * @ptr: Pointer to the buffer where formatted output is stored.
 * @k: Pointer to the index of the buffer.
 *
 * Description: Extracts an unsigned integer from the argument list and
 *              prints its lowercase hexadecimal representation using recursion.
 *
 * Return: The total number of characters printed.
 */
int _printf_hex(va_list *list, char *ptr, int *k)
{
	unsigned int num;
	int n = 0;

	num = va_arg(*list, unsigned int);

	_printf_hex_rec(&n, num, ptr, k);
	return (n);
}
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
#include "main.h"

/**
 * _printf_oct_rec - Recursively prints the octal representation of a number.
 * @n: Pointer to an integer that keeps track of the number of printed digits.
 * @num: The unsigned integer to be converted and printed in octal.
 * @ptr: Pointer to the buffer where characters will be stored.
 * @k: Pointer to the buffer index.
 *
 * Description: This function recursively divides the number by 8
 * to extract octal digits in the correct order.
 */
void _printf_oct_rec(int *n, unsigned int num, char *ptr, int *k)
{
	if (num / 8)
	{
		_printf_oct_rec(n, num / 8, ptr, k);
	}

	Buffer_editor(ptr, k, ('0' + num % 8));
	*n = *n + 1;
}

/**
 * _printf_oct - Converts an unsigned integer to octal and prints it.
 * @list: Argument list containing the number to convert.
 * @ptr: Pointer to the buffer where characters will be stored.
 * @k: Pointer to the buffer index.
 *
 * Description: Extracts an unsigned integer from the argument list
 * and prints its octal representation using recursion.
 *
 * Return: The total number of characters printed.
 */
int _printf_oct(va_list *list, char *ptr, int *k)
{
	int n = 0;
	unsigned int num;

	num = va_arg(*list, unsigned int);
	_printf_oct_rec(&n, num, ptr, k);

	return (n);
}
#include "main.h"

/**
 * _printf_hex_ptr - Recursively converts an unsigned long integer to lowercase hexadecimal
 *                   and stores the result in a buffer.
 * @n: Pointer to an integer that keeps track of the number of characters printed.
 * @num: The unsigned long integer to be converted and stored as hexadecimal.
 * @ptr: Pointer to the buffer where the formatted output is stored.
 * @k: Pointer to the index of the buffer.
 *
 * Description: This function recursively divides the number by 16
 *              to extract hexadecimal digits in the correct order.
 */
void _printf_hex_ptr(int *n, unsigned long int num, char *ptr, int *k)
{
	int a;

	if (num / 16)
	{
		_printf_hex_ptr(n, num / 16, ptr, k);
	}

	a = num % 16;

	if (a >= 0 && a <= 9)
	{
		Buffer_editor(ptr, k, ('0' + a));
	}
	else
	{
		Buffer_editor(ptr, k, ('a' + (a - 10)));
	}

	*n = *n + 1;
}

/**
 * _printf_pointer - Prints the address of a pointer in hexadecimal format.
 * @list: Argument list containing the pointer to be printed.
 * @ptr: Pointer to the buffer where the formatted output is stored.
 * @k: Pointer to the index of the buffer.
 *
 * Description: Extracts a pointer from the argument list and prints its
 *              address in lowercase hexadecimal format, prefixed with "0x".
 *              If the pointer is NULL, it prints "(nil)" instead.
 *
 * Return: The total number of characters printed.
 */
int _printf_pointer(va_list *list, char *ptr, int *k)
{
	unsigned long int num;
	int n = 0;

	num = va_arg(*list, unsigned long int);
	if (num == 0)
	{
		char *str = "(nil)";
		_printf_strings(&n, str, ptr, k);
		return (n);
	}

	Buffer_editor(ptr, k, ('0'));
	Buffer_editor(ptr, k, ('x'));
	n += 2;
	_printf_hex_ptr(&n, num, ptr, k);

	return (n);
}

/**
 * _printf_strings - Prints a string to the buffer.
 * @n: Pointer to an integer that keeps track of the number of characters printed.
 * @str: Pointer to the string to be printed.
 * @ptr: Pointer to the buffer where the formatted output is stored.
 * @k: Pointer to the index of the buffer.
 *
 * Description: Iterates over the characters of the string and stores them in
 *              the buffer. If the string is NULL, the function does nothing.
 */
void _printf_strings(int *n, char *str, char *ptr, int *k)
{
	int i = 0;

	if (str == NULL)
	{
		return;
	}

	while (str[i])
	{
		Buffer_editor(ptr, k, str[i]);
		*n = *n + 1;
		i++;
	}
}
#include "main.h"

/**
 * _printf_str - Prints a string from the argument list.
 * @list: Argument list containing the string to print.
 * @p: Pointer to the buffer where characters will be stored.
 * @k: Pointer to the buffer index.
 *
 * Description: Extracts a string from the argument list
 * and prints it character by character. If the string is NULL,
 * it prints "(null)" instead.
 *
 * Return: The total number of characters printed.
 */
int _printf_str(va_list *list, char *p, int *k)
{
	char *ptr = NULL;
	int n = 0;

	ptr = va_arg(*list, char *);
	if (ptr == NULL)
		ptr = "(null)";

	while (ptr[n])
	{
		Buffer_editor(p, k, (ptr[n]));
		n++;
	}

	return (n);
}
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
