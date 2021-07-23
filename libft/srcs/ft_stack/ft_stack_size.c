#include "libft.h"

/*
** The ft_stack_size() function counts the number of elements in a stack.
**
** @param	t_stack	*stack	- the beginning of the stack.
**
** @return
** 		- The ft_stack_size() function returns the number of elements in a stack.
*/
int	ft_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}
