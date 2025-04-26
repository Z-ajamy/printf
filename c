#include "main.h"

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

void binary_rec(int *num_rec, unsigned int num, char *ptr, int *k)
{
	if (num / 2)
	{
		binary_rec(num_rec, num / 2, ptr, k);
	}

	Buffer_editor(ptr, k, ('0' + num % 2));
	*num_rec = *num_rec + 1;
}

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

int _print_Uint(va_list *list, char *ptr, int *k)
{
	int n = 0;
	unsigned int num;

	num = va_arg(*list, unsigned int);

	print_Unum_rec(&n, num, ptr, k);
	return (n);
}

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


int _printf(const char *str, ...)
{
	int i = 0, n = 0, k = 0; /* i for iteration, n for char count, k for buffer index */
	char *ptr; /* Pointer to dynamically allocated memory for buffer */
	va_list list; /* Variable argument list */

	if (!str)/* Handle NULL format string */
		return (-1);
	ptr = (char *)malloc(sizeof(char) * BUFF_SIZE);/* Allocate memory for the buffer (size BUFF_SIZE) */
	if (!ptr)
		return (-1);
	va_start(list, str);/* Initialize the variable argument list */
	while (str[i])/* Loop through each character in the format string */
	{
		if (str[i] != '%')/* If current character is not '%', print it normally */
		{
			Buffer_editor(ptr, &k, str[i]); /* Store character in buffer */
			n++; /* Increment character count */
		}
		else /* Handle format specifiers */
		{
			if (!str[i + 1])/* Check if '%' is at the end without a valid specifier */
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
	_putchar(ptr, &k);/* Print the buffer contents */

	free(ptr);/* Free allocated memory and end variable argument list */
	va_end(list);
	return (n);/* Return the total number of characters printed */
}
#include "main.h"

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

int _printf_HEX(va_list *list, char *ptr, int *k)
{
	unsigned int num;
	int n = 0;

	num = va_arg(*list, unsigned int);

	_printf_HEX_rec(&n, num, ptr, k);
	return (n);
}
#include "main.h"

int _printf_char(va_list *list, char *ptr, int *k)
{
	Buffer_editor(ptr, k, (va_arg(*list, int)));
	return (1);
}
#include "main.h"

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

int _printf_hex(va_list *list, char *ptr, int *k)
{
	unsigned int num;
	int n = 0;

	num = va_arg(*list, unsigned int);

	_printf_hex_rec(&n, num, ptr, k);
	return (n);
}
#include "main.h"

void print_num_rec(int *num_rec, int num, char *ptr, int *k)
{
	if (num / 10)
	{
		print_num_rec(num_rec, num / 10, ptr, k);
	}
	Buffer_editor(ptr, k, ('0' + num % 10));
	(*num_rec)++;
}

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

void _printf_oct_rec(int *n, unsigned int num, char *ptr, int *k)
{
	if (num / 8)
	{
		_printf_oct_rec(n, num / 8, ptr, k);
	}

	Buffer_editor(ptr, k, ('0' + num % 8));
	*n = *n + 1;
}

int _printf_oct(va_list *list, char *ptr, int *k)
{
	int n = 0;
	unsigned int num;

	num = va_arg(*list, unsigned int);
	_printf_oct_rec(&n, num, ptr, k);

	return (n);
}
#include "main.h"

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

int _putchar(char *ptr, int *k)
{
	return (write(1, ptr, *k));
}
#include "main.h"

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
#ifndef MAIN_H
#define MAIN_H

#define BUFF_SIZE 1024



#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

typedef struct
{
	char c;
	int (*ptr)(va_list *list, char *ptr, int *k);
} char_case;

int _printf(const char *str, ...);


int _format_caces(char f, va_list *list, char *ptr, int *k);

int _putchar(char *ptr, int *k);

/* Functions to handle specific format specifiers */
int _printf_char(va_list *list, char *ptr, int *k);
int _printf_str(va_list *list, char *p, int *k);
int _printf_int(va_list *list, char *ptr, int *k);
void print_num_rec(int *num_rec, int num, char *ptr, int *k);

int _print_binary(va_list *list, char *ptr, int *k);
void binary_rec(int *num_rec, unsigned int num, char *ptr, int *k);

int _print_Uint(va_list *list, char *ptr, int *k);
void print_Unum_rec(int *num_rec, unsigned int num, char *ptr, int *k);

int _printf_oct(va_list *list, char *ptr, int *k);
void _printf_oct_rec(int *n, unsigned int num, char *ptr, int *k);

int _printf_hex(va_list *list, char *ptr, int *k);
void _printf_hex_rec(int *n, unsigned int num, char *ptr, int *k);

int _printf_HEX(va_list *list, char *ptr, int *k);
void _printf_HEX_rec(int *n, unsigned int num, char *ptr, int *k);

void Buffer_editor(char *ptr, int *k, char c);

int printf_custom_S(va_list *list, char *p, int *k);

int _printf_pointer(va_list *list, char *ptr, int *k);
void _printf_hex_ptr(int *n, unsigned long int num, char *ptr, int *k);

void _printf_strings(int *n, char *str, char *ptr, int *k);

#endif /* MAIN_H */
