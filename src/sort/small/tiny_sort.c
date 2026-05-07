/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 19:40:48 by pecoelho          #+#    #+#             */
/*   Updated: 2026/05/07 21:05:00 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **a, t_bench_mark *bench)
{
	t_stack	*highest;

	if (!a || !bench)
		return ;
	highest = find_max(*a);
	if (*a == highest)
		ra(a, bench);
	else if ((*a)->next == highest)
		rra(a, bench);
	if ((*a)->index > (*a)->next->index)
		sa(a, bench);
}

void	sort_four(t_stack **a, t_stack **b, t_bench_mark *bench)
{
	
	t_stack	*min;
	
	assign_index(a);
	min = find_min(*a);
	if (is_above_median(a, min))
	pa(b, a, bench);
}

void	sort_five(t_stack **a, t_stack **b, t_bench_mark *bench)
{
	t_stack	*min;

	assign_index(a);
	min = find_min(*a);
	if (is_above_median(a, min))
	{
		while (min != *a)
			ra(a, bench);
	}
	else
	{
		while (min != *a)
			rra(a, bench);
	}
	pb(a, b, bench);
	sort_four(a, b, bench);
}

void	tiny_sort(t_stack **a, t_stack **b, t_bench_mark *bench)
{
	size_t	size;

	size = stack_size(*a);
	if (size == 1)
		return ;
	else if (size == 2)
		sa(a, bench);
	else if (size == 3)
		sort_three(a, bench);
	else if (size == 4)
		sort_four(a, b, bench);
	else if (size == 5)
		sort_five(a, b, bench);
}
