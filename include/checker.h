#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/includes/libft.h"

void	get_moves(t_stack **stack_a, t_list **inst);
void	apply_moves(t_stack **stack_a, t_stack **stack_b, char *inst);
void	call_moves(t_stack **stack_a, t_stack **stack_b, t_list *inst);
char	**parse_string(int *argc, char **argv);
void	exit_chkr(t_stack *stack_a, t_stack *stack_b, t_list **inst, int flag);
void	reverse_rotate_stack(t_stack **base, t_stack **aux, char *msg);
void	rotate_stack(t_stack **base, t_stack **aux, char *msg);
void	swap_stack(t_stack *base, t_stack *aux, char *msg);
void	send_min_to_b(t_stack **stack_a, t_stack **stack_b);
void	push_stack(t_stack **from_stack, t_stack **to_stack, char *msg);
void	load_args(char **argv, t_stack **stack_a);

#endif
