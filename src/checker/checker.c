#include "../../include/checker.h"

/*
** Termina o programa se bem sucedido ou se Error.
**
** flag:
** 		0 - Caso o programa termine com Error.
** 		1 - Caso o programa termine com stack_a não ordenada.
** 		2 - Caso o programa termine com stack_a ordenada.
*/
void	exit_chkr(t_stack *stack_a, t_stack *stack_b, t_list **inst, int flag)
{
	if (stack_a)
		ft_stack_clear(&stack_a);
	if (stack_b)
		ft_stack_clear(&stack_b);
	if (*inst)
	{
		while (*inst)
		{
			free((*inst)->content);
			ft_lstremove(inst);
		}
	}
	if (!flag)
		ft_putstr_fd("Error\n", 2);
	else if (flag == 1)
		ft_putstr_fd("KO\n", 2);
	else if (flag == 2)
	{
		ft_putstr_fd("OK\n", 1);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}

/*
** Esta função implementa as instruções recebidas e envia para as stacks.
*/
void	apply_moves(t_stack **stack_a, t_stack **stack_b, char *inst)
{
	if (!ft_strcmp("sa", inst))
		swap_stack(*stack_a, 0, 0);
	if (!ft_strcmp("sb", inst))
		swap_stack(*stack_b, 0, 0);
	if (!ft_strcmp("ss", inst))
		swap_stack(*stack_a, *stack_b, 0);
	if (!ft_strcmp("pa", inst))
		push_stack(stack_b, stack_a, 0);
	if (!ft_strcmp("pb", inst))
		push_stack(stack_a, stack_b, 0);
	if (!ft_strcmp("ra", inst))
		rotate_stack(stack_a, 0, 0);
	if (!ft_strcmp("rb", inst))
		rotate_stack(stack_b, 0, 0);
	if (!ft_strcmp("rr", inst))
		rotate_stack(stack_a, stack_b, 0);
	if (!ft_strcmp("rra", inst))
		reverse_rotate_stack(stack_a, 0, 0);
	if (!ft_strcmp("rrb", inst))
		reverse_rotate_stack(stack_b, 0, 0);
	if (!ft_strcmp("rrr", inst))
		reverse_rotate_stack(stack_a, stack_b, 0);
}

/*
** Esta função irá iterar a lista 'inst' e chama a função
** apply_moves().
**
** *inst	- Lista com instruções.
*/
void	call_moves(t_stack **stack_a, t_stack **stack_b, t_list *inst)
{
	while (inst)
	{
		apply_moves(stack_a, stack_b,
			(char *)inst->content);
		inst = inst->next;
	}
}

/*
** A função get_moves() vai ler as linhas de STDIN e guardar nas
** inst (t_list * structure), se forem válidas.
**
** **inst	- lista que armazena as instruções para ordenar a stack_a.
** **stack_a		- stack contém os inteiros a serem ordenados.
** **stack_b		- stack que ajuda a ordenar a stack_a.
*/
void	get_moves(t_stack **stack_a, t_list **inst)
{
	char	*line;
	t_list	*new_node;

	while (get_next_line(STDIN_FILENO, &line))
	{
		if (!(!ft_strcmp("sa", line) || !ft_strcmp("sb", line)
				|| !ft_strcmp("ss", line) || !ft_strcmp("pa", line)
				|| !ft_strcmp("pb", line) || !ft_strcmp("ra", line)
				|| !ft_strcmp("rb", line) || !ft_strcmp("rr", line)
				|| !ft_strcmp("rra", line) || !ft_strcmp("rrb", line)
				|| !ft_strcmp("rrr", line)))
		{
			free(line);
			exit_chkr(*stack_a, 0, inst, 0);
		}
		new_node = ft_lstnew(line);
		if (!new_node)
		{
			free(line);
			exit_chkr(*stack_a, 0, inst, 0);
		}
		ft_lstadd_back(inst, new_node);
	}
	free(line);
}

/*
** BONUS = checker.
** A função main() protótipa e inicializa as duas stacks do projeto;
** Preenche a 'stack_a' - load_args();
** Recebe as instruções do usuário - get_moves();
** Executa as instruções - call_moves();
** Sai do programa - exit_chkr().
**
** argc		-> Número de argumentos da linha de comando.
** *argv	-> Executável + números para preencher a stack a ser ordenada.
*/
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*inst;

	if (argc == 1)
		exit(1);
	argv = &argv[1];
	argc--;
	if (argc == 1)
		argv = parse_string(&argc, argv);
	stack_a = 0;
	stack_b = 0;
	inst = 0;
	load_args(&argv[0], &stack_a);
	get_moves(&stack_a, &inst);
	call_moves(&stack_a, &stack_b, inst);
	if (ft_stack_is_sorted(stack_a) && !stack_b)
		exit_chkr(stack_a, stack_b, &inst, 2);
	exit_chkr(stack_a, stack_b, &inst, 1);
	return (0);
}
