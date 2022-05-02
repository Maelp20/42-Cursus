#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	a;

	a = 0;
	if (n == 0)
		return (0);
	while ((s1[a] != '\0') && (s1[a] == s2[a]) && (a < (n - 1)))
	{	
		a++;
	}
	return (s1[a] - s2[a]);
}