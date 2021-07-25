#include "libft.h"
#include "ft_stack.h"

/*
** The ft_stack_remove() function takes as a parameter an element and frees the
** memory of the element’s content making its previous element point to it's
** next and its next point to its previous; it also frees the element.
**
** @param	t_stack	*stack		- the element to remove.
*/
void	ft_stack_remove(t_stack **stack)
{
	t_stack	*temporary;

	if (!stack)
		return ;
	temporary = *stack;
	if (temporary->next)
		temporary->next->previous = temporary->previous;
	if (temporary->previous)
		temporary->previous->next = temporary->next;
	if (temporary->previous)
		*stack = temporary->previous;
	else
		*stack = temporary->next;
	free(temporary);
	temporary = NULL;
}
