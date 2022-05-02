void *ft_memcpy(void *dst, const void *src, size_t n)
{
    size_t i;

    i = 0;
    while (i < n)
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
    char src[5] = "Ayala";
    char srcb[5] = "Ayala";
    char dst[3] = "Hio";
    char dstb[3] = "Hio";
    ft_memcpy(dst, src, 3);
    memcpy(dstb, srcb, 3);
    char *pt = (char*) dst;
    char *ptb = (char*) dstb;
    printf("My memcpy : %s\n", pt);
    printf("Real memcpy : %s\n", ptb);
}