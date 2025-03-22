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

    len = _printf(NULL);
    len2 = printf(NULL);

    
    printf("Length:[%d, %d]\n", len, len2);
    return 0;
}
