#include "../../include/push_swap.h"

/*
** Esta função coloca o último elemento no topo da stack, descendo todos os
** outros uma posição.
**
** '**base'	- Esta stack será sempre rotacionada.
** '**aux'	- Esta stack é opcional e não precisa ser rotacionada.
** '*msg'	- Mensagem a ser exibida no final da função. Mensagens possíveis:
** 					"rra\n"	- Rotaciona reverso os elementos da 'stack_a'.
** 					"rrb\n"	- Rotaciona reverso os elementos da 'stack_b'.
** 					"rrr\n"	- Rotaciona reverso os elementos de ambas stacks.
*/
void	reverse_rotate_stack(t_stack **base, t_stack **aux, char *msg)
{
	int		data;
	t_stack	*last_node;

	last_node = ft_stack_last(*base);
	data = last_node->data;
	ft_stack_remove(&last_node);
	ft_stack_add_front(base, ft_stack_new(data));
	if (aux)
	{
		last_node = ft_stack_last(*aux);
		data = last_node->data;
		ft_stack_remove(&last_node);
		ft_stack_add_front(aux, ft_stack_new(data));
	}
	ft_putstr_fd(msg, 1);
}

/*
** Esta função coloca o primeiro elemento no final da stack, subindo todos os
** outros uma posição.
**
** '**base'	- Esta stack será sempre rotacionada.
** '**aux'	- Esta stack é opcional e não precisa ser rotacionada.
** '*msg'	- Mensagem a ser exibida no final da função:
**					"ra\n"	- Rotaciona os elementos da 'stack_a'.
**					"rb\n"	- Rotaciona os elementos da 'stack_b'.
**					"rr\n"	- Rotaciona os elementos de ambas stacks.
*/
void	rotate_stack(t_stack **base, t_stack **aux, char *msg)
{
	int	data;

	data = ft_stack_first(*base)->data;
	ft_stack_remove(base);
	ft_stack_add_back(base, ft_stack_new(data));
	if (aux)
	{
		data = ft_stack_first(*aux)->data;
		ft_stack_remove(aux);
		ft_stack_add_back(aux, ft_stack_new(data));
	}
	ft_putstr_fd(msg, 1);
}

/*
** Esta função troca os dois primeiros elementos no topo da 'stack_a' ou
** 'stack_b' ou ambos.
**
** **base	- Troca os dois primeiros elementos desta stack. Esta stack
** sempre será trocada.
**
** **aux	- Troca os dois primeiros elementos desta stack. Esta stack
** é opcional e não precisa ser trocada.
**
** *msg	- Mensagem a ser exibida no final da função. Mensagens possíveis:
** 				"sa\n"	- troca os dois primeiros elementos da 'stack_a'.
** 				"sb\n:	- troca os dois primeiros elementos da 'stack_b'.
** 				"ss\n"	- troca os dois primeiros elementos de ambas stacks.
*/
void	swap_stack(t_stack *base, t_stack *aux, char *msg)
{
	ft_swap(&(base->data), &(base->next->data));
	if (aux)
		ft_swap(&(aux->data), &(aux->next->data));
	ft_putstr_fd(msg, 1);
}

/*
** Essa função coloca os dois menores inteiros de stack_a para stack_b.
** Esta é uma função auxiliar da função sort_medium().
** Itera stack_a procurando por seu inteiro de valor mínimo rotacionando 'RA'
** ou 'RRA', depois quando o valor mínimo estiver no topo a função 'push_stack()
** empurra para stack_b.
*/
void	send_min_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = ft_stack_min_value(*stack_a);
	while ((*stack_a)->data != min)
	{
		if ((*stack_a)->data != min && (*stack_a)->next->data != min)
			reverse_rotate_stack(stack_a, 0, "rra\n");
		else
			rotate_stack(stack_a, 0, "ra\n");
	}
	push_stack(stack_a, stack_b, "pb\n");
}

/*
** Esta função pega o primeiro elemento no topo da 'from_stack' e coloca no
** topo da 'to_stack'.
**
** **from_stack		- stack para pegar o inteiro.
** **to_stack		- stack onde o inteiro deve ir.
** char	*msg	- mensagem a ser exibida no final da função.
** 			Possible msgs:
** 			"pa\n"	- põe o 1º elemento da 'stack_b' no o topo da 'stack_a'.
** 			"pb\n"	- põe o 1º elemento da 'stack_a' no o topo da 'stack_b'.
*/
void	push_stack(t_stack **from_stack, t_stack **to_stack, char *msg)
{
	if (!(*from_stack))
		return ;
	ft_stack_add_front(to_stack, ft_stack_new((*from_stack)->data));
	ft_stack_remove(from_stack);
	ft_putstr_fd(msg, 1);
}
