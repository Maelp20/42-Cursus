#include <stdlib.h>
#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *str;

    *str  = (char *) malloc((char) * (len + 1));
    if (!str)
        return (NULL);
    while(start > 0)
    {
        s++;
        start--;
    }
    ft_strlcpy(str, s, len);
    return(str);
}