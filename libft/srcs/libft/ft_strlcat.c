#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	d;
	size_t	i;

	if (destsize <= ft_strlen(dest))
		return (destsize + ft_strlen(src));
	d = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0' && d + 1 < destsize)
	{
		dest[d] = src[i];
		d++;
		i++;
	}
	dest[d] = '\0';
	return (ft_strlen(dest) + ft_strlen(&src[i]));
}
