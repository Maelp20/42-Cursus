#include <stdlib.h>
#include "libft.h"

void    *calloc(size_t count, size_t size)
{
    void    *ptr;

    ptr = (void *)malloc(count * size);
    if (!ptr)
        return (0);
    ft_bzero(ptr, count);
    return (ptr);
}