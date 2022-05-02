#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (*str != 0)
	{	
		i++;
		str++;
	}
	return (i);
}

void	ft_join(char *dest, char const *s1, char const *s2)
{
	int	i;
	int	j;

	i = 0;
	while (*s1)
	{
		dest[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		dest[i] = *s2;
		s2++;
		i++;
	}
	return ;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char 	*dest;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = 0;
		i++;
	}
	ft_join(dest, s1, s2);
	dest[len] = '\0';
	return (dest);
}

int	main ()
{
	char const s1[] = "Hello a  ";
	char const s2[] = "World";
	printf("Result : %s\n", ft_strjoin(s1, s2));
	return 0;
}