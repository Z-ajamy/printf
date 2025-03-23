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
