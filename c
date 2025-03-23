#include "main.h"

int _format_caces(char f, va_list *list, char *ptr, int *k)
{
	int n = 0;

	if (f == '%')
	{
		ptr[*k] = ('%');
		*k = *k +1;
		if (*k == 1024)
		{
			_putchar(ptr, k);
			*k = 0;
		};
		n++;
	}
	if (f == 'c')
	{
		n = _printf_char(list, ptr, k);
	}
	if (f == 's')
	{
		n = _printf_str(list, ptr, k);
	}
    if (f == 'd' || f == 'i')
    {
        n = _printf_int(list, ptr, k);
    }
    if (f == 'b')
    {
        n = _print_binary(list, ptr, k);
    }
	if (f == 'u')
	{
		n = _print_Uint(list, ptr, k);
	}
	if (f == 'o')
	{
		n = _printf_oct(list, ptr, k);
	}
	if (f == 'x')
	{
		n = _printf_hex(list, ptr, k);
	}
    if (f == 'X')
	{
		n = _printf_HEX(list, ptr, k);
	}

	return (n);
}
#include "main.h"

void binary_rec(int *num_rec, unsigned int num, char *ptr, int *k)
{
	if (num / 2)
	{
		binary_rec(num_rec, num / 2, ptr, k);
	}

	ptr[*k] = ('0' + num % 2);
				*k = *k +1;
				if (*k == 1024)
				{
					_putchar(ptr, k);
					*k = 0;
				}
	*num_rec = *num_rec + 1;
}

int _print_binary(va_list *list, char *ptr, int *k)
{
	int num_rec = 0;
	unsigned int num = va_arg(*list, unsigned int);

	if (num == 0)
	{
		ptr[*k] = ('0');
		*k = *k +1;
		if (*k == 1024)
		{
			_putchar(ptr, k);
			*k = 0;
		}
		return (1);
	}

	binary_rec(&num_rec, num, ptr, k);
	return (num_rec);
}
#include"main.h"

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
		print_num_rec(num_rec, num / 10, ptr, k);
	}

	ptr[*k] = ('0' + num % 10);
	*k = *k +1;
	if (*k == 1024)
	{
		_putchar(ptr, k);
		*k = 0;
	}
	(*num_rec)++;
}
#include "main.h"

int _printf(const char *str, ...)
{
	int i = 0, n = 0, k = 0;
	char *ptr;
	va_list list;

	if (!str)
		return (-1);
	ptr = (char *)malloc(sizeof(char) * 1024);

	va_start(list, str);

	while (str[i])
	{
		if (str[i] != '%') /* Print normal characters */
		{
			ptr[k] = (str[i]);
			k++;
			if (k == 1024)
			{
				_putchar(ptr, &k);
				k = 0;
			}
			n++;
		}
		else /* Handle format specifiers */
		{
			if (!str[i + 1]) /* Handle cases where '%' is at the end */
			{
				n = -1;
				break;
			}
			if (   str[i + 1] == 'c' || str[i + 1] == 's' || str[i + 1] == '%'
				|| str[i + 1] == 'i' || str[i + 1] == 'd' || str[i + 1] == 'b'
				|| str[i + 1] == 'u' || str[i + 1] == 'o' || str[i + 1] == 'x'
				|| str[i + 1] == 'X')
			{
				n += _format_caces(str[++i], &list, ptr, &k);
			}
			else /* Print '%' as a normal character if no valid specifier */
			{
				ptr[k] = ('%');
				k++;
				if (k == 1024)
				{
					_putchar(ptr, &k);
					k = 0;
				}
				n++;
			}
		}
		i++;
	}

	_putchar(ptr, &k);

	free(ptr);
	va_end(list);
	return (n);
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
		ptr[*k] = ('0' + a);
				*k = *k +1;
				if (*k == 1024)
				{
					_putchar(ptr, k);
					*k = 0;
				}
	}
	else
	{
		ptr[*k] = ('A' + (a - 10));
				*k = *k +1;
				if (*k == 1024)
				{
					_putchar(ptr, k);
					*k = 0;
				}
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
	ptr[*k] = (va_arg(*list, int));
	*k = *k +1;
	if (*k == 1024)
	{
		_putchar(ptr, k);
		*k = 0;
	}
	return (1);
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
		ptr[*k] = ('0' + a);
				*k = *k +1;
				if (*k == 1024)
				{
					_putchar(ptr, k);
					*k = 0;
				}
	}
	else
	{
		ptr[*k] = ('a' + (a - 10));
				*k = *k +1;
				if (*k == 1024)
				{
					_putchar(ptr, k);
					*k = 0;
				}
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

void print_num_rec(int *num_rec, int num, char *ptr, int *k)
{
	if (num / 10)
	{
		print_num_rec(num_rec, num / 10, ptr, k);
	}

	ptr[*k] = ('0' + num % 10);
	*k = *k +1;
	if (*k == 1024)
	{
		_putchar(ptr, k);
		*k = 0;
	}
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
		ptr[*k] = ('-');
		*k = *k +1;
		if (*k == 1024)
		{
			_putchar(ptr, k);
			*k = 0;
		}
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
		ptr[*k] = ('0' + 8);
		*k = *k +1;
		if (*k == 1024)
		{
			_putchar(ptr, k);
			*k = 0;
		} /* Adds back the last digit of INT_MIN */
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

	ptr[*k] = ('0' + num % 8);
				*k = *k +1;
				if (*k == 1024)
				{
					_putchar(ptr, k);
					*k = 0;
				}
	*n = *n + 1;
}

int _printf_oct(va_list *list, char *ptr, int *k)
{
	int n = 0;
	unsigned int num = va_arg(*list, unsigned int);

	_printf_oct_rec(&n, num, ptr, k);
	return (n);
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
		p[*k] = (ptr[n]);
		*k = *k +1;
		if (*k == 1024)
		{
			_putchar(p, k);
			*k = 0;
		}
		n++;
	}

	return (n);
}
#include "main.h"

int _putchar(char* ptr, int *k)
{
	return (write(1, ptr, *k));
}
