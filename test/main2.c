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
	char *str = "When %s invoke GCC, it %s and linking. The %coverall options%c allow you to stop this process at an intermediate stage. %s the -c option says not to run the linker. %s preprocessor and %cthers the compiler itself. Yet other %s need to use any of them.\n\nMost of the command line options that you can use with GCC are useful for C programs; when an option is only useful with another language (usually C ++ ), %d\n";
	char *tmp = "Then the output consists of object files output by the assembler.\n\nOther options are passed on to one stage of processing. Some options control the";
	char *tmp2 = "options control the assembler and linker; most of these are not documented here, since you rarely";

	len = _printf(str, "you", "normally does preprocessing, compilation, assembly", '"', '"', "For example,", tmp, 'o', tmp2, 123456789);
	printf("and\n");
    len2 = printf(str, "you", "normally does preprocessing, compilation, assembly", '"', '"', "For example,", tmp, 'o', tmp2, 123456789);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}
