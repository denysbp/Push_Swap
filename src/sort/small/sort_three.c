/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:14:17 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/06 19:05:14 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_three(t_stack **a, t_bench_mark *bench)
{
	t_stack	*highest;
	int		op_count;

	if (!a || !bench)
		return (NULL);
	highest = find_max(*a);
	if (*a == highest)
		op_count += ra(a, bench);
	else if ((*a)->next == highest)
		op_count += rra(a, bench);
	if ((*a)->index > (*a)->next->index)
		op_count += sa(a, bench);
	return (op_count);
}

int	sort_four(t_stack **a, t_stack **b, t_bench_mark *bench)
{
	int		op_count;

	assign_index(a);
	op_count = pb(a, b, bench);
	op_count += sort_three(a, bench);
	if ((*b)->index == 2)
	{
		op_count += rra(a, bench);
		op_count += pa(b, a, bench);
		op_count += ra(a, bench);
		op_count += ra(a, bench);
	}
	else
	{
		op_count += pa(b, a, bench);
		if ((*a)->index == 1)
			op_count += sa(a, bench);
		else if((*a)->index == 3)
			op_count += 4;
	}
	return (op_count);
}
