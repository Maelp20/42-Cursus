#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;

	if (*needle == 0)
		return (haystack);
	while (*haystack && len > 0)
	{
		if (*haystack == *needle)
		{
			i = 1;
			while ((haystack[i] == needle[i]) && (needle[i] != '\0'))
				i++;
			if (needle[i] == '\0')
				return (haystack);
		}
		haystack++;
        len --;
	}
	return (0);
}