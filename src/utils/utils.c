#include "../../include/push_swap.h"

/*
** Esta função trata a string de parametros, retornando apenas os argumentos
** necessários para preencher a 'stack_a'.
*/
char	**parse_string(int *argc, char **argv)
{
	int	i;

	i = 0;
	if (!(argv[0][0]))
		exit(0);
	argv = ft_split(argv[0], ' ');
	while (argv[i] != NULL)
		i++;
	*argc = i;
	return (argv);
}

/*
** Esta função recebe os argumentos da string do 'argv';
** Converte para inteiros e adiciona de traz pra frente na stack_a.
** Para isso, os argumentos precisam ser apenas numéricos;
** não podem haver dois argumentos iguais, e os inteiros não podem ser
** maior que MAX_INT nem menor que MIN_INT.
*/
void	load_args(char **argv, t_stack **stack_a)
{
	int			i;
	long int	data;
	t_stack		*new_node;

	i = 0;
	while (argv[i])
	{
		if (!ft_str_isnumeric(argv[i]))
			exit_push_swap(*stack_a, 0, 0);
		data = ft_atol(argv[i]);
		if (!ft_isint(data))
			exit_push_swap(*stack_a, 0, 0);
		new_node = ft_stack_new(data);
		if (!new_node)
			exit_push_swap(*stack_a, 0, 0);
		ft_stack_add_back(stack_a, new_node);
		i++;
	}
	if (ft_stack_is_duplicate(*stack_a))
		exit_push_swap(*stack_a, 0, 0);
}

/*
** Termina o programa, seja ele bem sucedido ou em caso de erro.
**
** Free na stack_a e stack_b se necessário.
** int status	->	status do programa
** 				->	0 - FAILURE - encerra o programa com "Error\n"
** 				->	1 -	SUCCESS - encerra o programa sem problemas.
*/
void	exit_push_swap(t_stack *stack_a, t_stack *stack_b, int status)
{
	if (stack_a)
		ft_stack_clear(&stack_a);
	if (stack_b)
		ft_stack_clear(&stack_b);
	if (!status)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
