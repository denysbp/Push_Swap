/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:07:48 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/04 22:08:03 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>
# include "ft_printf.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

void	stack_clear(t_stack **stack);
void	swap(int *a, int *b);
void	stack_add_back(t_stack **stack, t_stack *new);
void	free_split(char **split);
void	stack_add_front(t_stack **stack, t_stack *new);
void	stack_clear(t_stack **lst);
void	stack_delone(t_stack *lst);
void	sort_choose(t_stack **stack);
void	error(void);
void	push(t_stack **src, t_stack **dest);
void	radix_rank(t_stack **stack);
void	stack_indexing(t_stack **stack);
void	selection_min(t_stack **stack);
void	pa(t_stack **b, t_stack **a);
void	pb(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	push_chunks(t_stack **a, t_stack **b, size_t chunck_size);
void	push_back_sorted(t_stack **a,t_stack **b);
void	chunck_sort(t_stack	**stack);
void	assign_index(t_stack *stack);
bool	is_duplicate(t_stack *stack);
bool	string_overflow(char *string);
bool	valide_signal(char *string);
bool	is_signal(char string);
bool	check_numbers(char *string);
bool	validate_args(char **argv);
int		op_swap_stack(t_stack **name);
int		op_rot_stack(t_stack **stack);
int		op_rev_stack(t_stack **stack);
int		op_swap_both(t_stack **s1, t_stack **s2);
int		op_rot_both(t_stack **s1, t_stack **s2);
int		op_rev_both(t_stack **s1, t_stack **s2);
int		radix_sorts(char **nb);
long	ft_atoi_safe(const char *str);
size_t	stack_size(t_stack *stack);
size_t	get_position(t_stack *stack, t_stack *target);
size_t	ft_sqrt(size_t chuncks);
float	disorder_rate(t_stack *stack);
t_stack	*last_stack(t_stack *lst);
t_stack	*new_stack(int content);
t_stack	*find_max(t_stack *a);
t_stack	*first_stack(t_stack *lst);
t_stack	*parsing(char **argv);
t_stack	*find_min(t_stack *a);

#endif