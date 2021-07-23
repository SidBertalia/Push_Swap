#include "ft_stack.h"

/*
** This function iterates 'stack' and returns its value at the position
** 'position' if it exists.
**
** @param	t_stack	*stack		- stack of integers to iterate.
**
** @param	int		position	- position of the value we want to return.
**
** @return
**		- the ft_stack_get() function returns the index of the value from 0 to
**		ft_stack_size(stack) - 1; if it 'position' is bigger than the stacks's
**		size than the function returns INT_MIN.
*/
int	ft_stack_get(t_stack *stack, int position)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (i == position)
			return (stack->data);
		stack = stack->next;
		i++;
	}
	return (-2147483648);
}
