#include "libft.h"

/*
 * This function iterates a stack 'stack_a' and returns its maximum value.
 *
 * @param	t_stack	*stack_a	- stack to iterate.
 *
 * @return
 * 		- integer type value that corresponds to the biggest number in
 * 		'stack_a'.
*/
int	ft_stack_max_value(t_stack *stack_a)
{
	int	max_value;

	max_value = stack_a->data;
	while (stack_a)
	{
		if (stack_a->data > max_value)
			max_value = stack_a->data;
		stack_a = stack_a->next;
	}
	return (max_value);
}
