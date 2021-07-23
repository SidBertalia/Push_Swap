#include "libft.h"

static int	ft_strcount(char const *s, char c)
{
	int	n;
	int	istatus;

	n = 0;
	istatus = 1;
	if (s == NULL)
		return (0);
	while (*s != '\0')
	{
		if (*s != c && istatus)
		{
			n++;
			istatus = 0;
		}
		else if (*s != c && !istatus)
			istatus = 0;
		else
			istatus = 1;
		s++;
	}
	return (n);
}

char	**ft_split(char const *s, char c)
{
	char		**arr;
	char		**ret;
	size_t		i;

	i = 0;
	arr = (char **)malloc((ft_strcount(s, c) + 1) * sizeof(char *));
	if (arr == NULL || s == NULL)
		return (NULL);
	ret = arr;
	while (*s)
	{
		if (*s != c)
		{
			while (*(s + i) != c && *(s + i) != '\0')
				i++;
			*arr++ = ft_strndup(s, i);
			s += i - 1;
			i = 0;
		}
		s++;
	}
	*arr = NULL;
	return (ret);
}
