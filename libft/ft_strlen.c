unsigned long ft_strlen (const char *s)
{
    unsigned long i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}
/*#include <string.h>
#include <stdio.h>

int main ()
{
    printf("%lu\n", ft_strlen("Helloq"));
    printf("%lu\n", strlen("Helloq"));
}*/