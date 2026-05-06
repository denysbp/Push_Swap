/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:14:17 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/06 23:06:35 by deferrei         ###   ########.fr       */
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
