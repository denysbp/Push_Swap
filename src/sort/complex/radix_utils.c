/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:05:59 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/06 10:18:03 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	stackb_cleanup(t_stack **a, t_stack **b, t_bench_mark *bench)
{
	size_t	n;
	int		op_count;

	n = stack_size(*b);
	while (n)
	{
		op_count += pa(b, a, bench);
		n--;
	}
	return (op_count);
}

int	stack_selection(t_stack **a, t_stack **b, int mask, t_bench_mark *bench)
{
	if (!((*a)->index & mask))
		pb(a, b, bench);
	else
		ra(a, bench);
	return (1);
}
