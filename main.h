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

/**
 * _printf - Custom implementation of the printf function.
 * @str: The format string that contains directives for formatting output.
 *
 * Description: This function processes a format string and variable arguments
 * to print formatted output. It supports the following format specifiers:
 * - %c : Prints a character
 * - %s : Prints a string
 * - %% : Prints a percent symbol (%)
 *
 * Return: The total number of characters printed.
 */
int _printf(const char *str, ...);

/**
 * _putchar - Writes a single character to standard output.
 * @a: The character to be printed.
 *
 * Description: This function is a low-level character output function.
 * It is used internally by other functions to print individual characters.
 *
 * Return: 1 on success, -1 on failure.
 */
int _putchar(char a);

/**
 * _format_caces - Handles specific format specifiers in _printf.
 * @f: The format specifier character.
 * @list: The list of arguments to be printed.
 *
 * Description: This function is called inside _printf to process
 * format specifiers. It determines whether the format character is:
 * - 'c' (character) -> Calls _printf_char
 * - 's' (string) -> Calls _printf_str
 * - '%' (percent sign) -> Prints '%'
 *
 * Return: The number of characters printed for the given format.
 */
int _format_caces(char f, va_list *list);

/**
 * _printf_char - Prints a single character.
 * @list: The argument list containing the character to print.
 *
 * Description: Extracts a character from the argument list
 * and prints it using _putchar.
 *
 * Return: Always returns 1 (one character printed).
 */
int _printf_char(va_list *list);

/**
 * _printf_str - Prints a string.
 * @list: The argument list containing the string to print.
 *
 * Description: Extracts a string from the argument list and prints it
 * character by character. If the string is NULL, it prints "(null)".
 *
 * Return: The total number of characters printed.
 */
int _printf_str(va_list *list);




int _printf_int(va_list *list);
int _print_binary(va_list *list);
void binary_rec(int *num_rec, long num);
void print_num_rec(int *num_rec, int num);


#endif /* MAIN_H */
