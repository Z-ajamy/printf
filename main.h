#ifndef MAIN_H
#define MAIN_H

#include<stdlib.h>
#include<stdarg.h>
#include<unistd.h>

int _printf(const char* str, ...);
int _putchar(char a);
int _format_caces(char f, va_list *list);
int _printf_char(va_list *list);
int _printf_str (va_list *list);



#endif
