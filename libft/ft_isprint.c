int ft_isprint (int c)
{
    if ((c >= 33 && c <= 126))
        return (1);
    return (0);
}
/*#include <ctype.h>
#include <stdio.h>

int main ()
{
    printf("%d\n", ft_isprint('!'));
    printf("%d\n", isprint('!'));
}*/