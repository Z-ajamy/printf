#ifndef MAIN_H
#define MAIN_H

/*
 * File: main.h
 * Description: Header file for a custom _printf function.
 * It contains function prototypes, necessary libraries,
 * and a structure definition to handle different format cases.
 */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/*
 * struct char_case - Structure to handle format specifiers.
 * @c: The format specifier character.
 * @ptr: Pointer to function handling the format specifier.
 *
 * This structure is used to associate format specifiers such as
 * %c, %s, %d, etc., with the corresponding function that processes
 * and prints the argument.
 */
typedef struct
{
	char c;
	int (*ptr)(va_list *list, char *ptr, int *k);
} char_case;

/* Function prototypes for the custom printf implementation */

/*
 * _printf - Custom implementation of printf function.
 * @str: The format string containing format specifiers.
 *
 * This function processes the format string, identifies format
 * specifiers, and calls the corresponding functions to print
 * the arguments.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *str, ...);

/*
 * _format_caces - Handles various format specifiers.
 * @f: The format specifier character.
 * @list: Pointer to the argument list.
 * @ptr: Pointer to the buffer for formatted output.
 * @k: Pointer to track buffer position.
 *
 * This function determines the correct function to call based
 * on the format specifier and processes the corresponding argument.
 */
int _format_caces(char f, va_list *list, char *ptr, int *k);

/*
 * _putchar - Prints a character to the buffer.
 * @ptr: Pointer to the buffer.
 * @k: Pointer to track buffer position.
 *
 * Return: Always 1 (indicating one character printed).
 */
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

/*
 * Buffer_editor - Adds a character to the buffer.
 * @ptr: Pointer to the buffer.
 * @k: Pointer to track buffer position.
 * @c: The character to be added.
 */
void Buffer_editor(char *ptr, int *k, char c);

/*
 * printf_custom_S - Handles non-printable characters in strings.
 * @list: Pointer to the argument list.
 * @p: Pointer to the buffer.
 * @k: Pointer to track buffer position.
 *
 * This function converts non-printable characters to their
 * hexadecimal representation.
 */
int printf_custom_S(va_list *list, char *p, int *k);

/*
 * _printf_pointer - Handles %p format specifier.
 * @list: Pointer to the argument list.
 * @ptr: Pointer to the buffer.
 * @k: Pointer to track buffer position.
 *
 * This function prints memory addresses in hexadecimal format.
 */
int _printf_pointer(va_list *list, char *ptr, int *k);
void _printf_hex_ptr(int *n, unsigned long int num, char *ptr, int *k);

/*
 * _printf_strings - Prints strings with custom formatting.
 * @n: Pointer to an integer used for tracking recursion depth.
 * @str: Pointer to the string to be printed.
 * @ptr: Pointer to the buffer.
 * @k: Pointer to track buffer position.
 */
void _printf_strings(int *n, char *str, char *ptr, int *k);

#endif /* MAIN_H */
