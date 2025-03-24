#include"main.h"
/* return num of chars passed to buffer*/
int printf_custom_S(va_list *list, char *p, int *k)
{
    char *ptr = NULL;
        int n = 0, x = 0, temp = 0;

        ptr = va_arg(*list, char *);
        if (ptr == NULL)
                ptr = "(null)";

        while (ptr[n])
        {
            if ((ptr[n] < 32 && ptr[n] > 0) || ptr[n] >= 127)
            {
                Buffer_editor(p, k, '\\');
                Buffer_editor(p, k, 'x');
                x += 2;
                if (!((int)ptr[n] / 16))
                {
                    Buffer_editor(p, k, '0');
                    x++;
                }
                _printf_HEX_rec(&x, (unsigned int)ptr[n], p, k);
                temp++;
            }
            else
            {
                Buffer_editor(p, k, (ptr[n]));
            }
                n++;
        }
        return (n + x - temp);
}
