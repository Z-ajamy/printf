#include "main.h"

/**
 * _printf - Custom implementation of printf function.
 * @str: The format string containing directives.
 *
 * Description: Prints formatted output based on the provided format string.
 * Supports %c (character), %s (string), and %% (percentage symbol).
 *
 * Return: The number of characters printed.
 */
int _printf(const char *str, ...)
{
	int i = 0, n = 0, err = 0, m = 1;
	char *ptr;
	va_list list;

	ptr = (char *)malloc(sizeof(char) * 1024);
	if (!ptr)
		return -1;
	
	if (!str)
	{
		return (-1);
	}

	va_start(list, str);

	while (str[i] && n < 1023)
	{
		if (str[i] != '%')
		{
			ptr[n] = str[i];
			n++;
		}
		else
		{
			if (!str[i + 1])
			{
				err = -1;
			}
			if (   str[i + 1] == 'c' || str[i + 1] == 's' || str[i + 1] == '%'
				|| str[i + 1] == 'i' || str[i + 1] == 'd' || str[i + 1] == 'b'
				|| str[i + 1] == 'u' || str[i + 1] == 'o' || str[i + 1] == 'x'
				|| str[i + 1] == 'X')
			{
				m = _format_caces(str[++i], &list, &n, ptr);
				if (m == 0)
				{
					_putchar(ptr, *m);
					*m = 0;
				}
			}
			else if(err == 0)
			{
				ptr[n] = '%';
				n++;
			}
		}
		i++;
	}
	ptr[n] = '\0';
	_putchar(ptr, n);
	free(ptr);
	va_end(list);
	if (err != 0)
	{
		n = err;
	}
	return (n);
}
#include "main.h"

/**
 * _printf_char - Prints a single character.
 * @list: The argument list containing the character.
 *
 * Return: Always returns 1 (one character printed).
 */
int _printf_char(va_list *list, int *m, char *ptr)
{
	ptr[*m] = (va_arg(*list, int));
	*m = *m + 1;
	if (*m == 1023)
	{
		return 0;
	}
	return (1);
}
#include "main.h"

/**
 * print_num_rec - Recursively prints digits of an integer
 * @num_rec: Pointer to an integer that keeps track of printed digits
 * @num: The number to be printed
 *
 * Description: This function recursively divides the number by 10
 * and prints its digits one by one, ensuring correct order.
 */
int print_num_rec(int num, int *m, char *ptr)
{
	int a = 1;
	if (num / 10)
	{
		a = print_num_rec(num / 10, m, ptr);
	}
	if (a == 0)
	{
		_putchar(ptr, *m); // تفريغ المخزن
		*m = 0;
	}
	ptr[*m] = ('0' + num % 10);
	*m = *m +1;
	if (*m == 1023)
	{
		_putchar(ptr, *m); // تفريغ المخزن
		*m = 0;
	}
	return 1;
}

/**
 * _printf_int - Prints an integer
 * @list: Argument list containing the integer to print
 *
 * Description: Extracts an integer from the argument list, handles negative
 * values by printing a '-' sign, and correctly prints INT_MIN.
 *
 * Return: The total number of characters printed.
 */
int _printf_int(va_list *list, int *m, char *ptr)
{
	int a;
	char big = 0;
	int num;

	num = va_arg(*list, int);

	if (num < 0)
	{
		ptr[*m] = ('-');
		*m = *m + 1;
		if (*m == 1023)
		{
			_putchar(ptr, *m); // تفريغ المخزن
			*m = 0;
		}
		
		if (num < -2147483647) /* Handles INT_MIN case */
		{
			big = 1;
			num = num / 10;
		}
		num *= -1;
	}

	a = print_num_rec(num, m, ptr);
	if (a == 0)
	{
		_putchar(ptr, *m); // تفريغ المخزن
		*m = 0;
	}
	
	if (big)
	{
		ptr[*m] = ('0' + 8); /* Adds back the last digit of INT_MIN */
		*m = *m + 1;
	}
	if (*m == 1023)
	{
		_putchar(ptr, *m); // تفريغ المخزن
		*m = 0;
	}
	return (1);
}
#include "main.h"

/**
 * _printf_str - Prints a string.
 * @list: The argument list containing the string.
 *
 * Description: If the string is NULL, it prints "(null)" instead.
 *
 * Return: The number of characters printed.
 */
int _printf_str(va_list *list, int *m, char *ptr)
{
	char *p = NULL;
	int n = 0;

	p = va_arg(*list, char *);
	if (p == NULL)
		p = "(null)";

	while (p[n])
	{
		ptr[*m] = (p[n]);
		*m = *m + 1;
		if (*m == 1023)
		{
			return 0;
		}
		
		n++;
	}

	return (1);
}
#include "main.h"

/**
 * _format_caces - Handles specific format specifiers.
 * @f: The format specifier character.
 * @list: The argument list containing values to be printed.
 *
 * Return: The number of characters printed.
 */
int _format_caces(char f, va_list *list, int *m, char *ptr)
{
	int n = 1;

	if (f == '%')
	{
		ptr[*m] = '%';
		*m = *m + 1;
		if (*m == 1023)
		{
			n = 0;
		}
	}
	if (f == 'c')
	{
		n = _printf_char(list, m, ptr);
	}
	if (f == 's')
	{
		n = _printf_str(list, m, ptr);
	}
    if (f == 'd' || f == 'i')
    {
        n = _printf_int(list, m, ptr);
    }
    if (f == 'b')
    {
        n = _print_binary(list, m, ptr);
    }
	if (f == 'u')
	{
		n = _print_Uint(list, m, ptr);
	}
	if (f == 'o')
	{
		n = _printf_oct(list, m, ptr);
	}
	if (f == 'x')
	{
		n = _printf_hex(list, m, ptr);
	}
    if (f == 'X')
	{
		n = _printf_HEX(list, m, ptr);
	}

	return (n);
}
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
#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
 * File: main.h
 * Description: Header file for a custom printf function.
 *
 * This file contains function prototypes required for implementing
 * a simplified version of the printf function.
 */

int _printf(const char *str, ...);
int _putchar(char *a, int n);
int _format_caces(char f, va_list *list, int *n, char *ptr);
int _printf_char(va_list *list, int *m, char *ptr);
int _printf_str(va_list *list, int *m, char *ptr);
int _printf_int(va_list *list, int *m, char *ptr);
int print_num_rec(int num, int *n, char *ptr);
int _print_binary(va_list *list, int *m, char *ptr);
int binary_rec(unsigned int num, int *n, char *ptr);
int _print_Uint(va_list *list, int *m, char *ptr);
int print_Unum_rec(unsigned int num, int *m, char *ptr);
int _printf_oct(va_list *list, int *m, char *ptr);
int _printf_oct_rec(unsigned int num, int *m, char *ptr);
int _printf_hex(va_list *list, int *m, char *ptr);
int _printf_hex_rec(unsigned int num, int *m, char *ptr);
int _printf_HEX(va_list *list, int *m, char *ptr);
int _printf_HEX_rec(unsigned int num, int *m, char *ptr);


#endif /* MAIN_H */
