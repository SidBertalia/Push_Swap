#include "libft.h"

/*
** The ft_lstsize() function counts the number od elements in a list.
**
** @param	t_list	*lst	- the beginning of the list.
**
** @return
** 		- The ft_lstsize() function returns the number of elements in a list.
*/
int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
