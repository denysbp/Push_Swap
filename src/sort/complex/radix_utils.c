/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:05:59 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/07 21:51:19 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	assign_index(t_stack **stack)
{
	t_stack	*cur;
	t_stack	*cmp;
	int		index;

	cur = *stack;
	while (cur)
	{
		index = 0;
		cmp = *stack;
		while (cmp)
		{
			if (cmp->value < cur->value)
				index++;
			cmp = cmp->next;
		}
		cur->index = index;
		cur = cur->next;
	}
}

void	stackb_cleanup(t_stack **a, t_stack **b, t_bench_mark *bench)
{
	size_t	n;

	n = stack_size(*b);
	while (n)
	{
		pa(b, a, bench);
		n--;
	}
}

void	stack_selection(t_stack **a, t_stack **b, int mask, t_bench_mark *bench)
{
	if (!((*a)->index & mask))
		pb(a, b, bench);
	else
		ra(a, bench);
}
