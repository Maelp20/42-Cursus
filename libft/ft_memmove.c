#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
    size_t i;

    if (dst > src)
        i = len - 1;
        while (i >= 0)
        {
            *(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
            i--;
        }
    else
        i = 0;
        while (i < len)
        {
            *(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
            i++;
        }
    return (dst);
}
#include <string.h>
#include <stdio.h>

int main ()
{
    char src[5] = "Hello";
    char srcb[5] = "Hello";
    char dst[3] = "Aya";
    char dstb[3] = "Aya";
    ft_memmove(dst, src, 3);
    memmove(dstb, srcb, 3);
    char *pt = (char*) dst;
    char *ptb = (char*) dstb;
    printf("My memmove : %s\n", pt);
    printf("Real memmove : %s\n", ptb);
}