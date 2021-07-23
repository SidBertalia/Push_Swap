#include "../../include/push_swap.h"

/*
** Esta função itera a stack_a, a partir do topo e encontra o primeiro número
** com valores entre o primeiro e o segundo número em 'refs'.
**
** Esta função retorna o número estimado de instruções "ra" necessárias para o
** número desejado da stack_a chegar no topo.
*/
int	moves_to_top(t_stack *stack_a, t_stack *refs)
{
	int	first;
	int	max;
	int	min;

	min = refs->data;
	max = refs->next->data;
	first = 0;
	while (stack_a)
	{
		if (stack_a->data >= min && stack_a->data <= max)
			return (first);
		first++;
		stack_a = stack_a->next;
	}
	return (first);
}

/*
** Esta função seleciona o tipo de algoritmo de ordenacao com base no
** tamanho da 'stack_a'.
** Se o tamanho da stack:
** 		- é menos de 3: a função sort_small() é chamada.
** 		- é entre 4 ou 19: a função sort_medium() é chamada.
** 		- é mais de 20: a função sort_big() é chamada.
*/
void	choose_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*refs;
	int		max;
	int		min;

	max = ft_stack_max_value(*stack_a);
	min = ft_stack_min_value(*stack_a);
	if (ft_stack_size(*stack_a) <= 3)
		sort_small(stack_a);
	else if (ft_stack_size(*stack_a) <= 19)
		sort_medium(stack_a, stack_b);
	else
	{
		refs = ft_stack_new(min);
		ft_stack_add_back(&refs, ft_stack_new(max));
		sort_big(stack_a, stack_b, &refs, 0);
	}
}

/*
** int argc		- número de argumentos de linha de comando.
** char *argv	- arquivo executável + dígitos para preencher a pilha
** e ser classificado.
*/
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		exit(1);
	argv = &argv[1];
	argc--;
	if (argc == 1)
		argv = parse_string(&argc, argv);
	stack_a = 0;
	stack_b = 0;
	load_args(&argv[0], &stack_a);
	if (!ft_stack_is_sorted(stack_a))
		choose_algorithm(&stack_a, &stack_b);
	exit_push_swap(stack_a, stack_b, 1);
	return (0);
}
