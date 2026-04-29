/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:07:48 by deferrei          #+#    #+#             */
/*   Updated: 2026/04/29 19:13:47 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

#endif