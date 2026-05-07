/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 19:40:48 by pecoelho          #+#    #+#             */
/*   Updated: 2026/05/07 19:46:43 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	
	op_count = 0;
	assign_index(a);
	min = find_min(*a);
	if (is_above_median(a, min))
	op_count += pa(b, a, bench);
	return (op_count);
}

int	sort_five(t_stack **a, t_stack **b, t_bench_mark *bench)
{
	int		op_count;
	t_stack	*min;

	op_count = 0;
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
	op_count += sort_four(a, b, bench);
	return (op_count);
}

int	tiny_sort(t_stack **a, t_stack **b, t_bench_mark *bench)
{
	size_t	size;
	int		op_count;

	size = stack_size(*a);
	op_count = 0;
	if (size == 1)
		return (0);
	else if (size == 2)
		op_count += sa(a, bench);
	else if (size == 3)
		op_count += sort_three(a, bench);
	else if (size == 4)
		op_count += sort_four(a, b, bench);
	else if (size == 5)
		op_count += sort_five(a, b, bench);
	return (op_count);
}
