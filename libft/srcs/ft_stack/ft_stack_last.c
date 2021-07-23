#include "libft.h"

/*
** The ft_stack_last() funtion returns the last element of the stack.
**
** @param	t_stack	*stack	- the beginning of the stack.
**
** @return
** 		- the ft_stack_last() funtion returns the last element of the stack.
*/
t_stack	*ft_stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
