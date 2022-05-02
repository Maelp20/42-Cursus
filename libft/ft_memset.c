void    *ft_memset (void *b, int c, int len)
{
    int i;

    i = 0;
    while (i < len)
    {
        *(unsigned char *)(b + i) = (unsigned char)c;
        i++;
    }
    return (b);
}
/*#include <string.h>
#include <stdio.h>

int main ()
{
    int    str[50] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    int    strb[50] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};

    int i = 0;
    ft_memset(str + 13, 33, 5*sizeof(int));
    memset(strb + 13, 33, 5*sizeof(int));
    while (i < 25)
    {
        printf("My memset : %d\n", str[i]);
        printf("Real memset : %d\n", strb[i]);
        i++;
    }
    i = 0;
}*/