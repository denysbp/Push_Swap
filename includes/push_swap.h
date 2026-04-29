#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "ft_printf.h"

typedef	struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

t_stack	*last_stack(t_stack *lst);
void	swap(t_stack **a, t_stack **b);
t_stack	*new_stack(int content);
void	stack_add_back(t_stack **stack, t_stack *new);
size_t	stack_size(t_stack *stack);
void	stack_add_front(t_stack **stack, t_stack *new);

#endif