#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int _printf(const char *str, ...);

int _format_caces(char f, va_list *list, char *ptr, int *k);
int _putchar(char* ptr, int *k);


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

void _printf_strings(int *n,char *str, char *ptr, int *k);



#endif /* MAIN_H */
