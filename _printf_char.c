#include"main.h"

int _printf_char(va_list *list)
{
    _putchar(va_arg(*list, int));
    return 1;
}
