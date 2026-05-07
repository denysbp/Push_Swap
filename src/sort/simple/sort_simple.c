/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 02:02:43 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/07 21:10:54 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a(t_stack **stack, t_stack **b, size_t min_pos, size_t size, t_bench_mark *bench)
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
				ra(stack, bench);
		}
		else
		{
			count = size - min_pos;
			while (count--)
				rra(stack, bench);
		}
		pb(stack, b, bench);
	}
}

void	selection_min(t_stack **a, t_stack **b, t_bench_mark *bench)
{
	size_t	min_pos;
	size_t	size;

	min_pos = 0;
	size = 0;
	push_a(a, b, min_pos, size, bench);
	while (*b)
	{
		pa(b, a, bench);
	}
}
