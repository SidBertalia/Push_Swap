#include "libft.h"

/*
** The ft_lstlast() funtion returns the last element of the list.
**
** @param	t_list	*lst	- the beginning of the list.
**
** @return
** 		- the ft_lstlast() funtion returns the last element of the list.
*/
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
