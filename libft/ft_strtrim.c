#include <stdio.h>
#include <stdlib.h>

int	ft_in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_len(char *str, char *charset)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (ft_in_charset(str[i], charset))
			return (i);
		i++;
	}
	return (i);
}

void	ft_splitnwrite(char *s1, char *charset)
{
	int		i;
	int		j;
	int		len;
	char	*temp;

	if (!ft_in_charset(*str, charset))
	{
		len = ft_len(str, charset);
		temp = (char *)malloc(sizeof(char) * len + 1);
		j = -1;
		while (++j < len)
		{
			temp[j] = *str;
			str++;
		}
		dest[i] = temp;
	}
	dest[i] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	int		len;
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (ft_in_charset(s1[i], set))
    {
        i++;
        j++;
    }
    len = 0;
    while (!ft_in_charset(s1[i], set) && s1[i])
    {
        i++;
        len ++;
    }
	dest = (char **) malloc(sizeof(char *) * (len + 1));
	if (!dest)
		return (0);
	ft_splitnwrite(dest, str, charset, nbr);
	return (dest);
}