#include"main.h"

void Buffer_editor(char *p, int *k, char c)
{
    p[*k] = (c);
    *k = *k + 1;
    if (*k == 1024)
    {
        _putchar(p, k);
        *k = 0;
    }
}
