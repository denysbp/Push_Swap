/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:07:48 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/02 21:09:17 by pecoelho         ###   ########.fr       */
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

t_stack	*last_stack(t_stack *lst);
void	swap(int *a, int *b);
t_stack	*new_stack(int content);
void	stack_add_back(t_stack **stack, t_stack *new);
size_t	stack_size(t_stack *stack);
void	stack_add_front(t_stack **stack, t_stack *new);
float	disorder_rate(t_stack *stack);
void	bubble_sort(t_stack **stack);
void	sort_choose(t_stack **stack);
bool	is_duplicate(t_stack *stack);
void	error();
bool	string_overflow(char *string);
long	ft_atoi_safe(const char *str);
bool	check_numbers(char *string);
int 	op_swap_stack(t_stack **name);
int		op_rot_stack(t_stack **stack);
int		op_rev_stack(t_stack **stack);
int		op_swap_both(t_stack **s1, t_stack **s2);
int		op_rot_both(t_stack **s1, t_stack **s2);
int		op_rot_both(t_stack **s1, t_stack **s2);

#endif