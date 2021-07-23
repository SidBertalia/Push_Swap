#include "libft.h"
#include <stdio.h>

/*
** The ft_lstdelone() function takes as a parameter an element and frees the
** memory of the element’s content using the function ’del’ given as a parameter
** and free the element. The memory of ’next’ must not be freed.
**
** @param	t_list	*lst		- the element to free.
** @param	void (*del)(void *)	- the address of the function used to delete the
** 								content.
*/
void	ft_lstremove(t_list **lst)
{
	t_list	*temporary;

	if (!lst)
		return ;
	temporary = *lst;
	*lst = temporary->next;
	temporary->next = NULL;
	free(temporary);
}
