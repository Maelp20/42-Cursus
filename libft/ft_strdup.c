#include <stdlib.h>
#include "libft.h"

char	*ft_strcpy(char	*dest, char	*src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	char	*newstr;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	newstr = malloc(sizeof(*s1) *(i + 1));
	if (!newstr)
		return (NULL);
	return (ft_strcpy(newstr, s1));
}