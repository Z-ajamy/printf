#include"main.h"
/* return num of chars passed to buffer*/
int printf_custom_S(va_list *list, char *p, int *k)
{
    char *ptr = NULL;
        int n = 0, x = 0, len = 0;

        ptr = va_arg(*list, char *);
        if (ptr == NULL)
                ptr = "(null)";

        while (ptr[n])
        {
            if ((ptr[n] < 32 && ptr[n] > 0) || ptr[n] >= 127)
            {
                Buffer_editor(p, k, '\\');
                Buffer_editor(p, k, 'x');
                if (!((int)ptr[n] / 16))
                {
                Buffer_editor(p, k, '0');
                }
                _printf_HEX_rec(&x, (unsigned int)ptr[n], p, k);
                len += 2;
            }
            else
            {
                Buffer_editor(p, k, (ptr[n]));
                len++;
            }
                n++;
        }
        return (len);
}
