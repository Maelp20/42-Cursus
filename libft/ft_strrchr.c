#include "libft.h"

char *strrchr(const char *s, int c)
{
    char    *p;
    char    a;
    size_t i;

    a = (char)c;
    i = ft_strlen(*s);
    while (i >= 0)
    {
        if (a == s)
            return (s)
        i--;
        s--;
    }
    return (0);
}