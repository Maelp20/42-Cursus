#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	length;
	size_t	i;
	size_t	j;

	length = ft_strlen(dest);
	i = length;
	j = 0;
	if (size == 0 || i >= size)
		return (ft_strlen(src) + size);
	while ((j < (size - length - 1)) && (src[j] != '\0'))
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (length + ft_strlen(src));
}