#include <libft.h>

/*
** This function converts a ASCII string to an integer.
** The ft_atoi() function converts the initial portion of the string pointed to
** by str to int representation.
**
** @param	const char	*str	- string to be converted to int.
**
** @return
** 		- The ft_atoi() function returns the int representation of the string.
*/

long long	ft_atol(const char *str)
{
	int				i;
	int				negative;
	long long int	number;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	negative = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			negative = -1;
	}
	number = 0;
	while (ft_isdigit(str[i]))
		number = (number * 10) + (negative * (str[i++] - '0'));
	return (number);
}
