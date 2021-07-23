#include "libft.h"

/*
** This function adds an element to a stack. 
** The ft_stack_add_back() function adds the element 'new' at the end of the
** stack.
**
** @param	t_stack **stack	- address of a pointer to the first link of a stack.
** @param	t_stack	*new	- address of a pointer to the element to be added to
**							the stack.
*/
void	ft_stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!*stack)
		*stack = new;
	else
	{
		last = ft_stack_last(*stack);
		new->previous = last;
		last->next = new;
	}
}
