int ft_isalnum (int c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return (1);
    else if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

#include <ctype.h>
#include <stdio.h>

int main ()
{
    printf("%d\n", ft_isalnum(','));
    printf("%d\n", isalnum(','));
}