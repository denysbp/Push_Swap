/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 02:02:43 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/05 00:28:08 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **stack, t_stack **b, size_t min_pos, size_t size)
{
	size_t	count;
	t_stack	*min;

	while (*stack)
	{
		min = find_min(*stack);
		min_pos = get_position(*stack, min);
		size = stack_size(*stack);
		if (min_pos <= size / 2)
		{
			while (min_pos--)
				ra(stack);
		}
		else
		{
			count = size - min_pos;
			while (count--)
				rra(stack);
		}
		pb(stack, b);
	}
}

void	selection_min(t_stack **stack)
{
	t_stack	*b;
	size_t	min_pos;
	size_t	size;

	b = NULL;
	min_pos = 0;
	size = 0;
	push_a(stack, &b, min_pos, size);
	while (b)
	{
		pa(&b, stack);
	}
}
