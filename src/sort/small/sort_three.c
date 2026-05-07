/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:14:17 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/07 15:22:22 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_three(t_stack **a, t_bench_mark *bench)
{
	t_stack	*highest;
	int		op_count;

	if (!a || !bench)
		return (0);
	op_count = 0;
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
	t_stack	*min;

	assign_index(a);
	min = find_min(a);
	if (is_above_median(a, min))
	{
		while (min != *a)
			op_count += ra(a, bench);
	}
	else
	{
		while (min != *a)
			op_count += rra(a, bench);
	}
	op_count += pb(a, b, bench);
	op_count += sort_three(a, bench);
	op_count += pa(b, a, bench);
	return (op_count);
}
