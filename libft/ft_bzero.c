void    ft_bzero(void *s, int n)
{
    int i;

    i = 0;
    while (i < n)
    {
        *(unsigned char *)(s + i) = '\0';
        i++;
    }
}
/*#include <string.h>
#include <stdio.h>

int main ()
{
    char str[5] = "Hello";
    char strb[5] = "Hello";
    ft_bzero(str + 3, 2);
    printf("My bzero : %s\n",  str);
    bzero(strb + 3, 2);
    printf("Real bzero : %s\n",  strb);
}*/