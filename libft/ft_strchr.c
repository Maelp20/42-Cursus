#include "libft.h"

char *strchr(const char *s, int c)
{
    char    a;
    size_t i;

    a = (char)c;
    i = 0;
    while (i <= ft_strlen(*s))
    {
        if (a == s)
            return (s)
        i++;
        s++;
    }
    return (0);
}