#include <libft.h>

/*
** This function swaps two integers with one another.
*/
void	ft_swap(int *a, int *b)
{
	int	temporary;

	temporary = *a;
	*a = *b;
	*b = temporary;
}
