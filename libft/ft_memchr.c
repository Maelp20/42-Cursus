#include "libft.h"

void *memchr(const void *s, int c, size_t n)
{
    unsigned char    a;
    size_t i;

    a = (unsigned char)c;
    i = 0;
    while (i <= n)
    {
        if (a == s)
            return (s)
        i++;
        s++;
    }
    return (0);
}