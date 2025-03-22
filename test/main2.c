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

    len = _printf("%fg%");
    len2 = printf("Let's try to printf a%% simple sentence.\n");

    
    printf("Length:[%d, %d]\n", len, len2);
    return 0;
}
