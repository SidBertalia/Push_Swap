#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

# ifndef MAX_SIZE
#  define MAX_SIZE 20
# endif

void	choose_algorithm(t_stack **stack_a, t_stack **stack_b);
void	sort_small(t_stack **stack_a);
void	sort_medium(t_stack **stack_a, t_stack **stack_b);
void	sort_big(t_stack **stack_a, t_stack **stack_b, t_stack **refs, int i);
void	send_min_to_b(t_stack **stack_a, t_stack **stack_b);
void	get_new_block(t_stack **refs, t_stack *stack, int flag);
int		moves_to_top(t_stack *stack_a, t_stack *refs);
void	split_blocks(t_stack **stack_a, t_stack **stack_b, t_stack *refs);
void	merge_max_back(t_stack **stack_a, t_stack **stack_b, t_stack *refs);
void	merge_sorted(t_stack **stack_a, t_stack **stack_b, t_stack *refs);
void	rotate_stack_to_sort(t_stack **stack_a, t_stack *refs);
int		count_index(t_stack *stack_a, t_stack *refs);
int		get_next_min(t_stack *stack_a, t_stack **refs);
char	**parse_string(int *argc, char **argv);
void	push_stack(t_stack **from_stack, t_stack **to_stack, char *msg);
void	reverse_rotate_stack(t_stack **base, t_stack **aux, char *msg);
void	rotate_stack(t_stack **base, t_stack **aux, char *msg);
void	swap_stack(t_stack *base, t_stack *aux, char *msg);
void	load_args(char **argv, t_stack **stack_a);
void	exit_push_swap(t_stack *stack_a, t_stack *stack_b, int flag);

#endif