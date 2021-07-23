#include "../../include/push_swap.h"

/*
** Para stack_a de tamanho inferior a 3.
** Apenas instruções: RRA, RA, SA.
**
** if)		verifica se o segundo elemento de stack_a corresponde ao
** 			valor máximo da pilha, e se o primeiro não é o
** 			valor mínimo - Ex: 2 3 1
** 			Para este caso, RRA.
**
** else if)	Verifica se o primeiro elemento de stack_a corresponde ao
** 			valor mínimo da pilha, e se o segundo não for o
** 			valor máximo - Ex: 3 1 2
** 			Para este caso, RA.
**
** else)	Se não for nenhum dos casos acima, SA nos dois primeiros
** 			elementos da stack_a, para então ficar com um dos casos acima.
** 			Ex: 3 2 1 - Neste caso trocamos os dois primeiros números com
** 			SA - 2 3 1 - depois RRA - 1 2 3.
*/
void	sort_small(t_stack **stack_a)
{
	int	max;
	int	min;

	max = ft_stack_max_value(*stack_a);
	min = ft_stack_min_value(*stack_a);
	while (!ft_stack_is_sorted(*stack_a))
	{
		if ((*stack_a)->data != min && (*stack_a)->next->data == max)
			reverse_rotate_stack(stack_a, 0, "rra\n");
		else if ((*stack_a)->data == max && (*stack_a)->next->data == min)
			rotate_stack(stack_a, 0, "ra\n");
		else
			swap_stack(*stack_a, 0, "sa\n");
	}
}

/*
** Para stack_a de tamanho entre 4 e 19.
** Esse algoritmo é dividida em três etapas:
**
** 1º)	Pega as instruções para passar os dois menores números da
** 		stack_a para stack_b - por exemplo: stack_a é: 3 2 5 1 4
** 		Passando os números 1 e 2 para stack_b, ficando na stack_a 3 5 4
**
** 2º)	Uma vez que stack_a contém apenas três inteiros para classificar,
** 		chamamos a função sort_small().
** 		Seguindo o exemplo acima, stack_a seria agora: 3 4 5.
**
** 3º)	Agora o programa precisa voltar os números da stack_b para stack_a.
*/
void	sort_medium(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_stack_size(*stack_a) > 3)
		send_min_to_b(stack_a, stack_b);
	sort_small(stack_a);
	while (ft_stack_size(*stack_b))
		push_stack(stack_b, stack_a, "pa\n");
}

/*
** Para stack_a de tamanho maior que 20.
** Separei o algoritmo em duas fases diferentes:
** a fase de dividir, e a fase de mesclagem.
**
** Fase de divisão:
** Esta fase é focada em passar para stack_b, os números entre um certo bloco.
** As instruções usadas para esta parte são: "RA", "RRA" e "PB".
** Esta fase termina quando todos os números do bloco estão na stack_b.
**
** Ex:		100 números aleatórios de 1 a 100.
** 			1º bloco: números de 1 a 50 na stack_b.
** 			2º bloco: números de 50 a 100 na stack_a.
**
** Agora o programa decidirá entre:
** 	- Fase de voltar a mesclar:
** 		Esta fase ocorre se o tamanho da stack_b é muito grande para a fase de
** 		classificar e mesclar. Então, o que acontecerá aqui é que a metade
** 		dos valores da stack_b voltarão para stack_a (especificamente valores
**		que são maiores que o valor mediano da stack_b).
** 		Isso acontece ao mesmo tempo que tenta classificar o que é possível
**		enquanto volta pra stack_a.
** 	- Fase de classificar e mesclar:
** 		Esta fase ocorre se a stack_b estiver pronta para voltar pra stack_a.
*/
void	sort_big(t_stack **stack_a, t_stack **stack_b, t_stack **refs, int i)
{
	if (ft_stack_size(*refs) == 1)
	{
		ft_stack_clear(refs);
		return ;
	}
	if (ft_stack_size(*refs) == 2 && count_index(*stack_a, *refs) >= MAX_SIZE)
		get_new_block(refs, *stack_a, 1);
	if (!ft_stack_size(*stack_b))
	{
		split_blocks(stack_a, stack_b, *refs);
		rotate_stack_to_sort(stack_a, *refs);
	}
	if (ft_stack_size(*stack_b) >= MAX_SIZE)
		merge_max_back(stack_a, stack_b, *refs);
	else
	{
		merge_sorted(stack_a, stack_b, *refs);
		ft_stack_remove(refs);
	}
	sort_big(stack_a, stack_b, refs, ++i);
}

/*
** Esta é uma função auxiliar da merge_sorted(). Ela retornará o número
** mínimo de stack_a que não está ordenado, como o novo limite.
** 	Ex:
** 		refs: {12, 25, 50, 100}
** 		stack_a: [1, 12] ordenado
** 				[12, 100] desordenado
** 		new refs: {13, 25, 50, 100}
*/
int	get_next_min(t_stack *stack_a, t_stack **refs)
{
	t_stack	*duplicate;
	int		position;
	int		min;

	duplicate = ft_stack_duplicate(stack_a);
	ft_stack_sort(&duplicate);
	position = ft_stack_find(duplicate, (*refs)->next->data);
	min = ft_stack_get(duplicate, position);
	if (min == ft_stack_last(duplicate)->data)
	{
		ft_stack_clear(&duplicate);
		return (min);
	}
	else
		min = ft_stack_get(duplicate, position + 1);
	ft_stack_clear(&duplicate);
	return (min);
}

/*
** Rotaciona stack_a até que os números ordenados sejam encontrados na parte
** inferior da pilha ordenada em ordem decrescente.
*/
void	rotate_stack_to_sort(t_stack **stack_a, t_stack *refs)
{
	t_stack	*duplicate;
	int		num;
	int		index;

	duplicate = ft_stack_duplicate(*stack_a);
	ft_stack_add_front(&duplicate, ft_stack_new(refs->data));
	ft_stack_sort(&duplicate);
	num = ft_stack_get(duplicate, ft_stack_find(duplicate, refs->data) - 1);
	ft_stack_clear(&duplicate);
	index = ft_stack_find(*stack_a, num);
	if (num == -2147483648 || index == -2147483648)
		return ;
	if (index <= ft_stack_size(*stack_a) / 2)
		while (ft_stack_last(*stack_a)->data != num)
			rotate_stack(stack_a, 0, "ra\n");
	else
		while (ft_stack_last(*stack_a)->data != num)
			reverse_rotate_stack(stack_a, 0, "rra\n");
}
