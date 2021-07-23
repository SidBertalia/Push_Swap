#include "libft.h"

/*
** This function adds an element to a list. 
** The ft_lstadd_front() functionn adds the element 'new' at the beginning of
** the list.
**
** @param	t_list 	**lst	- address of a pointer to the first link of a list.
** @param	t_list	*new	- address of a pointer to the element to be added to
** 							the list.
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
