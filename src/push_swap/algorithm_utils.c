#include "../../include/push_swap.h"

/*
** Esta função pega a 'stack_a' e conta os números entre os dois primeiros
** elementos da stack 'refs'.
**
** A função count_index() retorna quantos elementos há entre os dois primeiros
** elementos da 'refs' na stack_a.
*/
int	count_index(t_stack *stack_a, t_stack *refs)
{
	t_stack	*duplicate;
	int		max_idx;
	int		min_idx;

	duplicate = ft_stack_duplicate(stack_a);
	ft_stack_sort(&duplicate);
	min_idx = ft_stack_find(duplicate, refs->data);
	max_idx = ft_stack_find(duplicate, refs->next->data);
	ft_stack_clear(&duplicate);
	return (max_idx - min_idx + 1);
}

/*
** Esta função vai pegar os números medianos da 'stack_a' entre os dois
** primeiros limites da stack 'refs' e adicioná-los na 'refs'.
**
** Começa criando uma cópia da 'stack_a' - 'duplicate';e ordena essa stack,
** 'duplicate' será uma cópia ordenada da 'stack_a'.
**
** A função tentará encontrar o índice em 'duplicate' do primeiro elemento da
** 'refs' - min_idx; O mesmo acontece com 'max_idx' - o índice do segundo
** elemento de 'refs' em 'duplicate'.
**
** Depois disso, é possível encontrar o índice do elemento mediano do max_idx
** e min_idx. Os cálculos são: (max_idx - min_idx) / 2 + min_idx.
**
** O 'new' será então o elemento cujo índice em 'duplicate' é o número entre
** max_idx e min_idx.
**
** 'new' é adicionado ao 'refs' e 'refs' é ordenado para que ele contenha
** todas as partições da 'stack_a' em ordem.
*/
void	get_new_block(t_stack **refs, t_stack *stack, int flag)
{
	t_stack	*duplicate;
	int		min_idx;
	int		max_idx;
	int		new;

	duplicate = ft_stack_duplicate(stack);
	ft_stack_sort(&duplicate);
	if (flag)
	{
		min_idx = ft_stack_find(duplicate, (*refs)->data);
		max_idx = ft_stack_find(duplicate, (*refs)->next->data);
		new = ft_stack_get(duplicate, ((max_idx - min_idx) / 2 + min_idx + 3));
	}
	else
		new = ft_stack_get(duplicate, ft_stack_size(duplicate) / 2);
	ft_stack_add_front(refs, ft_stack_new(new));
	ft_stack_sort(refs);
	ft_stack_clear(&duplicate);
}

/*
** Divide da 'stack_a' para 'stack_b' os números cujos limites estão entre os
** dois primeiros elementos da stack 'refs'.
**
** EX:
** 	- ANTES
** 			refs:		{25, 50, 75, 100}
** 			stack_a:	[1, 24] ordenados
** 						[25, 100] desordenados
** 			stack_b:	VAZIA
** 	- DEPOIS
** 			refs:		{25, 50, 75, 100}
** 			stack_a:	[1, 24] ordenados
** 						[51, 100] desordenados
** 			stack_b:	[25, 50] desordenados
*/
void	split_blocks(t_stack **stack_a, t_stack **stack_b, t_stack *refs)
{
	int	size;
	int	first;

	size = count_index(*stack_a, refs);
	while (ft_stack_size(*stack_b) < size)
	{
		first = moves_to_top(*stack_a, refs);
		while (first--)
			rotate_stack(stack_a, 0, "ra\n");
		push_stack(stack_a, stack_b, "pb\n");
	}
}

/*
** Esta função pega 'stack_b' e todos os seus números com valor acima do segundo
** elemento de 'refs' e joga de volta para 'stack_a'
** 		Ex:
** 			50 números aleatórios entre 1 e 100;
** 			stack_a: [50, 100] desordenados
** 			stack_b: [1, 49] desordenados
** 			refs: {1, 25, 50, 100}
** 		Todos os números maiores que 25 têm que voltar a stack_a.
*/
void	merge_max_back(t_stack **stack_a, t_stack **stack_b, t_stack *refs)
{
	get_new_block(&refs, *stack_b, 0);
	while (ft_stack_has_bigger(*stack_b, refs->next->data))
	{
		if ((*stack_b)->data == ft_stack_min_value(*stack_b))
		{
			push_stack(stack_b, stack_a, "pa\n");
			if ((*stack_b)->data != ft_stack_min_value(*stack_b)
				&& (*stack_b)->data <= refs->next->data)
				rotate_stack(stack_a, stack_b, "rr\n");
			else
				rotate_stack(stack_a, 0, "ra\n");
		}
		else if ((*stack_b)->data > refs->next->data)
			push_stack(stack_b, stack_a, "pa\n");
		else
			rotate_stack(stack_b, 0, "rb\n");
	}
}

/*
** Mescla o restante da stack_b 'para' stack_a 'de forma ordenada.
**
** **stack_a	- onde os números voltarão ordenados.
** **stack_b	- onde serão ordenados e ao final ficará vazia.
** *refs		- contém os limites das partições das outras stacks.
*/
void	merge_sorted(t_stack **stack_a, t_stack **stack_b, t_stack *refs)
{
	t_stack	*duplicate;

	duplicate = ft_stack_duplicate(*stack_b);
	ft_stack_sort(&duplicate);
	while (ft_stack_size(*stack_b))
	{
		if ((*stack_b)->data == duplicate->data)
		{
			push_stack(stack_b, stack_a, "pa\n");
			duplicate = duplicate->next;
			 if (ft_stack_size(*stack_b) && (*stack_b)->data != duplicate->data
				&& (*stack_b)->data != ft_stack_max_value(*stack_b))
				rotate_stack(stack_a, stack_b, "rr\n");
			else
				rotate_stack(stack_a, 0, "ra\n");
		}
		else if ((*stack_b)->data == ft_stack_max_value(*stack_b))
			push_stack(stack_b, stack_a, "pa\n");
		else
			rotate_stack(stack_b, 0, "rb\n");
	}
	while (ft_stack_last(*stack_a)->data != refs->next->data)
		rotate_stack(stack_a, 0, "ra\n");
	refs->next->data = get_next_min(*stack_a, &refs);
	ft_stack_clear(&duplicate);
}
