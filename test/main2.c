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
	int n = _printf("%p\n", (void *)NULL);
	int m = printf("%p\n",(void *)NULL);
	printf("%d %d\n", n, m);
	return (0);
}
