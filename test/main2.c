#include <limits.h>
#include <stdio.h>
#include "../main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len, len2;

    len = _printf("%X\n", 271);;
    len2 = printf("%x\n", 271);

    printf("Length:[%d, %i]\n", len, len2);
    return 0;
}
