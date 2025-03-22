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
    int len;

    len = _printf("%b\n", 8);
    printf("Length:[%d]\n", len);

    return 0;
}
