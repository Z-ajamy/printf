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

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    len = _printf("Negative:[%d]\n", -2147483648);
    len2 = printf("Negative:[%d]\n", -2147483647);
    printf("Length:[%d, %i]\n", len, len2);

    return 0;
}
